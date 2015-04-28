CFLAGS = -g -Wall
animal1 : animal1.o p4.o
	gcc $(CFLAGS) -o animal1 animal1.o p4.o
animal2 : animal2.o p4.o
	gcc $(CFLAGS) -o animal2 animal2.o p4.o
animal1.o : animal1.c animal.h
animal2.o : animal2.c animal.h
c.animal1 : animal1.c p4.c
	#load $(CFLAGS) animal1.c p4.c
c.listtest : animal2.c p4.c
	#load $(CFLAGS) animal2.c p4.c 
