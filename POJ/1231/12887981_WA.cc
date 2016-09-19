
#include <iostream>
using namespace std;

int main() {
	int t;
	cin>>t;
	while (t-- > 0) {
		int n, ni;
		cin>>n>>ni;
		int left[30], right[30], top[30], bottom[30];
		int i = 0, j = 0;
		int po;
		while (i < n) {
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
		int flag = 0;
		for (i = 0; i < n; ++i) {
			for (j = i + 1; j < n; ++j) {
				if (left[i] > right[j] || right[i] < left[j] || top[i] < bottom[j] || bottom[i] > top[j])
					flag++;
			}
		}
		//cout<<flag<<endl;
 		if (flag == n)
 			cout<<"YES"<<endl;
 		else
 			cout<<"NO"<<endl;
	}
}