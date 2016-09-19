#include <iostream>
using namespace std;

int main() {
	int sn = 1;
	int i = 0;
	char c[9][11];
	bool f = false;
	while (scanf("%s", c[i++]) != EOF) {
		if (c[i-1][0] == '9') {
			for (int m = 0; m < i; ++m) {
				for (int n = m+1; n < i; ++n) {
					f = false;
					for (int k = 0; c[m][k] != '\0' && c[n][k] != '\0'; ++k) {
						if (c[m][k] != c[n][k]) {
							f = true;
							break;
						}
					}
					if (!f) break;
				}
				if (!f) break;
			}
			if (f) printf("Set %d is immediately decodable\n", sn);
			else printf("Set %d is not immediately decodable\n", sn);
			i = 0;
			sn++;
		}
	}
	return 0;
}