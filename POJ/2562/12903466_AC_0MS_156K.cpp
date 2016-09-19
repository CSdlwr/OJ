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
		//int p1, p2;
		int p1 = l1 - 1;
		int p2 = l2 - 1;
// 		p1 = &s1[l1-1];
// 		p2 = &s2[l2-1];
		while (true) {
			if (p1 >= 0)
				c += s1[p1--] - 48;
			if (p2 >= 0)
				c += s2[p2--] - 48;
			if (c > 9)
				++count;
			c /= 10;
			if (p1 < 0 && p2 < 0)
				break;
		}
// 		for (int i = min - 1; i >= 0; --i) {
// 			if ((c = s1[i] + s2[i] - 96 + c) > 9) 
// 				count++;
// 			c /= 10;
// 		}
		//printf("%d\n", count);
		if (count == 0)
			printf("No carry operation.\n");
		else if (count == 1)
			printf("1 carry operation.\n");
		else
			printf("%d carry operations.\n", count);
	}
}