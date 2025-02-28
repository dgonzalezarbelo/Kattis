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

struct comp {
    bool operator() (pair<ll, ll> const& p1, pair<ll, ll> const& p2) const {
        return p1.second * p2.first < p2.second * p1.first;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll n, m; cin >> n >> m;
    vector<pair<ll, ll>> v(n);
    for(auto & p : v) {
        ll a, b; cin >> a >> b;
        p = {a, b};
    }
    sort(all(v), comp());
    ll sum = m, por_dia = 0, dias = LLONG_MAX;
    for(int i = 0; i < n; i++) {
        auto p = v[i];
        sum += p.second;
        por_dia += p.first;
        dias = min(dias, (sum + por_dia - 1) / por_dia);
    }
    cout << dias << '\n';
    return 0;
}