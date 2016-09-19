class Solution {
public:
    
    double helper(double x, int n) {
        if (n == 0) return 1;
        double t = helper(x, n/2);
        t *= t;
        if (n % 2) t *= x;
        return t;
    }
    
    double pow(double x, int n) {
        double r = 0;
        if (n < 0) { r = helper(x, -1*n); r = 1/r; }
        else r = helper(x, n);
        return r;
    }
};
