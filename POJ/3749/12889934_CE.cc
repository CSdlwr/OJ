#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char dic[27] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M',
					'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };
	char msg[201];
	char bound[11];
	char msgEnd[11] = "ENDOFINPUT";
	int pt = 0;
	while (true) {
		cin>>bound;
		if (strcmp(bound, msgEnd) == 0)
			return 0;
		getchar();
		gets(msg);
		cin>>bound;
		int i = 0;
		while (msg[i] != '\0') {
			if (msg[i] >= 'A' && msg[i] <= 'Z') {
				msg[i] -= 'A';
				pt = msg[i] - 5;
				if (pt < 0)
					pt += 26;
				else if (pt > 25)
					pt -= 26;
				msg[i] = dic[pt];
			}
			cout<<msg[i];
			++i;
		}
		cout<<endl;
	}
	return 0;
}