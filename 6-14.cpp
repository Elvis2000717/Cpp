#include <bits/stdc++.h>
#define MAX 100
using namespace std;
int n,c;
int w[MAX],p[MAX];
int cp=0,cw=0;
int bestp=0;
int x[MAX];
int order[MAX];
void backpack(int i){
	if(i>n){
		if(cp>bestp){
			bestp=cp;
			for(int i=1;i<n;i++){
				order[i]=x[i];
			}
		}
	}
	else{
		for(int j=0;j<=1;j++){
			x[i] = j;
			if(cw+w[i]*x[i]<=c){
                 cp+=p[i]*x[i];
                 cw+=w[i]*x[i];
                 backpack(i+1);
                 cp-=p[i]*x[i];
                 cw-=w[i]*x[i];
            }
		}
	}
}
int main()
{
	cin>>n>>c;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		cin>>w[i];
	}
	backpack(1);
	cout<<bestp<<endl;
	for(int i=1;i<=n;i++){
		cout<<order[i]<<" ";
	}
	return 0;
}
