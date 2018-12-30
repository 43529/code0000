#include<iostream>
using namespace std;
class travellingSalesmanProblem
{
    private:
        int city_num;
        int **dis;
        int **process;
    public:
        travellingSalesmanProblem(int city_num);
        void dynamicProgramming();
        void printdis();
};
//构造函数
travellingSalesmanProblem::travellingSalesmanProblem(int num)
{
    city_num=num;
    dis=new int *[city_num];
    for(int i=0;i<city_num;i++)
    {
        dis[i] = new int [city_num];
        for(int j=0;j<city_num;j++)
        {
                if(i==j)
                    dis[i][j]=0;
                else 
                    cin>>dis[i][j];
        }
    }
    process = new int *[city_num];
    for(int i=0;i<city_num;i++)
    {
        process[i] = new int[1<<(city_num-1)];
    }
}
void travellingSalesmanProblem::dynamicProgramming()
{
    int i,j,k;
    for(i=0;i<city_num;i++)
    {
        process[i][0] = dis[i][0];
    }
    for(i=1;i<(1<<(city_num-1));i++)
    {
        for(j=0;j<city_num;j++)
        {
            process[j][i]=0x3f3f3f3f;

            if((i>>(j-1)&1)==1)
                continue;

            for(k=1;k<city_num;k++)
            {
                if((i>>(k-1)&1)==0)
                    continue;

                if(process[j][i]>dis[j][k]+process[k][i^(1<<(k-1))])
                    process[j][i]=dis[j][k]+process[k][i^(1<<(k-1))];
            }
        }
    }
    cout<<process[0][(1<<(city_num-1))-1]<<endl;
}
//打印
void travellingSalesmanProblem::printdis()
{
    for(int i=0;i<city_num;i++)
    {
        for(int j=0;j<city_num;j++)
        {
            cout<<dis[i][j]<<" ";
        }
        cout<<endl;
    }
}
int main()
{
    int n;
    cin>>n;
    travellingSalesmanProblem tsp(n);
    //tsp.printdis();
    tsp.dynamicProgramming();
    return 0;
}