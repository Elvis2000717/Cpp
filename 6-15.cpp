#include <bits/stdc++.h>
using namespace std;
#define MAX 100
int f1=0;
int f2[MAX]={0};
int f=0;
int a[MAX][MAX],best[MAX],x[MAX];
int bestf=63355;
int backpack(int t,int n){
	if(t>n){
		for(int i=1;i<=n;i++){
			best[i]=x[i];
		}
		bestf=f;
	}
	for(int i=t;i<=n;i++){
		f1+=a[1][x[i]];
		f2[t]=((f2[t-1]>f1)?f2[t-1]:f1)+a[2][x[i]];
        f+=f2[t];
        if(f<bestf){
            swap(x[i],x[t]);
            backpack(t+1,n);
            swap(x[t],x[i]);
        }
        f1-=a[1][x[i]];
        f-=f2[t];
	}
}
int main()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
        x[i] = i;
    }
    for(int i = 1;i<n;i++){
        for(int j = 1;j<=n;j++){
            cin>>a[i][j];
        }
    }
    backpack(1,n);
    cout<<bestf<<endl;
    for(int i = 1;i<=n;i++){
          cout<<best[i]<<" ";
    }
   return 0;
}
