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

/*-------------------------------------*/

int main() {
	int x, n, p;
	cin >> x >> n;
	x *= n + 1;
	while (n--) {
		cin >> p;
		x -= p;
	}
	cout << x;
	return 0;
}