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
    int i = 0;
    set<int> cuadrados;
    while(i * i < 1e6 + 1) {
        cuadrados.insert(i * i);
        i++;
    }
    int n; cin >> n;
    while(n--) {
        int a; cin >> a;
        if(a % 2 == 1 && cuadrados.count(a)) cout << "OS\n";
        if(a % 2 == 1 && !cuadrados.count(a)) cout << "O\n";
        if(a % 2 == 0 && cuadrados.count(a)) cout << "S\n";
        if(a % 2 == 0 && !cuadrados.count(a)) cout << "EMPTY\n";
    }
    return 0;
}