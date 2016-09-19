#include <iostream>
using namespace std;

int main () {
	bool exit = true;
	int n1, n2, n3, n4, n5, n6;
	int s5, s4, s3, sn;
	int packSum = 0;
	while (true) {
		packSum = 0;
		cin>>n1>>n2>>n3>>n4>>n5>>n6;
		exit = true;
		if (n1 != 0 || n2 != 0 || n3 != 0 || n4 != 0 || n5 != 0 || n6 != 0)
			exit = false;
		if (exit)
			return 0;
		packSum = n6 + n5 + n4;
		s5 = n5 * 11;
		s4 = n4 * 5 * 4;
		if (n3 % 4 == 0)
			packSum += n3 / 4;
		else {
			packSum += n3 / 4 + 1;
			s3 = (4 - (n3 % 4)) * 9;
		}
		if (n2 * 4 > s4) {
			if (s4 > 0) {
				n2 -= s4 / 4;
				s4 = 0;
			}
			if (n2 > (s3 * 2)/9 - 1) {
				if (s3 > 0) {
					n2 -= (s3 * 2)/9 - 1;
					s3 = s3 / 9 + 4;
				}
				if (n2 % 9 == 0)
					packSum += n2 / 9;
				else {
					packSum += n2 / 9 + 1;
					sn = (9 - (n2 % 9)) * 4;
				}
			} else
				s3 -= n2 * 4;
		} else
			s4 -= n2 * 4;
		if (n1 > s5) {
			if (s5 > 0) {
				n1 -= s5;
				s5 = 0;
			}
			if (n1 > s4) {
				if (s4 > 0) {
					n1 -= s4;
					s4 = 0;
				}
				if (n1 > s3) {
					if (s3 > 0) {
						n1 -= s3;
						s3 = 0;
					}
					if (n1 > sn) {
						if (sn > 0) {
							n1 -= sn;
							sn = 0;
						}
						if (n1 % 36 == 0)
							packSum += n1 / 36;
						else
							packSum += n1 /36 + 1;
					}
				}
			}
		}
		cout<<packSum<<endl;
	}
	return 0;
}
