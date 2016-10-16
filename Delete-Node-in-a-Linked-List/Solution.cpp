/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    void deleteNode(ListNode* node) {    // 删除结点必须知道其前一个结点。
        //  node = node->next; 无用，因为改变node只是改变这个指针的指向(下一个)，pre的next域值没变，整体链没变。  
        // 把node->next换掉不再在下面使用可以从28ms->16ms.
        if (node == NULL) return;
        
        ListNode* p = node->next;
       // if (p->next) {         // 不需要这步，因为已假设p不为尾指针。
        *node = *p;     // 解引用，得到的是p的值。 指针加上整数还是指针。
        node->next = p->next;
        delete p;
    }
};
