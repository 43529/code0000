#include <iostream>
#include <algorithm>
using namespace std;
const int MAX = 101;
int city_num;
int dis[MAX][MAX];
int p[MAX];
int bestway[MAX] = {0};
int bestvalue = 0x3f3f3f3f;
int cv = 0;

void init(int num)
{
    city_num = num;
    for (int i = 1; i <= city_num; i++)
    {
        for (int j = 1; j <= city_num; j++)
        {
            if (i == j)
                dis[i][j] = 0;
            else
                cin >> dis[i][j];
        }
    }
    for (int i = 1; i <= city_num; i++)
    {
        p[i] = i;
        bestway[i] = 0;
    }
}
void backTrace(int n)
{
    if (n > city_num)
    {
        if ((dis[p[city_num]][1]) && (dis[p[city_num]][1] + cv < bestvalue))
        {
            bestvalue = dis[p[city_num]][1] + cv;
            for (int i = 1; i <= city_num; i++)
            {
                bestway[i] = p[i];
            }
        }
    }
    else
    {
        for (int i = n; i <= city_num; i++)
        {
            if ((dis[p[n - 1]][p[i]]) && (dis[p[n - 1]][p[i]] + cv < bestvalue))
            {
                swap(p[i], p[n]);
                cv += dis[p[n - 1]][p[n]];
                backTrace(n + 1);
                cv -= dis[p[n - 1]][p[n]];
                swap(p[i], p[n]);
            }
        }
    }
}
void printdis()
{
    /*for(int i=1;i<=city_num;i++)
    {
        for(int j=1;j<=city_num;j++)
        {
           cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }*/
    cout << bestvalue << endl;
}
int main()
{
    int n;
    cin >> n;
    init(n);
    backTrace(2);
    printdis();
    return 0;
}