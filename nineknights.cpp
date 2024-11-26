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

vii dirs = {{1,2},{1,-2},{-1,2},{-1,-2},{2,1},{2,-1},{-2,1},{-2,-1}};

bool valid(int x, int y) {
    return x >= 0 && x < 5 && y >= 0 && y < 5;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> mat(5);
    rep(i,0,5) cin >> mat[i];
    int ks = 0;
    bool ok = true;
    pair<int, int> p;
    rep(i,0,5) rep(j,0,5) {
        if(mat[i][j] == 'k') {
            ks++;
            for(auto d : dirs) {
                int x = i + d.first, y = j + d.second;
                if(valid(x, y) && mat[x][y] == 'k') {
                    ok = false;
                }
            }
        }
    }
    if(ok && ks == 9) cout << "valid\n";
    else cout << "invalid\n";
    return 0;
}