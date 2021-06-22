#include "bits/stdc++.h"
using namespace std;   

int main() { 
    int N,Q;
    cin >> N >> Q;
    string s;
    cin >> s;
    int dp[N + 1];
    for(int i = 1; i <= N; i++) 
    {
        dp[i] = dp[i - 1] + (int)(s[i - 1] - 'a') + 1;
    }
    while (Q--)
    {
        int l,r;
        cin >> l >> r;
        cout << dp[r] - dp[l - 1] << endl;
    }
    return 0; 
}