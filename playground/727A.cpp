#include "bits/stdc++.h"

using namespace std;   
int main() { 
    int K;
    cin >> K; 
    while (K--)
    {  
        int64_t N,X,T;
        cin >> N >> X >> T;
        int64_t B = min(N, T/X);
        if (X <= T)
        { 
            if (N < T/X)
            { 
                cout << N*(N - 1) / 2 << endl;
            }
            else
            {
                int64_t p1 =(N - T/X - 1) * (T/X);
                int64_t p2 = (T/X) * (T/X + 1) / int64_t(2.0);
                cout << p1 + p2 << endl;
            }
             
        }
        else
        {
            cout << 0 << endl;
        }
    }
    
    return 0;
}