#include<iostream>
#include<string>
#include<stack>
using namespace std;
stack<string> f;
stack<string> b;
string cmd, cur;

int main() {
	cur = "http://www.acm.org/";
	while (cin>>cmd) {
		if (cmd[0] == 'Q') break;
		else if (cmd[0] == 'B') {
			if (!b.empty()) {
				f.push(cur);
				cur = b.top();
				cout<<cur<<endl;
				b.pop();
			} else cout<<"Ignored"<<endl;
		} else if (cmd[0] == 'F') {
			if (!f.empty()) {
				b.push(cur);
				cur = f.top();
				cout<<cur<<endl;
				f.pop();
			} else cout<<"Ignored"<<endl;
		} else {
			b.push(cur);
			cin>>cur;
			cout<<cur<<endl;
			while (!f.empty()) f.pop();
		}
	}
	return 0;
}