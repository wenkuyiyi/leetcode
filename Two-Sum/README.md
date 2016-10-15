#12. Two-Sum


* Difficulty： Easy Hash table

* 题目描述： 给一个数组，找出两个数的和为特定目标。(假定只有一组和成立)
```
  Example:
  Given nums = [2, 7, 11, 15], target = 9,
  Because nums[0] + nums[1] = 2 + 7 = 9,
  return [0, 1].
```
----
* 思路：建一个unordered_map, 把target-nums[i]放入，则在遍历完数组前一定有一个数在map里。  
       还有个思路是两数组往中间逼近。
