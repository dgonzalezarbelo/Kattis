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

vii dirs_exterior = {{1,0}, {0,1}, {-1,0}, {0,-1}};

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int r, c, u; cin >> r >> c >> u; cin.get();
    int S;
    UF uf(r * c);
    vector<vector<char>> mat(r, vector<char>(c));
    rep(i,0,r) {
        string s; getline(cin, s);
        rep(j,0,c) {
            mat[i][j] = s[j];
            if(s[j] == 'S') S = i * c + j;
        }
    }
    rep(i,0,r) rep(j,0,c) {
        if(mat[i][j] == '.') continue;
        for(ii d : dirs_exterior) {
            if(i + d.fi >= 0 && i + d.fi < r && j + d.se >= 0 && j + d.se < c) {
                if(mat[i + d.fi][j + d.se] != '.') uf.join(i * c + j, (i + d.fi) * c + j + d.se);
            }
        }
    }
    cout << uf.size(S) << '\n';
    rep(_,0,u) {
        int i, j; cin >> i >> j;
        i--; j--;
        mat[i][j] = '#';
        for(ii d : dirs_exterior) {
            if(i + d.fi >= 0 && i + d.fi < r && j + d.se >= 0 && j + d.se < c) {
                if(mat[i + d.fi][j + d.se] != '.') uf.join(i * c + j, (i + d.fi) * c + j + d.se);
            }
        }
        cout << uf.size(S) << '\n';
    }
    return 0;
}