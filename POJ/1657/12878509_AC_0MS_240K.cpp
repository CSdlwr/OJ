#include <iostream>
#include <math.h>
using namespace std;

int main () {
	int num = 0;
	cin>>num;
	getchar();
	char s[3], e[3];
	while (num -- > 0) {
		cin>>s>>e;
		int xx = abs(s[0] - e[0]);
		int yy = abs(s[1] - e[1]);
		if (s[0] == e[0] && s[1] == e[1]) {
			cout<<"0 0 0 0";
			getchar();
			cout<<endl;
			continue;
		}
		else if (s[0] == e[0])
			cout<<yy<<" 1"<<" 1";
		else if (s[1] == e[1])
			cout<<xx<<" 1"<<" 1";
		else if (xx == yy)
			cout<<xx<<" 1"<<" 2";
		else if (xx < yy)
			cout<<yy<<" 2"<<" 2";
		else
			cout<<xx<<" 2"<<" 2";
		if (xx == yy)
			cout<<" 1";
		else if ((xx + yy) % 2 == 0)
			cout<<" 2";
		else cout<<" Inf";
		getchar();
		cout<<endl;
	}
	return 0;
}