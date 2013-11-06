###################################################
CC = gcc
LOADLIBES =  -lsjy -lConfig -lkvp -lMsgLog
SJY_DIR = ${shell pwd}/fnal_camac
INCDIR = ${shell pwd}/include
INC = -I$(SJY_DIR)/include -I$(INCDIR)
OPTIMISE = -O2
CFLAGS = -g $(INC) $D -DNEW -Wall $(OPTIMISE)
LIBDIR = ${shell pwd}/lib
LDFLAGS = -L$(SJY_DIR)/lib -L$(LIBDIR)


%.d : %.c ; ${CC} ${INC} -MM $< > $@ 


OBJS = camacDaq.o
DEPS = $(OBJS:%.o=%.d)
TARGETS = camacDaq

###################################################

all : $(TARGETS) $(DEPS)

ifneq ($(MAKECMDGOALS),clean)
include $(DEPS)
endif

clean:
	rm -f *.o *.d $(TARGETS)

