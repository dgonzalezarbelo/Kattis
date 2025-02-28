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

double dist(pair<double, double> p1, pair<double, double> p2) {
    return sqrt((p1.first - p2.first) * (p1.first - p2.first) + (p1.second - p2.second) * (p1.second - p2.second));
}

vi vis, match;
vvi g;
int N, M;
int aug(int l) {
    if (vis[l])
        return 0;
    vis[l] = 1;
    for (int r : g[l])
        if (match[r] == -1 || aug(match[r])) {
            match[r] = l;
            return 1;
        }
    return 0;
}

int berge_mcbm() {
    unordered_set<int> libres;
    for (int l = 0; l < N; ++l)
        libres.insert(l);
    int mcbm = 0;
    match.assign(N + M, -1);
    for (int l = 0; l < N; ++l) {
        vector<int> candidatos;
        for (int r : g[l])
            if (match[r] == -1)
                candidatos.push_back(r);
        if (!candidatos.empty()) {
            ++mcbm;
            libres.erase(l);
            int r = rand() % int(candidatos.size());
            match[candidatos[r]] = l;
        }
    }
    for (int l : libres) {
        vis.assign(N, 0);
        mcbm += aug(l);
    }
    return mcbm;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, caso = 1;
    while(cin >> n && n) {
        cout << "Scenario " << caso << '\n';
        caso++;
        vector<pair<double, double>> v(n);
        for(auto & p : v) cin >> p.first >> p.second;
        int h; cin >> h;
        N = n; M = h;
        vector<pair<double, double>> holes(h);
        for(auto & p : holes) cin >> p.first >> p.second;
        g.assign(n + h, vi());
        rep(i,0,n) rep(j,0,h) {
            if(dist(v[i], holes[j]) <= 50.0) {
                g[i].push_back(j);
                g[n + j].push_back(i);
            }
        }
        cout << "In 5 seconds " << berge_mcbm() << " robot(s) can escape\n";
        rep(i,0,n) rep(j,0,h) {
            double d = dist(v[i], holes[j]);
            if(d <= 100.0 && d > 50.0) {
                g[i].push_back(j);
                g[n + j].push_back(i);
            }
        }
        cout << "In 10 seconds " << berge_mcbm() << " robot(s) can escape\n";
        rep(i,0,n) rep(j,0,h) {
            double d = dist(v[i], holes[j]);
            if(d <= 200.0 && d > 100.0) {
                g[i].push_back(j);
                g[n + j].push_back(i);
            }
        }
        cout << "In 20 seconds " << berge_mcbm() << " robot(s) can escape\n";
        cout << '\n';
    }
    return 0;
}