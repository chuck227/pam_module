#include <security/pam_modules.h>
#include <ctype.h>
#include <math.h>

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
				return pow(10, i) + j;
		}
	}
	return -1;


	/*switch(var){
		case '=' || '+':
			char_value+=1;
		case '-' || '_':
			char_value+=1;
		case '0' || ')':
			char_value+=1;
		case '9' || '(':
			char_value+=1;

		case '1' || '!':
			char_value+=1;
			break

		case 'p':
			char_value+=1;
		case 'o': 
			char_value+=1;
		case 'i':
			char_value+=1;
		case 'u':
			char_value+=1;
		case 'y':
			char_value+=1;
		case 't':
			char_value+=1;
		case 'r':
			char_value+=1;
		case 'e':
			char_value+=1;
		case 'w':
			char_value+=1;
		case 'q':
			char_value+=101;
			break;
	}*/
}
