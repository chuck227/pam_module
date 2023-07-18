#include <stdio.h>
#include "pam_password_verifier.h"

int main(int argv, char* argc){
	if(argv > 1){
		printf("Char %c converts to: %d", argc[0], char_to_keyboard_value(argc[0]));
	}
}
