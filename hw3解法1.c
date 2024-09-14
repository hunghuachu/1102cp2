#include <stdio.h>

int main(){
    int time, n;
    scanf("%d", &time);
    for(int i = 0; i < time; i++){
        scanf("%d", &n);
        int cnt = 0;
        for(int j = 0, tmp; j < n; j++){
            scanf("%d", &tmp);
            if(cnt >= j && j+tmp > cnt){
                cnt = j+tmp;
            }
        }
        if(cnt >= n-1)
            printf("yes\n");
        else
            printf("no\n");
    }
}