#include <iostream>
using namespace std;

int f(int m, int n);
int main() {
    int t;
    cin>>t;
    int m, n;
    while (t-- > 0) {
        cin>>m>>n;
        cout<<f(m, n)<<endl;
    }
    return 0;
}

int f(int m, int n) {
    if (m == 1 || m == 0 || n == 1)
        return 1;
    else if (m >= n)
        return f(m - n, n) + f(m, n - 1);
    else if (m < n)
        return f(m, m);
}
