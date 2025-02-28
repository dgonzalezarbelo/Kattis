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
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        int n, f; cin >> n >> f;
        f++;
        vi v(n);
        rep(i,0,n) {
            cin >> v[i];
        }
        double pi = acos(-1);
        double ini = 0.0, fin = pi * 100010.0 * 100010.0;
        while(fin - ini > 1e-5) {
            double mid = (ini + fin) / 2.0;
            int cur = 0;
            for(int r : v) {
                double vv = pi * (double)r * (double)r;
                cur += floor(vv / mid);
            }
            if(cur >= f) // Me vale con mid -> sol >= mid
                ini = mid;
            else
                fin = mid;
        }
        cout << setprecision(8) << fixed << ini << '\n';
    }
    return 0;
}