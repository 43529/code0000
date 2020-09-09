#include<stdio.h>
#include<math.h>
int main(){
    int a=1,b=7,c=12;
    double res;
    res = (-b+sqrt(b*b-4*a*c))/(2.0*a);
    printf("%f",res);
    return 0;
}
