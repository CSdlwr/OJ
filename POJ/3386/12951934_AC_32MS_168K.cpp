#include <iostream>
using namespace std;

int main() {
	int A, a, B, b, P;
	scanf("%d %d %d %d %d", &A, &a, &B, &b, &P);
	if (A <= P && B <= a || B <= P && A <= b || A + B <= P) 
		printf("Yes\n");
	else printf("No\n");
	return 0;
}