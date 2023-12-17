/* Pow(x, n)

Implement pow(x, n), which calculates x raised to the power n (i.e., xn).*/

class Solution {
public:
    double myPow(double x, int n) {
        if (n == 0)return 1;
        long long N = n;
        if (n < 0) {
            x = 1 / x;
            N = -N;
        }

    if (N & 1) {
        return x * myPow(x * x, N / 2);
    } else {
        return myPow(x * x, N / 2);
    }
        }
    
};