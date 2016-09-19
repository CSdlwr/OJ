#include <iostream>
using namespace std;

int main() {
	int n = 0;
	char* p = new char[10000];
	while (gets(p)) {
		char c;
		while ((c = *p++) != '\0') {
			if (c == '"') {
				n++;
				if (n % 2)	printf("%s", "``");
				else printf("%s", "''");
			} else
				printf("%c", c);
		}
		printf("\n");
	}
	return 0;
}