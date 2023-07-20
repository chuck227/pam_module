all: library test

run: library test
	./test

test: library
	gcc -o test test.c -Wall -L -l ./pam_password_verifier.so 

library:
	gcc -o pam_password_verifier.so -shared -fPIC pam_password_verifier.c -lpam -lm -Wall 

clean:
	rm test pam_password_verifier.so
