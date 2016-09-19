#include <iostream>
using namespace std;

int main () {
	int i = 12;
	float b = 0;
	float sum = 0;
	while (i-- > 0) {
		cin>>b;
		sum += b;
	}
	printf("$%.2f", sum/12);
}
