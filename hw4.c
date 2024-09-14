#include <stdio.h>

int main(){
    char n[110];
    int cnt = 0;
    while(scanf("%c", &n[cnt])!=EOF && n[cnt] != '\n') //因為enter也會被吃進去
        cnt++;
    long long dp[110] = {1}, now = 0;  //將dp[0]設成1, 其他為0
    for(int i = 0; i < cnt; i++){   
        now = now * 10 + n[i] - '0';
        if(now > 9 && now <27) 
            dp[i+1] += dp[i-1];
        now%=10;
        if(now > 0) 
            dp[i+1] += dp[i];
    }
    printf("%lld\n", dp[cnt]);
}