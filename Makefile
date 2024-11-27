ti = -Wall -Wextra

all: main mainAPI

main : main.o fonction.o
	gcc $^ -o $@ $(ti)

mainAPI: mainAPI.c fonction.c fonction.h userNetwork.h
	$(CC) $(CFLAGS) -L. -o mainAPI mainAPI.c fonction.c -lothello

main.o: main.c fonction.h
	gcc -c $< -o $@ $(ti)

test : test.c fonction.o
	gcc -o $@ $^

fonction.o : fonction.c fonction.h
	gcc -c $< -o $@ $(ti)

clean :
	rm -f main *.o
