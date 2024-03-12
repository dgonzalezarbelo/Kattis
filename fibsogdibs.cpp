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

const ll MOD = 1e9 + 7;

vector<vll> mult(vector<vll> & mat1, vector<vll> & mat2) {
    return {{((mat1[0][0] * mat2[0][0]) % MOD + (mat1[0][1] * mat2[1][0]) % MOD) % MOD, 
                ((mat1[0][0] * mat2[0][1]) % MOD + (mat1[0][1] * mat2[1][1]) % MOD ) % MOD},
            {((mat1[1][0] * mat2[0][0]) % MOD + (mat1[1][1] * mat2[1][0]) % MOD) % MOD, 
                ((mat1[1][0] * mat2[0][1]) % MOD + (mat1[1][1] * mat2[1][1]) % MOD ) % MOD}};
}

vector<vll> elevar(vector<vll> & mat, int n) {
    if(n == 0) {
        return {{1, 0}, {0, 1}};
    }
    if(n == 1) return mat;
    vector<vll> ant = elevar(mat, n / 2);
    vector<vll> multi = mult(ant, ant);
    if(n % 2 == 0)
        return multi;
    else
        return mult(multi, mat);
}

void simular(ll a, ll b, ll n) {
    ll na = a, nb = b;
    rep(i,0,n) {
        na = na + nb;
        na %= MOD;
        nb = nb + na;
        nb %= MOD;
    }
    cout << "SIMULADO -> " << na << ' ' << nb << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    ll a, b, n;
    cin >> a >> b >> n;
    vector<vll> mat = {{1,1}, {1,0}};
    mat = elevar(mat, 2 * n);
    ll na, nb;
    nb = ((mat[0][0] * b) % MOD + (mat[0][1] * a) % MOD) % MOD;
    na = ((mat[1][0] * b) % MOD + (mat[1][1] * a) % MOD) % MOD;
    cout << na << ' ' << nb << endl;
    //simular(a, b, n);
    return 0;
}