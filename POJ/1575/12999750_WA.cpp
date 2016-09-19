#include<iostream>
#include<string.h>
using namespace std;

char in[25];

bool vo(char c) {
	if (c == 'a' || c == 'e' || c == 'i' 
		|| c == 'o' || c == 'u') return true;
	return false;
}

int l;
bool f1, f2, f3;
int main() {
	while (scanf("%s", in)) {
		if (strcmp(in, "end") == 0) break;
		l = strlen(in);
		if (l == 1) {
			if (vo(in[0])) { printf("<%s> is acceptable.\n", in); continue; }
			printf("<%s> is not acceptable.\n", in);
			continue;
		}
		if (l == 2) {
			if (in[0] == in[1] ) {
				if (in[0] == 'e' || in[0] ==  'o') {
					printf("<%s> is acceptable.\n", in); continue;
				} else { printf("<%s> is not acceptable.\n", in); continue; }
			} else if (vo(in[0]||vo(in[1]))) {
				printf("<%s> is acceptable.\n", in); continue;
			} else { printf("<%s> is not acceptable.\n", in); continue; }
		} else {
			f1 = false;
			f2 = f3 = true;
			for (int i = 0; i < l; ++i) 
				if (!f1&&vo(in[i])) { f1 = true; break; }
			if (!f1) { printf("<%s> is not acceptable.\n", in); continue; }
			for (int i = 0; i < l-2; i++) {
				if (vo(in[i]) && vo(in[i+1]) && vo(in[i+2])) f2 = false;
				else if (!(vo(in[i]) || vo(in[i+1]) || vo(in[i+2]))) f2 = false;
				if (!f2) break;
			}
			if (!f2) { printf("<%s> is not acceptable.\n", in); continue; }
			for (int i = 0; i < l-1; i++) {
				if (in[i] == in[i+1] && !(in[i] == 'e' || in[i] == 'o')) {f3 = false; break;}
			}
			if (f3) printf("<%s> is acceptable.\n", in);
			else printf("<%s> is not acceptable.\n", in);
		}
	}
	return 0;
}