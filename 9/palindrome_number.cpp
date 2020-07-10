#include <iostream>


class Solution {
public:
    bool isPalindrome(int x) {
        if (x<0) return false;
        long x2=0;
        long x3=x;
        while(x){
            x2 = x2*10+x%10;
            x = x/10;
        }
        return x3==x2;
    }
};


int main(){
  Solution s;
  bool ans = s.isPalindrome(121);
  std::cout << ans << std::endl;

}
