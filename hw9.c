#include <stdio.h>
#include <stdlib.h>

int main(){
    int a, b, n;
    scanf("%d\n", &a);
    int arr1[a];;
    for(int i = 0; i < a; i++){
        scanf("%d", arr1+i);
    }
    scanf("%d", &b);
    int arr2[b];
    for(int i = 0; i < b; i++){
        scanf("%d", &arr2[i]);
    }
    scanf("%d", &n);
    int** arr3 = (int**)malloc(sizeof(int*)*n);
    for(int i = 0; i < n; i++){
        arr3[i] = (int*)malloc(sizeof(int)*4);
    }
    for(int i = 0; i < n; i++){
        scanf("%d %d %d %d", &arr3[i][0], &arr3[i][1], &arr3[i][2], &arr3[i][3]);
        int l_a = arr3[i][0], r_a = arr3[i][1], l_b = arr3[i][2], r_b = arr3[i][3];
        int total = arr3[i][1]-arr3[i][0] + arr3[i][3]-arr3[i][2];
        int ans[total];
        for(int j = 0; j < total; j++){
           if(l_a < r_a && l_b < r_b){
               ans[j] = (arr1[l_a] >= arr2[l_b] ? arr2[l_b++] : arr1[l_a++]);
            }
           else if(l_a >= r_a && l_b < r_b){
               ans[j] = arr2[l_b++];
           }
           else if(l_a < r_a && l_b >= r_b){
               ans[j] = arr1[l_a++];
           }
        }
     //   for(int j = 0; j < total; j++)
     //       printf("%d" , ans[j]);
        int mid = total/2;
        if(total%2==0)
            printf("%d %d", ans[mid-1], ans[mid]);
        else
            printf("%d", ans[mid]);
        printf("\n"); 
    }  
    for(int i = 0; i < n; i++)
        free(arr3[i]);
    free(arr3);  
}