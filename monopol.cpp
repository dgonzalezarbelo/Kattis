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
    vi v(13);
    v[0] = 0;
    v[1] = 0;
    v[2] = 1;
    v[3] = 2;
    v[4] = 3;
    v[5] = 4;
    v[6] = 5;
    v[7] = 6;
    v[8] = 5;
    v[9] = 4;
    v[10] = 3;
    v[11] = 2;
    v[12] = 1;
    int n; cin >> n;
    int fav = 0;
    while(n--) {
        int a; cin >> a;
        fav += v[a];
    }
    cout << setprecision(6) << (double) fav / (double) 36 << '\n';
    return 0;
}