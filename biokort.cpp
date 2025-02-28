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
    int n, pi, pa; cin >> n >> pi >> pa;
    map<int, int, greater<int>> popularidades;
    int suma = 0;
    rep(i,0,n) {
        string s; cin >> s;
        int pop; cin >> pop;
        popularidades[pop]++;
        suma += pop;
    }
    int encima = 0, suma_encima = 0;
    int sol = suma * pi, minx = 0;
    for(auto it = popularidades.begin(); it != popularidades.end(); it++) {
        int x = it->first;
        int cur = (suma_encima - encima * x) * pi + x * pa;
        if(cur < sol) {
            sol = cur;
            minx = x;
        }
        encima += it->second;
        suma_encima += it->first * it->second;
    }
    cout << minx << ' ' << sol << '\n';
    return 0;
}