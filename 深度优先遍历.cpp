#include<iostream>
using namespace std;

#define N 20

class Graph 
{ 
private:
    int flag[N];//״̬����
    int Vexnum;//ͼ�Ķ�������
    int Matrix[N][N];  //�ڽӾ���
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
void Graph::SetMatrix(int n,int p[N][N])//�����ڽӾ���
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
    for(i=0;i<Vexnum;i++)//�����ж����ͨͼ
    {
        if(flag[i]==0)//�ҵ�һ��״̬Ϊ0�Ķ���
            DFS(i);
    }
    cout<<endl;
}
 
void Graph::DFS(int v)
{
    int w,i,k;
    flag[v]=1;//����������״̬����Ϊ1
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
    for(i=0;i<k;i++)//�������������ݹ����
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
