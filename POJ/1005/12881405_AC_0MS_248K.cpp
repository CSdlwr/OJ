#include <iostream>
#include <math.h>
using namespace std;

#define PI 3.141592653

int main() {

	int num = 0;
	cin >> num;
	int i = 1;
	while (i < num+1) {
		int count = 1;
		float x, y;
		cin >> x >> y;
		float n = 50, s, r = sqrt(x*x + y*y);
		s = PI * r * r / 2;
		while (n < s) {
			n += 50;
			++count;
		}
		cout<<"Property "<<i++<<": This property will begin eroding in year "<<count<<"."<<endl;
	}
	cout<<"END OF OUTPUT.";
}
