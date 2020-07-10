#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int i = digits.size();
        while(i>0)
        {
            i=i-1;
            if (digits.at(i) == 9)
            {
                digits.at(i) = 0;
                if (i==0)
                {
                    digits.insert(digits.begin(), 1);
                }
            }
            else
            {
                digits.at(i)++;
                i = 0;
            }
        }
        return digits;
    }
};

int main(){
  vector<int> a = {1,2,3};
  Solution s;
  vector<int> ans = s.plusOne(a);
  for (auto n : ans){
    std::cout << n << std::endl;
  }

}
