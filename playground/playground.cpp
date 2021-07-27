#include<bits/stdc++.h>
using namespace std; 
#define int long long
#define endl '\n'
#define PII pair<int,int>
#define INF 0x3f3f3f3f
const int N=1e6+5;
int h[N],e[N],nx[N],idx;
int k,T,t,n,m,ans,cnt;
int a[N][10];
int sa[N],sb[N],sc[N],sd[N],se[N];
bool vis[N];
string s;
priority_queue <int,vector<int>,greater<int> > q;
void solve(int a[])
{
	int res=0;
	for(int i=1;i<=n;i++)
	{
		res+=a[i];		
		if(res>0)ans=max(ans,i);
		else break;
	}
}
signed main()
{
	ios::sync_with_stdio(false);
 	cin.tie(0),cout.tie(0);
	cin>>T;
	while(T--)
	{
		ans=0;
		cin>>n;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=5;j++) a[i][j]=0;
		for(int i=1;i<=n;i++)
		{
			s.clear();			
			cin>>s;
			for(int j=0;j<s.size();j++) a[i][s[j]-'a']++;
			sa[i]=2*a[i][0]-s.size();
			sb[i]=2*a[i][1]-s.size();
			sc[i]=2*a[i][2]-s.size();
			sd[i]=2*a[i][3]-s.size();
			se[i]=2*a[i][4]-s.size();			
		}
		sort(sa+1,sa+1+n,greater<int>());
		sort(sb+1,sb+1+n,greater<int>());
		sort(sc+1,sc+1+n,greater<int>());
		sort(sd+1,sd+1+n,greater<int>());
		sort(se+1,se+1+n,greater<int>());		
		for(int i=1;i<=n;i++) cout<<sa[i]<<" ";
		cout<<endl;
		for(int i=1;i<=n;i++) cout<<sb[i]<<" ";
		cout<<endl;
		for(int i=1;i<=n;i++) cout<<sc[i]<<" ";
		cout<<endl;
		for(int i=1;i<=n;i++) cout<<sd[i]<<" ";
		cout<<endl;				
		solve(sa),solve(sb),solve(sc),solve(sd),solve(se);
		cout<<ans<<endl;
	}
 
	return 0;
}