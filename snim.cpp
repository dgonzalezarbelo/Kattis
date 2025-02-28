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

int solve(int a, set<int> const& s, unordered_map<int, int> & dp) {
    // cout << "a -> " << a << endl;
    if(dp.count(a)) return dp[a];
    if(a == 0) return 0;
    if(a < *(s.begin())) return 0;
    set<int> mex;
    for(int b : s) {
        if(b <= a)
            mex.insert(solve(a - b, s, dp));
    }
    int i = 0;
    while(mex.count(i)) i++;
    return dp[a] = i;
}

int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int n; cin >> n;
    set<int> s;
    rep(i,0,n) {
        int a; cin >> a;
        s.insert(a);
    }
    unordered_map<int, int> dp;
    int m; cin >> m;
    rep(i,0,m) {
        int k; cin >> k;
        int sol = 0;
        rep(j,0,k) {
            int a; cin >> a;
            int cur_sol = solve(a, s, dp);
            // cout << "cur_sol -> " << cur_sol << endl;
            sol ^= cur_sol;
        }
        if(sol == 0) cout << "L";
        else cout << "W";
    }
    return 0;
}