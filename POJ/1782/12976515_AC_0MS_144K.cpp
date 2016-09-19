#include<iostream>
#include<string.h>
using namespace std;

char *cur, *pre, *tp;
int cnt;
char in[1000], diff[1000];
int main() {
	while (gets(in)) {
		if (strlen(in) == 0) {
//			printf("1%c", in[0]);
//			if (in[0] == '1') printf("1");
//			printf("1\n");
			printf("\n");
			continue;
		}
		cnt = 0;
		pre = in;
		cur = pre;
		while (1) {
			if (*pre == *cur) {
				++cnt;
				++cur;
				if (cnt == 9) {
					printf("%d%c", cnt, *pre);
					pre = cur;
					cnt = 0;
				}
				if (pre == cur && *cur == '\0') break;
				continue;
			}
			if (cnt > 1) {
				printf("%d%c", cnt, *pre);
				pre = cur;
				cnt = 1;
				if (*pre != '\0') ++cur;
				else break;
			} else if (cnt == 1){
				tp = pre;
				while (*pre != *cur && *cur != '\0') {
					pre = cur++;
//					if (*(++cur) == '\0') break;
				}
				printf("1");
				while (tp != pre) {
					printf("%c", *tp);
					if (*tp++ == '1') printf("1");
				}
				if (*cur == '\0') {
					printf("%c", *pre);
					if (*pre == '1') printf("1");
				}
				printf("1");
				if (*cur == '\0') break;
			}
		}
		printf("\n");
	}
	return 0;
}