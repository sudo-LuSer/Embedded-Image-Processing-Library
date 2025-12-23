objects = main.o bitmaplib.o vectlib.o 
rmObj = main.o bitmaplib.o vectlib.o programme

program : $(objects)
	gcc -Wall -o programme $(objects)
	./programme

main.o : main.c bitmaplib.h vectlib.h
	gcc -Wall -c main.c

vectlib.o : vectlib.c vectlib.h 
	gcc -Wall -c vectlib.c

bitmaplib.o : bitmaplib.c bitmaplib.h
	gcc -Wall -c bitmaplib.c 

clean : 
	rm $(rmObj)