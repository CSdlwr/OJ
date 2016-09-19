#include <iostream>
using namespace std;

int main() {
	int A, a, B, b, P;
	scanf("%d %d %d %d %d", &A, &a, &B, &b, &P);
	if (A > B && A < P && B < a || B > A && B < P && A < b) 
		printf("Yes\n");
	else printf("No\n");
	return 0;
}