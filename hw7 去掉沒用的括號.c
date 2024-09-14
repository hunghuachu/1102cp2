#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char* str = (char*)malloc(sizeof(char)*30);
    int place[30];
    scanf("%s", str);
    if(str[0] == '(' || str[0] == ')')
        place[0] = 1;
    else place[0] = 0;
    for(int i = 1; i < strlen(str); i++){
        if(str[i] == '(')
            place[i] = 1;
        else if(str[i] == ')'){
            for(int j = i-1; j >= 0; j--){
                if(j == 0 && place[j] == 0)
                    place[i] = 1;
                else if(place[j] == 1 && str[j] == '('){
                    place[j] = 0;
                    place[i] = 0;
                    break;
                }
            }
        }
        else 
            place[i] = 0;
    }
    if(place[0] == 1){
        for(int i = 1; i < strlen(str); i++){
            if(place[i] == 0) 
                break;
            else if(i == strlen(str)-1 && place[i] == 1) 
                printf("(blank)");
        }
    }
    for(int i = 0; i < strlen(str); i++){
        if(place[i] == 0)
            printf("%c", str[i]);
    }
}