#include <security/pam_modules.h>
#include <ctype.h>
#include <math.h>
#include <stddef.h>

#include "pam_password_verifier.h"

int char_to_keyboard_value(char var){
	int i, j;
	switch(var){
		case '!': 
			var='1';
			break;
		case '@':
			var='2';
			break;
		case '#':
			var='3';
			break;
		case '$':
			var='4';
			break;
		case '%':
			var='5';
			break;
		case '^':
			var='6';
			break;
		case '&':
			var='7';
			break;
		case '*':
			var='8';
			break;
		case '(':
			var='9';
			break;
		case ')':
			var='0';
			break;
		case '-':
			var='_';
			break;
		case '=':
			var='+';
			break;
		case '{':
			var='[';
			break;
		case '}':
			var=']';
			break;
		case '|':
			var='\\';
			break;
		case ':':
			var=';';
			break;
		case '"':
			var='\'';
			break;
		case '<':
			var=',';
			break;
		case '>':
			var='.';
			break;
		case '?':
			var='/';
			break;
		default:
			var = tolower(var);
	}
	for(i=0;i<4;i++){
		for(j=0;j<13;j++){
			if(MAPPING[i][j] == var)
				return pow(10, ( i + 1 )) + pow(10, i) * j;
		}
	}
	return -1;
}

int passes_run_check(char* password, int max_in_row_allowed){
	int i = 0, prev_value = char_to_keyboard_value(*password), cur_count = 0, cur_value;

	while( *(password+i) != 0x00){
		cur_value = char_to_keyboard_value(*( password+i ));
		if( 
			cur_value == prev_value || cur_value - prev_value == 1 || cur_value - prev_value == -1 ||
			( cur_value * 10 ) == prev_value || ( cur_value * 10 ) - prev_value == 1 || ( cur_value * 10 ) - prev_value == -1 ||
			( cur_value / 10 ) == prev_value || ( cur_value / 10 ) - prev_value == 1 || ( cur_value / 10 ) - prev_value == -1
		){ // Do check for adjacency here
			if( ++cur_count > max_in_row_allowed )
				return 0;
		}
		else
			cur_count = 0;

		i++;
	}

	return 1;
}
