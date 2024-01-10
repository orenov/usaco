#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <climits>
#include <string>
#include <set>


void modify(int bit, std::string& s, std::set<int>& fset, std::multiset<int>& mset) {
    if (false) {
    std::cout << "fset: ";
    for (auto it = fset.begin(); it != fset.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';

    std::cout << "mset: ";
    for (auto it = mset.begin(); it != mset.end(); ++it) {
        std::cout << *it << ' ';
    }
    std::cout << '\n';
    }

    if (bit == 0) {
        auto it = fset.upper_bound(bit);
        int r = *it;
        mset.erase(mset.find(r - bit));

        if (r == bit + 1) {
            int new_r = *fset.upper_bound(r);
            fset.erase(r);
            mset.erase(mset.find(new_r - r));
            mset.insert(new_r);
        } else {
            mset.insert(1);
            mset.insert(r - 1);
            fset.insert(1);
        }

        return;
    }

    if (fset.find(bit) != fset.end()) {
        //std::cout << bit << " try\n";
        auto it = fset.upper_bound(bit);
        int r = *it;
        --it;
        --it;
        int l = *it;

        //std::cout << l << ' ' << r << '\n';
        //std::cout << "in fset " << bit - l << ' ' << r - bit << '\n';
        mset.erase(mset.find(bit - l));
        mset.erase(mset.find(r - bit));
            
        // update
        fset.erase(bit);

        if (bit + 1 == s.size()) {
            mset.insert(r - l);
        } else if (r == bit + 1) {
            //std::cout << "in r == bit + 1\n";
            auto new_r = *fset.upper_bound(r);
            fset.erase(bit + 1);
            mset.erase(mset.find(new_r - r));
            mset.insert(new_r - l);
            //std::cout << "new_r: " << new_r << " r: " << r << " l: " << l << '\n';
        } else {
            fset.insert(bit + 1);
            mset.insert(bit + 1 - l);
            mset.insert(r - (bit + 1));
        }
        //std::cout << "exiting\n";
    } else {
        //std::cout << bit << " enter\n";
        auto it = fset.upper_bound(bit);
        int r = *it;
        --it;
        int l = *it;
            
        //std::cout << l << ' ' << r << '\n';

        mset.erase(mset.find(r - l));

        // update
        fset.insert(bit);
        if (bit + 1 == s.size()) {
            mset.insert(bit - l);
            mset.insert(r - bit);
        } else if (bit + 1 == r) {
            int new_r = *fset.upper_bound(r);
            fset.erase(r);
            mset.erase(mset.find(new_r - r));
            mset.insert(bit - l);
            mset.insert(new_r - bit);
        } else {
            fset.insert(bit + 1);
            mset.insert(bit - l);
            mset.insert(bit + 1 - bit);
            mset.insert(r - (bit + 1));
        }
    }
}

int main() {
    std::string s; std::cin >> s;
    int m; std::cin >> m;

    std::set<int> fset;
    std::multiset<int> mset;

    fset.insert(0);
    fset.insert(s.size());

    for (int i = 1; i < s.size(); ++i) {
        if (s[i] != s[i-1]) fset.insert(i);
    }

    for (auto it = fset.begin(); next(it) != fset.end(); ++it) {
        mset.insert(*next(it) - *it);
    }
    
    for (int i = 0; i < m; ++i) {
        int bit; std::cin >> bit; bit--;
        modify(bit, s, fset, mset);
        std::cout << *mset.rbegin() << ' ';
    }
    std::cout << '\n';
}
