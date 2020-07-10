#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if (!l1) return l2;
        if (!l2) return l1;
        ListNode* first;
        if (l1->val > l2->val) {
            first = l2;
            l2 = l2->next;
        }
        else {
            first = l1;
            l1 = l1->next;
        }
        ListNode* L = first;
        while (l1 || l2){
            if (!l1) {
                L->next = l2;
                l2 = l2->next;
                L = L->next;
                continue;
            }
            if (!l2){
                L->next = l1;
                l1 = l1->next;
                L = L->next;
                continue;
            }
            if (l1->val > l2->val){
                L->next = l2;
                l2 = l2->next;
                L = L->next;
                continue;
            }
            if (l1->val <= l2->val){
                L->next = l1;
                l1 = l1->next;
                L = L->next;
                continue;
            }
        }
        return first;
        
    }
};

int main(){
  ListNode a1(1), a2(2), a3(4);
  ListNode b1(1), b2(3), b3(4);
  a1.next = &a2;
  a2.next = &a3;
  b1.next = &b2;
  b2.next = &b3;
  Solution s;
  ListNode *ans = s.mergeTwoLists(&a1, &b1);
  while(ans){
    std::cout << ans->val << std::endl;
    ans = ans->next;
  }
}
