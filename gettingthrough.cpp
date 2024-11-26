#include <bits/stdc++.h>
#pragma warning (disable : 4996)
using namespace std;

#define rep(i, a, b) for(int i = a; i < b; ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
#define fi first
#define se second
#define mp make_pair

const double EPS = 1e-7;
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

struct UF {
	vi e;
	UF(int n) : e(n, -1) {}
	bool sameSet(int a, int b) { return find(a) == find(b); }
	int size(int x) { return -e[find(x)]; }
	int find(int x) { return e[x] < 0 ? x : e[x] = find(e[x]); }
	bool join(int a, int b) {
		a = find(a), b = find(b);
		if (a == b) return false;
		if (e[a] > e[b]) swap(a, b);
		e[a] += e[b]; e[b] = a;
		return true;
	}
};

ll dist2(ll x1, ll y1, ll x2, ll y2) {
    return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

bool tryRadius(vector<pair<pair<ll,ll>, ll>> & points, ll w, double r) {
    int n = sz(points);
    UF uf(n + 2);
    rep(i,0,n) {
        ll x1, y1, r1;
        x1 = points[i].first.first;
        y1 = points[i].first.second;
        r1 = points[i].second;
        if(x1 - r1 - 2 * r <= 0) uf.join(0, i + 2);
        if(x1 + r1 + 2 * r >= w) uf.join(1, i + 2);
    }
    rep(i,0,n) {
        rep(j,i+1,n) {
            ll x1, y1, r1, x2, y2, r2;
            x1 = points[i].first.first;
            y1 = points[i].first.second;
            r1 = points[i].second;
            x2 = points[j].first.first;
            y2 = points[j].first.second;
            r2 = points[j].second;
            if(dist2(x1, y1, x2, y2) <= (r1 + r2 + 2 * r) * (r1 + r2 + 2 * r)) uf.join(i + 2, j + 2);
        }
    }
    return !uf.sameSet(0, 1);
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n;
        ll w;
        cin >> w >> n;
        UF uf(n + 2);
        vector<pair<pair<ll,ll>, ll>> points(n);
        rep(i,0,n) {
            ll x, y, r;
            cin >> x >> y >> r;
            points[i] = mp(mp(x, y), r);
        }
        if(n == 0) {
            cout << w / 2.0 << '\n';
            continue;
        }
        if(!tryRadius(points, w, 0.0)) {
            cout << "0\n";
            continue;
        }
        double ini = 0.0, fin = (double)w;
        while(fin - ini > EPS) {
            double mid = (ini + fin) / 2.0;
            if(tryRadius(points, w, mid)) ini = mid;
            else fin = mid;
        }
        cout << setprecision(7) << ini << '\n';
    }
    return 0;
}