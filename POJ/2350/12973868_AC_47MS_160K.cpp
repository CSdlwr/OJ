#include<iostream>
using namespace std;
//void swap(int *a, int *b);
//int partition(int a[], int p, int r);
//void qsort(int a[], int p, int r);
int main () {
	int c;
	int sc[1005], sn;
	double avg, sum;
	scanf("%d", &c);
	while (c-- > 0) {
		scanf("%d", &sn);
		sum = 0;
		for (int i = 0; i < sn; ++i) {
			scanf("%d", &sc[i]);
			sum += sc[i];
		}
		avg = sum / sn;
//		qsort(sc, 0, sn-1);
		int i = 0;
		int cnt = 0;
		for (; i < sn; ++i)
			if (sc[i]*1.0 > avg)
				++cnt;
//		sum = (sn-i)*1.0/sn;
//		sum = cnt*100.0;
		printf("%.3lf%%\n", (cnt*100.0)/sn);
//		printf("%\n");
	}
	return 0;
}
