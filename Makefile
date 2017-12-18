chess: main.o lib.o
       gcc -o chess main.o lib.o
        
main.o: main.c lib.h
        gcc -c main.c 

lib.o: lib.c lib.h
       gcc -c lib.c
