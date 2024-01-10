#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <map>
#include <list>
#include <stack>
#include <sstream>
#include <string>
#include <fstream>
#include <set>
#include <iomanip>
#include <math.h>
#include <queue>

using namespace std;
using ll = long long int;

// https://codeforces.com/contest/1520/submission/115361490


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int n, t; cin >> n >> t;
    int k; cin >> k;
    // need to find first occurence of sum = k;
    // basically lower_bound of this
    // [1,0,1,1,0,1]
    int r = n;
    int l = 1;

    while (r > l) {
        int m = (l + r) / 2;
        cout << "? " << l << ' ' << m  << endl;
        cout.flush();
        int res; 
        cin >> res;
        if (res == -1) return 0;

        res = m - l + 1 - res; // number of zeros

        if (res >= k) {
            r = m;
        } else {
            l = m + 1;
            k = k - res;
        }
    }

    cout << "! "  << r << endl;
    return 0;
}