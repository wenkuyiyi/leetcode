public class Solution {
    public int removeDuplicates(int[] nums) {
        if (nums.length == 0 || nums.length == 1) return nums.length;
        
        int news = 0;      // news表示新元素
        for (int i = 1; i<nums.length; i++) {          // java与C++区别， nums.size()
            if (nums[i] != nums[i-1]) {
                news++;
                nums[news] = nums[i];
            }
        }
        return news+1;
    }
}

// 数组一new出来就固定了大小，删除元素只有用集合中的remove
 /*
   List<Integer> list = new ArrayList<Integer>();  
   // List是接口，ArrayList是集合类，封装了个动态数组。
   // java.lang.Integer是一个类.对它的操作要通过类的方法 . int是JAVA缺省的8中基本数据类型之一.不是类的对象.
   list.removeRange(news, nums.length);   // 一般删除一个元素是remove(index);   **/
    
 // 一开始定义不是集合就不好操作..
