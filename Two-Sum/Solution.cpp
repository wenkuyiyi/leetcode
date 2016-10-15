class Solution {              // 12ms, beat 85%
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> other;
        vector<int> res;

        for (int i = 0; i<nums.size(); i++) {
            if (other.find(nums[i]) == other.end()) 
                 other[target-nums[i]] = i;
            else {                
                 res.push_back(other[nums[i]]);
                 res.push_back(i);
                 return res;
            }
        }
        return res;
    }
};
