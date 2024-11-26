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
    int l, h, k; cin >> l >> h >> k;
    vector<vector<char>> mat(h, vector<char>(l, '_'));
    rep(_,0,k) {
        char c = 'a' + _;
        int dj, di, j, i; cin >> dj >> di >> j >> i;
        for(int cur_i = 0; cur_i < di && cur_i + i < h; cur_i++) {
            for(int cur_j = 0; cur_j < dj && cur_j + j < l; cur_j++) {
                mat[i + cur_i][j + cur_j] = c;
            }
        }
    }
    rep(i,0,h) {
        rep(j,0,l) {
            cout << mat[i][j];
        }
        cout << '\n';
    }
    return 0;
}