class Solution {                 // 有论文说明这种问题n=3时，时间复杂度最好O(n^2);
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> tmp;
        int len = nums.size();
        if (len<3) return res;
        
        int target = 0, left = 0, right = 0;  // 也可以front和back
        
        sort(nums.begin(), nums.end());
        for(int i = 0; i<len-2; i++) {
            if (nums[i] > 0)  break;  // ***很重要. 可缩短时间
            
            if (i>0 && (nums[i] == nums[i-1])) continue;  // 当有重复数字时，要跳过第二个和之后的，不然结果会重复.
            target = 0 - nums[i];
            
            left = i+1;
            right = len-1;
            while (left < right) {
                if (nums[left] +nums[right] == target){
                    tmp.push_back(nums[i]);
                    tmp.push_back(nums[left]);
                    tmp.push_back(nums[right]);
                    res.push_back(tmp);
                    tmp.clear();
                    while (left < right && nums[left+1] == nums[left])        // 用于防止[-2,0,0,2,2]这种.去除重复
                        ++left;
                    while (left < right && nums[right-1] == nums[right])
                        --right;
                    ++left;
                    --right;
                    
                }
                else if (nums[left] +nums[right] < target) left++;
                else right--;
            }
        }
        return res;
    }
};
