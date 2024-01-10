#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

// http://www.usaco.org/index.php?page=viewproblem2&cpid=1323

std::vector<int> same(int x) {
    std::vector<int> r;
    if (x % 2 == 1) {
        r.push_back(0);
        r.push_back(2);
        x -= 1;
        while (x > 0) {
            r.push_back(r.back() + 2);
            x -= 2;
        }
    } else {
        r.push_back(1);
        r.push_back(3);
        x -= 2;
        while (x > 0) {
            r.push_back(r.back() + 2);
            x -= 2;
        }
    }
    return {r[0], r.back()};
}

std::vector<int> diff(int x) {
    if (x == 1) {
        return {1,1};
    }
    x -= 1;
    return same(x);
}

std::vector<int> plus(std::vector<int> x, int y) {
    std::vector<int> r;
    while (x[0] <= x[1]) {
        r.push_back(x[0] + y);
        x[0] += 2;
    }
    return r;
}

std::vector<int> union_fun(const std::vector<int>& x, const std::vector<int>& y) {
    std::vector<int> r;
    
    for (int i = 0; i < x.size(); ++i) {
        r.push_back(x[i]);
    }
    for (int i = 0; i < y.size(); ++i) {
        r.push_back(y[i]);
    }

    std::sort(r.begin(), r.end());
    std::vector<int> r2;
    for (int i = 0; i < r.size(); ++i) {
        if (r2.size() > 0 && r2.back() == r[i]) {
            // continue
        } else {
            r2.push_back(r[i]);
        }
    }

    return r2;
}

int main() {
    int n; std::cin >> n;
    std::string s; std::cin >> s;
    std::vector<std::string> ss;

    if (s[0] == 'F' || s.back() == 'F') {
        if (s[0] == 'F' && s.back() == 'F') {
            s[0] = 'B'; 
            s[s.size()-1] = 'B';
            ss.push_back(s);
            s[0] = 'B';
            s[s.size()-1] = 'E';
            ss.push_back(s);
            
            s[0] = 'E'; 
            s[s.size()-1] = 'B';
            ss.push_back(s);
            s[0] = 'E';
            s[s.size()-1] = 'E';
            ss.push_back(s);
        } else if (s[0] == 'F') {
            s[0] = 'B'; 
            ss.push_back(s);
            s[0] = 'E';
            ss.push_back(s);
        } else if (s.back() == 'F') {
            s[s.size() - 1] = 'B'; 
            ss.push_back(s);
            s[s.size() - 1] = 'E';
            ss.push_back(s);
        }
    } else {
        ss.push_back(s);
    }

    std::vector<int> r;
    for (int i = 0; i < ss.size(); ++i) {
        std::string t = ss[i];
        std::vector<int> tmp = {0, 0};
        int j = 0;
        int pos = 0;

        // guarantee t[j] is B or E
        while (j < t.size() - 1) {
            int cnt = 0;
            if (t[j] == t[j+1]) {
                pos++;
                j++;
            } else if (t[j+1] == 'F') {
                int cnt = 0;
                int old_j = j;
                j++;
                while (t[j] == 'F') {
                    j++; cnt++;
                }
                if (t[j] == t[old_j]) {
                    auto val = same(cnt);
                    tmp[0] += val[0];
                    tmp[1] += val[1];
                } else {
                    auto val = diff(cnt);
                    tmp[0] += val[0];
                    tmp[1] += val[1];
                }
            } else {
                j++;
            }
        }
        //std::cout << tmp[0] << ' ' << tmp[1] << '\n';
        tmp = plus(tmp, pos);
        //for (int i = 0; i < tmp.size(); ++i) {
        //    std::cout << tmp[i] << ' ';
        //}
        //std::cout << '\n';

        r = union_fun(r, tmp);
    }

    std::sort(r.begin(), r.end());
    std::cout << r.size() << '\n';
    for (int i = 0; i < r.size(); ++i) {
        std::cout << r[i] << '\n';
    }
}