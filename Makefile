all: library 

library:
	gcc -o pam_password_verifier.so -shared -fPIC pam_password_verifier.c -lpam