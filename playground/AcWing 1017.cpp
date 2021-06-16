#include <iostream>
#include <algorithm>
using namespace std;

const int N = 120;
int A[N];
int dp[N];
int main() { 
    int T;
    cin >> T;
    while (T --)
    {
        int n;
        cin >> n;
        for(int i = 1; i <= n; i++) {
            cin >> A[i];
        }
        int res = 0;
        for(int i = 1; i <= n; i++) {
            dp[i] = 1;
            for(int j = 1; j < i; j++) {
                if (A[j] < A[i])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res = max(res, dp[i]);
        }
        for(int i = n; i > 0; i --) {
            dp[i] = 1;
            for(int j = n; j > i; j--) {
                if (A[i] > A[j])
                {
                    dp[i] = max(dp[i], dp[j] + 1);
                }
            }
            res  = max(res, dp[i]);
        }
        cout << res << endl;
    }
    
    return 0;
}