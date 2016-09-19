#include <iostream>
using namespace std;

char dic[] = "`1234567890-=QWERTYUIOP[]\ASDFGHJKL;'ZXCVBNM,./";

int main() {
	char c;
	while ((c = getchar()) != '\n') {
		if (c == ' ') {
			printf("%c", c);
			continue;
		} 
		int i = 0;
		for ( ; dic[i] != c && dic[i] != '\0'; ++i) ;
		printf("%c", dic[i-1]);
	}
	return 0;
}