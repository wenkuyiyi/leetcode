class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int len = prices.size();
        if (len == 0 || len == 1) return 0;
        
        int min = prices[0], difference = 0;
        for (int i = 1; i<len; i++) {
            if (prices[i] < min) min = prices[i];
            else 
                if (prices[i]-min > difference) difference = prices[i]-min;
        }
        return difference;
    }
};
// 这其实是动态规划DP的思想. diff[j+1] = max{diff[j], prices[i+1]-min}


// 算法导论上有通过 走势变化 的思想的方法，不太懂(第四章)  这里数组元素trend[i] = price[i]-price[i-1]
    int maxProfit(vector<int>& prices) {
        int maxCur = 0, maxSoFar = 0;
        for(int i = 1; i < prices.size(); i++) {
            maxCur = Math.max(0, maxCur += trend[i]); 
                                            //对走势而言，当 profit<0 对之后发展只有负作用, 可以删除, 从下一个重新计算
            maxSoFar = Math.max(maxCur, maxSoFar);       // 已知的最大profit
        }
        return maxSoFar;
    }
// 基本思想还是DP, diff[j+1] = max{diff[j], trend[j+1]+maxCur} 

