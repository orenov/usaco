#include <iostream>
#include <vector>
#include <map>
#include <random>
#include <deque>

std::vector<int> brute(std::vector<std::vector<int>>& a) {
    std::vector<int> res;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i][0] == 1) {
            res.push_back(a[i][1]);
        } else {
            for (int j = 0; j < res.size(); ++j) {
                if (res[j] == a[i][1]) {
                    res[j] = a[i][2];
                }
            }
        }
    }

    return res;
}

bool compare(std::vector<int>& a, std::vector<int>& b) {
    if (a.size() != b.size()) return false;
    for (int i = 0; i < a.size(); ++i) {
        if (a[i] != b[i]) return false;
    }
    return true;
}


std::vector<int> optimal_new(std::vector<std::vector<int>>& a) {
    std::vector<std::deque<int>> from_to(5e5 + 1, std::deque<int>());

    std::map<int, std::vector<int>> jump_over_map;
    std::vector<int> res;

    for (int i = 0; i < a.size(); ++i) {
        if (a[i][0] == 2) {
            from_to[a[i][1]].push_back(a[i][2]);
        }
    }

    for (int i = 0; i < from_to.size(); ++i) from_to[i].push_back(i);


    std::cout << "=======\n";
    
    for (int i = 0; i < a.size(); ++i) {
        std::cout << "Query: " << a[i][0] << ' ' << a[i][1] << ' ' << a[i][2] << '\n';
        if (a[i][0] == 1) {
            int val = a[i][1];
            while (val != from_to[val].front()) {
                {
                    // jump
                    int jump_from = val;
                    int jump_over = from_to[val].front();
                    int jump_dest = from_to[from_to[val].front()].front();

                    if (jump_over != jump_dest) {
                        jump_over_map[jump_over].push_back(jump_from);
                        from_to[jump_from].pop_front();
                        from_to[jump_from].push_front(jump_dest);
                    }
                }
                // update val
                val = from_to[val].front();
            }
            std::cout << "Out value: " << val << '\n';
            res.push_back(val);
        } else {
            // delete this edge
            int from = a[i][1];
            int to   = a[i][2];

            from_to[from].pop_front();

            std::vector<int> waiting_updates{from};

            while (waiting_updates.size() > 0) {
                int v = waiting_updates.back(); waiting_updates.pop_back();

                for (int j = 0; j < jump_over_map[v].size(); ++j) {
                    int skip = jump_over_map[v][j];
                    from_to[skip].pop_back();
                    from_to[skip].push_back(v);
                    waiting_updates.push_back(skip);
                }

                jump_over_map[v].clear();
            }
        }
    }

    return res;
}


std::vector<int> optimal(std::vector<std::vector<int>>& a) {
    std::vector<int> from_to(5e5 + 1, 0);

    int n = 5e5 + 1;
    for (int i = 0; i < n; ++i) {
        from_to[i] = i;
    }

    std::map<int, std::vector<int>> jump_over_map;

    std::vector<int> res;
    
    for (int i = a.size() - 1; i >= 0; --i) {
        if (a[i][0] == 1) {
            int val = a[i][1];
            while (false && val != from_to[val]) {
                if (false) {
                    // jump
                    int jump_from = val;
                    int jump_over = from_to[val];
                    int jump_dest = from_to[from_to[val]];

                    if (jump_over != jump_dest) {
                        jump_over_map[jump_over].push_back(jump_from);
                        from_to[jump_from] = jump_dest;
                    }
                }
                // update val
                val = from_to[val];
            }

            res.push_back(from_to[val]);
        } else {
            int from = a[i][1];
            int to = a[i][2];

            while (to != from_to[to]) {
                int v1 = to;
                int v2 = from_to[to];
                int v3 = from_to[from_to[to]];

                // update
                if (v2 != v3) {
                    jump_over_map[v2].push_back(v1);
                }

                to = from_to[to];
            }

            //from_to_original[from] = to;
            
            from_to[from] = to;

            if (false) {
            std::vector<int> waiting_updates{from};

            while (waiting_updates.size() > 0) {
                int v = waiting_updates.back(); waiting_updates.pop_back();

                for (int j = 0; j < jump_over_map[v].size(); ++j) {
                    int skip = jump_over_map[v][j];
                    from_to[skip] = from; // can be just v ???
                    waiting_updates.push_back(skip);
                }

                jump_over_map[v].clear();
            }
            }
        }
    }

    for (int i = 0; i < res.size() / 2; ++i) {
        std::swap(res[i], res[res.size() - i - 1]);
    }

    return res;
}

std::vector<int> optimal_brand(std::vector<std::vector<int>>& a) {
    std::vector<int> from_to(5e5 + 1, 0);

    int n = 5e5 + 1;
    for (int i = 0; i < n; ++i) {
        from_to[i] = i;
    }

    std::vector<int> res;    
    for (int i = a.size() - 1; i >= 0; --i) {
        if (a[i][0] == 1) {
            res.push_back(from_to[a[i][1]]);
        } else {
            int from = a[i][1];
            int to = a[i][2];

            from_to[from] = from_to[to];
        }
    }

    for (int i = 0; i < res.size() / 2; ++i) {
        std::swap(res[i], res[res.size() - i - 1]);
    }

    return res;
}

void test() {
    int n = 40;
    std::mt19937 generator;
    std::uniform_int_distribution<int64_t> random_type(1, 2);
    std::uniform_int_distribution<int64_t> random_val(1, n);

    for (int i = 0; i < n; ++i) {
        std::cout << "Test case #" << i + 1 << ":\n";
        std::vector<std::vector<int>> a( n, std::vector<int>(3, 0));
        for (int j = 0; j < a.size(); ++j) {
            a[j][0] = random_type(generator);
            a[j][1] = random_val(generator);
            a[j][2] = random_val(generator);
        }

        auto res1 = optimal_brand(a);
        auto res2 = brute(a);

        if (!compare(res1, res2)) {
            for (int j = 0; j < a.size(); ++j) {
                std::cout << a[j][0] << ' ' << a[j][1] << ' ' << a[j][2] << '\n';
            }
            std::cout << "Brute:\n";
            for (int j = 0; j < res2.size(); ++j) {
                std::cout << res2[j] << ' ';
            }
            std::cout << '\n';

            std::cout << "Optimal:\n";
            for (int j = 0; j < res1.size(); ++j) {
                std::cout << res1[j] << ' ';
            }
            std::cout << '\n';
            return;
        }
    }

}


int main() {
    //test();

    int q; std::cin >> q;
    std::vector<std::vector<int>> a(q, std::vector<int>(3, 0));
    for (int i = 0; i < q; ++i) {
        std::cin >> a[i][0] >> a[i][1];
        if (a[i][0] == 2) std::cin >> a[i][2];
    }

    std::vector<int> res = optimal_brand(a);

    for (int i = 0; i < res.size(); ++i) {
        std::cout << res[i] << ' ';
    }
    std::cout << '\n';
}