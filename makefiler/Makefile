OBJ = date.o calendar.o
CFLAGS = -Wall -pedantic

calendar.o: calendar.c date.o
	gcc $(CFLAGS) -c calendar.c -o calendar.o

date.o: date.c
	gcc $(CFLAGS) -c date.c -o date.o

calendartest.o: calendartest.c date.o calendar.o 
	gcc $(CFLAGS) -c calendartest.c -o calendartest.o

calendartest: calendar.o date.o calendartest.o 
	gcc $(CFLAGS) calendartest.o calendar.o date.o -o calendartest

myapp.o: myapp.c calendar.o date.o
	gcc $(CFLAGS) -c myapp.c -o myapp.o

myapp: myapp.o date.o calendar.o
	gcc $(CFLAGS) myapp.o calendar.o date.o -o myapp

all: date.o calendar.o calendartest