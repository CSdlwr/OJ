#include <iostream>
using namespace std;

int main() {
	int n = 0;
	char* p = new char[1000	];
	while (strlen(gets(p)) != 0) {
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