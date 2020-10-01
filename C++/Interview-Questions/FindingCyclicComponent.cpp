/**
*      Author : tourist1256
*      Time   : 2020-10-01 13:34:32
**/

#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <vector>

using namespace std;
#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")
#define time cout << (0.1 * clock()) / CLOCKS_PER_SEC << endl;
#define countBits(x) __builtin_popcount(ll(x))
#define countZeroesAtBegin(x) __builtin_clz(ll(x))
#define countZeroesAtEnd(x) __builtin_ctz(ll(x))
#define last(x) x[x.end() - x.begin() - 1]
#define pb push_back
#define bg begin
#define FF first
#define SS second
#define PI 3.1415926535897932384626
#define si(x) scanf("%d", &x)
#define sl(x) scanf("%lld", &x)
#define ss(s) scanf("%s", s)
#define pi(x) printf("%d\n", x)
#define pl(x) printf("%lld\n", x)
#define ps(s) printf("%s\n", s)
#define deb(x) cout << #x << "=" << x << endl
#define deb2(x, y) cout << #x << "=" << x << "," << #y << "=" << y << endl
typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pl;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<pii> vpii;
typedef vector<pl> vpl;
typedef vector<vi> vvi;
typedef vector<vll> mat;
const ll MAX = 1e5;
const ll mod = 1000000007;
#define all(x) x.begin(), x.end()
#define rev(x) x.rbegin(), x.rend()
#define clr(x) memset(x, 0, sizeof(x))
#define sortall(x) sort(all(x))
#define sortrev(x) sort(rev(x))
#define forn(n) for (ll i = 0; i < ll(n); i++)
#define forkn(i, k, n) for (ll i = k; i < ll(n); i++)
#define forin(n) for (ll i = ll(n - 1); i >= 0; i--)
#define tr(it, a) for (auto it = a.begin(); it != a.end(); it++)

bool visited[200001] = {false};
vll paths;

ll mpow(ll base, ll exp) {
    base %= mod;
    ll result = 1;
    while (exp > 0) {
        if (exp & 1) result = ((ll)result * base) % mod;
        base = ((ll)base * base) % mod;
        exp >>= 1;
    }
    return result;
}

void dfs(vll adj[], ll s) {
    paths.pb(s);
    for (auto u : adj[s]) {
        if (visited[u]) continue;
        visited[u] = true;
        dfs(adj, u);
    }
}

void solve() {
    ll n, m, u, v;
    cin >> n >> m;
    vll adj[n + 1];
    forn(m) {
        cin >> u >> v;
        adj[u].pb(v);
        adj[v].pb(u);
    }
    // forkn(i, 1, n + 1) {
    //     cout << adj[i].size() << " ";
    // }
    // cout << endl;
    ll ans = 0;
    forkn(i, 1, n + 1) {
        if (!visited[i]) {
            visited[i] = true;
            paths.clear();
            dfs(adj, i);
            // for (auto it : paths) {
            //     cout << it << " ";
            // }
            // cout << endl;
            if (paths.size() > 2) {
                ans += 1;
                // deb(ans);
                forkn(j, 0, paths.size()) {
                    // deb(adj[paths[j]].size());
                    if (adj[paths[j]].size() != 2) {
                        ans -= 1;
                        break;
                    }
                }
                // deb(ans);
            }
        }
    }
    cout << ans << endl;
}

int32_t main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    ll tc = 1;
    // cin >> tc;
    while (tc--) {
        solve();
    }
    return 0;
}
