#include <iostream>


class Solution {
public:
    int climbStairs(int n) {
        if (n==0) return 0;
        if (n==1) return 1;
        if (n==2) return 2;
        int a,b,ans;
        a=1;
        b=2;
        for (int i=3; i<=n; i++){
            ans = a + b;
            a = b;
            b = ans;
        }
        return ans;
    
    }

};


int main(){

Solution s;
std::cout << s.climbStairs(2) << std::endl;

}
