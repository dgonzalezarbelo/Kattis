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
    int n; cin >> n;
    if(n == 1) {
        cout << n;
        return 0;
    }
    int sol = 1;
    int a, aux;
    int subiendo = 0;
    cin >> a >> aux;
    if (a > aux) subiendo = -1;
    if (a < aux) subiendo = 1;
    if (a != aux) sol++;
    a = aux;
    for(int i = 2; i < n; i++) {
        cin >> aux;
        if(subiendo == 1 && aux < a) sol++;
        if(subiendo == -1 && aux > a) sol++;
        if (a > aux) subiendo = -1;
        if (a < aux) subiendo = 1;
        a = aux;
    }
    cout << sol;
    return 0;
}