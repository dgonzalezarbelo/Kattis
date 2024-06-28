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
    int n, p, d; cin >> n >> p >> d; cin.get();
    vi v(n);
    rep(i,0,n) {
        char c; cin >> c;
        if(c == 'Z') v[i] = 1;
    }
    vi sum(n);
    sum[0] = v[0];
    rep(i,1,n)
        sum[i] = sum[i - 1] + v[i];
    int sol = 0;
    rep(i,0,n) {
        if(i - p >= 0) {
            if(sum[i] - sum[i - p] < d)
                sol++;
        }
        else {
            if(sum[n - 1] - sum[i - p + n] + sum[i] < d)
                sol++;
        }
    }
    cout << sol << '\n';
    return 0;
}