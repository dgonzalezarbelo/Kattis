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
    int n, m, q; cin >> n >> m >> q;
    vector<string> mat(n);
    rep(i,0,n) cin >> mat[i];
    vi valid(n, true);
    rep(_,0,q) {
        int col; cin >> col; col--;
        char c; cin >> c;
        for(int i = 0; i < n; i++) {
            if(mat[i][col] != c) valid[i] = false;
        }
    }
    int sol, sols = 0;
    rep(i,0,n) {
        if(valid[i]) {
            sols++;
            sol = i;
        }
    }
    if(sols == 1) cout << "unique\n" << sol + 1 << '\n';
    else cout << "ambiguous\n" << sols << '\n';
    return 0;
}