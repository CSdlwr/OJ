#include <iostream>
using namespace std;

// char inp[33];


int main() {
	int n;
	int ip;
	char ch;
	scanf("%d", &n);
	bool t;
	while (n-- > 0) {
		for (int k = 0; k < 4; ++k) {
			ip = 0;
			for (int i = 0; i < 8; ++i) {
				do {
					ch = getchar();
				} while (ch != '0' && ch != '1');
				if (ch == '1') {
					switch(i) {
					case 0: ip += 128; break;
					case 1: ip += 64; break;
					case 2: ip += 32; break;
					case 3: ip += 16; break;
					case 4: ip += 8; break;
					case 5: ip += 4; break;
					case 6: ip += 2; break;
					case 7: ip += 1; break;
					default: break;
					}
				}
			}
			if (k == 3)
				printf("%d", ip);
			else printf("%d.", ip);
		}
		printf("\n");
	}
	return 0;
}
