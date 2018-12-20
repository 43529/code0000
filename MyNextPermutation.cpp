#include<iostream>
#include<algorithm>
using namespace std;
void mySwap(int *a, int *b)
{
    int tmp = *a;
    *a = *b;
    *b = tmp;
}
void myReverse(int *a, int *b)
{
    for(b--; a<b; a++,b--)
        mySwap(a,b);
}
bool myNextPermutation(int *begin, int *end)
{
    if(begin >= end)
        return false;
    int *i = end - 1;
    while(i > begin && *(i-1) >= *i)
        i--;
    if(i == begin)
    {
        myReverse(begin, end);
        return false;
    }
    i--;
    int *j = end - 1;
    while(*i >= *j)
        j--;
    mySwap(i,j);
    myReverse(i+1,end);
}
int main()
{
    int a[]={1,2,3,4};
    do{
        for(int i=0;i<4;i++)
            cout<<a[i]<<" ";
        cout<<endl;
    }while(myNextPermutation(a,a+4));
    return 0;
}
