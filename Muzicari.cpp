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

vvi dp;
vi sol_final;

bool solve(vi & v, vi & sol, int T, int i, int m1, int m2) {
    if(i >= sz(v)) {
        if(sol_final[0] == -1) for(int j = 0; j < sz(v); j++) sol_final[j] = sol[j];
        return true;
    }
    if(dp[i][m1] != -1) return dp[i][m1];
    bool ok = false;
    if(m1 + v[i] <= T) {
        sol[i] = m1;
        ok |= solve(v, sol, T, i + 1, m1 + v[i], m2);
    } 
    if(ok) {
        dp[i][m1] = 1;
        return true;
    }
    if(m2 + v[i] <= T) {
        sol[i] = m2;
        ok |= solve(v, sol, T, i + 1, m1, m2 + v[i]);
    } 
    if(ok) {
        dp[i][m1] = 1;
        return true;
    }
    dp[i][m1] = 0;
    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t, n; cin >> t >> n;
    vi v(n);
    dp.assign(n, vi(t + 1, -1));
    sol_final.assign(n, -1);
    for(int i = 0; i < n; i++) {
        cin >> v[i];
    }
    vi sol(n);
    if(solve(v, sol, t, 0, 0, 0)) {
        for(int i = 0; i < n; i++) {
            if(i) cout << ' ';
            cout << sol_final[i];
        }
    }
    return 0;
}