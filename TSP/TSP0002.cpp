#include<iostream>
#include<algorithm>
using namespace std;
const int MAX=21;
const int INF=0x3f3f3f3f;
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
    int n,sum=0,minLength=INF;
    int arr[MAX][MAX]={0};
    int permutation[MAX]={0};
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(i!=j)
                cin>>arr[i][j];
        }
    }
    for(int i=0;i<n;i++){
        permutation[i]=i;
    }

    do{
        for(int i=0;i<n-1;i++)
            sum+=arr[permutation[i]][permutation[i+1]];
        sum+=arr[permutation[n-1]][permutation[0]];
        if(minLength>sum)
            minLength=sum;
        else sum = 0;
    }while(myNextPermutation(permutation,permutation+n));
    cout<<minLength<<endl;
    return 0;
}
