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

struct UF {
    vi e;
    vi sumas;
    vi actualizado;
    int adicionales;
    UF(int n, int m) : e(n + m + 1, -1), actualizado(n + 1) {
        sumas.assign(n + m + 1, 0);
        rep(i,0,n + m) {
            sumas[i] = i;
            actualizado[i] = i;
        }
        adicionales = n;
    }
    int size(int x) { return -e[find(actualizado[x])]; }
    int suma(int x) { return sumas[find(actualizado[x])]; }
    int find(int x) { return e[x] < 0 ? x : find(e[x]); }
    bool join(int a, int b) {
        a = actualizado[a], b = actualizado[b];
        a = find(a), b = find(b);
        if (a == b) return false;
        if (e[a] > e[b]) swap(a, b);
        e[a] += e[b]; e[b] = a;
        sumas[a] += sumas[b];
        return true;
    }
    bool mueve(int a, int b) {
        int act_a = actualizado[a], act_b = actualizado[b];
        if (find(act_a) == find(act_b)) return false;
        int raiz_a = find(act_a);
        e[raiz_a]++;
        sumas[raiz_a] -= a;
        act_a = actualizado[a] = adicionales++;
        sumas[act_a] = a;
        join(act_a, find(act_b));
        return true;
    }
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, q;
    cin >> n >> q;
    UF ufds(n + 1, q + 1);
    while(q--) {
        int op; cin >> op;
        if(op == 1) {
            int a, b; cin >> a >> b;
            ufds.join(a, b);
        }
        else if(op == 2) {
            int a, b; cin >> a >> b;
            ufds.mueve(a, b);
        }
        else {
            int a; cin >> a;
            cout << ufds.size(a) << ' ' << ufds.suma(a) << endl;
        }
    }
    return 0;
}
