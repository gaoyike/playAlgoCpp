#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
using namespace std;
typedef pair<int, int> pii;
const int N = 5010;
pii v[N];
int A[N];
int dp[N]; 
int main() { 
    int n;
    int res = 0;
    cin >> n;
    for(int i = 1; i <= n; i++) {
        cin >> v[i].first >> v[i].second; 
    } 
    sort(v + 1, v + n);
    for(int i = 1; i<= n; i++) {
        dp[i] = 1;
        for(int j = 1; j < i; j++){
            if (v[j].second < v[i].second)
            {
                dp[i] = max(dp[i], dp[j] + 1);
            }
        }
        res = max(res, dp[i]);
    }
    cout << res << endl;
    return 0;
}