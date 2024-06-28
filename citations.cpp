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

vvi al;
vi costes, acumulados;

int dfs(int a) {
    int n_hijos = 0;
    for(int b : al[a]) 
        n_hijos += dfs(b);
    // Los ordenamos por lo que tarda cada rama. Lo optimo es priorizar las que menos tardan
    sort(all(al[a]), [&](int x, int y) {
            return acumulados[x] < acumulados[y];
        });
    int acum = 0, cur_acum = 0;
    for(int b : al[a]) {
        cur_acum += acumulados[b];
        acum += cur_acum;
    }
    acum += 1 + costes[a];
    acumulados[a] = acum;
    // El coste de esta rama es el de hacer las cosas de forma optima
    return n_hijos + 1;
}

int sol;

int dfs2(int a, int acum_prev) {
    int t = 1 + acum_prev;
    for(int b : al[a])
        t = dfs2(b, t);
    t += costes[a];
    sol += t;
    return t;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    sol = 0;
    int n; cin >> n;
    al.assign(n, {});
    costes.assign(n, {});
    acumulados.assign(n, {});
    rep(i,0,n) {
        int k; cin >> k;
        costes[i] = k;
        int f; cin >> f;
        while(f--) {
            int a; cin >> a;
            a--;
            al[i].push_back(a);
        }
    }
    dfs(0);
    dfs2(0,0);
    cout << sol << endl;
    return 0;
}