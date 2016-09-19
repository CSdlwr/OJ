
#include <iostream>
using namespace std;

int min(int i, int j);
int max(int i, int j);


int main() {
	int t;
	cin>>t;
	while (t-- > 0) {
		int n, ni;
		cin>>n>>ni;
		int left[30], right[30], top[30], bottom[30];
		int i = 0, j = 0;
		int po;
		bool flag[30];
		while (i < n) {
			flag[i] = false;
			j = 0;
			while (j < ni * 2) {
				cin>>po;
				if (j == 0) {
					left[i] = 30;
					right[i] = 1;
					top[i] = 30;
					bottom[i] = 1;
				} 
				if (j % 2 != 0) {
					if (po < top[i])
						top[i] = po;
					if (po > bottom[i])
						bottom[i] = po;
				} else {
					if (po > right[i])
						right[i] = po;
					if (po < left[i])
						left[i] = po;
				}
				j++;
			}
			i++;
		}
		for (i = 0; i < n; ++i) {
			int f1 = 0, f2 = 0;
			for (j = i + 1; j < n; ++j) {
				if (left[i] > right[j] || right[i] < left[j]) {
					f1++;
					for (int k = 0; k < n; ++k) {
						if (k == i || k == j)	continue;
						if (left[k] <= min(right[i], right[j]) && right[k] >= max(left[i], left[j])) {
							f1--;
						//	break;
						}
					}
					if (f1 == n - i -1)	flag[i] = true;
				}
				if ((top[i] > bottom[j] || bottom[i] < top[j])) {
					f2++;
					for (int k = 0; k < n; ++k) {
						if (k == i || k == j)	continue;
						if (top[k] <= min(bottom[i], bottom[j])  && bottom[k] >= max(top[i], top[j])) {
							f2--;
						//	break;
						}
					}
					if (f2 == n - i - 1)	flag[i] = true;
				}
			}
		}
		bool r = true;
		for (i = 0; i < n - 1; ++i)
			if (!flag[i])
				r = false;
		if (r) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
}

int min(int i, int j) {
	return i > j ? j : i; 
}

int max(int i, int j) {
	return i > j ? i : j;
}