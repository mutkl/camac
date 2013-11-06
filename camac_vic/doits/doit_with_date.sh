#!/bin/bash

n_of_runs=$1
output_name=acquisition.root
new_name_prefix=8_Various_3_Various_1_Various/data_


time_to_seconds(){
 m=$1
 d=$2
 t=$3

 months[0]=31
 months[1]=28
 months[2]=31
 months[3]=30
 months[4]=31
 months[5]=30
 months[6]=31
 months[7]=31
 months[8]=30
 months[9]=31
 months[10]=30
 months[11]=31

 mm=''
 daypermonth=0

 if [ "$m" = "Oct" ]; then
     mm=9
     daypermonth=31
 elif [ "$m" = "Nov" ]; then
     mm=10
     daypermonth=30
 elif [ "$m" = "Dec" ]; then
     mm=11
     daypermonth=31
 elif [ "$m" = "Jan" ]; then
     mm=0
     daypermonth=31
 elif [ "$m" = "Feb" ]; then
     mm=1
     daypermonth=28
 elif [ "$m" = "Mar" ]; then
     mm=2
     daypermonth=31
 elif [ "$m" = "Apr" ]; then
     mm=3
     daypermonth=30
 elif [ "$m" = "May" ]; then
     mm=4
     daypermonth=31
 elif [ "$m" = "Jun" ]; then
     mm=5
     daypermonth=30
 elif [ "$m" = "Jul" ]; then
     mm=6
     daypermonth=31
 elif [ "$m" = "Aug" ]; then
     mm=7
     daypermonth=31
 elif [ "$m" = "Sep" ]; then
     mm=8
     daypermonth=30
 else
     echo " month " $m " unknown "
     exit
 fi


 h=`echo $t | awk -F ":" '{print $1}'`
 mi=`echo $t | awk -F ":" '{print $2}'`
 se=`echo $t | awk -F ":" '{print $3}'`

 days_in_past_months=0
 for((imonth=0; imonth<$mm; imonth++)); do
     days_in_past_months=`echo $days_in_past_months ${months[$imonth]} | awk '{ T=$1 + $2}; END { print T}'`
 done

 secperhour=3600
 secpermin=60
 hourperday=24

 thetime=`echo $mm $d $h $mi $se $secperhour $hourperday $daypermonth $secpermin $days_in_past_months | awk '{ T=(($10 + $2)*$7 + $3)*$6 + $4*$9 + $5}; END { print T}'`


}


echo " I will run over " $n_of_runs " runs"


 I=$n_of_runs
 for(( i=0; i<$n_of_runs; i++)); do

  echo "doing run " $i
  month=`date | awk '{print $2}'`
  day=`date | awk '{print $3}'`
  hour=`date | awk '{print $4}'`
  time_to_seconds $month $day $hour

  echo month $month day $day hour $hour

  initial_time=`echo $thetime`

  ./camacDaq

  new_full_name=$new_name_prefix$initial_time.root

  echo file name $new_full_name

  mv $output_name $new_full_name
 done


 echo all done
