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

struct FT {
	vector<ll> s;
	FT(int n) : s(n) {}
	void update(int pos, ll dif) { // a[pos] += dif
		for (; pos < sz(s); pos |= pos + 1) s[pos] += dif;
	}
	ll query(int pos) { // sum of values in [0, pos)
		ll res = 0;
		for (; pos > 0; pos &= pos - 1) res += s[pos-1];
		return res;
	}
	int lower_bound(ll sum) {// min pos st sum of [0, pos] >= sum
		// Returns n if no sum is >= sum, or -1 if empty sum is.
		if (sum <= 0) return -1;
		int pos = 0;
		for (int pw = 1 << 25; pw; pw >>= 1) {
			if (pos + pw <= sz(s) && s[pos + pw-1] < sum)
				pos += pw, sum -= s[pos-1];
		}
		return pos;
	}
};

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int casos = 1;
    while(casos--) {
        int n; cin >> n;
        vi v(n);
        set<int> distintos;
        map<int, int> index;
        for(int & x : v) {
            cin >> x;
            distintos.insert(x);
        }
        int s = 0;
        for(auto it = distintos.begin(); it != distintos.end(); it++) {
            int x = *it;
            index[x] = s++;
        }
        FT cuantos(s), medios(s);
        ll sol = 0;
        for(int i = n - 1; i >= 0; i--) {
            if(v[i] / 2 < *distintos.begin()) {
                cuantos.update(index[v[i]], 1);
                continue;
            }
            int id; //Queremos el index del elemento n / 2 o el más cercano por debajo
            if(index.count(v[i] / 2)) id = index[v[i] / 2];
            else {
                auto it = index.upper_bound(v[i] / 2);
                if(it != index.begin()) it--;
                id = it->second;
            }
            ll cant = cuantos.query(id + 1); //Cantidad de elementos <= n / 2 hasta el momento (posibles finales de cadena)
            ll med = medios.query(id + 1); //Cantidad de mitades de cadenas <= n / 2 (que con el elemento actual forman cadena)
            int cur_id = index[v[i]];
            // Añadimos al intervalo [0, cur_id] 1 elemento (cuantos) y cant mitades de cadena (el elemento actual formará cadena con todos ellos)
            if(cur_id < s - 1) {
                cuantos.update(cur_id, 1);
                medios.update(cur_id, cant);
            }
            sol += med;
        }
        cout << sol << endl;
    }
    return 0;
}