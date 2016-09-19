#include <iostream>
using namespace std;

int main() {
	char s1[10], s2[10];
	while (scanf("%s%s", s1, s2)) {
		int l1 = strlen(s1);
		int l2 = strlen(s2);
		if (l1 == 1 && s1[0] == '0' 
			&& l2 == 1 && s2[0] == '0')
			break;
		int count = 0, c = 0;
		int min = l1 < l2 ? l1 : l2;
		for (int i = min - 1; i >= 0; --i) {
			if ((c = s1[i] + s2[i] - 96 + c) > 9) 
				count++;
			c /= 10;
		}
		//printf("%d\n", count);
		if (count == 0)
			printf("No carry operation.\n");
		else if (count == 1)
			printf("1 carry operation.\n");
		else
			printf("%d carry operations.\n", count);
	}
}