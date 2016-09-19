#include <iostream>
using namespace std;

char dic[] = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";

int main() {
	char c;
	char* p = new char[1000];
	while ((gets(p))) {
		while ((c = *p++) != '\0') {
			if (c == ' ') {
				printf("%c", c);
				continue;
			} 
			int i = 0;
			for ( ; dic[i] != c && dic[i] != '\0'; ++i) ;
			if (i < strlen(dic))
				printf("%c", dic[i-1]);
		}
		printf("\n");
	}
	return 0;
}