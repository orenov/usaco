#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>
#include <set>

#define LOCAL false

/*
    Author: Oleksii Renov
    http://www.usaco.org/index.php?page=viewproblem2&cpid=965
*/

using namespace std;
using ll = long long int;

void run(int pos, 
         vector<bool>& choose, 
         vector<string>& a, 
         vector<string>& cur, 
         vector<string>& ans, 
         map<string, set<string>>& fmap) 
{
    if (pos == a.size()) {
        if (ans.size() > 0) return;
        // validate
        bool valid = true;
        for (int i = 0; i < cur.size(); ++i) {
            for (auto cow: fmap[cur[i]]) {
                bool f1 = i > 0 && cur[i-1] == cow;
                bool f2 = i < cur.size() - 1 && cur[i+1] == cow;
                if (!f1 && !f2) valid = false;
            }
        }
        if (valid) ans = cur;

    } else {
        for (int i = 0; i < choose.size(); ++i) {
            if (!choose[i]) {
                choose[i] = true;
                cur.push_back(a[i]);
                run(pos + 1, choose, a, cur, ans, fmap);
                choose[i] = false;
                cur.pop_back();
            }
        }
    }
}


int main() {
    if (!LOCAL) freopen("lineup.in", "r", stdin);

    int n; cin >> n;
    map<string, set<string>> fmap;
    fmap["Bessie"] = {};
    fmap["Buttercup"] = {};
    fmap["Belinda"] = {};
    fmap["Beatrice"] = {};
    fmap["Bella"] = {};
    fmap["Blue"] = {};
    fmap["Betsy"] = {};
    fmap["Sue"] = {};
    
    vector<string> a{"Beatrice", "Belinda", "Bella", "Bessie", "Betsy", "Blue", "Buttercup", "Sue"};
    sort(a.begin(), a.end());


    for (int i = 0; i < n; ++i) {
        string s1, s2, s3, s4, s5, s6;
        cin >> s1 >> s2 >> s3 >> s4 >> s5 >> s6;
        fmap[s6].insert(s1);
    }

    vector<string> answer;
    vector<string> cur;
    vector<bool> choose(8, false);

    run(0, choose, a, cur, answer, fmap);

    if (!LOCAL) freopen("lineup.out", "w", stdout);
    for (int i = 0; i < answer.size(); ++i) {
        std::cout << answer[i] << '\n';
    }
}
