class Solution {
public:
    string intToRoman(int num) {        // 枚举命名规则,枚举类名属于类型名，按类命名，值全大写加下划线
        string THOUSAND[4] = {"", "M", "MM", "MMM"},
               HUNDRED[10] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"},
               TEN[10]   =   {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"},
               ONE[10]   =   {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};
        return THOUSANF[num/1000] + HUNDRED[(num%1000)/100] + TEN[(num%100)/10] + ONE[(num%10)];
    }
};
// 求余数问题。eg. 怎么求5932的个位数2？
