all: main.o
	gcc -o signal main.c

main.o: main.c
	gcc -c main.c

run:
	./signal

clean:
	rm *.o
