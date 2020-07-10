#include <stdio.h>
#include <stdlib.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *first, *current;
    current = (struct ListNode*)malloc(sizeof(struct ListNode));
    current->next = NULL;
    first = current;
    int a=0;
    while(1){
        if (l1 == NULL && l2 == NULL && a==1){
            current->val = a;
            a=0;
        }
        else if (l1 == NULL && l2 != NULL){
            current->val = (l2->val+a)%10;
            a = (l2->val+a)/10;
            l2 = l2->next;
        }
        else if (l2 == NULL && l1 != NULL){
            current->val = (l1->val+a)%10;
            a = (l1->val+a)/10;
            l1 = l1->next;
        }
        else{
            current->val = (l1->val + l2->val + a)%10;
            a = (l1->val + l2->val + a)/10;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 == NULL && l2 == NULL && a==0) break;
        current->next = (struct ListNode*)malloc(sizeof(struct ListNode));
        current->next->next = NULL;
        current = current->next;
    }
    return first;
    
}



int main(){
  struct ListNode a1, a2, a3;
  struct ListNode b1, b2, b3;
  a1.val = 2;
  a2.val = 4;
  a3.val = 3;
  a1.next = &a2;
  a2.next = &a3;
  b1.val = 5;
  b2.val = 6;
  b3.val = 4;
  b1.next = &b2;
  b2.next = &b3;

  struct ListNode* ans = addTwoNumbers(&a1, &b1);

  while(ans){
    printf("%d\n", ans->val); 
    ans = ans->next;
  }

}


