#include <iostream>
#include <vector>

/*
a b  c d
0 0  1 0 = 1
0 0  0 1 = -1

0 1  1 0 = a > b 
0 1  0 1 = a > b

1 0  1 0 = a > b 
1 0  0 1 = a > b

1 1  1 0 = -1
1 1  0 1 = 1
*/

int ask(int a, int b) {
    std::cout << "? " << a << " " << b << '\n';
    fflush(stdout);
    int answer;
    std::cin >> answer;
    return answer;
}

int main() {
    int a = 0;
    int b = 0;
    int sign = ask(0, 0); // we know which is higher number right now
    for (int i = 29; i >= 0; --i) {
        int v1 = ask(a ^ (1 << i), b);
        int v2 = ask(a, b ^ (1 << i));
        if (v1 == v2) {
            if (sign == 1) {
                a |= 1 << i;
            } else {
                b |= 1 << i;
            }
            sign = v1;
        } else {
            if (v1 == -1 && v2 == 1) {
                a |= 1 << i;
                b |= 1 << i;
            }
        }
    }

    std::cout << "! " << a << ' ' << b << '\n';
    fflush(stdout);
}