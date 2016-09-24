class Solution {                    // hash
public:
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> counts;   // 这里用vector不合适, 因为这个不是顺序的问题, 数字可能很大.
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            counts[nums[i]] = counts[nums[i]] + 1;   // vector 要用push_back加新元素, 只map才能用下标加.
            if (counts[nums[i]] > n / 2)          //  返回关键字为nums[i]的元素, 如果nums[i]不存在则添加并初始化.    
                return nums[i];
        }
    }
};

-------------------------------------------------------------------------------------

class Solution {                          // sort类似
public:
    int majorityElement(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        return nums[nums.size() / 2];
    } 
};     
// 使第n+1个元素X到达最终位置，并且比这个元素小的都排在X之前，比这个元素大的都排在X之后，但不能保证他们是有序的.

---------------------------------------------------------------------------------------

共六种方法。。
https://discuss.leetcode.com/topic/17446/6-suggested-solutions-in-c-with-explanations

