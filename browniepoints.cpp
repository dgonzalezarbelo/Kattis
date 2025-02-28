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
    int n;
    while(cin >> n && n) {
        int eje_x, eje_y;
        vector<pair<int, int>> v;
        for(int i = 0; i < n; i++) {
            int a, b; cin >> a >> b;
            if(i == n / 2) {
                eje_x = a;
                eje_y = b;
            }
            else
                v.push_back({a, b});
        }
        int stan = 0, ollie = 0;
        for(auto p : v) {
            long long prod = (long long)(p.first - eje_x) * (long long)(p.second - eje_y);
            if(prod > 0) stan++;
            else if(prod < 0) ollie++;
        }
        cout << stan << ' ' << ollie << '\n';
    }
    return 0;
}