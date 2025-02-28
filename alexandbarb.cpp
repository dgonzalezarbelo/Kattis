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
    int k, m, n; cin >> k >> m >> n;
    // vi v(1000);
    // for(int i = 0; i < m; i++) v[i] = 0;
    // for(int i = m; i <= n; i++) v[i] = 1;
    // for(int i = n + 1; i < 1000; i++) {
    //     for(int j = m; j <= n; j++) {
    //         if(v[i - j] == 0) {
    //             v[i] = 1;
    //             break;
    //         }
    //     }
    // } 
    // cout << v[999];
    if(k < m) cout << "Barb\n";
    else if(m <= k && k <= n) cout << "Alex\n";
    else {
        int inf = (k / (n + m)) * (n + m);
        if(k <= inf + m - 1) cout << "Barb\n";
        else cout << "Alex\n";
    }

    return 0;
}