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
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    unordered_map<int, int> m;
    int N, t; cin >> N >> t;
    vb rango(1001, false);
    vi v(N);
    bool suma7 = false;
    bool unico = true;
    int moda = -1;
    for(int i = 0; i < N; i++) {
        int a; cin >> a;
        m[a]++;
        if(a <= 7777 && m[7777 - a] > 0) suma7 = true;
        if(100 <= a && a <= 999) rango[a] = true;
        if(m[a] > 1) unico = false;
        if(m[a] > N / 2) moda = a;
        v[i] = a;
    }
    if(t == 1) {
        if(suma7) cout << "Yes";
        else cout << "No";
    }
    if(t == 2) {
        if(unico) cout << "Unique";
        else cout << "Contains duplicate";
    }
    if(t == 3) {
        cout << moda;
    }
    if(t == 4) {
        sort(v.begin(), v.end());
        if(N % 2 == 0) cout << v[N / 2 - 1] << ' ' << v[N / 2];
        else cout << v[N / 2];
    }
    if(t == 5) {
        bool primero = true;
        for(int i = 100; i < 1000; i++) {
            if(rango[i]) {
                for(int j = 0; j < m[i]; j++) {
                    if(!primero) cout << ' ';
                    primero = false;
                    cout << i;
                }
            }
        }
    }
    return 0;
}