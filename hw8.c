#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    if (*(long long int*)a - *(long long int*)b < 0)
        return -1;
    if(*(long long int*)a - *(long long int*)b > 0)
        return 1;
    return 0;
} 

int main(){
    int n;
    scanf("%d", &n);
    long long arr[n];
    long long val = 0; 
    long long ans = 0; 
    long long max = 1; 
    for(int i = 0; i < n; i++)
        scanf("%lld", &arr[i]);
    qsort(arr, n, sizeof(arr[0]), cmp);
    long long tmp = arr[0];
    for(int i = 0; i < n-1; i++){
        if(arr[i+1]!=tmp){
            if(tmp*max > val){
                val = tmp*max;
                ans = tmp;
            }
            tmp = arr[i+1];
            max = 1;
            if(i==n-2){
                if(tmp>val){
                    val = tmp;
                    ans = tmp;
                }
            }
        }
        else if(arr[i+1] == tmp){
            max++;
            if(i==n-2){
                if(tmp*max>val){
                    val = tmp*max;
                    ans = tmp;
                }
            }
        }
    }
    printf("%lld\n%lld", ans, val*10000);
}