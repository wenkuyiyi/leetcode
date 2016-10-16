#237. Delete Node in a Linked List


* Difficulty： Easy Linked List

* 题目描述： 有个链表eg. 1 -> 2 -> 3 -> 4, 但现在只给你其中一个数eg. 3的指针， 请删除这个node变为1 -> 2  -> 4。删除点不为尾指针

----
```
编程：  
1. 解引用，得到的是p的值。 指针加上整数还是指针。  
2. 删除结点必须知道其前一个结点。

----

时间：12ms,基本最低，9ms可能没delete node
