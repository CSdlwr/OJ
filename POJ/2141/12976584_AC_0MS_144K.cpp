#include<iostream>
using namespace std;

char dic[27];
char ch;
int a, b;
int main() {
	scanf("%s", dic);
	getchar();
	while ((ch = getchar()) != '\n') {
		a = ch - 'a';
		b = ch - 'A';
		if (a >= 0 && a < 26) printf("%c", dic[a]);
		else if (b >= 0 && b < 26) printf("%c", dic[b]-32);
		else printf("%c", ch);
	}
	printf("\n");
	return 0;
}