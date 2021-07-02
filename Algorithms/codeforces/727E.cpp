#ifdef ONLINE_JUDGE
#pragma GCC optimize("Ofast")
#pragma GCC target("avx2")
#endif
#include <bits/stdc++.h>
using namespace std;
#define pb push_back
#define mp make_pair
#define x first
#define y second
#define LL long long
#define LD long double
#define Complex complex<double>
#define y1 ___y1
#define next ___next
#define left ___left
#define right ___right
#define pii pair<int, int>
#define pll pair<LL, LL>
#define pdd pair<double, double>
#define pldld pair<LD, LD>
#define vi vector<int>
#define vl vector<LL>
#define vii vector<pii>
#define vll vector<pll>
#define PQ priority_queue
#define ffo fflush(stdout)
#define gch getchar()
#define e (int)(1e9 + 7)
#define MOD (int)(1e9 + 7)
#define e2 (double)2.71828182846
#define pi (double)3.14159265358979
#define ri(X) scanf("%d", &(X))
#define rii(X, Y) scanf("%d%d", &(X), &(Y))
#define riii(X, Y, Z) scanf("%d%d%d", &(X), &(Y), &(Z))
#define rl(X) scanf("%lld", &(X))
#define rll(X, Y) scanf("%lld%lld", &(X), &(Y))
#define rlll(X, Y, Z) scanf("%lld%lld%lld", &(X), &(Y), &(Z))
#define printi(X) printf("%d", (int)(X))
#define printii(X, Y) printf("%d %d", (int)(X), (int)(Y))
#define printiii(X, Y, Z) printf("%d %d %d", (int)(X), (int)(Y), (int)(Z))
#define printl(X) printf("%lld", (LL)(X))
#define printll(X, Y) printf("%lld %lld", (LL)(X), (LL)(Y))
#define printlll(X, Y, Z) printf("%lld %lld %lld", (LL)(X), (LL)(Y), (LL)(Z))
#define enter printf("\n")
#define space printf(" ")
int T;
int n, m;
pii dp[100005][2];
int bk[100005][2];
int k[100005];
pii a[100005][2];

pii inter(pii p1, pii p2) {
    pii ans;
    ans.x = max(p1.x, p2.x);
    ans.y = min(p1.y, p2.y);
    if (ans.x > ans.y) return mp(-1, -1);
    return ans;
}

bool in(int x, pii pr) {
    if (pr.x <= x && x <= pr.y) return true;
    return false;
}

void solve(int CASE) {
    rii(n, m);
    for (int i = 1; i <= n; i++) {
        ri(k[i]);
        rii(a[i][0].x, a[i][0].y);
        rii(a[i][1].x, a[i][1].y);
    }
    if (in(k[n], a[n][0])) {
        dp[n][0] = a[n][1];
    }
    else {
        dp[n][0] = mp(-1, -1);
    }
    if (in(k[n], a[n][1])) {
        dp[n][1] = a[n][0];
    }
    else {
        dp[n][1] = mp(-1, -1);
    }
    for (int i = n - 1; i > 0; i--) {
        if (in(k[i], inter(dp[i + 1][1], a[i][0]))) {
            dp[i][0] = a[i][1];
            bk[i][0] = 1;
        }
        else if (in(k[i], a[i][0])) {
            dp[i][0] = inter(a[i][1], dp[i + 1][0]);
            bk[i][0] = 0;
        }
        else {
            dp[i][0] = mp(-1, -1);
        }
        if (in(k[i], inter(dp[i + 1][0], a[i][1]))) {
            dp[i][1] = a[i][0];
            bk[i][1] = 0;
        }
        else if (in(k[i], a[i][1])) {
            dp[i][1] = inter(a[i][0], dp[i + 1][1]);
            bk[i][1] = 1;
        }
        else {
            dp[i][1] = mp(-1, -1);
        }
    }
    int pl;
    if (in(0, dp[1][0])) {
        pl = 0;
    }
    else if (in(0, dp[1][1])) {
        pl = 1;
    }
    else {
        printf("No\n");
        return;
    }
    printf("Yes\n");
    for (int i = 1; i <= n; i++) {
        printf(i == n? "%d\n":"%d ", pl);
        pl = bk[i][pl];
    }
    return;
}

int main() {
    T = 1;
    // ios::sync_with_stdio(false), cin.tie(NULL), cout.tie(NULL);
    // cin >> T;
    // calfacinv(1e6);
    for (int _ = 1; _ <= T; _++) {
        solve(_);
    }
    return 0;
}