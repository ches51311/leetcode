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
    ListNode* swapPairs(ListNode* head) {
        if (!head || !head->next) return head;
        ListNode **pp = &head;
        ListNode *p;
        while(*pp && (*(*pp)).next ){
            p = (*pp);
            (*pp) = (*p).next;
            // (*p).next = (*(*pp)).next;
            (*p).next = (*(*p).next).next;
            (*(*pp)).next = p;
            // (*(*p).next).next = p;
            pp = &(*(*(*pp)).next).next;
        }
        return head;
    }
};

int main()
{
    ListNode *tmp = new ListNode(1);
    ListNode *tmp2 = tmp;
    for (int i = 2; i < 5; i++){
        tmp->next = new ListNode(i);
        tmp = tmp->next;
    }
    ListNode head(1);
    Solution s;
    tmp2 = s.swapPairs(tmp2);
    while(tmp2){
        std::cout << tmp2->val << std::endl;
        tmp2 = tmp2->next;
    }
    return 0;
}

