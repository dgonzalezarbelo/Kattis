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
    int l; cin >> l; cin.get();
    stack<char> s;
    int fallo = -1;
    char c_fallo;
    string linea; getline(cin, linea);
    for(int i = 0; i < l; i++) {
        char c = linea[i];
        if(c == ' ') continue;
        if(c == '(' || c == '[' || c == '{')
            s.push(c);
        else {
            char apertura;
            switch(c) {
                case ')':
                    apertura = '(';
                    break;
                case ']':
                    apertura = '[';
                    break;
                case '}':
                    apertura = '{';
                    break;
            }
            if(!s.empty() && s.top() == apertura)
                s.pop();
            else if(fallo == -1) {
                fallo = i;
                c_fallo = c;
            }
        }
    }
    if(fallo == -1) cout << "ok so far\n";
    else cout << c_fallo << ' ' << fallo << '\n';
    return 0;
}