#include <iostream>
#include <vector>
#include <string>
#include <map>

int main() {
    std::string s; std::cin >> s;
    std::map<int, int> fmap;
    fmap[0] = 1;

    int64_t cnt = 0;
    int64_t val = 0;
    for (int i = 0; i < s.size(); ++i) {
        val ^= (1 << (s[i] - '0'));
        cnt += fmap[val];
        fmap[val]++;
    }

    std::cout << cnt << '\n';
}