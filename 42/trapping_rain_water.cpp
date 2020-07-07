#include <iostream>
#include <vector>


using std::vector;
using std::max;
using std::min;

class Solution {
public:
    int trap(vector<int>& height) {
        int count = 0;
        int l, r;
        int li, ri;
        if (height.size() == 1)
        {
            return 0;
        }
        for (int i=0; i<height.size(); i++)
        {
            l = *max_element(height.begin(), height.begin() + i);
            r = *max_element(height.begin() + i, height.end());
            /*l = height.at(i);
            r = height.at(i);
            li = i;
            ri = i;
            while(li > 0)
            {
                li = li - 1;
                if (l < height.at(li))
                {
                    l = height.at(li);
                }
            }
            while(ri < height.size() - 1)
            {
                ri = ri + 1;
                if (r < height.at(ri))
                {
                    r= height.at(ri);
                }
            }*/
            count = count + max(min(l,r) - height.at(i), 0);
        }
        return count;
    }
};

int main(){
  vector<int> v = {0,1,0,2,1,0,1,3,2,1,2,1};
  Solution s;
  std::cout << s.trap(v) << std::endl;

}

