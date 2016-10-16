/*
class Solution {
public:
    int climbStairs(int n) {
        if (n<2) return 1;   // 即使是负台阶，方法也是1种，0不走
        
        vector<int> ways;
        ways.push_back(1);   // 0台阶时ways是1种
        ways.push_back(1);
        
        int ways_n = 0;
        for(int i = 2; i<=n; i++) {
            ways_n = ways[i-1] + ways[i-2];    // 递归处
            ways.push_back(ways_n);
        }
        return ways[n];
    }
};**/

public class Solution {                  // 和上面思路一样，但递归处其实只要保存三个数就可以了。O(1)的空间复杂度
  public int climbStairs(int n) {  
     int[] map = new int[3];
     map[0] = 1;
     map[1] = 1;
     map[2] = 1;
     for(int i=2; i<=n; i++){
        map[2] = map[1] + map[0];
        map[0] = map[1];
        map[1] = map[2];
     }   
     return map[2];
  }
}
