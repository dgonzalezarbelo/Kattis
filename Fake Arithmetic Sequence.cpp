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

int main() {
    int n; cin >> n;
    vector<ll> v(n);
    unordered_map<ll, vector<int>> m;
    for(int i = 0; i < n; i++) {
        cin >> v[i];
        m[v[i]].push_back(i);
    }
    vector<vector<ll>> dp(n, vector<ll>(n, 2));
    dp[n - 1][n - 1] = 1;
    ll sol = 2;
    for(int i = n - 2; i >= 0; i--) {
        for(int j = n - 2; j > i; j--) {
            if(m.count(v[i] + v[j])) {
                for(int k : m[v[i] + v[j]]){
                    if(k <= j) continue;
                    dp[i][j] = max(dp[i][j], 1 + dp[j][k]);
                    sol = max(sol, dp[i][j]);
                }
            }
        }
    }
    cout << sol;
    return 0;
}