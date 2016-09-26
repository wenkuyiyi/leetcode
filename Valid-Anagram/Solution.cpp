class Solution {                         // 43ms
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> counts;
        for (auto i: s) 
            counts[i]++;
        for (auto j: t) {
            auto elem = counts.find(j);
            if (elem == counts.end()) return 0;
            else --elem->second;
            if (elem->second < 0 ) return 0;
        }
        
        auto map_it = counts.begin();
        while (map_it != counts.end()) {
            if (map_it->second != 0) return 0;
            map_it++;
        }
        return 1;
    }
};

------------------------------------------------------------------------

class Solution {                         // 103ms
public:
    bool isAnagram(string s, string t) {
        int lens = s.size();
        int lent = t.size();
        if (lens != lent) return 0;
        sort(s.begin(), s.end());
        sort(t.begin(), t.end());
        for(int i = 0; i<lens; i++) {
            if (s[i] != t[i]) return 0;
        }
        return 1;
    }
};

--------------------------------------------------------------------------

class Solution {             // 9ms最简答案，思想其实和1差不多，但这个直接数组就省去map的查找时间。
public:
    bool isAnagram(string s, string t) {
        int i,a[26]={0};
        for (i=0;i<s.size();++i)    ++a[s[i]-'a'];      // 本来主元素是字母，所以想到map更快，但字母可以转成数字所以vector更快。。
        for (i=0;i<t.size();++i)    --a[t[i]-'a'];
        for (i=0;i<26;++i)  if (a[i]) return false;
        return true;
    }
};

/*有的时候vector可以替代map 
比如key是整数，就可以以key的跨度作为长度来定义vector。 
数据规模很大的时候，差异是惊人的。当然，空间浪费往往也惊人。
vector需要连续的内存空间，显然在初始化这个容器的时候会花费很大的容量。 
如果内存不是考虑的问题。用vector比map好。map每插入一个数据，都要排序一次。所以速度反不及先安插所有元素，再进行排序。**/
