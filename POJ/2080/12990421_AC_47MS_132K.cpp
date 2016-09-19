#include<iostream>
using namespace std;

int n, y, s = 2000;
bool r;
int m = 1, d = 1, w;
int md[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

void week(int w) {
	if (w == 0) printf("Saturday\n");
	else if (w==1) printf("Sunday\n");
	else if (w==2) printf("Monday\n");
	else if (w==3) printf("Tuesday\n");
	else if (w==4) printf("Wednesday\n");
	else if (w==5) printf("Thursday\n");
	else printf("Friday\n");
}

int main() {
	while (scanf("%d", &n)) {
		if (n == -1) break;
		++n;
		y = s;
		w=n%7;
		w--;
		m = 1; d = 1;
		while (1) {
			r = false;
			if (y%400==0 || 
			y%100!=0 && y%4==0)
				r = true;
			if (r) {
				if (n-1461<=0) break;
				else n -= 1461;
			} else {
				if (n-1460<=0) break;
				else n -= 1460;
			}
			y += 4;
		}
		if (r && n == 1461 
			|| !r && n == 1460) {
			y += 3;
			printf("%d-%02d-%02d ", y, 12, 31);
			week(w);
			continue;
		}
		if (!r) {
			if (n%365==0) {
				y += n/365-1;
				m = 12;
				d = 31;
			} else {
				y += n/365; n %= 365;
				int mi = 1;
				while (1) {
					if (n-md[mi] <= 0) break;
					n -= md[mi];
					m++;
					mi++;
				}
				d = n;
			}
			printf("%d-%02d-%02d ", y, m, d);
			week(w);
			continue;
		}
		else if (n > 366){
			n -= 366;
			y++;
			if (n%365==0) {
				y += n/365-1;
				m = 12;
				d = 31;
			} else {
				y += n/365;
				n %= 365;
				int mi = 1;
				while (1) {
					if (n-md[mi] <= 0) break;
					n -= md[mi];
					m++;
					mi++;
				}
				d = n;
			}
			printf("%d-%02d-%02d ", y, m, d);
			week(w);
			continue;
		} else if (n > 60) {
			n -= 60;
			m += 2;
			int mi = 3;
			while (1) {
				if (n-md[mi] <= 0) break;
				n -= md[mi];
				m++;
				mi++;
			}
			d = n;
			printf("%d-%02d-%02d ", y, m, d);
			week(w);
			continue;
		} else if (n == 60) {
			m += 1;
			d = 29;
			printf("%d-%02d-%02d ", y, m, d);
			week(w);
			continue;
		} else if (n > 31) {
			n -= 31;
			m += 1;
		}
		d = n;
		printf("%d-%02d-%02d ", y, m, d);
		week(w);
	}
	return 0;
}