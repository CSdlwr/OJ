#include <iostream>
#include <string.h>
#include <stdlib.h>
using namespace std;

int main () {
	int num = 0;
	char in[21];
	char year[10];
	char* d = NULL;
	char t[3];
	cin>>num;
	int i;
	while (num-- > 0) {
		i = 0;
		cin>>in;
		d = &in[5];
		strncpy(year, in, 4);
		while (i < 5) {
			in[i] = d[i];
			++i;
		}
		in[i] = '/';
		i = 0;
		while (i < 4) {
			in[i+6] = year[i];
			++i;
		}
		t[0] = in[11];
		t[1] = in[12];
		int h = atoi(t);
		if (h >= 12)
			in[19] = 'p';
		else
			in[19] = 'a';
		in[20] = 'm';
		if (h == 0) {
			in[11] = '1';
			in[12] = '2';
		}
		cout<<in<<endl;
	}
	return 0;
}
