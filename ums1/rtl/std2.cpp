#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int N=3010;
int n,m;
char s[N];
int c[255][2];
int f[N][N];
bool vis[123];
int main(){
    //cin>>m>>n;
    scanf("%s",s+1);
    n = strlen(s + 1);
    for (int i = 1; i <= n; ++i)
        if (!vis[s[i] - 'a']) {
            vis[s[i] - 'a'] = true;
            ++m;
        }
    for(int i=1;i<=m;++i){
        char op[2];
        int a,b;
        scanf("%s %d %d",op,&a,&b);
        c[op[0]][0]=a;
        c[op[0]][1]=b;
	}
	memset(f,0x3f,sizeof f);
	for(int i=1;i<=n;++i)f[i][i]=0;
	for(int i=0;i<=n+1;++i){
	    for(int j=0;j<i;++j)f[i][j]=0;
	}
	for(int k=1;k<=n;++k){
	    for(int i=1;k+i<=n;++i){
	    	int j=k+i;
	        f[i][j]=min(f[i+1][j]+min(c[s[i]][0],c[s[i]][1]),
			            f[i][j-1]+min(c[s[j]][0],c[s[j]][1]));
			if(s[i]==s[j]){
				if(j-i==1)f[i][j]=0;
			    else f[i][j]=min(f[i][j],f[i+1][j-1]);
			}
		}
	}
	cout<<f[1][n]<<endl;
}
