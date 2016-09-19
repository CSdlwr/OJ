#include<iostream>
#include<string.h>
using namespace std;

char ans[105];
char in[105];
char t[105];
int len, ca;
int ml = 0;
int ti = 0;
int main() {
	memset(ans, '0', sizeof(ans));
	while (scanf("%s", in)) {
		len = strlen(in);
		if (len == 1 && in[0] == '0') break;
		for (int i = 0; i < len; ++i) 
			t[i] = in[len-i-1];
		int k = 0, sum=0, ca = 0;
		if (ti++ == 0) {
			strcpy(ans, t);
			continue;
		}
		while (t[k] != '\0' && ans[k] != '\0') {
			sum = ans[k]+t[k]+ca-'0'*2;
			ca = sum/10;
			ans[k] = sum%10+'0';
			++k;
		}
		sum = 0;
		if (ans[k] == '\0') {
			while (t[k] != '\0') {
				sum += t[k]+ca-'0';
				ca = sum/10;
				ans[k] = sum%10+'0';
				++k;
			}
		} else if (t[k] == '\0') {
			while (ans[k] != '\0') {
				sum += ans[k]+ca-'0';
				ca = sum/10;
				ans[k] = sum%10+'0';
				++k;
			}
		}
		ml = ml < k ? k : ml;
	}
	for (int i = ml-1; i >= 0; --i)
	printf("%c", ans[i]);
	return 0;
}