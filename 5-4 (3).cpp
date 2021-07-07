#include <bits/stdc++.h>
using namespace std;
int a[100][100],b[100];
int sum=0,minn=1234567,i,j,n;
void dfs(int dep){
	for(int r=1;r<=n;++r){
		if(!b[r]){
			b[r]=1;
			sum+=a[dep][r];
			if(dep==n&&sum<minn){
				minn=sum;
			}
			if(dep!=n){
				if(sum<minn){
					dfs(dep+1);
				}
			}
			sum-=a[dep][r];
			b[r]=0;
		}
	}
}
int main()
{
	cin>>n;
	for(i=1;i<=n;++i){
		for(j=1;j<=n;++j){
			cin>>a[i][j];
		}
	}
	dfs(1);
	cout<<minn<<endl;
}
