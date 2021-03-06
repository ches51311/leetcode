#include <iostream>
#include <vector>

using std::vector;

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int a = 0, b = 0;
        for (vector<int>::size_type i = 0; i < nums.size(); i++){
            if (nums[i] == 0){
                nums[a] = 0;
                a++;
            }
            else if (nums[i] == 1) b++;
        }
        for (vector<int>::size_type i = a; i < nums.size(); i++){
            nums[i] = i < (a+b) ? 1 : 2;
        }
    }
};

int main()
{
	vector<int> a = {2,0,2,1,1,0};
	Solution s;
	s.sortColors(a);
	for (auto i = begin(a); i != end(a); i++)
		std::cout << *i << std::endl;
}

