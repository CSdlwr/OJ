#include <iostream>
#include <math.h>
using namespace std;

#define PI 3.1415926

int main() {
	int num = 0;
	cin >> num;
	int i = 1;
	while (i < num+1) {
		int count = 1;
		float x, y;
		cin >> x >> y;
		float n, c, r = sqrt(x*x + y*y);
		n = sqrt(100/PI + c*c);
		while (n < r) {
			c = n;
			n = sqrt(100/PI + c*c);
			++count;
		}
		cout<<"Property "<<i++<<": This property will begin eroding in year "<<count<<"."<<endl;
	}
	cout<<"END OF OUTPUT.";
}
