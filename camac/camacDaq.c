/*********************************************************************
A-camacDaq
this program will take data from the CAMAC and save it in the original
format which has line breaks stating the event number.  this uses up
about twice as much space so i've edited this program to be BcamacDaq
and does not include that extra text.  because of the difference in the
data file the A(macro) series of macros are for the AcamacDaq and the
B(macro) series of macros are for the BcamacDaq!
*********************************************************************/

#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <signal.h>
#include <sys/time.h>
#include "ieee_fun_types.h"
#include "configLib.h"
#include "keyValuePair.h"

typedef enum {FALSE, TRUE} bool_t ;

#define NCHAN_2249 12
#define NCHAN_2228 8

static u_int32_t ext2249[NCHAN_2249];
static u_int32_t ext2228[NCHAN_2228];
static u_int32_t outreg_ext ;
static int branch=17; //this must be 9 but it's NOT the slot# which is specified in the nemoDaq.config!!!
static int crate=1;
static bool_t runActive;
static FILE* outputFile;


static void timerHandler(int signal)
{
   runActive=FALSE;
}


int open_camac (void)
{
  /* open the SCSI device */
  if((cdchn (branch, 1, 0) &1) != 1)
    {
      perror ("cdchn error (2)") ;
      return (2) ;
    }
  
  /* set the controller type */
  ccctype(branch,0,1); /* parallel - Jor 73A is considered parallel */
  printf("ok finished open_camac\n");
  return (0) ;
}


void caminit (void)
{
  int ext;
  int slot;
  int subaddr;
  
  /* We're dealing with the crate so N and A are not significant */
  slot = 1;
  subaddr = 0;
  cdreg (&ext, branch, crate, slot, subaddr);
  cccc (ext);
  cccz (ext);
  ccci (ext, FALSE);
  printf("ok finished caminit\n");
}


int adcRead(u_int16_t* buffer)
{
  int subaddr;
  int qresponse;
  
  for (subaddr=0; subaddr<NCHAN_2249; subaddr++) 
    {
      cssa (0, ext2249[subaddr], &buffer[subaddr], &qresponse);
    }
  return(0);
}


void adcClear()
{
   u_int16_t dwords[2];
   int qresponse;
   cssa (9, ext2249[0], dwords, &qresponse);
}


int tdcRead(u_int16_t* buffer)
{
  int subaddr;
  int qresponse;
  
  for (subaddr=0; subaddr<NCHAN_2228; subaddr++) 
    {
      cssa (0, ext2228[subaddr], &buffer[subaddr], &qresponse);
    }
  return(0);
}


void tdcClear()
{
  u_int16_t dwords[2];
  int qresponse;
  cssa (9, ext2228[0], dwords, &qresponse);
}


int waitForLAM(int ext)
{
  int npolls;
  int qresponse;
  int delay;
  u_int16_t dwords[2];
  volatile int dummy;
  
  npolls=0;
  do {
    cssa (8, ext, dwords, &qresponse) ;
    if (!qresponse)
      {
	npolls++ ;
	if (npolls < 2)
	  {
            for (delay = 0 ; delay < 150000 ; delay++) dummy = delay ;
	  }
	else
	  {
            usleep (1) ;
	  }
      }
  } while (runActive && !qresponse) ;
  
  return(qresponse);
}


void removeTriggerInhibit (u_int16_t or_data)
{
  int or_q;
  
#ifdef TRACE
  printf ("In remove_inhibit: calling cssa\n") ;
#endif
  cssa (17, outreg_ext, &or_data, &or_q);
}

int openOutput(char*outputPath, int runNumber)
{
  char fname[FILENAME_MAX] ;
  int status ;
  
  status = 0 ;
  snprintf (fname, sizeof(fname), "%s/run%0d.dat", outputPath, runNumber) ;
  outputFile = fopen (fname, "w") ;
  if (outputFile == NULL)
    {
      perror ("openOutput") ;
      status = 1 ;
    }
  return(status);
}


void trapSignal(int signal, void (*handler)(int))
{
  struct sigaction action ;
  
  /* Register signal handler */
  action.sa_handler = handler ;
  sigemptyset (&action.sa_mask) ;
  action.sa_flags = 0 ;
  sigaction (signal, &action, NULL) ;
}


void setupTimer(int seconds)
{
  struct itimerval interval;
  
  /* Setup the interval timer */
  interval.it_interval.tv_sec=0;
  interval.it_interval.tv_usec=0;
  
  interval.it_value.tv_sec=seconds;
  interval.it_value.tv_usec=0;
  
  setitimer(ITIMER_REAL, &interval, 0);
  
}



int main(int argc, char* argv[])
{
  u_int16_t adcValues[12];
  u_int16_t tdcValues[8];
  int channel;
  int slot2249;
  int slot2228;
  int slotOutput;
  u_int16_t or_data;
  
  bool_t useADC;
  bool_t useTDC;
  int runTime;
  int maxEvents;
  int eventNumber;
  int runNumber;
  //int rnStream;  //was getting a warning that this was an unused variable
  char* outputPath;
  FILE* rnFile;
  
  configLoad("runNumber.config","run");
  runNumber=kvpGetInt("runNumber", 0);
  runNumber++;
  rnFile=fopen("runNumber.config", "w");
  fprintf(rnFile,"<run>\nrunNumber#S=%d;\n</run>\n", runNumber);
  fclose(rnFile);
  
  /*** Get configuration from file into kvp buffer ***/
  configLoad("nemoDaq.config","global");
  useADC=kvpGetInt("useADC", 0);
  if (useADC) 
    {
      slot2249=kvpGetInt("slot2249", 0);
      if (slot2249 == 0) 
	{
	  fprintf(stderr, "ERROR: slot2249 not defined!\n");
	  return(EXIT_FAILURE);
	}
      for (channel=0; channel<NCHAN_2249; channel++) 
	{
	  cdreg (&ext2249[channel], branch, crate, slot2249, channel);
	}
    }
  useTDC=kvpGetInt("useTDC", 0);
  if (useTDC) 
    {
      slot2228=kvpGetInt("slot2228", 0);
      if (slot2228 == 0) 
	{
	  fprintf(stderr, "ERROR: slot2228 not defined!\n");
	  return(EXIT_FAILURE);
	}
      
      for (channel=0; channel<NCHAN_2228; channel++) 
	{
	  cdreg (&ext2228[channel], branch, crate, slot2228, channel);
	}
    }
  
  slotOutput=kvpGetInt("slotOutput", 0);
  if (slotOutput == 0) 
    {
      fprintf(stderr, "ERROR: slotOutput not defined!\n");
      return(EXIT_FAILURE);
    }
  cdreg (&outreg_ext, branch, crate, slotOutput, 0);
  or_data=kvpGetInt("valueOutput", 1);
  
  runTime=kvpGetInt("runTime", 0);
  
  maxEvents=kvpGetInt("maxEvents",0);
  
  outputPath=kvpGetString("outputPath");
  if (outputPath != NULL) 
    {
      openOutput(outputPath, runNumber);
    }
  else 
    {
      outputFile=stdout;
    }
  
  open_camac();
  caminit();
  printf("ok finished doing those two\n");
  runActive=TRUE;
  eventNumber=0;
  if (runTime != 0) 
    {
      trapSignal(SIGALRM, timerHandler);
      setupTimer(runTime);
    }
  trapSignal(SIGINT, timerHandler);
  while (runActive) 
    {
      removeTriggerInhibit(or_data);
      
      if (useADC) 
	{
	  waitForLAM(ext2249[0]);
	  adcRead(adcValues);
	  adcClear();
	}
      
      if (useTDC) 
	{
	  waitForLAM(ext2228[0]);
	  tdcRead(tdcValues);
	  tdcClear();
	}
      if (runActive) 
	{
	  fprintf(outputFile, "\nEvent %d", eventNumber);  //don't want this in datfile
	  if (useADC) 
	    {
	      fprintf(outputFile, "\nADC:");  //don't want this in datfile
	      for (channel=0; channel<NCHAN_2249; channel++) 
		{
		  fprintf(outputFile, "%i ", adcValues[channel]);
		  //printf("%i ",adcValues[channel]);  //print to screen
		}
	      fprintf(outputFile,"\n");
	      //printf("\n");  //print to screen
	    }
	  if (useTDC) 
	    {
	      fprintf(outputFile, "\nTDC:");
	      for (channel=0; channel<NCHAN_2228; channel++) 
		{
		  fprintf(outputFile, " %i", tdcValues[channel]);
		}
	    }
	  eventNumber++;
	  if ((maxEvents != 0) && (eventNumber >= maxEvents)) 
	    {
	      runActive=FALSE;
	    }
	}
    }
  fclose(outputFile);
  return (0);
}

