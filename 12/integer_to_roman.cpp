#include <iostream>
#include <string>

using std::string;

class Solution {
public:
    inline string appendstr(string &ans, int &num, int ronum, string roman){
        while(num / ronum ){
            ans.append(roman);
            num = num - ronum;
        }
        return ans;
    }
    string intToRoman(int num) {
        string ans="";
        appendstr(ans, num, 1000, "M");
        appendstr(ans, num, 900, "CM");
        appendstr(ans, num, 500, "D");
        appendstr(ans, num, 400, "CD");
        appendstr(ans, num, 100, "C");
        appendstr(ans, num, 90, "XC");
        appendstr(ans, num, 50, "L");
        appendstr(ans, num, 40, "XL");
        appendstr(ans, num, 10, "X");
        appendstr(ans, num, 9, "IX");
        appendstr(ans, num, 5, "V");
        appendstr(ans, num, 4, "IV");
        appendstr(ans, num, 1, "I");
        
        return ans;
    }
};

int main(){
  Solution s;
  string ans = s.intToRoman(3);
  std::cout << ans << std::endl;

}
