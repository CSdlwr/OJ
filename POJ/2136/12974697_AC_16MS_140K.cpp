#include<iostream>
using namespace std;

int s[26], m = 0;
char in[75];
int i = 4, j, c;
int main() {
	while (i-- > 0) {
		gets(in);
		j = 0;
		while (in[j] != '\0') {
			c = in[j] - 'A';
			if (c >= 0 && c <= 25)	{
				s[c]++;
				m = s[c] > m ? s[c] : m;
			}
			j++;
		}
	}
	for (i = 0; i < m; ++i) {
		for (j = 0; j < 26; ++j) {
			if (i < m-s[j]) printf(" ");
			else printf("*");
			if (j != 25) printf(" ");
		}
		printf("\n");
	}
	for (i = 0; i < 26; ++i) {
		printf("%c", i+'A');
		if (i != 25) printf(" ");
	}
	return 0;
}