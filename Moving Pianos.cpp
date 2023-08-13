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
using ii = pair<int, int>;
using vi = vector<int>;
using vvi = vector<vi>;
using vii = vector<ii>;
using vvii = vector<vii>;
using vb = vector<bool>;
using vvb = vector<vb>;
using db = double;
using vdb = vector<db>;
using ldb = long double; //100 ceros pero poca precision decimal

struct comp {
    bool operator()(ii const& p1, ii const& p2) {
        return p1.second > p2.second || (p1.second == p2.second && p1.first > p2.first);
    }
};

bool sin_fines(vii & v, int m) {
    priority_queue<ii, vector<ii>, comp> pq;
    for(ii p : v) pq.push(p);
    int dia = 1, cuantos = 0;
    while(!pq.empty()) {
        ii p = pq.top();
        pq.pop();
        if(p.first > dia) {
            dia = p.first;
            cuantos = 0;
        }
        if(dia % 7 != 6 && dia % 7 != 0) {
            if(cuantos < m - 1) {
                cuantos += 2;
            }
            else {    
                if(p.first == p.second) return false;
                else pq.push(mp(p.first + 1, p.second));
            }
        }
        else {
            if(p.first == p.second) return false;
            else pq.push(mp(p.first + 1, p.second));
        }
    }
    return true;
}

bool con_fines(vii & v, int m) {
    priority_queue<ii, vector<ii>, comp> pq;
    for(ii p : v) pq.push(p);
    int dia = 1, cuantos = 0;
    while(!pq.empty()) {
        ii p = pq.top();
        pq.pop();
        if(p.first > dia) {
            dia = p.first;
            cuantos = 0;
        }
        if(cuantos < m - 1) {
            cuantos += 2;
        }
        else {    
            if(p.first == p.second) return false;
            else pq.push(mp(p.first + 1, p.second));
        }
    }
    return true;
}

void solve() {
    int n, m; cin >> n >> m;
    vii v(n);
    for(int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }
    if(sin_fines(v, m)) cout << "fine\n";
    else if(con_fines(v, m)) cout << "weekend work\n";
    else cout << "serious trouble\n";
}

int main() {
    int t; cin >> t;
    while(t--) solve();
    return 0;
}