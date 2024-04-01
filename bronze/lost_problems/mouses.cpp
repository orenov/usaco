#include <iostream>
#include <vector>
#include <algorithm>
#include <limits>
#include <cstdio>
#include <map>
#include <string>
#include <climits>

int main() {
    int a, b, c, n; std::cin >> a >> b >> c >> n;
    std::vector<long long> usb;
    std::vector<long long> ps;

    for (int i = 0; i < n; ++i) {
        long long price; std::cin >> price;
        std::string type; std::cin >> type;

        if (type == "USB") {
            usb.push_back(price);
        } else {
            ps.push_back(price);
        }
    }

    std::sort(usb.begin(), usb.end());
    std::sort(ps.begin(), ps.end());

    long long price = 0;
    int cnt = 0;

    int i = 0;
    int j = 0;
    
    while (a > 0 && i < usb.size()) {
        cnt++;
        price += usb[i];
        i++;
        a--;
    }

    while (b > 0 && j < ps.size()) {
        cnt++;
        price += ps[j];
        j++;
        b--;
    }

    while (c > 0 && (i < usb.size() || j < ps.size())) {
        if (i < usb.size() && j < ps.size()) {
            if (usb[i] < ps[j]) {
                cnt++;
                price += usb[i];
                i++;
                c--;
            } else {
                cnt++;
                price += ps[j];
                j++;
                c--;
            }
        } else if (i < usb.size()) {
            cnt++;
            price += usb[i];
            i++;
            c--;
        } else {
            cnt++;
            price += ps[j];
            j++;
            c--;
        }
    }

    std::cout << cnt << ' ' << price << '\n';
}
