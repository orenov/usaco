#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <map>

#define LOCAL true

/*
    Author: Oleksii Renov
*/

using namespace std;
using ll = long long int;

int main() {
    int T; cin >> T;
    for (int qq = 1; qq <= T; ++qq) {
        int N, C, P;
        cin >> N >> C >> P;

        map<string, vector<string>> fmap;
        for (int i = 0; i < N; ++i) {
            string s1, s2; cin >> s1 >> s2;
            fmap[s2].push_back(s1);
        }

        string s = "";
        int len = 0;
        int cnt1 = min(fmap["noun"].size(), fmap["intransitive-verb"].size());
        int cnt2 = min(fmap["noun"].size() / 2, fmap["transitive-verb"].size());

        for (int i = cnt1; i >= 0; --i) {
            for (int j = cnt2; j >= 0; --j) {
                // i - number of type 1
                // j - number of type 2
                // all type 2 are 3 length except last one
                int n = fmap["noun"].size();
                int v1 = fmap["transitive-verb"].size();
                int v2 = fmap["intransitive-verb"].size();
                int conj = fmap["conjunction"].size();
                
                // type1 check
                if (min(n, v2) < i) continue;
                n -= i;
                v2 -= i;

                // type2 check
                if (min(n / 2, v1) < j) continue;
                n -= 2 * j;
                v1 -= j;

                // conjunction use
                int conj_use = min(conj, (i + j) / 2);

                // periods required
                int periods = i + j - conj_use;
                if (periods > P) continue;

                int cur_len = i * 2 + j * 3 + conj_use + ((j > 0) ? min(n, C) : 0);

                if (cur_len > len) {
                    len = cur_len;
                    // string construct
                    vector<string> n_map = fmap["noun"];
                    vector<string> v1_map = fmap["transitive-verb"];
                    vector<string> v2_map = fmap["intransitive-verb"];
                    vector<string> conj_map = fmap["conjunction"];
                    vector<string> sent;
                    int ii = i;
                    int jj = j;

                    while (ii > 0) {
                        sent.push_back(n_map.back() + " " + v2_map.back());
                        n_map.pop_back();
                        v2_map.pop_back();
                        ii--;
                    }
                    
                    while (jj > 1) {
                        string tmp = n_map.back();
                        n_map.pop_back();
                        tmp += " " + v1_map.back() + " " + n_map.back();
                        sent.push_back(tmp);
                        n_map.pop_back();
                        v1_map.pop_back();
                        jj--;
                    }
                    
                    if (jj == 1) {
                        int t = min(n, C);
                        string tmp = n_map.back();
                        n_map.pop_back();
                        tmp += " " + v1_map.back() + " " + n_map.back();
                        n_map.pop_back();
                        v1_map.pop_back();
                        
                        while(t > 0) {
                            tmp += ", " + n_map.back();
                            n_map.pop_back();
                            t--;
                        }

                        sent.push_back(tmp);
                    }

                    vector<string> sent2;
                    while (conj_use > 0) {
                        string s1 = sent.back();
                        sent.pop_back();
                        string s2 = sent.back();
                        sent.pop_back();
                        sent2.push_back(s1 + " " + conj_map.back() + " " + s2);
                        conj_map.pop_back();
                        conj_use--;
                    }

                    for (auto ff: sent2) {
                        sent.push_back(ff);
                    }


                    string final = "";
                    for (int q = 0; q < sent.size(); ++q) {
                        final += sent[q] + ".";
                        if (q != sent.size() - 1) {
                            final += " ";
                        }
                    }

                    s = final;
                }


            }
        }


        std::cout << len << '\n';
        std::cout << s << '\n';
    }
}
