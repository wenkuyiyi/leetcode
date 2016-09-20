/**
#include<iostream>
#include<string>
#include<vector>
using namespace std;
**/
:set paste
set pastetoggle=<F2>
/**
#include<iostream>
#include<string>
#include<vector>
using namespace std;
**/

class Solution {
public:
	int removeDuplicates(vector<int>& nums) {
	    if(nums.size() == 0)    return 0;   //必须考虑长度为0的情况
	    
		int news = 0;
		unsigned int sized = nums.size();   // vs上<vector>size()返回值必须为unsighed int；
		for (unsigned int j = 1; j < nums.size(); j++)   // i,j的遍历
			if (nums[j] != nums[j - 1])
			{
				nums[news+1] = nums[j];
				news++;
				
			}
		for (int i = 0; i < sized - news - 1; i++)   
			nums.pop_back();
		return news + 1;
	}
	
};
