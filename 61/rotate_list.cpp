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
    ListNode* rotateRight(ListNode* head, int k) {
        if (!head || !head->next) return head;
        int cnt = 0, size = 1;
        ListNode *result, *walk = head;
        while(walk->next){
            walk = walk->next;
            size++;
        }
        walk->next = head;
        walk = walk->next;
        k = k % size;
        while(true){
            if (cnt == (size - k - 1)) {
                result = walk->next;
                walk->next = NULL;
                break;
            }
            walk = walk->next;
            cnt++;
        }
        return result;
    }
};

int main()
{
    ListNode *tmp = new ListNode(1);
    ListNode *tmp2 = tmp;
    for (int i = 2; i < 6; i++){
        tmp->next = new ListNode(i);
        tmp = tmp->next;
    }
    ListNode head(1);
    Solution s;
    tmp2 = s.rotateRight(tmp2, 2);
    while(tmp2){
        std::cout << tmp2->val << std::endl;
        tmp2 = tmp2->next;
    }
    return 0;
}

