#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmp(const void *a, const void *b){
    if(strlen(*(char**)a)!=strlen(*(char**)b))  //若a和b的長度不相同 
        return strlen(*(char**)b) - strlen(*(char**)a);    //
    return strcmp(*(char**)a, *(char**)b);
}

int main(){
    int n, m;
    scanf("%d\n", &n);
    for(int i = 0; i < n; i++){
        scanf("%d\n", &m);
        char** word = malloc(sizeof(char*)*m);
        for(int j = 0; j < m; j++)
            *(word+j) = malloc(sizeof(char)*100000);
        for(int j = 0; j < m; j++)
            scanf("%s\n", *(word+j));
        qsort(word, m, sizeof(char*), cmp);
        for(int j = 0; j < m; j++)
            printf("%s\n", *(word+j));
        for(int j = 0; j < m; j++)
            free(*(word+j));
        free(word);
    }
   }