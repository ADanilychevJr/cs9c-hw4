all:
	gcc p4.c -o p4.o -c
	gcc animal1.c -o animal1.o -c
	gcc animal2.c -o animal2.o -c 

	gcc -o myprog p4.o animal1.o animal2.o
