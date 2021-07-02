#include "bits/stdc++.h"
using namespace std;   
const auto fr = [](){
    std::ios_base::sync_with_stdio(0); std::cin.tie(0);
    std::cout << std::fixed << std::setprecision(12);
    return 1;
}();

template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v);
template<typename A, typename B> ostream& operator<<(ostream &cout, pair<A, B> const &p) { return cout << "(" << p.first << ", " << p.second << ")"; };
template<typename A> ostream& operator<<(ostream &cout, vector<A> const &v) {
	cout << "["; for(int i = 0; i < v.size(); i++) {if (i) cout << ", "; cout << v[i];} return cout << "]";
}
template<typename A, typename B> istream& operator>>(istream& cin, pair<A, B> &p) {
	cin >> p.first;
	return cin >> p.second;
}

// vars:
using ll = long long;
using ull = unsigned long long;
using ld = long double;
using vi = std::vector<int>;
using vl = std::vector<ll>;
using vvi = std::vector<vi>;
using vvl = std::vector<vl>;
using pii = std::pair<int,int>;
using pil = std::pair<int,ll>;
using pli = std::pair<ll,int>;
using pll = std::pair<ll,ll>;
using vpii = std::vector<pii>;
using vvpii = std::vector<vpii>;
int main() { 
    fr; 
    int T;
    cin >> T;
    while (T --)
    {
        int N;
        cin >> N;
        ll A[N + 1]={};
        for (int i = 1; i <= N; i++)
        {
            cin >> A[i];
        } 
        sort(A+1, A+N+1);
        if(N < 3)
        {
            cout << 0 << endl;
            continue;
        } 
        ll res = 0; 
        ll pre[N + 2]={};
        for (int i = 1; i <= N; i++)
        {
            pre[i + 1] = pre[i] + A[i];
        } 
        for (int i = 3; i <= N; i++)
        {
            res -= ((i - 2) * A[i] - pre[i - 1] );
        }
        
        cout << res << endl;
    }
    
    return 0; 
}