#include<stdio.h>
int main(){
    int n;
    char c1,c2;
    char arr[40][80];
    scanf("%d",&n);
    // n = getchar();
    getchar();
    c1 = getchar();
    getchar();
    c2 = getchar();
    printf("----------\n");
    /*printf("%d\n",n);
    putchar(c1);
    putchar(c2);*/
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n;j++){
            if(j<n-1-i || j>n-1+i){
                arr[i][j] = ' ';
            }else if(j==n-1-i || j==n-1+i){
                arr[i][j] = c1;
            }else if(j>n-1-i && j<n-1+i){
                arr[i][j] = c2;
            }
            if(i==n-1){
                arr[i][j] = c1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<2*n;j++){
            printf("%c",arr[i][j]);
        }
        printf("\n");
    }
    return 0;
}
