ti = -Wall -Wextra

main : main.o fonction.o
	gcc $^ -o $@ $(ti)

main.o: main.c fonction.h
	gcc -c $< -o $@ $(ti)

fonction.o : fonction.c fonction.h
	gcc -c $< -o $@ $(ti)

clean :
	rm -f main *.o
