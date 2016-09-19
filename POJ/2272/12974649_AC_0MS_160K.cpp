#include<iostream>
#include<math.h>
using namespace std;
double getScore(double x, double y);
double s1, s2;
int cnt = 0;
double x, y;
int main() {
	while (1) {
		s1 = s2 = 0;
		for (int i = 0; i < 3; ++i) {
			scanf("%lf %lf", &x, &y);
			if (x == -100) return 0;
			s1 += getScore(x, y);
		}
		for (int i = 0; i < 3; ++i) {
			scanf("%lf %lf", &x, &y);
			s2 += getScore(x, y);
		}
		if (s1 == s2) printf("SCORE: %d to %d, TIE.\n", (int)s1, (int)s2);
		else if (s1 > s2) printf("SCORE: %d to %d, PLAYER 1 WINS.\n", (int)s1, (int)s2);
		else printf("SCORE: %d to %d, PLAYER 2 WINS.\n", (int)s1, (int)s2);
	}
	return 0;
}

double getScore(double x, double y) {
	double d = sqrt(x*x + y*y);
	if (d>=0 && d <= 3) return 100;
	else if (d > 3 && d <= 6) return 80;
	else if (d > 6 && d <= 9) return 60;
	else if (d > 9 && d <= 12 ) return 40;
	else if (d > 12 && d <= 15) return 20;
	return 0;
}