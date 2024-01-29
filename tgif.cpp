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
    unordered_map<string, int> meses;
    meses["JAN"] = 1;
    meses["FEB"] = 2;
    meses["MAR"] = 3;
    meses["APR"] = 4;
    meses["MAY"] = 5;
    meses["JUN"] = 6;
    meses["JUL"] = 7;
    meses["AUG"] = 8;
    meses["SEP"] = 9;
    meses["OCT"] = 10;
    meses["NOV"] = 11;
    meses["DEC"] = 12;
    vi dias_por_mes(13);
    dias_por_mes[1] = 31;
    dias_por_mes[2] = 28;
    dias_por_mes[3] = 31;
    dias_por_mes[4] = 30;
    dias_por_mes[5] = 31;
    dias_por_mes[6] = 30;
    dias_por_mes[7] = 31;
    dias_por_mes[8] = 31;
    dias_por_mes[9] = 30;
    dias_por_mes[10] = 31;
    dias_por_mes[11] = 30;
    dias_por_mes[12] = 31;
    unordered_map<string,int> dias;
    dias["MON"] = 1;
    dias["TUE"] = 2;
    dias["WED"] = 3;
    dias["THU"] = 4;
    dias["FRI"] = 5;
    dias["SAT"] = 6;
    dias["SUN"] = 7;
    int dia;
    string mes;
    cin >> dia >> mes;
    int nmes = meses[mes];
    string primerdia;
    cin >> primerdia;
    int nprimerviernes = (12 - dias[primerdia]) % 7 + 1;
    int ac = 0;
    for(int i = 1; i < nmes; i++) {
        ac += dias_por_mes[i];
    }
    ac += dia;
    ac += 14 - nprimerviernes;
    if(nmes <= 2) {
        if (ac % 7 == 0) cout << "TGIF";
        else cout << ":(";
    }
    else {
        if (ac % 7 == 0 || ac % 7 == 6) cout << "not sure";
        else cout << ":(";
    }
    return 0;
}