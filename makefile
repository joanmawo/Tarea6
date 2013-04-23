a.out: main.o runge.o funciones.o 
	@cc main.o runge.o funciones.o
	@./a.out
	@python graficador.py


main.o: main.c
	@cc -c main.c

runge.o: runge.c 
	@cc -c runge.c

funciones.o: funciones.c 
	@cc -c funciones.c

all: a.out

clean:
	@rm -f *.o
	@rm -f a.out
	@rm -f *.jpg
