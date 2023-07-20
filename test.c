#include <stdio.h>
#include <assert.h>

#include "pam_password_verifier.h"

int main(int argv, char** argc){
	if(argv > 1){
		printf("Char %c converts to: %d\n", argc[0][0], char_to_keyboard_value(argc[1][0]));
	}
	else{
		printf("Running unit tests\n");
		printf("Running char to value mapping tests...\n");
		
		assert(12 == char_to_keyboard_value('1'));
		assert(22 == char_to_keyboard_value('q'));
		assert(22 == char_to_keyboard_value('Q'));
		assert(32 == char_to_keyboard_value('a'));
		assert(46 == char_to_keyboard_value('B'));

		printf("Running run checks...\n");

		assert(0 == passes_run_check("aaa", 3));
		assert(0 == passes_run_check("asd", 3));
		assert(0 == passes_run_check("gtr", 3));
		assert(0 == passes_run_check("pok", 3));
		assert(0 == passes_run_check("bhu", 3));
		assert(0 == passes_run_check("moneyHJ", 3));
		assert(0 == passes_run_check("U&6", 3));
		assert(0 == passes_run_check("moneymoneymoney123", 3));
		assert(0 == passes_run_check("kKiI87", 6));
		assert(0 == passes_run_check("Thisisawaintit", 3));

		assert(1 == passes_run_check("abcdefgh", 4));
		assert(1 == passes_run_check("asdfqwerzxcv", 5));
		assert(1 == passes_run_check("asd", 4));
		assert(1 == passes_run_check("dkqldnbmdoxlqme", 10));

		printf("Completed! All tests passed!\n");
	}
}
