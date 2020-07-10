#include <stdio.h>
#include <stdlib.h>


int lengthOfLongestSubstring(char* s) {
    if (s[0] == '\0' || s[0] == NULL) return 0;
    int s_len = 0;
    int max_len=0;
    int cur_len=0;
    
    int check;
    
    while (s[s_len] != '\0') s_len++;
    
    char *s_tmp;
    s_tmp = malloc(s_len*sizeof(char));
    
    for (int i=0; i<s_len; i++){
        cur_len = 0;
        for (int j=i; j<s_len; j++){
            check = 0;
            for (int k=0; k<cur_len; k++){
                if (s_tmp[k] == s[j]) check = 1;
            }
            if (check == 0){
                s_tmp[cur_len] = s[j];
                cur_len++;
            }
            else break;
        }
        if (max_len < cur_len) max_len = cur_len;
    }
    
    
    return max_len;
    
}

int main(){
  char s[9] = "abcabcbb\0";
  int ans = lengthOfLongestSubstring(s);
  printf("%d\n", ans);
}


