#include<cstdio>
#include<cstring>
#include<cmath>
#include<iostream>
#include<algorithm>
using namespace std ;
template<class T>void read(T &x){
	x=0;int f=0;char ch=getchar();
	while(ch<'0'||ch>'9'){f|=(ch=='-');ch=getchar();}
	while(ch>='0'&&ch<='9'){x=(x<<1)+(x<<3)+(ch^48);ch=getchar();}
	x=f?-x:x; return ;
}
const int maxn=55;

int num1,num2;
int num[maxn],num3[maxn][maxn];
bool chaf;
char str[maxn],calstr[maxn][maxn];

namespace debug{
	inline void p_num(){
		for(int i=1;i<=num2;i++)
			printf("%d ",num[i]);
	}
}

namespace scan{
 
	inline bool isbigwr(char ch){
		return ch<='Z'&&ch>='A';
	}

	inline bool issmwr(char ch){
		return ch<='z'&&ch>='a';
	}

	inline bool isnum(char ch){
		return ch<='9'&&ch>='0';
	}

	inline char transbig(char x){
		return x+('A'-'a');
	}
	
	inline char transsm(char x){
		return x-('A'-'a');
	}

	
	inline int calnum(int i,int j,int k,bool f){
		int x=transsm(str[i])-'a'+1;int y;
		if(i==j) y=x;
		else y=str[j]-'a';
		if(f) num3[x][y]=k;
		else {return num3[x][y];}
	}
	
	inline void calu(int l,int r,int mpp){
		int rpos,mul=0;
		if(str[l]=='(') l++;
		if(isnum(str[r])){
			for(rpos=r;rpos>=l;rpos--)
				if(!isnum(str[rpos-1])) break;
			
			for(int i=rpos;i<=r;i++)
				mul=mul*10+(str[i]-'0');
		}
		else if(str[r]==')') r--,mul=1;
		//NO3 * 2
		
		for(int i=l;i<=rpos;){
			if(!chaf) num2++;
			int nn=i+1;
			while(1){
				if(isbigwr(str[nn])||str[nn]=='='||str[nn]=='+'||str[nn]=='(') break;
				nn++;
			}
			int j;int Num_=0;
			for(j=nn;j>=i;j--)
				if(!isnum(str[j])) break;
			for(int J=j+1;J<=nn;J++)
				Num_=10*Num_+(str[J]-'0');
			num[calnum(i,j,num2,0)]+=mpp*mul*(chaf?-Num_:Num_);	
			i=nn+1;	
		}
	}
	inline void cal(int l,int r){
		num1++;
		int fla=0,mtep=0;
		if(!isnum(str[l])) mtep=1;
		else{
			int rpp=l;
			for(;rpp<=r;rpp++)
				if(!isnum(str[rpp+1])) break;
			
			for(int i=l;i<=rpp;i++)
				mtep=mtep*10+(str[i]-'0');
			l=rpp+1;
		}
		for(int i=1;i<=r-l+1;i++) calstr[num1][i]=str[i+l-1];
		for(int i=l;i<=r;){
			
			if(str[i]=='(') fla=1;
			if(fla){
				int rs=l;
				for(;rs<=r;rs++) if(str[rs]=='+'||str[rs]=='-') break;
				calu(i,rs,mtep);i=rs+1;
			}
			else if(isbigwr(str[i])){
				if(!chaf) num2++;
				int nn=i+1;
				while(1){
					if(isbigwr(str[nn])||str[nn]=='='||str[nn]=='+'||str[nn]=='(') break;
					nn++;
				}
				nn--;
				
				int j,hasn;int Num_=0;
				
				for(j=nn;j>=i;j--)
					if(!isnum(str[j])) break;
				
				calnum(i,j,num2,1);	
				for(int J=j+1;J<=nn;J++)
					Num_=10*Num_+(str[J]-'0');
				num[calnum(i,j,num2,0)]+=mtep*(chaf?-Num_:Num_);	
				
				i=nn+1;			
			}
		}
	}

	inline void initstr(){
		int len=strlen(str+1);
		int l=1;
		for(int i=1;i<=len;i++){
			if(str[i]=='=') chaf=1;
			if(str[i]=='+'||str[i]=='=')
				cal(l,i-1),l=i+1;
		}
	}

	inline void clear(){
		memset(str,0,sizeof(str));
		memset(num,0,sizeof(num));
		memset(num3,0,sizeof(num3));
		memset(calstr,0,sizeof(calstr));
		num1=num2=chaf=0;
	}
}

namespace cal{
	inline void print(){
		bool flg=0;
		for(int i=1;i<=num2;i++)
			if(num[i]) {printf("No AMD!\n");flg=1;break;}
		if(!flg)printf("AMD Yes!\n");
	}
}

int main()
{
	scanf("%s",str+1);
	scan::initstr();
	cal::print();
	scan::clear();
	return 0;
}
