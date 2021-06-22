#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <vector>
#include <deque>
using namespace std;  
int main() { 
    int T;
    cin >> T;
    while (T --)
    {
        int N;
        cin >> N;
        int A[N];
        for(int i = 0; i < N; i++)
            cin >> A[i];
        int64_t sum = 0;
        for(int i = 0; i < N; i++){
            sum += A[i];
        } 
        if (sum == N)
        {
            cout << "0" << endl;
        }
        else if (sum > N) {
            cout << sum - N << endl;
        }
        else{
            cout << "1" << endl;
        }
        
    }
    return 0;
}