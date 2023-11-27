all: geraos main

main: main.o aluno.o vector.o relatorio.o
	gcc *.o -o main

geraos: main.c aluno.c vector.c relatorio.c
	gcc -c -g *.c

clean:
	rm -rf *.o main