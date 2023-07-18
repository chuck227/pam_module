all: library

library:
	gcc -o pam_password_verifier.so -shared -fPIC pam_password_verifier.c -lpam

test: library
	gcc -o test test.c -L -lpam_password_verifier.so

clean:
	rm test pam_password_verifier.so
