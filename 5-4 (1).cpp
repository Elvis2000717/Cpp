#include <bits/stdc++.h>
#define N 100
int n;
int x[N],opt[N],p[N][N],Q[N][N];
int tempvalue=0,maxvalue=0;
void compute(){
	tempvalue=0;
	for(int i=1;i<=n;i++){
		tempvalue+=p[i][x[i]]*Q[x[i]][i];
	}
	if(tempvalue>maxvalue){
		maxvalue=tempvalue;
		for(int i=1;i<=n;i++){
			opt[i]=x[i];
		}
	}
} 
void traceback(int t){
	int i,j,temp;
	if(t>n){
		compute();
	}
	for(i=t;i<=n;i++){
		temp=x[i];
		x[i]=x[t];
		x[t]=temp;
		traceback(t+1);
		temp=x[i];
		x[i]=x[t];
		x[t]=temp;
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		x[i]=i;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&p[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&Q[i][j]);
		}
	}
	traceback(1);
	printf("%d",maxvalue);
}
