#include <stdio.h>

#define max(a, b) (a > b ? a : b)

int main(){
      int n;
      scanf("%d\n", &n);
      int tmp;
  	int ans = -2147483648;
  	int mx;
  	scanf("%d ", &mx);
      for(int i = 1; i < n; i++){
            scanf("%d ", &tmp);
          	ans = max(ans, mx - tmp);
          	mx = max(mx, tmp);
      }
      printf("%d\n", ans);
}
//在計算ans的時候，也一邊在更新mx (如果輸入的下一位數比mx大 就把mx更新)

// int max(int a, int b){
//      int ans = (a > b ? a : b);
//      return ans;
//}