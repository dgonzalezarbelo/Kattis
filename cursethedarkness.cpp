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

double dist(pair<double, double> p1, pair<double, double> p2) {
    double dif_x = p1.first - p2.first;
    double dif_y = p1.second - p2.second;
    return sqrt((dif_x * dif_x + dif_y * dif_y));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int t; cin >> t;
    while(t--) {
        double x, y; cin >> x >> y;
        int n; cin >> n;
        bool cerca = false;
        for(int i = 0; i < n; i++) {
            double a, b; cin >> a >> b;
            if(dist({x, y}, {a, b}) <= 8.0)
                cerca = true;
        }
        if(cerca)
            cout << "light a candle\n";
        else
            cout << "curse the darkness\n";
    }   
    return 0;
}