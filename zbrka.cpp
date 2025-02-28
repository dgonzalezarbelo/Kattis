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

const int mod = 1'000'000'007;

signed main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m; cin >> n >> m;
    vvi dp(n + 1, vi(m + 1));
    vi cur(m + 1), prev(m + 1);
    cur[0] = prev[0] = 1;
    rep(i,2,n + 1) {
        int suma = prev[0];
        cur[0] = suma;
        rep(j,1,m + 1) {
            suma += prev[j];
            suma %= mod;
            if(j >= i) suma = (suma + mod - prev[j - i]) % mod;
            cur[j] = suma;
        }
        prev = cur;
    }
    cout << cur[m] << '\n';
    return 0;
}