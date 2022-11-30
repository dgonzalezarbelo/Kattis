#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
#include <map>
#include <unordered_set>
#include <set>
#include <iomanip>
#include <climits>
#include <cmath>
#include <list>
#include <queue>
#include <stack>
#include <deque>
#include <bitset>
#include <algorithm>
#pragma warning (disable : 4996)

using namespace std;
typedef vector<int> vi;
typedef pair<int, int> ii;
typedef vector<ii> vii;
typedef long long ll;
typedef vector<ll> vll;

/*-------------------------------------*/

vii quesos;
int w, h;
ll mod = 1000000007;

vector<ll> factoriales;

ll elevar(ll a, ll pot) {
    if (a == 1) return 1;
    if (pot == 0) return 1;
    if (pot == 1) return a;
    ll b = elevar(a, pot / 2);
    b %= mod;
    if (pot % 2 == 0) return (b * b) % mod;
    else return (((b * b) % mod) * a) % mod;
}

bool posible(int x1, int y1, int x2, int y2) {
    return x1 <= x2 && y1 <= y2;
}

ll paths(int x1, int y1, int x2, int y2) {
    ll num = factoriales[y2 + x2 - y1 - x1];
    ll den = factoriales[y2 - y1] * factoriales[x2 - x1];
    den %= mod;
    return (num * elevar(den, mod - 2)) % mod;
}

ll solve(int curr, int depth, int max_depth, int prev_x, int prev_y) {
    ll sol = paths(prev_x, prev_y, quesos[curr].first, quesos[curr].second);
    if (depth == max_depth) {
        sol *= paths(quesos[curr].first, quesos[curr].second, w, h);
        sol %= mod;
        return sol;
    }
    bool alguno_posible = false;
    ll sol_aux = 0;
    for (int i = curr + 1; i < quesos.size(); i++) {
        if (posible(quesos[curr].first, quesos[curr].second, quesos[i].first, quesos[i].second)) {
            alguno_posible = true;
            sol_aux += solve(i, depth + 1, max_depth, quesos[curr].first, quesos[curr].second);
            sol_aux %= mod;
        }
    }
    sol *= sol_aux;
    sol %= mod;
    if (alguno_posible) return sol;
    else return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> w >> h;
    int n;
    cin >> n;
    quesos.assign(n, { -1,-1 });
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        quesos[i] = { a, b };
    }
    sort(quesos.begin(), quesos.end());
    factoriales.assign(100002, 1);
    for (ll i = 2; i < factoriales.size(); i++) {
        factoriales[i] = factoriales[i - 1] * i;
        factoriales[i] %= mod;
    }
    int signo = -1;
    ll sol = 0;
    for (int max_depth = 1; max_depth <= quesos.size(); max_depth++) {
        signo *= -1;
        ll curr_sol = 0;
        for (int i = 0; i < quesos.size(); i++) {
            curr_sol += solve(i, 1, max_depth, 1, 1);
            curr_sol %= mod;
        }
        if (signo == -1) {
            sol += mod - curr_sol;
        }
        else {
            sol += curr_sol;
        }
        sol = ((sol % mod) + mod) % mod;
    }
    cout << sol << '\n';
    return 0;
}