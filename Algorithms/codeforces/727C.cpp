#include "bits/stdc++.h"
using namespace std;   
#define fr ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
 
int main() { 
    fr;
    int64_t N,K,X;
    cin >> N >> K >> X;
    int64_t A[N + 1];
    for(int i = 1; i <= N; i++)
    {
        cin >> A[i];
    }
    sort(A + 1, A+N+1);
    int64_t res = 1;  
    vector<int64_t> v;
    for(int i = 1; i < N; i++) 
    { 
        v.push_back((A[i + 1] - A[i] - 1) / X);
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
    {
        if (v[i] <= 0)
        {
            continue;
        }
        if (K >= v[i])
        {
            K -= v[i];
        }
        else
        {
            res++;
        } 
    }
    cout << res << endl;
    return 0; 
}