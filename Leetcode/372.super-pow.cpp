/*
 * @lc app=leetcode id=372 lang=cpp
 *
 * [372] Super Pow
 */

// @lc code=start
class Solution {
public:
    const int M = 1337;
    int superPow(int a, vector<int>& b) {
        int N = b.size();
        int res = 1;
        for(auto i : b) {
            res = power(res,10) * power(a,i)%M;
            cout << res << endl;
        }
        return res;
    }
    long power(int n,int k){ // n^k
        if(k == 0)
            return 1;
        if(k == 1)
            return n % M;
        long h = power(n, k / 2) % M;
        if(k % 2)
            return h*h*n%M;
        else
            return h*h%M; 
    }

};
// @lc code=end

