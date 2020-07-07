#include <stdio.h>

int maxArea(int* height, int heightSize){
    int i=0, j=heightSize-1;
    int ans=0;
    int tmp;
    while (i<j){
        if (height[i] > height[j]){
            tmp = (j-i)*height[j];
            j = j-1;

        }
        else{
            tmp = (j-i)*height[i];
            i = i+1;
        }
        if (tmp>ans) ans=tmp;
    }
    return ans;

}

int main(){
  int h[9] = {1,8,6,2,5,4,8,3,7};

  int ans = maxArea(h, 9);
  printf("%d\n", ans);
  return 0;
}
