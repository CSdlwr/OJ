#include <iostream>
#include <string.h>
using namespace std;

int main () {
	char s[100001], t[100001];
	int i, j;
	int ls, lt;
	while (cin>>s>>t) {
		i = 0; j = 0;
		ls = strlen(s);
		lt = strlen(t);
		while (j <= lt -ls + i && i < ls) {
			if (s[i] != t[j++])
				;
			else
				++i;
		}
		if (i == ls)
			cout<<"Yes"<<endl;
		else
			cout<<"No"<<endl;
	}
}