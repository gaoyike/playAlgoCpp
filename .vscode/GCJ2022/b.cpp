#include<bits/stdc++.h>
using namespace std; 
#define PII pair<int,int> 
void solve(int r, int c);
signed main()
{   
	int T,R,C;
	cin >> T;
	for(int i = 1; i <= T; i++)
	{ 
		cout << "Case #" << i << ": " ;
		solve(R,C);
	}
}

void solve(int r, int c) 
{ 
		vector<vector<int>> v(3, vector<int>(4));
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 4; j++)
			{
				cin >> v[i][j];
			}
						
		}
		int total = 0;
		vector<int> res;
		for (int i = 0; i < 4; i++)
		{
			int m = 1e6 + 1;
			for (int j = 0; j < 3; j++)
			{
				m = min(m, v[j][i]);
			} 
			total += m;
			res.push_back(m);
		}  
		if(total < 1e6)
			cout << "IMPOSSIBLE" << endl;
		else if(total == 1e6)
		{
			for (int i = 0; i < 4; i++)
			{
				cout << res[i]<<" ";
			}
			cout<<endl;
		}
		else
		{
			total = 1e6;
			for (int i = 0; i < 4; i++)
			{
				if(total - res[i] > 0){
					cout << res[i] << " ";
					total -= res[i];
				}
				else{
					cout << total << " ";
					i++;
					while (i < 4)
					{ 
						cout << "0" << " ";
						i++;
					}
					cout << endl;
					return;
				}
			}
		}
		
}