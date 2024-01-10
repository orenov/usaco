#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <set>

#define LOCAL false

/*
    Author: Oleksii Renov
    http://www.usaco.org/index.php?page=viewproblem2&cpid=857
*/

using namespace std;
using ll = long long int;

void run(int pos, vector<int>& a, vector<int>& b, set<int>& cnt, int sum_a) {
    if (pos == 0) {
        cnt.insert(sum_a);
        return;
    }

    if (pos % 2 == 0) {
        for (int i = 0; i < a.size(); ++i) {
            swap(a[i], a[a.size()-1]);
            sum_a -= a.back();
            b.push_back(a.back());
            a.pop_back();

            run(pos - 1, a, b, cnt, sum_a);

            a.push_back(b.back());
            b.pop_back();
            sum_a += a.back();
            swap(a[i], a[a.size()-1]);
        }
    } else {
        for (int i = 0; i < b.size(); ++i) {
            swap(b[i], b[b.size()-1]);
            sum_a += b.back();
            a.push_back(b.back());
            b.pop_back();

            run(pos - 1, a, b, cnt, sum_a);

            b.push_back(a.back());
            a.pop_back();
            sum_a -= b.back();
            swap(b[i], b[b.size()-1]);
        }
    }
}



int main() {
    if (!LOCAL) freopen("backforth.in", "r", stdin);

    vector<int> a(10, 0);
    vector<int> b(10, 0);
    set<int> cnt;

    for (int i = 0; i < a.size(); ++i) {
        cin >> a[i];
    }

    for (int i = 0; i < b.size(); ++i) {
        cin >> b[i];
    }

    run(4, a, b, cnt, 1000);

    if (!LOCAL) freopen("backforth.out", "w", stdout);
    std::cout << cnt.size() << '\n';
}
