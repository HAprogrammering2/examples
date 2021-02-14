CFLAGS = -Wall -pedantic
OBJS = myapp.o calendar.o date.o
TESTOBJS = datetest.o calendartest.o

# ----------------------
# OS dependent makros
# ----------------------
ifeq ($(OS), Windows_NT)
RM = del
BINS = myapp.exe
TESTBINS = datetest.exe calendartest.exe
else
RM = rm -rf
BINS = myapp
TESTBINS = datetest calendartest
endif


all: $(BINS) $(TESTBINS)

clean:
	rm -rf $(OBJS) $(TESTOBJS) $(BINS) $(TESTBINS)

# ----------------------
# Rules for the app
# ----------------------
myapp.o: myapp.c calendar.h date.h
	gcc $(CFLAGS) -c myapp.c 

calendar.o: calendar.c calendar.h date.h
	gcc $(CFLAGS) -c calendar.c 

date.o: date.c date.h
	gcc $(CFLAGS) -c date.c 

myapp: myapp.o calendar.o date.o
	gcc $(CFLAGS) myapp.o calendar.o date.o -o myapp

# ----------------------
# Rules for unit testing
# ----------------------
datetest.o: datetest.c date.h
	gcc $(CFLAGS) -c datetest.c

calendartest.o: calendartest.c calendar.h date.h
	gcc $(CFLAGS) -c calendartest.c

datetest: datetest.o date.o
	gcc $(CFLAGS) date.o datetest.o -o datetest

calendartest: calendartest.o calendar.o date.o
	gcc $(CFLAGS) date.o calendar.o calendartest.o -o calendartest

runtest: $(TESTBINS)
	./datetest
	./calendartest

# ----------------------------
# Implicit rule for future use
# ----------------------------
%.o: %.c
	gcc $(CFLAGS) -c $< -o $@
