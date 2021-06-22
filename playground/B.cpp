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
        int N,M,I,J;
        cin >> N >> M >> I >> J;
        auto dis = [&] (int x1, int y1, int x2, int y2) -> int64_t {
            if(x1 == x2 && y1 == y2){
                return -1;
            }
            return abs(x2 - x1) + abs(y2 - y1);
        };
        vector<pair<int64_t, pair<int, int>>> v; 
        int64_t a1 = dis(1, 1, I, J);
        int64_t a2 = dis(N, M, I, J);
        int64_t a3 = dis(1, M, I, J);
        int64_t a4 = dis(N, 1, I, J); 
        v.push_back(make_pair(a1, make_pair(1, 1)));
        v.push_back(make_pair(a2, make_pair(N, M)));
        v.push_back(make_pair(a3, make_pair(1, M)));
        v.push_back(make_pair(a4, make_pair(N, 1)));
        sort(v.begin(), v.end());
        cout << to_string(v[3].second.first) + " " + to_string(v[3].second.second);
        int64_t b1 = dis(1, 1, v[3].second.first, v[3].second.second);
        int64_t b2 = dis(N, M, v[3].second.first, v[3].second.second);
        int64_t b3 = dis(1, M, v[3].second.first, v[3].second.second);
        int64_t b4 = dis(N, 1, v[3].second.first, v[3].second.second); 
        vector<pair<int64_t, pair<int, int>>> vv; 
        vv.push_back(make_pair(b1, make_pair(1, 1)));
        vv.push_back(make_pair(b2, make_pair(N, M)));
        vv.push_back(make_pair(b3, make_pair(1, M)));
        vv.push_back(make_pair(b4, make_pair(N, 1))); 
        sort(vv.begin(), vv.end());
        cout << " "+ to_string(vv[3].second.first) + " " + to_string(vv[3].second.second) << endl;

    }
    return 0;
}