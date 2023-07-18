#include <stdio.h>
#include <assert.h>

#include "pam_password_verifier.h"

int main(int argv, char** argc){
	if(argv > 1){
		printf("Char %c converts to: %d\n", argc[0][0], char_to_keyboard_value(argc[1][0]));
	}
	else{
		printf("Running unit tests\n");
		
		assert(11 == char_to_keyboard_value('1'));
		assert(110 == char_to_keyboard_value('q'));
		assert(110 == char_to_keyboard_value('Q'));
		assert(1100 == char_to_keyboard_value('a'));
		assert(15000 == char_to_keyboard_value('B'));

		printf("Completed test\n");
	}
}
