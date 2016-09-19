#include<iostream>
#include<string.h>
using namespace std;

int h[10], l[10];
char g[10];
int a;
int hn = 0, ln = 0;
bool dh = false;
int main() {
	while (scanf("%d", &a)) {
		if (a == 0) break;
		getchar();
		gets(g);
		if (strcmp(g, "right on") == 0) {
			for (int i = 0; i < hn; ++i)
				if (h[i] <= a) dh = true;
			if (!dh) {
				for (int i = 0; i < ln; ++i)
				if (l[i] >= a) dh = true;
			}
			if (dh) printf("Stan is dishonest\n");
			else printf("Stan may be honest\n");
			hn = ln = 0;
			dh = false;
		} else if (strcmp(g, "too high") == 0)
			h[hn++] = a;
		else l[ln++] = a;
	}
	return 0;
}