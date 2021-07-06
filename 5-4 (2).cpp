#include <bits/stdc++.h>
int main()
{
	long long int i,mark,m,n,sum=0;
	int flag=0;
	scanf("%d",&n);
	if(n==1){
		printf("1\n");
		return 0;
	}
	else if(n==2){
		printf("2\n");
		return 0;
	}
	else if(n==3){
		printf("3\n");
		return 0;
	}
	else if(n==4){
		printf("4\n");
		return 0;
	}
	else if(n==5){
		printf("6\n");
		return 0;
	}
	int list[200];
	for(i=2;i<=n;i++){
		sum+=i;
		if(sum==n){
			flag=0;
			break;
		}
		else if(sum>n){
			sum-=i;
			mark=i-2;
			flag=1;
			break;
		}
		else list[i-1]=i;
	}
	m=mark;
	if(flag){
		while(sum!=n){
			list[m]=list[m]+1;
			if(m==1){
				m=mark;
			}
			else{
				m--;
			}
			sum++;
		}
	}
	long long int y=1;
	for(i=1;i<=mark;i++){
		y*=list[i];
	}
	printf("lld\n",y);
 } 
