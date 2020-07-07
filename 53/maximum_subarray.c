#include <stdio.h>
#include <stdlib.h>

int maxSubArray(int* nums, int numsSize) {
    int *dp = malloc(numsSize * sizeof(int));
    *dp = *nums;
    int ans = *dp;
    for (int i=1; i<numsSize; i++){
        if (*(dp+i-1) > 0) *(dp+i) = *(dp+i-1) + *(nums + i);
        else *(dp+i) = *(nums + i);
        if (ans<*(dp+i)) ans = *(dp+i);
    }
    
    
    return ans;
    
}

int main(){
  int a[9] = {-2, 1, -3, 4, -1, 2, 1, -5, 4};
  int ans = maxSubArray(a, 9);
  printf("%d\n", ans);
  return 0;
}
