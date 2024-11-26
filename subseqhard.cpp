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
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    int t; cin >> t;
    vii sol;
    while(t--) {
        int n; cin >> n;
        vi v(n);
        for(int & x : v) cin >> x;
        int i = 0, j = 1;
        int sum = v[0];
        while(j <= n) {
            if(sum == 47) {
                sol.push_back({i,j - 1});
                j++;
                i = j - 1;
                sum = v[i];
            }
            else if(sum < 47) {
                sum += v[j];
                j++;
            }
            else {
                sum -= v[i];
                i++;
            }
        }
        cout << sol.size() << '\n';
    }
    return 0;
}