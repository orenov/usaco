#include <iostream>
#include <vector>

bool is_prime(int x) {
    if (x <= 2) return true;
    for (int i = 2; i * i <= x; ++i) {
        if (x % i == 0) return false;
    }
    return true;
}

int run(int x) {
    if (is_prime(x)) return 1;

    if (x % 2 == 0) {
        // lose - take minimum val so that rest is not prime
        for (int i = 1; i <= x; ++i) {
            if (is_prime(i) && !(is_prime(x - i))) {
                return 1 + run(x - i);
            }
        }
        return 1 + run(x - 1);
    } else {
        // win
        for (int i = x; i >= 1; --i) {
            if (is_prime(i) && !(is_prime(x - i))) {
                return 1 + run(x - i);
            }
        }

        return 1 + run(x - 1);
    }

    return 0; // Error
}


int main() {
    int T; std::cin >> T;
    for (int t = 0; t < T; ++t) {
        int n; std::cin >> n;
        std::vector<int> a(n, 0);
        for (int i = 0; i < n; ++i) {
            std::cin >> a[i];
        }

        int minimum = 1e9;
        for (int i = 0; i < n; ++i) {
            a[i] = run(a[i]);
            minimum = std::min(minimum, a[i]);
        }

        if (minimum % 2 == 1) {
            std::cout << "Farmer John\n"; 
        } else {
            std::cout << "Farmer Nhoj\n";
        }
        
    }
}