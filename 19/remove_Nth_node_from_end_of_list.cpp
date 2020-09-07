
#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* walk = head;
        ListNode* target = head;
        for (int i=0; i < n; i++){
            walk = walk->next;
            if (walk == NULL){
                return head->next;
            }
        }
        while(walk->next != NULL){
            walk = walk->next;
            target = target->next;            
        }
        target->next = target->next->next;
        return head;
    }
};

int main(){
    ListNode* head = new ListNode(1);
    ListNode* walk = head;
    for (int i = 2; i < 6; i++){
        walk->next = new ListNode(i);
        walk = walk->next;
    }
    Solution s;
    head = s.removeNthFromEnd(head, 2);
    while(head != NULL){
        std::cout << head->val << std::endl;
        head = head->next;
    }
    return 0;
}



