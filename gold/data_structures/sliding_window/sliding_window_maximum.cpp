class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> fmap;
        vector<int> r;
        
        for (int i = 0; i < nums.size(); ++i) {
            fmap.insert(nums[i]);
            
            if (i >= k - 1) {
                r.push_back(*(fmap.rbegin()));
            }
            
            if (i >= k - 1) {
                fmap.erase(fmap.find(nums[i - k + 1]));
            }
        }
        
        return r;
    }
};