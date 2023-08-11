#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <string>

#define LOCAL false

/*
    Author: Oleksii Renov
*/

using namespace std;
using ll = long long int;

void fun1(vector<string>& a, vector<vector<int>>& b) {
    int n = a.size();
    int l, r;
    for (int l0 = 0; l0 <= 1000; ++l0) {
        int cur = l0;
        bool valid = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] == "on") {
                cur += b[i][1];
            } else if (a[i] == "off") {
                cur -= b[i][0];
            } else if (cur >= b[i][0] && cur <= b[i][1]) {

            } else {
                valid = false;
            }
        }

        if (valid) {
            l = l0;
            break;
        }
    }

    for (int l0 = 1000; l0 >= 0; --l0) {
        int cur = l0;
        bool valid = true;
        for (int i = 0; i < n; ++i) {
            if (a[i] == "on") {
                cur += b[i][0];
            } else if (a[i] == "off") {
                cur -= b[i][1];
            } else if (cur >= b[i][0] && cur <= b[i][1]) {

            } else {
                valid = false;
            }
        }

        if (valid) {
            r = l0;
            break;
        }
    }

    std::cout << l << ' ' << r << '\n';
}


void fun2(vector<string>& a, vector<vector<int>>& b) {
    int n = a.size();
    int l, r;
    for (int l0 = 0; l0 <= 1000; ++l0) {
        int cur = l0;
        bool valid = true;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == "on") {
                cur -= b[i][0];
            } else if (a[i] == "off") {
                cur += b[i][1];
            } else if (cur >= b[i][0] && cur <= b[i][1]) {

            } else {
                valid = false;
            }
        }

        if (valid) {
            l = l0;
            break;
        }
    }

    for (int l0 = 1000; l0 >= 0; --l0) {
        int cur = l0;
        bool valid = true;
        for (int i = n - 1; i >= 0; --i) {
            if (a[i] == "on") {
                cur -= b[i][1];
            } else if (a[i] == "off") {
                cur += b[i][0];
            } else if (cur >= b[i][0] && cur <= b[i][1]) {

            } else {
                valid = false;
            }
        }

        if (valid) {
            r = l0;
            break;
        }
    }

    std::cout << l << ' ' << r << '\n';
}

int main() {
    if (!LOCAL) freopen("traffic.in", "r", stdin);
    int n; cin >> n;
    vector<string> a(n, "");
    vector<vector<int>> b(n, vector<int>(2, 0));

    for (int i = 0; i < n; ++i) {
        cin >> a[i] >> b[i][0] >> b[i][1];
    }

    if (!LOCAL) freopen("traffic.out", "w", stdout);
    fun1(a, b);
    fun2(a, b);
}
