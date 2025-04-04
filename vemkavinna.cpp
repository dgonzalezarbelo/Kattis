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

bool ganaA = false, ganaB = false;

bool victoria(vector<string> const& mat) {
    rep(i,0,3) {
        if(mat[i][0] == mat[i][1] && mat[i][0] == mat[i][2] && mat[i][0] != '_') {
            if(mat[i][0] == 'X') ganaA = true;
            else ganaB = true;
            return true;
        }
    }
    rep(j,0,3) {
        if(mat[0][j] == mat[1][j] && mat[0][j] == mat[2][j] && mat[0][j] != '_') {
            if(mat[0][j] == 'X') ganaA = true;
            else ganaB = true;
            return true;
        }
    }
    if(mat[0][0] == mat[1][1] && mat[0][0] == mat[2][2] && mat[0][0] != '_') {
        if(mat[0][0] == 'X') ganaA = true;
        else ganaB = true;
        return true;
    }
    if(mat[0][2] == mat[1][1] && mat[0][2] == mat[2][0] && mat[0][2] != '_') {
        if(mat[0][2] == 'X') ganaA = true;
        else ganaB = true;
        return true;
    }
    return false;
}

void solve(vector<string> & mat, bool turno) {
    if(victoria(mat)) return;
    rep(i,0,3) rep(j,0,3) {
        if(mat[i][j] == '_') {
            if(turno)
                mat[i][j] = 'X';
            else
                mat[i][j] = 'O';
            solve(mat, !turno);
            mat[i][j] = '_';
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    vector<string> mat(3, "aaa");
    map<string, int> lmao;
    rep(i,0,3) {
        string a, b, c; cin >> a >> b >> c;
        lmao[a]++;
        lmao[b]++;
        lmao[c]++;
        mat[i] = a + b + c;
    }
    bool turno;
    if(lmao["X"] == lmao["O"]) turno = true;
    else turno = false;
    solve(mat, turno);
    if(ganaA && ganaB) cout << "Abdullah och Johan kan vinna\n";
    else if(ganaA) cout << "Johan kan vinna\n";
    else if(ganaB) cout << "Abdullah kan vinna\n";
    else cout << "ingen kan vinna\n";
    return 0;
}