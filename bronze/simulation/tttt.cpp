#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <set>

#define LOCAL false

/*
    Author: Oleksii Renov
    http://www.usaco.org/index.php?page=viewproblem2&cpid=831
*/

using namespace std;
using ll = long long int;


int main() {
    if (!LOCAL) freopen("tttt.in", "r", stdin);
    vector<vector<int>> a(8, vector<int>(27, 0));

    string s1, s2, s3; cin >> s1 >> s2 >> s3;

    a[0][s1[0]-'A']++;
    a[0][s1[1]-'A']++;
    a[0][s1[2]-'A']++;
    
    a[1][s2[0]-'A']++;
    a[1][s2[1]-'A']++;
    a[1][s2[2]-'A']++;
    
    a[2][s3[0]-'A']++;
    a[2][s3[1]-'A']++;
    a[2][s3[2]-'A']++;

    a[3][s1[0]-'A']++;
    a[3][s2[0]-'A']++;
    a[3][s3[0]-'A']++;

    a[4][s1[1]-'A']++;
    a[4][s2[1]-'A']++;
    a[4][s3[1]-'A']++;
    
    a[5][s1[2]-'A']++;
    a[5][s2[2]-'A']++;
    a[5][s3[2]-'A']++;
    
    a[6][s1[0]-'A']++;
    a[6][s2[1]-'A']++;
    a[6][s3[2]-'A']++;

    a[7][s1[2]-'A']++;
    a[7][s2[1]-'A']++;
    a[7][s3[0]-'A']++;


    set<int> c1;
    set<pair<int,int>> c2;

    for (int i = 0; i < a.size(); ++i) {
        int n2 = -1;
        int n1 = -1;
        for (int k = 0; k < 27; ++k) {
            if (a[i][k] == 3) {
                c1.insert(k);
                break;
            }
            if (a[i][k] == 2) {
                n2 = k;
            }
            if (a[i][k] == 1) {
                n1 = k;
            }
        }

        if (n1 != -1 && n2 != -1) {
            c2.insert({min(n1,n2), max(n1,n2)});
        }
    }



    if (!LOCAL) freopen("tttt.out", "w", stdout);
    std::cout << c1.size() << '\n';
    std::cout << c2.size() << '\n';
}
