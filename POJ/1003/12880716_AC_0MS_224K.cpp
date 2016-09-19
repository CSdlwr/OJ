#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char input[5];
	cin >> input;
	while (strcmp(input, "0.00") != 0) {
		int count = 2;
		float sum = 0;
		float len = input[0] - 48 + ((float) (input[2] - 48)) / 10
				+ ((float) (input[3] - 48)) / 100;
		while (sum < len)
			sum += (float) 1 / count++;
		cout<<count-2<<" card(s)"<<endl;
		cin>>input;
	}
}
