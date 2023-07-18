const char MAPPING[4][13] = { 
					{'`', '1', '2', '3', '4', '5', '6', '7', '8', '9', '0', '-', '='},
					{NULL, 'q', 'w', 'e', 'r', 't', 'y', 'u', 'i', 'o', 'p', '[', ']'},
					{NULL, 'a', 's', 'd', 'f', 'g', 'h', 'j', 'k', 'l', ';', '\'', NULL},
					{NULL, 'z', 'x', 'c', 'v', 'b', 'n', 'm', ',', '.', '/', NULL, NULL}
			    }

int char_to_keyboard_value(char var);
