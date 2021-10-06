#include <iostream>
#include <stdlib.h>
#include <cmath>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <random>
#include <assert.h>
#include <memory.h>
#include <time.h>

#define uint unsigned int
#define ll long long
#define ull unsigned long long
#define ld long double
#define rep(i, l, r) for (int i = l; i < r; i++)
#define repb(i, r, l) for (int i = r; i > l; i--)
#define sz(a) (int)a.size()
#define fi first
#define se second
#define mp(a, b) make_pair(a, b)

using namespace std;

inline void setmin(int &x, int y) { if (y < x) x = y; }
inline void setmax(int &x, int y) { if (y > x) x = y; }
inline void setmin(ll &x, ll y) { if (y < x) x = y; }
inline void setmax(ll &x, ll y) { if (y > x) x = y; }

const int N = 1000000 + 239;
const int inf = (int)1e9 + 1;
const ll big = (ll)1e18 + 1;
const int P = 239;
const int P1 = 31;
const int P2 = 57;
const int MOD = (int)1e9 + 7;
const int MOD1 = (int)1e9 + 9;
const int MOD2 = 998244353;
const double eps = 1e-9;
const double pi = atan2(0, -1);
const int ABC = 26;

namespace GEO
{
    struct Point
    {
        ll x, y;
        Point() {}
        Point(ll x, ll y) : x(x), y(y) {}
        ld len() { return sqrt(x * x + y * y); }
        ll len2() { return x * x + y * y; }
        void read() { cin >> x >> y; }
    };

    bool operator == (Point &p1, Point &p2) { return p1.x == p2.x && p1.y == p2.y; }
    bool operator != (Point &p1, Point &p2) { return p1.x != p2.x || p1.y != p2.y; }
    Point operator + (Point &p1, Point &p2) { return Point(p1.x + p2.x, p1.y + p2.y); }
    Point operator - (Point &p1, Point &p2) { return Point(p1.x - p2.x, p1.y - p2.y); }
    ll operator * (Point p1, Point p2) { return p1.x * p2.x + p1.y * p2.y; }
    ll operator % (Point p1, Point p2) { return p1.x * p2.y - p1.y * p2.x; }

    ld dist(Point &p1, Point &p2) { return (p1 - p2).len(); }
    ll dist2(Point &p1, Point &p2) { return (p1 - p2).len2(); }

    vector<Point> convex_hull(vector<Point> a)
    {
        int pos_mi = min_element(a.begin(), a.end(), [&](Point &p1, Point &p2) { return p1.y != p2.y ? p1.y < p2.y : p1.x < p2.x; }) - a.begin();
        swap(a[0], a[pos_mi]);
        sort(a.begin() + 1, a.end(), [&](Point &p1, Point &p2) { ll v = (p1 - a[0]) % (p2 - a[0]); return v != 0 ? v > 0 : (p1 - a[0]).len2() < (p2 - a[0]).len2(); });
        vector<Point> hull;
        for (Point &p : a)
        {
            while (sz(hull) >= 2 && (hull.back() - hull[sz(hull) - 2]) % (p - hull.back()) <= 0)
                hull.pop_back();
            hull.push_back(p);
        }
        return hull;
    }

    bool point_in_segment(Point a, Point b, Point p)
    {
        if ((b - a) % (p - a) != 0)
            return false;
        return ((b - a) * (p - a) >= 0 && (a - b) * (p - b) >= 0);
    }

    ld dist_point_to_segment(Point p, Point a, Point b)
    {
        if (a == b)
            return (a - p).len();
        else if ((b - a) * (p - a) >= 0 && (a - b) * (p - b) >= 0)
            return abs((a - p) % (b - p)) / (b - a).len();
        else
            return min((a - p).len(), (b - p).len());
    }

    bool SIS(Point a, Point b, Point c, Point d)
    {
        if ((b - a) % (d - c) == 0)
        {
            if (point_in_segment(a, b, c))
                return true;
            if (point_in_segment(a, b, d))
                return true;
            if (point_in_segment(c, d, a))
                return true;
            if (point_in_segment(c, d, b))
                return true;
            return false;
        }
        else
        {
            ll v1 = (b - a) % (c - a), v2 = (b - a) % (d - a);
            if (v1 < 0 && v2 < 0 || v1 > 0 && v2 > 0)
                return false;
            v1 = (d - c) % (a - c); v2 = (d - c) % (b - c);
            if (v1 < 0 && v2 < 0 || v1 > 0 && v2 > 0)
                return false;
            return true;
        }
    }

    bool point_in_triangle(Point a, Point b, Point c, Point p)
    {
        ll v1 = (b - a) % (p - a);
        ll v2 = (c - b) % (p - b);
        ll v3 = (a - c) % (p - c);
        return (v1 >= 0 && v2 >= 0 && v3 >= 0) || (v1 <= 0 && v2 <= 0 && v3 <= 0);
    }

    ll get_area2(vector<Point> &a, bool absolute)
    {
        int n = sz(a);
        ll res = 0;
        rep(i, 0, n)
        res += a[i] % a[(i + 1) % n];
        if (absolute)
            res = abs(res);
        return res;
    }

    bool check_counter_clockwise(vector<Point> &a)
    {
        return get_area2(a, false) > 0;
    }

    bool check_diagonal_in_polygon(vector<Point> &a, int i, int j) // strictly inside
    {
        assert(i != j);
        int n = sz(a);
        if (n <= 2)
            return false;
        if ((i + 1) % n == j || (j + 1) % n == i)
            return false;
        rep(k, 0, n)
        if (k != i && k != j && point_in_segment(a[i], a[j], a[k]))
            return false;
        rep(k, 0, n)
        if (k != i && (k + 1) % n != i && k != j && (k + 1) % n != j)
            if (SIS(a[i], a[j], a[k], a[(k + 1) % n]))
                return false;
        vector<Point> b, c;
        for (int k = i; ; k = (k + 1) % n)
        {
            b.push_back(a[k]);
            if (k == j)
                break;
        }
        for (int k = j; ; k = (k + 1) % n)
        {
            c.push_back(a[k]);
            if (k == i)
                break;
        }
        if (get_area2(b, true) + get_area2(c, true) != get_area2(a, true))
            return false;
        return true;
    }

    bool point_in_convex_polygon(vector<Point> &a, Point p)
    {
        int n = sz(a);
        if (n == 1)
            return (a[0] == p);
        else if (n == 2)
            return point_in_segment(a[0], a[1], p);

        if ((a[1] - a[0]) % (p - a[0]) < 0)
            return false;
        else if ((a[1] - a[0]) % (p - a[0]) == 0)
            return point_in_segment(a[0], a[1], p);
        if ((a[n - 1] - a[0]) % (p - a[0]) > 0)
            return false;
        else if ((a[n - 1] - a[0]) % (p - a[0]) == 0)
            return point_in_segment(a[0], a[n - 1], p);

        int l = 1, r = n - 1, mid;
        while (r - l > 1)
        {
            mid = (l + r) / 2;
            if ((a[mid] - a[0]) % (p - a[0]) >= 0)
                l = mid;
            else
                r = mid;
        }
        return point_in_triangle(a[0], a[l], a[l + 1], p);
    }

    ll max_distance(vector<Point> &a) {
        int n = sz(a);
        if (n == 1) {
            return 0;
        }
        if (n == 2) {
            return dist2(a[0], a[1]);
        }
        ll ans = 0;
        int p = 0;
        rep(i, 0, n) {
            Point vect = a[(i + 1) % n] - a[i];
            while (vect % (a[(p + 1) % n] - a[i]) >= vect % (a[p] - a[i])) {
                p = (p + 1) % n;
            }
            setmax(ans, dist2(a[i], a[p]));
            setmax(ans, dist2(a[(i + 1) % n], a[p]));
        }
        return ans;
    }
}

using namespace GEO;

int name[N];
vector<Point> nat[N];
bool is_big[N];
bool in_name[N];

int main()
{
    //freopen("a.in", "r", stdin);
    //freopen("a.out", "w", stdout);
    //ios_base::sync_with_stdio(0);
    //cin.tie(0);
    //cout.precision(20);
    //cout << fixed;
    //ll TL = 0.95 * CLOCKS_PER_SEC;
    //clock_t time = clock();
    int n, m, d;
    scanf("%d %d %d", &n, &m, &d);
    rep(i, 0, n) {
        scanf("%d", &name[i]);
        in_name[name[i]] = true;
    }
    rep(i, 0, m) {
        int x, y, col;
        scanf("%d %d %d", &x, &y, &col);
        nat[col].push_back(Point(x, y));
    }
    rep(i, 0, N) {
        if (sz(nat[i]) != 0) {
            nat[i] = convex_hull(nat[i]);
            if (max_distance(nat[i]) > 1LL * d * d) {
                is_big[i] = true;
            }
        }
    }
    int l = -inf, r = inf;
    rep(i, 0, n) {
        int id = name[i];
        if (!is_big[id]) {
            cout << "NO\n";
            return 0;
        }
        int fr = inf, to = -inf;
        for (Point p : nat[id]) {
            setmin(fr, p.x);
            setmax(to, p.x);
        }
        assert(fr <= to);
        setmax(l, fr);
        setmin(r, to);
    }
    if (l > r) {
        cout << "NO\n";
        return 0;
    }
    vector<pair<int, int> > E;
    rep(id, 0, N) {
        if (is_big[id] && !in_name[id]) {
            int fr = inf, to = -inf;
            for (Point p : nat[id]) {
                setmin(fr, p.x);
                setmax(to, p.x);
            }
            assert(fr <= to);
            if (to < l || fr > r) {
                continue;
            }
            fr = max(fr, l);
            to = min(to, r);
            E.push_back({fr * 2, -1});
            E.push_back({fr * 2, 0});
            if (fr < to) {
                E.push_back({fr * 2 + 1, 0});
            }
            E.push_back({to * 2, 1});
            E.push_back({to * 2, 0});
            if (to < r) {
                E.push_back({to * 2 + 1, 0});
            }
        }
    }
    E.push_back({l * 2, -1});
    E.push_back({l * 2, 0});
    if (l < r) {
        E.push_back({l * 2 + 1, 0});
    }
    E.push_back({r * 2, 1});
    E.push_back({r * 2, 0});
    sort(E.begin(), E.end());
    int best = inf, last = l, cur = 0;
    for (auto it : E) {
        if (it.se == -1) {
            cur++;
        } else if (it.se == 1) {
            cur--;
        } else {
            setmin(best, cur);
        }
    }
    cout << "YES " << best - 1 + n << "\n";
    return 0;
}
