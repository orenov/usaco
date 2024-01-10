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

void run(vector<int>& nums, int& cnt) {
    //std::cout << nums.size() << '\n';
    if (nums.size() == 1) {
        if (nums[0] <= 24 && cnt <= nums[0]) {
                    //std::cout << nums[0] << '\n';

            cnt = nums[0];
        }
        return;
    }

    for (int i = 0; i < nums.size(); ++i) {
        for (int j = i + 1; j < nums.size(); ++j) {
            //std::cout << i << ' ' << j << '\n';
            int v1 = nums[i];
            int v2 = nums[j];

            swap(nums[j], nums[nums.size() - 1]);
            nums.pop_back();
            swap(nums[i], nums[nums.size() - 1]);
            nums.pop_back();

            // +
            {
                nums.push_back(v1 + v2);
                run(nums, cnt);
                nums.pop_back();
            }

            // -
            {
                nums.push_back(v1 - v2);
                run(nums, cnt);
                nums.pop_back();
            }

            // - 
            {
                nums.push_back(v2 - v1);
                run(nums, cnt);
                nums.pop_back();
            }

            // *
            {
                nums.push_back(v2 * v1);
                run(nums, cnt);
                nums.pop_back();
            }

            // /
            if (v2 != 0 && v1 % v2 == 0) {
                nums.push_back(v1 / v2);
                run(nums, cnt);
                nums.pop_back();
            }

            // /
            if (v1 != 0 && v2 % v1 == 0) {
                nums.push_back(v2 / v1);
                run(nums, cnt);
                nums.pop_back();
            }

            nums.push_back(v1);
            swap(nums[i], nums[nums.size() - 1]);
            nums.push_back(v2);
            swap(nums[j], nums[nums.size() - 1]);
        }
    }

}

int main() {
    int n; cin >> n;
    vector<vector<int>> a(n, vector<int>(4, 0));
    for (int i = 0; i < n; ++i) { 
        for (int j = 0; j < 4; ++j) {       
            cin >> a[i][j];
        }
    }

    for (int i = 0; i < a.size(); ++i) {
        int cnt = 0;
        run(a[i], cnt);
        std::cout << cnt << '\n';
    }

}
