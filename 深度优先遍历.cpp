#include<iostream>
using namespace std;

#define N 20

class Graph 
{ 
private:
    int flag[N];//状态数组
    int Vexnum;//图的顶点数量
    int Matrix[N][N];  //邻接矩阵
    void DFS(int v);
public:  
    Graph() 
    { 
        for(int i=0;i<N;i++)
            flag[i]=0;
    } 
    void DFStra();
    void SetMatrix(int n,int p[N][N]);
};
void Graph::SetMatrix(int n,int p[N][N])//设置邻接矩阵
{
    Vexnum=n;
    for(int i=0;i<Vexnum;i++)
        for(int j=0;j<Vexnum;j++)
        {
            Matrix[i][j]=p[i][j];   
        }
}
void Graph::DFStra()
{
    int i;
    for(i=0;i<Vexnum;i++)//可能有多个连通图
    {
        if(flag[i]==0)//找到一个状态为0的顶点
            DFS(i);
    }
    cout<<endl;
}
 
void Graph::DFS(int v)
{
    int w,i,k;
    flag[v]=1;//把这个顶点的状态设置为1
    cout<<v<<" ";
    int temp[N];
    for(i=0;i<Vexnum;i++)
        temp[i]=0;
    k=0;
    for(i=0;i<Vexnum;i++)
    {
        if(Matrix[v][i]==1)
            temp[k++]=i;
    }
    i=0;
    for(i=0;i<k;i++)//对这个几个顶点递归遍历
    {
        w=temp[i];
        if(flag[w]==0)
            DFS(w);
    }
     
}
int main() 
{ 
    int t,i,num,j; 
    int x[N][N];
    int n; 
    cin>>t; 
    while(t--) 
    { 
        cin>>n;
        for(i=0;i<n;i++)
            for(j=0;j<n;j++)
                cin>>x[i][j];
        Graph p;
        p.SetMatrix(n,x);
        p.DFStra();
    } 
}
