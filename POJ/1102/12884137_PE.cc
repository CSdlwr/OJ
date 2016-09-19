#include <iostream>
#include <string.h>
using namespace std;

int main() {
	int s;
	char d[9];
	while (cin>>s>>d) {
		if (s == 0)
			return 0;

		for (int i = 0; i < strlen(d); ++i) {
			cout<<" ";
			for (int j = 0; j < s; ++j) {
				if (d[i] == '1' || d[i] == '4')
					cout<<" ";
				else
					cout<<"-";
			}
			cout<<"  ";
		}

		cout<<endl;

		for (int i = 0; i < s; ++i) {
			for (int j = 0; j < strlen(d); ++j) {
				if (d[j] == '1' || d[j] == '2' || d[j] == '3' || d[j] == '7')
					cout<<" ";
				else
					cout<<"|";
				for (int k = 0; k < s; ++k)
					cout<<" ";
				if (d[j] == '5' || d[j] == '6')
					cout<<" ";
				else
					cout<<"|";
				cout<<" ";
			}
			cout<<endl;
		}

		for (int i = 0; i < strlen(d); ++i) {
			cout<<" ";
			for (int j = 0; j < s; ++j) {
				if (d[i] == '1' || d[i] == '7' || d[i] == '0')
					cout<<" ";
				else
					cout<<"-";
			}
			cout<<"  ";
		}
		cout<<endl;

		for (int i = 0; i < s; ++i) {
			for (int j = 0; j < strlen(d); ++j) {
				if (d[j] == '2' || d[j] == '6' || d[j] == '8' || d[j] == '0')
					cout<<"|";
				else
					cout<<" ";
				for (int k = 0; k < s; ++k)
					cout<<" ";
				if (d[j] == '2')
					cout<<" ";
				else
					cout<<"|";
				cout<<" ";
			}
			cout<<endl;
		}

		for (int i = 0; i < strlen(d); ++i) {
			cout<<" ";
			for (int j = 0; j < s; ++j) {
				if (d[i] == '1' || d[i] == '7' || d[i] == '4')
					cout<<" ";
				else
					cout<<"-";
			}
			cout<<"  ";
		}
		cout<<endl;

	}
	return 0;
}