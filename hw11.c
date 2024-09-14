#include <stdio.h>

int main(){
    int n, target, high = 0, low = 0, sum = 0;
    scanf("%d\n", &n);
    int min = n+1;
    int len[n];
    for(int i = 0; i < n; i++)
        scanf("%d ", &len[i]);
    scanf("%d", &target);
    while(high < n){
        sum += len[high++];
        while(sum >= target){
            if(high - low < min)
                min = high - low;
            sum -= len[low++];
        }
    }
    if(min == n+1)
        min = 0;
    printf("%d", min);
}