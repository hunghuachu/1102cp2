#include <stdio.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
        int c = *(int*)a;
        int d = *(int*)b;
        if(c < d)
                return -1;
        else if (c == d)
                return 0;
        else return 1;
}

int main(){
        int num, k, tmp;
        scanf("%d %d", &num, &k);
        int arr[1000000], ans[1000000];
        for(int i = 0; i < num; i++)
            scanf("%d", &arr[i]);
        qsort(arr, num, sizeof(int), cmp);  //將輸入由小到大排列
        tmp = arr[0]; 
        ans[0] = tmp; //令ans[0]為 arr[0]排完順序後的第一個元素
        for(int i = 0, j = 1; i < num; i++){  
                if(arr[i+1] != arr[i]){   
                        tmp = arr[i+1];
                        ans[j] = tmp;
                        j++;
                }

        }
        printf("%d\n", ans[k-1]);
}