#include<stdio.h>
#include<string.h>

char a1[105], a2[105];
char s[105];

void add(char a[], char b[]) {
	int ca = 0;
	int t = 0, cnt = 0;
	bool fa = false;
	while (*b != 0 || !fa || ca != 0) {
		t = 0;
		if (*a != 0) t += *a - '0';
		else fa = true;
		if (*b != 0) t += *b++ - '0';
		t += ca;
		*a = t % 10 + '0';
		ca = t / 10;
		++a;
		++cnt;
	}
	*a = 0;
}

int main() {
	memset(a1, 0, sizeof(a1));
	memset(a2, 0, sizeof(a2));
	int cnt = 0;
	while (gets(s)) {
		int len = strlen(s);
		if (len == 1 && s[0] == '0') break;
		char *p1 = s + len - 1, *p2 = a2;
		while (p1 >= s) *p2++ = *p1--;
		add(a1, a2);
	}
	int i = 100;
	for (; i >= 0; --i) if (a1[i] != '0' && a1[i] != 0) break;
	for (int j = i; j >= 0; --j) printf("%c", a1[j]);
	printf("\n");
	return 0;
}