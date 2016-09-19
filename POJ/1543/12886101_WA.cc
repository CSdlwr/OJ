#include <iostream>
using namespace std;

int main() {
    int n;
    cin>>n;
    int a, b, c, d;
    int i = 0;
    for (a = 2; a <= n; ++a)
        for (b = a-1; b >= 2; --b)
            for (c = b-1; c >= 2; --c)
                for (d = c-1; d >= 2; --d)
                    if (a*a*a == b*b*b + c*c*c + d*d*d)
                        cout<<"Cube = "<<a<<", Triple = ("<<d<<","<<c<<","<<b<<")"<<endl;
    return 0;
}
