#include<iostream>
using namespace std;

int wd;
int w, h;
int tw, th, mh, mw;
int main() {
	while (scanf("%d", &wd)) {
		if (wd == 0) break;
		tw = mh = mw = th = 0;
		while (scanf("%d %d", &w, &h)) {
			if (w == -1 && h == -1) break;
			if (tw+w <= wd) { 
			tw += w; 
			mh = mh < h ? h : mh;
			}
			else {
			mw = mw < tw ? tw : mw;
			tw = w; th += mh; mh = h;
			}
		}
		mw = mw < tw ? tw : mw;
		th += mh;
		printf("%d x %d\n", mw, th);
	}
	return 0;
}