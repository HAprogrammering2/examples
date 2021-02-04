OBJ = date.o calendar.o 
CFLAGS = -Wall -pedantic
RM = del
BIN = datetest.exe calendartest.exe myapp.exe

calendar.o: calendar.c date.o
	gcc $(CFLAGS) -c calendar.c -o calendar.o

date.o: date.c
	gcc $(CFLAGS) -c date.c -o date.o

datetest: datetest.c date.o
	gcc $(CFLAGS) datetest.c date.o -o datetest

calendartest: calendar.o date.o calendartest.c 
	gcc $(CFLAGS) calendartest.c calendar.o date.o -o calendartest

myapp.o: myapp.c calendar.o date.o
	gcc $(CFLAGS) -c myapp.c -o myapp.o

myapp: myapp.o date.o calendar.o
	gcc $(CFLAGS) myapp.o calendar.o date.o -o myapp

all: datetest calendartest myapp 

clean:
	$(RM) $(OBJ) $(BIN)

runtest: datetest calendartest
	datetest
	calendartest