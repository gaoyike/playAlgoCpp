#include "bits/stdc++.h"
using namespace std;   
#define fr ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
#define pb push_back;
typedef int64_t ll;
typedef pair<ll, ll> pll;
int main() { 
    fr; 
	ll N;
	cin >> N;
	pll A[N];
	ll total = 0;
	for(int i = 1; i <= N; i++) 
	{
		cin >> A[i].second >> A[i].first;
		total += A[i].second;
	}
	sort(A + 1, A + N + 1);
	ll left = 0;
	ll right = total;
	ll res = 0;
	auto check = [&](ll n) -> bool 
	{
		ll cur = total - n; // n is the number of discounted items, cur is the items wit origal price
		for(int i = 1; i <= N; i++) 
		{
			if (A[i].first > cur)
			{
				return false;
			}
			ll taken = min(A[i].second, n); // buy all A[i] in discounted price
			cur += taken;
			n -= taken;
			if(n == 0)// we found all available n
				return true;			
		}
		return true;
	};
	while (left < right)
	{
		ll mid = left + (right - left) / 2;
		if (check(mid))
		{
			left = mid + 1;
			res = mid;
		}
		else
		{
			right = mid;
		}
		
	} 
	cout << 2 * total - res << endl;
    return 0; 
}