/*
 * @lc app=leetcode id=50 lang=cpp
 *
 * [50] Pow(x, n)
 */

// @lc code=start
class Solution {
public:
    double myPow(double x, int n) { 
        long long N = n;
        if(n < 0){
            N = - N; 
            x = 1/x;
        }
        return fast(x, N);
        
    }
    double fast(double x, long long n) {
        if(n == 0)
            return 1.0;
        if(n == 1)
            return x;
        double h = fast(x, n / 2);
        if (n % 2)
        {
            return h * h * x;
        }
        else
        {
            return h * h;
        }
        
    }
};
// @lc code=end

