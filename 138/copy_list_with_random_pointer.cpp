#include <iostream>
#include <vector>

class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if (head == NULL) return NULL;
        Node *walk = head, *tmp;
        while(walk != NULL){
            tmp = walk->next;
            walk->next = new Node(walk->val);
            walk->next->next = tmp;
            walk = walk->next->next;
        }
        walk = head;
        while(walk != NULL){
            if (walk->random != NULL){
                walk->next->random = walk->random->next;                
            }
            walk = walk->next->next;
        }
        walk = head->next;//copy
        tmp = head;//origin
        head = head->next;
        while(walk != NULL){
            tmp->next = walk->next;
            tmp = tmp->next;
            if (walk->next == NULL) break;
            walk->next = walk->next->next;
            walk = walk->next;
        }
        return head;
    }
};

int main(){
  std::vector<int> tmp1 = {7, 13, 11, 10, 1};
  std::vector<int> tmp2 = {-1, 0, 4, 2, 0};
  Node *head = new Node(tmp1[0]);
  Node *walk = head;
  for (std::vector<int>::size_type i = 1; i < tmp1.size(); i++) {
    walk->next = new Node(tmp1[i]);
    walk = walk->next;
  }
  walk = head;
  Node *tmp;
  for (std::vector<int>::size_type i = 0; i < tmp2.size(); i++) {
    if (tmp2[i] == -1) walk->random = NULL;
    else{
      tmp = head;
      int cnt = tmp2[i];
      while(cnt > 0){
        tmp = tmp->next;
        cnt--;
      }
      walk->random = tmp;
    }
    walk = walk->next;
  }
  Solution s;
  walk = s.copyRandomList(head);
  head = walk;
  while(walk != NULL){
    if (walk->random == NULL)
      std::cout << walk->val << ", NULL" << std::endl;
    else {
      tmp = head;
      int cnt = 0;
      while(walk->random != tmp) {
        cnt++;
        tmp = tmp->next;
      }
      std::cout << walk->val << ", " << cnt <<std::endl;
    }
    walk = walk->next;
  }
}
