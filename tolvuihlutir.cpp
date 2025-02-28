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

struct Componente {
    Componente() {}
    Componente(string s, int precio, int rendimiento) : tipo(s), precio(precio), rendimiento(rendimiento) {}
    string tipo;
    int precio, rendimiento;
};

bool comprueba(int m, int k, int dinero, vector<Componente> & v) {
    map<string, int> por_comp;
    for(Componente & c : v) {
        if(c.rendimiento >= m) {
            if(!por_comp.count(c.tipo))
                por_comp[c.tipo] = c.precio;
            else
                por_comp[c.tipo] = min(por_comp[c.tipo], c.precio);
        }
    }
    int suma = 0;
    for(auto it : por_comp) {
        suma += it.second;
    }
    return por_comp.size() == k && suma <= dinero;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k, dinero; cin >> n >> k >> dinero;
    vector<string> componentes(k);
    for(string & s : componentes) cin >> s;
    vector<Componente> v(n);
    int max_rend = 0, min_rend = INT_MAX;
    set<int> s_rendimientos;
    rep(i,0,n) {
        string s; cin >> s;
        int a, b; cin >> a >> b;
        v[i] = Componente(s, a, b);
        max_rend = max(max_rend, b);
        min_rend = min(min_rend, b);
        s_rendimientos.insert(b);
    }
    vi rendimientos;
    for(int x : s_rendimientos) rendimientos.push_back(x);
    if(!comprueba(min_rend, k, dinero, v)) {
        cout << "O nei!\n";
    }
    else{
        int ini = 0, fin = sz(rendimientos);
        while(ini + 1 < fin) {
            int m = (ini + fin) / 2;
            if(comprueba(rendimientos[m], k, dinero, v))    // rendimientos[m] es válido -> la solución es >= m
                ini = m;
            else                                            // rendimientos[m] no es válido -> la solución es < m
                fin = m;
        }
        cout << rendimientos[ini] << '\n';
    }
    return 0;
}