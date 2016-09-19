#include <iostream>
using namespace std;

int main () {
	int n;
	cin>>n;
	int d[n+1];
	int input[n+1];
	int i = 0;
	int max = 1;
	while (i < n) {
		cin>>input[i];
		d[i++] = 1;
	}

	for(i = 1; i < n; ++i) {
		for (int j = 0; j < i; j++) {
			if (input[j] < input[i] && d[j] + 1 > d[i]) {
				d[i] = d[j] + 1;
				if (d[i] > max)
					max = d[i];
			}
		}
	}
	cout<<max;
	return 0;
}