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

vi v, al, visited, en_bucle;
vvi al_inv;

void bucle(int i, unordered_set<int> & s, ll & tam_bucle) {
    visited[i] = true;
    tam_bucle++;
    s.insert(v[i]);
    if(!visited[al[i]]) bucle(al[i], s, tam_bucle);
}

vi order, component;

void dfs1(int i) {
    visited[i] = true;
    if(al[i] != -1 && !visited[al[i]])
        dfs1(al[i]);
    order.push_back(i);
}

void dfs2(int i) {
    visited[i] = true;
    component.push_back(i);
    for (auto u : al_inv[i])
        if (!visited[u])
            dfs2(u);
}

ll dfs3(int i, unordered_set<int> & s_componente, unordered_set<int> & nuevos, ll & sol) {
    visited[i] = true;
    bool nuevo = false;
    if(!s_componente.count(v[i]) && !nuevos.count(v[i])) {
        nuevos.insert(v[i]);
        nuevo = true;
    }
    ll acum = 1;
    for(int b : al_inv[i]) {
        if(!en_bucle[b]) acum += dfs3(b, s_componente, nuevos, sol); //Si es parte del bucle nos lo saltamos, ya se considera en el otro caso
    }
    if(nuevo) {
        sol += acum;
        nuevos.erase(v[i]); //Lo quito por si al explorar otra rama disjunta se encuentra de nuevo
    }
    return acum;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int n; cin >> n;
    v.assign(n, -1);
    al.assign(n, -1);
    en_bucle.assign(n, 0);
    al_inv.assign(n, {});
    order.assign(0, 0);
    for(int & x : v)
        cin >> x;
    for(int i = 0; i < n; i++) {
        int salto = v[i];
        if(i + salto < n && i + salto >= 0) {
            al[i] = i + salto;
            al_inv[i + salto].push_back(i);
        }
    }
    //Buscamos SCCs (bucles en este caso)
    visited.assign(n, false);
    for(int i = 0; i < n; i++) {
        if(!visited[i])
            dfs1(i);
    }
    visited.assign(n, false);
    reverse(order.begin(), order.end());
    int n_componentes = 0;
    vi componente(n, -1);
    vector<unordered_set<int>> elementos_por_componente;
    for(int i : order) {
        if(!visited[i]) {
            dfs2(i);
            if(sz(component) > 1) {
                unordered_set<int> elementos;
                for(int x : component) {
                    en_bucle[x] = true;
                    componente[x] = n_componentes;
                    elementos.insert(v[x]);
                }
                elementos_por_componente.push_back(elementos);
                n_componentes++;
            }
            component.assign(0, 0); //Vaciar la componente
        }
    }
    visited.assign(n, false);
    ll sol = 0;
    for(int i = 0; i < n; i++) {
        if(!visited[i]) {
            //Por cada bucle se añade a la solución el número de nodos en el bucle multiplicado por el número de elementos distintos en el bucle
            if(en_bucle[i]) {
                unordered_set<int> s;
                ll tam_bucle = 0;
                bucle(i, s, tam_bucle);
                sol += ll(sz(s)) * tam_bucle;
            }
            else {
                if(al[i] != -1 && !en_bucle[al[i]]) continue; //Solo quiero empezar desde el final de la cadena
                if(al[i] == -1) { //Se sale
                    unordered_set<int> s_componente, nuevos;
                    dfs3(i, s_componente, nuevos, sol);
                }
                else { //En este caso no se sale pero se mete a un bucle
                    int u = al[i]; //Este está en un bucle
                    bool se_ha_visitado_antes = visited[u];
                    unordered_set<int> nuevos;
                    //Para cada elemento en la cadena que no esté en la SCC de u se suma como en el caso anterior
                    //Para cada elemento distinto de la SCC de u se suman todos los de la cadena
                    ll acum = dfs3(u, elementos_por_componente[componente[u]], nuevos, sol);
                    acum--; //Quitamos u
                    sol += ll(sz(elementos_por_componente[componente[u]])) * acum;
                    visited[u] = se_ha_visitado_antes;
                }
            }
        }
    }
    cout << sol << endl;
    return 0;
}