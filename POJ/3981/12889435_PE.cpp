#include <iostream>
#include <string.h>
using namespace std;

int main() {
	char s[50];
	while (scanf("%s" , s) != EOF) {
		if (strcmp(s, "you") == 0)
			cout<<"we ";
		else cout<<s<<" ";
	}
}