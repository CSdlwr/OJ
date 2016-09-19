#include<iostream>
using namespace std;

char s[8];
char out[8];
int b1, b2;
int v(char c) {
	int v;
	if (c >= '0' && c <= '9') return c-'0';
	else return 10+c-'A';
}
int _10base;
int cnt, t;
int main() {
	while (scanf("%s%d%d", s, &b1, &b2) != EOF) {
		_10base = 0;
		for (int i = 0; s[i] != '\0'; ++i)
			_10base = _10base * b1 + v(s[i]);
		if (b2 == 10) {
			printf("%7d\n", _10base);
			continue;
		}
		cnt = 7;
		out[cnt--] = '\0';
		while (cnt >= 0) {
			if (_10base == 0) { out[cnt--] = ' '; continue; }
			t = _10base%b2;
			if (t > 9) { 
				t = t-10+'A';
				out[cnt--] = t;
			}
			else out[cnt--] = t+'0';
			_10base /= b2;
		}
		if (_10base != 0) printf("  ERROR\n");
		else printf("%s\n", out);
	}
	return 0;
}