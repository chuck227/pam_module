#include <ctype.h>
#include <math.h>
#include <stddef.h>
#include <string.h>

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
				return 10 * ( i+1 ) + ( j+1 );
		}
	}
	return -1;
}

int passes_run_check(char* password, int min_in_row_to_fail){
	int i = 0, prev_value = char_to_keyboard_value(*password), cur_count = 0, cur_value;

	while( *(password+i) != 0x00){
		cur_value = char_to_keyboard_value(*( password+i ));
		if( 
			cur_value == prev_value || cur_value - prev_value == 1 || cur_value - prev_value == -1 ||
			( cur_value + 10 ) == prev_value || ( cur_value + 10 ) - prev_value == 1 ||
			( cur_value - 10 ) == prev_value || ( cur_value - 10 ) - prev_value == -1
		){ 
			if( ++cur_count >= min_in_row_to_fail )
				return 0;
		}
		else
			cur_count = 1; // Must be 1 instead of 0 because otherwise it is one short
		prev_value = cur_value;
		i++;
	}

	return 1;
}

PAM_EXTERN int pam_sm_chauthtok(pam_handle_t* handle, int flags, int argc, const char **argv){
	char password[ MAX_PASSWORD_LENGTH ] = { 0 };
	char copy[ MAX_PASSWORD_LENGTH ] = { 0 };

	if( flags & PAM_ESTABLISH_CRED ){
		if( !(flags & PAM_SILENT) )
			printf("Enter your new password: ");

		fgets(password, MAX_PASSWORD_LENGTH, stdin);
		strncpy(copy, password, MAX_PASSWORD_LENGTH);

		if( passes_run_check( copy, MIN_IN_ROW_TO_FAIL ) ){
			return PAM_SUCCESS;
		}
		return PAM_TRY_AGAIN;
	}

	return PAM_IGNORE;
}

PAM_EXTERN int pam_sm_authenticate(pam_handle_t* handle, int flags, int argc, const char **argv){
	return PAM_IGNORE;
}

PAM_EXTERN int pam_sm_acct_mgmt(pam_handle_t* handle, int flags, int argc, const char **argv){
	return PAM_IGNORE;
}

PAM_EXTERN int pam_sm_setcred(pam_handle_t* handle, int flags, int argc, const char **argv){
	return PAM_IGNORE;
}
