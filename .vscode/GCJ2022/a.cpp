#include<bits/stdc++.h>
using namespace std; 
#define int long long 
#define PII pair<int,int> 
void solve(int r, int c);
signed main()
{   
	int T,R,C;
	cin >> T;
	for(int i = 1; i <= T; i++)
	{
		cin >> R;
		cin >> C;
		cout << "Case #" << i << ":" << endl;
		solve(R,C);
	}
}

void solve(int r, int c) 
{
	vector<vector<char>> v(r * 2 + 1, vector<char>(c*2 + 1));
	for (int i = 0; i <= r * 2; i++)
	{
		if(i % 2 == 0)
		{
			for (int j = 0; j <= c * 2; j++)
			{
				if(j % 2 == 0)
					v[i][j] = '+';
				else
					v[i][j] = '-';
			}	
		}
		else
		{
			for (int j = 0; j <= c * 2; j++)
			{
				if(j % 2 == 0)
					v[i][j] = '|';
				else
					v[i][j] = '.';
			}
			
		}
	}
	v[0][0] = '.';
	v[1][0] = '.';
	v[0][1] = '.';
	for (int i = 0; i <= r * 2; i++)
	{
		for (int j = 0; j <= c * 2; j++)
		{
			cout << v[i][j]; 
		}
		cout << endl;
	}
}