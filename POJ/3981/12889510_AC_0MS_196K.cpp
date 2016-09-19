#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char s[1001];
	while (gets(s)) {
		char* p = s;
		while (*p != '\0') {
			if (*p == 'y' && *(p+1) && *(p+1) == 'o' && *(p+2) && *(p+2) == 'u') {
				*p = 'w';
				*(p+1) = 'e';
				*(p+2) = 1;
				p = p + 2;
			}
			p++;
		}
		p = s;
		while (*p != '\0') {
			if (*p != 1)
				cout<<*p;
			p++;
		}
		cout<<endl;
	}
}