#include <vector>
#include <iostream>
#include <string>

std::vector<int> parse() {
    //std::cout << "Calling parse\n";
    int n = 0; std::cin >> n;
    std::vector<int> out(n, 0);

    for (int i = 0; i < out.size(); ++i) {
        std::string s; std::cin >> s;
        for (int j = 0; j < s.size(); ++j) {
            out[i] |= 1 << (s[j] - '0');
        }
    }
    return out;
}

bool checkOut(std::vector<int>& out, int val) {
    for (int i = 0; i < out.size(); ++i) {
        if ((out[i] & val) == val) {
            return true;
        }
    }

    return false;
}

int main() {
    int k = 0;
    while (true) {
        std::cout << "next 0 1\n";
        fflush(stdout);
        auto out = parse();

        std::cout << "next 1\n";
        fflush(stdout);
        out = parse();

        if (checkOut(out, 3)) {
            break;
        }
        k++;
    }

    while (true) {
        std::cout << "next 0 1 2 3 4 5 6 7 8 9\n";
        fflush(stdout);
        if (parse().size() == 1) {
            break;
        }
    }

    std::cout << "done\n";
    fflush(stdout);

    return 0;
}