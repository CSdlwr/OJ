#include <iostream>
using namespace std;

int main () {
	int input[7];
	bool exit = true;
	int sum = 0;
	while (true) {
		for(int i = 0; i < 6; ++i) {
			cin>>input[i];
			if (input[i] != 0)
				exit = false;
			sum += input[i] * (i + 1);
		}
		if (exit) return 0;
		if (sum % 36 == 0)
			cout<<sum/36<<endl;
		else cout<<sum/36 + 1<<endl;
	}
	return 0;
}