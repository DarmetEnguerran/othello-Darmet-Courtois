ti = -Wall -Wextra

all: main mainAPI IA IA_API maintest

main : main.o fonction.o
	gcc $^ -o $@ $(ti)

mainAPI: mainAPI.c fonction.c fonction.h userNetwork.h
	$(CC) $(CFLAGS) -L. -o mainAPI mainAPI.c fonction.c -lothello

IA : IAmain.o IAfonction.o fonction.o
	gcc $^ -o $@ $(ti)

IA_API:IAmainAPI.c IAfonction.c fonction.c fonction.h userNetwork.h
	$(CC) $(CFLAGS) -L. -o IA_API IAmainAPI.c IAfonction.c fonction.c -lothello

maintest: test.c fonction.c fonction.h
	gcc -Wall -Wextra -o maintest test.c fonction.c



main.o: main.c fonction.h
	gcc -c $< -o $@ $(ti)

IAmain.o: IAmain.c IAfonction.h fonction.h
	gcc -c $< -o $@ $(ti)

fonction.o : fonction.c fonction.h
	gcc -c $< -o $@ $(ti)

IAfonction.o: IAfonction.c IAfonction.h
	gcc -c $< -o $@ $(ti)



clean :
	rm -f main mainAPI maintest IA IA_API *.o
