#include "bits/stdc++.h"
using namespace std;   
// fast read
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
// consts
ll M = 0;
// ksm (kuai su mi)
ll ksm(ll a,ll p){ll res=1;while(p){if(p&1){res=res*a%M;}a=a*a%M;p>>=1;}return res;}
ll gcd(ll a, ll b){if(b == 0) return a; return gcd(b, a % b);}
ll lcm(ll a, ll b){return a * b / gcd(a, b);}

int main() { 
    fr; 
    int T;
	cin >> T;
	while (T--)
	{ 
		string s;
		cin >> s;
		int count[26]={0};
		int one[26] ={0};
		int two[26] ={0};
		for(char c : s)
			count[c - 'a']++;
		int res = 0;
		int c1 = 0;
		int c2 = 0;
		for(int i = 0; i < 26; i++)
		{
			if(count[i])
			{
				if(count[i] == 1)
				{
					if(c1 < c2)
						c1++;
					else
						c2++;
				}
				else
				{
					c1++;
					c2++;
				}
			}
		} 
		cout << min(c1,c2) << endl;
	}
    return 0; 
}