#include <algorithm>
#include <array>
#include <cassert>
#include <chrono>
#include <cmath>
#include <cstring>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <vector>
#include<bits/stdc++.h>
using namespace std;

void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifdef NEAL_DEBUG
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif


const int64_t M = 12 * 3600 * int64_t(1e9);
const int64_t INV11 = 15709090909091LL;

void run_case(int test_case) {
    auto solve = [&](int64_t A, int64_t B, int64_t C) -> int64_t {
        int64_t T = int64_t((__int128_t) (B - A + M) * INV11 % M);
        if (719 * T % M != (C - A + M) % M)
            return -1;

        return T;
    };

    array<int64_t, 3> hands;
    cin >> hands[0] >> hands[1] >> hands[2];
    sort(hands.begin(), hands.end());
    int64_t T = -1;

    do {    
        T = max(T, solve(hands[0], hands[1], hands[2]));
    } while (next_permutation(hands.begin(), hands.end()));

    int64_t N = T % int64_t(1e9);
    T /= int64_t(1e9);
    int64_t S = T % 60;
    T /= 60;
    int64_t MIN = T % 60;
    T /= 60;
    int64_t H = T;
    cout << "Case #" << test_case << ": " << H << ' ' << MIN << ' ' << S << ' ' << N << '\n';
}

int main() {
    int tests;
    cin >> tests;

    for (int tc = 1; tc <= tests; tc++) {
        run_case(tc);
        cout << flush;
    }
}
