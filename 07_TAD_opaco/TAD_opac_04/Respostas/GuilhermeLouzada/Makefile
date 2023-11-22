all: geraos main

main: main.o aluno.o
	gcc main.o aluno.o -o main -lm

geraos: main.c aluno.c
	gcc -c -g main.c aluno.c

clean:
	rm -rf *.o main