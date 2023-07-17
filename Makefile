all: library test

library:
	gcc -o pam_password_verifier.so -shared -fPIC pam_password_verifier.c -lpam

test: 
	gcc -o test test.c 

clean:
	rm test pam_password_verifier.so
