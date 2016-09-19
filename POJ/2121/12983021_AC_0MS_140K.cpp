#include<iostream>
#include<string.h>
using namespace std;

int getNum(char* str) {
	if (strcmp(str, "zero") == 0) return 0;
	else if (strcmp(str, "one") == 0) return 1;
	else if (strcmp(str, "two") == 0) return 2;
	else if (strcmp(str, "three") == 0) return 3;
	else if (strcmp(str, "four") == 0) return 4;
	else if (strcmp(str, "five") == 0) return 5;
	else if (strcmp(str, "six") == 0) return 6;
	else if (strcmp(str, "seven") == 0) return 7;
	else if (strcmp(str, "eight") == 0) return 8;
	else if (strcmp(str, "nine") == 0) return 9;
	else if (strcmp(str, "ten") == 0) return 10;
	else if (strcmp(str, "eleven") == 0) return 11;
	else if (strcmp(str, "twelve") == 0) return 12;
	else if (strcmp(str, "thirteen") == 0) return 13;
	else if (strcmp(str, "fourteen") == 0) return 14;
	else if (strcmp(str, "fifteen") == 0) return 15;
	else if (strcmp(str, "sixteen") == 0) return 16;
	else if (strcmp(str, "seventeen") == 0) return 17;
	else if (strcmp(str, "eighteen") == 0) return 18;
	else if (strcmp(str, "nineteen") == 0) return 19;
	else if (strcmp(str, "twenty") == 0) return 20;
	else if (strcmp(str, "thirty") == 0) return 30;
	else if (strcmp(str, "forty") == 0) return 40;
	else if (strcmp(str, "fifty") == 0) return 50;
	else if (strcmp(str, "sixty") == 0) return 60;
	else if (strcmp(str, "seventy") == 0) return 70;
	else if (strcmp(str, "eighty") == 0) return 80;
	else if (strcmp(str, "ninety") == 0) return 90;
	else if (strcmp(str, "hundred") == 0) return 100;
	else if (strcmp(str, "thousand") == 0) return 1000;
	else if (strcmp(str, "million") == 0) return 1000000;
	return -1;
}
char in[200];
char num[15];
char *p;
int cnt, ans, ta, tn;
bool ng;
int main() {
	while (gets(in)) {
		cnt = tn = ans = 0;
		p = in;
		memset(num, 0, sizeof(num));
		ng = false;
		if (*p == '\0') break;
		do {
			if (*p == ' ') {
				ta = getNum(num);
				if (ta == -1) ng = true;
				else if (ta == 1000000)	{ ans = (ans+tn)*ta; tn = 0;}
				else if (ta == 1000) { 
					if (ans+tn < 1000) {
						ans = (ans+tn)*1000;
						tn = 0;
					}
					else tn *= 1000; ans += tn; tn = 0;
				}
				else if (ta == 100) tn *= 100;
				else tn += ta;
				cnt = 0;
				p++;
				memset(num, 0, sizeof(num));
				continue;
			}
			else num[cnt++] = *p++;
		} while (*p != '\0');
		ta = getNum(num);
		if (ta == 1000000)	{ ans = (ans+tn)*ta; tn = 0;}
		else if (ta == 1000) { 
			if (ans+tn < 1000) {
				ans = (ans+tn)*1000;
				tn = 0;
			}
			else tn *= 1000; ans += tn; tn = 0;
		}
		else if (ta == 100) { tn *= 100; ans += tn; tn = 0;} 
		else {tn += ta; ans += tn;}
		if (ng) ans *= -1;
		printf("%d\n", ans);
	}
	return 0;
}