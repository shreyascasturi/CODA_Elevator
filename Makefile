CC=gcc
CLAGS=-I

hello_make:
	$(CC) -o hello hello.c $(CFLAGS)
elevator_make: main.c
	$(CC) -o main main.c $(CFLAGS)

all:
	$(CC) -o hello hello.c $(CFLAGS)
	$(CC) -o main main.c $(CFLAGS)

clean:
	rm main hello