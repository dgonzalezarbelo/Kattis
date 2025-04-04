#include <bits/stdc++.h>
#pragma warning (disable : 4996)
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define mp make_pair

const double EPS = 1e-9;
const double INF = 1e9; //1e18 tambien suele ir bien
using ll = long long int;
#define int ll
using ull = unsigned long long;
using ii = pair<int, int>;
using vi = vector<int>;
using vll = vector<ll>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vb = vector<bool>;
using vvb = vector<vb>;
using db = double;
using vdb = vector<db>;
using ldb = long double; //100 ceros pero poca precision decimal

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k; cin >> n >> k;
    vi v(n);
    vvi por_cat(k + 1);
    rep(i,0,n) {
        cin >> v[i];
        por_cat[v[i]].push_back(i);
    }
    vi next(n);
    // Para cada elemento calculo su siguiente más cercano
    for(int i = 0; i < n; i++) {
        if(v[i] == k) continue;
        auto it = lower_bound(all(por_cat[v[i] + 1]), i);
        if(it == por_cat[v[i] + 1].end())
            it = por_cat[v[i] + 1].begin();
        next[i] = *it;
    }

    // Luego, partiendo de K, vuelvo hacia atrás, contando para cada K - 1 lo que tarda en llegar a K si empiezas ahi
    // Luego, para cada K - 2 lo que tarda en llegar a K (pasando por K - 1) si empiezas ahi

    vi res(n);
    for(int x : por_cat[k]) res[x] = 0;
    for(int kk = k - 1; kk >= 1; kk--) {
        for(int x : por_cat[kk]) {
            int dist;
            if(next[x] > x) dist = next[x] - x;
            else dist = next[x] + n - x;
            res[x] = dist + res[next[x]];
        }
    }
    int sol = LLONG_MAX;
    for(int x : por_cat[1])
        sol = min(sol, res[x]);
    cout << sol + 1 << '\n';
    return 0;
}