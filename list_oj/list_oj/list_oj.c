#include<stdio.h>
//删除链表中等于给定值 val 的所有节点。

//示例 :

//输入: 1->2->6->3->4->5->6, val = 6
//输出 : 1->2->3->4->5

 
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 


struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    while (cur) {
        if (cur->val == val) {
            //非头节点
            if (prev != NULL) {
                prev->next = cur->next;
            }
            else {
                //头节点
                head = cur->next;
            }
            struct ListNode* next = cur->next;
            free(cur);
            cur = next;
        }
        else {
            prev = cur;
            cur = cur->next;
        }
    }
    return head;
}