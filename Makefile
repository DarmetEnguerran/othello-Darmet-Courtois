ti = -Wall -Wextra

all: main mainAPI magnus magnusAPI maintest

main : main.o fonction.o
	gcc $^ -o $@ $(ti)

mainAPI: mainAPI.c fonction.c fonction.h userNetwork.h
	$(CC) $(CFLAGS) -L. -o mainAPI mainAPI.c fonction.c -lothello

magnus : magnus.o fartif.o fonction.o
	gcc $^ -o $@ $(ti)

magnusAPI:artifAPI.c fartif.c fonction.c fonction.h userNetwork.h
	$(CC) $(CFLAGS) -L. -o magnusAPI artifAPI.c fartif.c fonction.c -lothello

maintest: test.c fonction.c fonction.h
	gcc -Wall -Wextra -o maintest test.c fonction.c



main.o: main.c fonction.h
	gcc -c $< -o $@ $(ti)

magnus.o: artif.c fartif.h fonction.h
	gcc -c $< -o $@ $(ti)

fonction.o : fonction.c fonction.h
	gcc -c $< -o $@ $(ti)

fartif.o: fartif.c fartif.h
	gcc -c $< -o $@ $(ti)



clean :
	rm -f main mainAPI magnus *.o
