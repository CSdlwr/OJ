#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;

int main () {
	int num = 0;
	cin>>num;
	int i = 0;
	char ws[5];
	int w, s;
	char p[num][16];
	char f[num];
	int count = 1, out = 0;
	while (i < num) {
		cin>>p[i];
		f[i++] = 't';
	}
	cin>>ws;
	w = atoi(strtok(ws, ","));
	s = atoi(strtok(NULL, ","));
	--w;
	while (true) {
		if (w == num)
			w %= num;
		if (count == s) {
			if (f[w] == 't') {
				cout<<p[w]<<endl;
				f[w] = 'f';
				count = 0;
				++out;
				if (out >= num)
					return 0;
			}
		}
		if (f[++w%num] == 't')
			++count;
	}
	return 0;
}