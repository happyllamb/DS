#include<stdio.h>
//ɾ�������е��ڸ���ֵ val �����нڵ㡣

//ʾ�� :

//����: 1->2->6->3->4->5->6, val = 6
//��� : 1->2->3->4->5

 
  struct ListNode {
      int val;
      struct ListNode *next;
  };
 


struct ListNode* removeElements(struct ListNode* head, int val) {
    struct ListNode* cur = head;
    struct ListNode* prev = NULL;
    while (cur) {
        if (cur->val == val) {
            //��ͷ�ڵ�
            if (prev != NULL) {
                prev->next = cur->next;
            }
            else {
                //ͷ�ڵ�
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