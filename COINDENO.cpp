#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <algorithm>
#include <math.h>
#include <string>
#include <cstring>
#include <set>
#include <map>
#include <unordered_map>
#include <assert.h>
#include <array>
#include <random>
#include <chrono>

using namespace std;

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<int, pair<int, int>> piii;
typedef vector<int> vi;
typedef vector<pii> vii;

int dadsadasda;

#define ri(a) dadsadasda=scanf("%d", &a)
#define rii(a,b) dadsadasda=scanf("%d %d", &a, &b)
#define riii(a,b,c) dadsadasda=scanf("%d %d %d", &a, &b, &c)
#define rl(a) dadsadasda=scanf("%lld", &a)
#define rll(a,b) dadsadasda=scanf("%lld %lld", &a, &b)
#define FOR(i,n,m) for(int i=n; i<m; i++)
#define ROF(i,n,m) for(int i=n; i>m; i--)
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define F first
#define S second
#define ALL(s) s.begin(),s.end()
#define SZ(s) (int)s.size()

const int INF = 0x3f3f3f3f;
const ll LLINF = 1e18;
const int MAXN = 101; // CAMBIAR ESTE
const int MOD = 1e9 + 7;
//mt19937 rng(chrono::system_clock::now().time_since_epoch().count());

// GJNM
int N, C, M;
ll A[MAXN], W[MAXN];
const __int128 _one = 1;
const __int128 LLLINF = _one << 120;

void printt(__int128 x) {
    if (x < 0) {
        putchar('-');
        x = -x;
    }
    if (x > 9) printt(x / 10);
    putchar(x % 10 + '0');
}

__int128 DP[5000001];
int main() {
    riii(N, C, M);
    FOR(i, 0, N) rll(A[i], W[i]);

    for (int i = 1; i <= 5000000; ++i) {
        DP[i] = LLLINF;
        FOR(j, 0, N) if (i - A[j] >= 0)
            DP[i] = min(DP[i], W[j] + DP[i - A[j]]);
    }

    while (M--) {
        ll qi; rl(qi);
        __int128 ans = LLLINF;
        FOR(i, 0, N) {
            __int128 need = max((qi - 5000000 + A[i] - 1) / A[i], 0ll);
            ans = min(ans, need * W[i] + DP[qi - need * A[i]] );
        }
        if (ans >= LLLINF)
            printf("-1");
        else
            printt(ans % MOD);
        printf("\n");
    }

    return 0;
}
