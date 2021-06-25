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
    while (T--)
    {
        int N;
        cin >> N; 
        int res = 0;
        int A[2*N + 1];
        for (int i = 0; i < 2*N + 1; i++)
        {
            A[i] = INT_MAX  ;
        }
        
        for (int i = 1; i <= N; i++)
        { 
            int C;
            cin >> C;
            A[C] = i; 
        }
        
        for (int i = 1; i < 2 * N; i++)
        { 
            for (int j = 1; j <= sqrt(i); j++)
            {
                if(i % j == 0 && i != j*j && A[j] + A[i/j] == i)
                    res++;
            }
        }
        cout << res << endl;
    }
    
    return 0; 
}