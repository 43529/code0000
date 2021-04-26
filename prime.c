#include<stdio.h>
int main() {
    int flag = 0;
    printf("2 ");
    for(int i=3;i<1000;i+=2){
        for(int j = 1; j*j <= i; j++){
           if(i%j == 0 && j != 1) {
	       flag = 1;
	       break;
           } 
        }
        if(flag == 0){
            printf("%d ",i);
        } else {
            flag = 0;
        }
    }
    printf("\n");
    return 0;
}
