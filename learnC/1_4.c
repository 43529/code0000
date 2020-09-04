#include<stdio.h>
#define MAX_NUM 100
int main(){
    printf("2 ");
    // printf("%d",3/2);
    for(int i=3;i<MAX_NUM;i++){
        for(int j=2;j<i;j++){
            if(j == i-1){
                printf("%d ",i);
                continue;
            }
            // printf("%d",i/j);
            if(i%j == 0){
                break;
            }
        }
    }
    return 0;
}
