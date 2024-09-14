#include <stdio.h>
#include <stdlib.h>

struct node{
    int val;
    struct node* next;
};

int main(){
    int times, loc1, loc2;
    while(scanf("%d", &times)!=EOF){
        char verb[4], prep[4];
        struct node** blocks = (struct node**)malloc(sizeof(struct node*)*times);
        for(int i = 0; i < times; i++){
            struct node* newBlocks = (struct node*)malloc(sizeof(struct node));
            newBlocks->val = i;
            newBlocks->next=NULL;
            blocks[i] = newBlocks;
        }

        while(1){
            scanf(" %c %c %c %c", &verb[0], &verb[1], &verb[2], &verb[3]);
            if(verb[0] == 'q')  //quit
                break;
            scanf(" %d", &loc1);
            scanf(" %c %c %c %c", &prep[0], &prep[1], &prep[2], &prep[3]);
            scanf(" %d", &loc2);
            int lineOfLoc1, lineOfLoc2;
            if(loc1==loc2)
                continue;
            struct node* toLoc1=NULL;
            struct node* toLoc2=NULL;
            for(int j = 0; j < times; j++){
                struct node* tmp = blocks[j];
                while(tmp != NULL){
                    if(tmp->val == loc1)
                        lineOfLoc1 = j;
                    if(tmp->val == loc2)
                        lineOfLoc2 = j;
                    tmp = tmp->next;
                }
            }
            if(lineOfLoc1 == lineOfLoc2)
                continue;
            if(verb[0] == 'm'){  //move
                struct node* pre;
                struct node* cur;
                if(blocks[lineOfLoc1]->val == loc1){
                    toLoc1 = blocks[lineOfLoc1];
                    blocks[lineOfLoc1] = NULL;
                }
                else{
                    pre = blocks[lineOfLoc1];
                    cur = blocks[lineOfLoc1]->next;
                    while(cur!=NULL){
                        if(cur->val == loc1){
                            toLoc1 = cur;
                            pre->next = NULL;
                            break;
                        }
                        cur = cur->next;
                        pre = pre->next;
                    }
                }
                struct node* reset1 = toLoc1->next;
                toLoc1->next = NULL;
                toLoc2 = NULL;
                while(reset1!=NULL){
                    int index = reset1->val;
                    blocks[index] = reset1;
                    reset1 = reset1->next;
                    blocks[index]->next = NULL;
                }
                if(prep[1] == 'n'){  //onto
                    struct node* cur2;
                    cur2 = blocks[lineOfLoc2];
                    while(toLoc2==NULL){
                        if(cur2->val == loc2){
                            toLoc2 = cur2;
                            break;
                        }
                        cur2 = cur2->next;
                    }
                    struct node* reset2 = toLoc2->next;
                    while(reset2!=NULL){
                        int index = reset2->val;
                        blocks[index] = reset2;
                        reset2 = reset2->next;
                        blocks[index]->next = NULL;
                    }
                    toLoc2->next = toLoc1;
                }
                else{    //over
                    struct node* cur2;
                    cur2 = blocks[lineOfLoc2];
                    while(cur2->next!=NULL){
                        cur2 = cur2->next;
                    }
                    cur2->next = toLoc1;
                }
            }
            if(verb[0] == 'p'){  //pile
                struct node* pre;
                struct node* cur;
                if(blocks[lineOfLoc1]->val == loc1){
                    toLoc1 = blocks[lineOfLoc1];
                    blocks[lineOfLoc1] = NULL;
                }
                else{
                    pre = blocks[lineOfLoc1];
                    cur = blocks[lineOfLoc1]->next;
                    while(cur!=NULL){
                        if(cur->val == loc1){
                            toLoc1 = cur;
                            pre->next = NULL;
                            break;
                        }
                        cur = cur->next;
                        pre = pre->next;
                    }
                }

                if(prep[1] == 'n'){  //onto
                    struct node* cur2;
                    cur2 = blocks[lineOfLoc2];
                    while(cur2!=NULL){
                        if(cur2->val == loc2){
                            toLoc2 = cur2;
                            break;
                        }
                        cur2 = cur2->next;
                    }
                    struct node* reset2 = toLoc2->next;
                    while(reset2!=NULL){
                        int index = reset2->val;
                        blocks[index] = reset2;
                        reset2 = reset2->next;
                        blocks[index]->next = NULL
                    }
                        toLoc2->next = toLoc1;
                    }
                else{   //over
                    struct node* cur2;
                    cur2 = blocks[lineOfLoc2];
                    while(cur2->next!=NULL)
                        cur2 = cur2->next;
                    cur2->next = toLoc1;
                }
            }
        }
        for(int i = 0; i < times; i++){
            printf("%d: ", i);
            while(blocks[i]!=NULL){
                printf("%d ", blocks[i]->val);
                struct node* remover = blocks[i];
                blocks[i] = blocks[i]->next;
                free(remover);
            }
            printf("\n");
        }
    }
}