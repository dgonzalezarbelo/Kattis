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

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int u, k; cin >> u >> k;
    unordered_map<string, vector<pair<string, int>>> recetas;
    unordered_map<string, int> veces;
    map<string, int> cantidades;
    rep(i,0,u) {
        string s; cin >> s;
        int n; cin >> n;
        vector<pair<string, int>> ingr(n);
        rep(j,0,n) {
            string ss; cin >> ss;
            int a; cin >> a;
            ingr[j] = {ss, a};
        }
        recetas[s] = ingr;
    }
    rep(i,0,k) {
        int kk; cin >> kk;
        rep(j,0,kk) {
            string s; cin >> s;
            int n; cin >> n;
            veces[s] += n;
        }
    }
    for(auto & p : veces) {
        for(auto& pp : recetas[p.first]) {
            cantidades[pp.first] += pp.second * p.second;
        }
    }
    for(auto & p : cantidades) {
        if(p.second > 0) cout << p.first << ' ' << p.second << '\n';
    }
    return 0;
}