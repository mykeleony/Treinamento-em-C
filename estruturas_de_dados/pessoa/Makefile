all: data.o pessoa.o main.o
	gcc -o meuPrograma data.o pessoa.o main.o

data.o: data.h data.c
	gcc -c data.c

pessoa.o: pessoa.h pessoa.c data.h
	gcc -c pessoa.c

main.o: main.c pessoa.h
	gcc -c main.c

clean:
	rm -f *.o meuPrograma
