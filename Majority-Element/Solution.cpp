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

class Solution {                          // sort类似  48ms
public:
    int majorityElement(vector<int>& nums) {
        nth_element(nums.begin(), nums.begin() + nums.size() / 2, nums.end());
        return nums[nums.size() / 2];
    } 
};     
// 使第n+1个元素X到达最终位置，并且比这个元素小的都排在X之前，比这个元素大的都排在X之后，但不能保证他们是有序的.

---------------------------------------------------------------------------------------

class Solution {             // Moore's voting algorithm,    时间复杂度为O(n).  效率最好20ms.
public:
int majorityElement(vector<int> &num) {       
    int majorityIndex = 0;
    for (int count = 1, i = 1; i < num.size(); i++) {
        num[majorityIndex] == num[i] ? count++ : count--;
        if (count == 0) {
            majorityIndex = i;
            count = 1;
        }
    }
    return num[majorityIndex];
    }
};

// http://blog.csdn.net/chfe007/article/details/42919017 实质是主元素和其他元素拼消耗，主元素一定能赢
---------------------------------------------------------------------------------------

class Solution {             // 纯算法思想
public:
    int majorityElement(vector<int>& nums) {
        return majority(nums, 0, nums.size() - 1);
    }
private:
    int majority(vector<int>& nums, int left, int right) {
        if (left == right) return nums[left];
        int mid = left + ((right - left) >> 1);
        int lm = majority(nums, left, mid);
        int rm = majority(nums, mid + 1, right);
        if (lm == rm) return lm;
        return count(nums.begin() + left, nums.begin() + right + 1, lm) > count(nums.begin() + left, nums.begin() + right + 1, rm) ? lm : rm;
    }
}; 

---------------------------------------------------------------------------------------
共六种方法。。
https://discuss.leetcode.com/topic/17446/6-suggested-solutions-in-c-with-explanations

