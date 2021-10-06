#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define nl "\n"
#define pb push_back
#define mk make_pair
#define pii pair<int, int>
#define f first
#define s second
#define vi vector<int>
#define all(x) (x).begin(), (x).end()
#define umap unordered_map
#define uset unordered_set
#define MOD 1000000007
#define imax INT_MAX
#define imin INT_MIN
#define FOR(i,n) for(int i=0;i<(n);i++)
#define FORA(i,a,b) for(int i=(a);i<(b);i++)
#define FORR(i,n) for(int i=(n);i>=0;i--)

void solve() {
    ll n, x;
    cin >> n >> x;
    umap<ll, ll>u;
    FOR(i,n) {
        ll temp;
        cin >> temp;
        u[temp]++;
    }
    ll diff = 0;
    for(auto i:u) {
        if (i.second > 0)
            diff++;
    }
    ll ans = min(n-x, diff);
    cout << ans << nl;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll t; cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}
