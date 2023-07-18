const char MAPPING[4][13] = { 
					{'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '='},
					{0x00, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']'},
					{0x00, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', 0x00},
					{0x00, 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', 0x00, 0x00}
			    };

int char_to_keyboard_value(char var);
int passes_run_check(char* password, int max_in_row_allowed);
