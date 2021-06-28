#include <bits/stdc++.h>
#define N 100
int n; 
int P[N][N],Q[N][N];
int x[N];
int tempValue=0,maxValue=0;
void compute(){
	tempValue=0;
	for(int i=1;i<=n;i++){
		tempValue+=P[i][x[i]]*Q[x[i]][i];
	}
	if(tempValue>maxValue){
		maxValue=tempValue;
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
int main(){
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
    	x[i]=i;
	}    
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&P[i][j]);
		}
	} 
	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			scanf("%d",&Q[i][j]);
		}
	}  
	traceback(1); 
	printf("%d\n",maxValue);
	return 0;
}
