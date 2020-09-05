#include<cstdio>
#include<cctype>
#define N 100005
#define int long long
const int mod=1e9+7;

int n,m;
int val[N];

struct Matrix{
	int m[4][4];

	void clear(){
		for(int i=0;i<4;i++){
			for(int j=0;j<4;j++)
				m[i][j]=0;
		}
	}

	void init(){
		for(int i=0;i<4;i++)
			m[i][i]=1;
	}

	void print(){
		for(int i=1;i<=2;i++){
			for(int j=1;j<=2;j++)
				printf("i=%lld,j=%lld,m=%lld\n",i,j,m[i][j]);
		}
	}

	bool empty(){
		if(m[1][1]!=1) return 0;
		if(m[1][2]!=0) return 0;
		if(m[2][1]!=0) return 0;
		if(m[2][2]!=1) return 0;
		return 1;
	}

	Matrix operator*(const Matrix &y) const {
		Matrix z; z.clear();
		for(int i=1;i<=2;i++){
			for(int k=1;k<=2;k++){
				for(int j=1;j<=2;j++)
					z.m[i][j]=(z.m[i][j]+m[i][k]*y.m[k][j])%mod;
			}
		}
		return z;
	}

	friend Matrix operator+(Matrix a,Matrix b){
		Matrix c;c.clear();
		for(int i=1;i<=2;i++){
			for(int j=1;j<=2;j++)
				c.m[i][j]=(a.m[i][j]+b.m[i][j])%mod;
		}
		return c;
	}

};

Matrix dw,fir;
Matrix mat[N<<2],lazy[N<<2];

int getint(){
	int x=0;char ch=getchar();
	while(!isdigit(ch)) ch=getchar();
	while(isdigit(ch)) x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	return x;
}

Matrix ksm(Matrix a,int b){
	Matrix ret; ret.clear(); ret.init();
	while(b){
		if(b&1) ret=ret*a;
		a=a*a;
		b>>=1;
	}
	return ret;
}

void pushup(int cur){
	mat[cur]=mat[cur<<1]+mat[cur<<1|1];
}

void build(int cur,int l,int r){
	mat[cur].clear();
	lazy[cur].clear();
	lazy[cur].init();
	if(l==r){
		mat[cur]=fir*ksm(dw,val[l]-1);
		return;
	}
	int mid=l+r>>1;
	build(cur<<1,l,mid);
	build(cur<<1|1,mid+1,r);
	pushup(cur);
}

void pushdown(int cur,int l,int r){
	if(lazy[cur].empty()) return;
	mat[cur<<1]=mat[cur<<1]*lazy[cur];
	lazy[cur<<1]=lazy[cur<<1]*lazy[cur];
	mat[cur<<1|1]=mat[cur<<1|1]*lazy[cur];
	lazy[cur<<1|1]=lazy[cur<<1|1]*lazy[cur];
	lazy[cur].clear();
	lazy[cur].init();
}

void modify(int cur,int ql,int qr,int l,int r,Matrix x){
	if(ql<=l and r<=qr){
		mat[cur]=mat[cur]*x;
		lazy[cur]=lazy[cur]*x;
		return;
	}
	pushdown(cur,l,r);
	int mid=l+r>>1;
	if(ql<=mid)
		modify(cur<<1,ql,qr,l,mid,x);
	if(mid<qr)
		modify(cur<<1|1,ql,qr,mid+1,r,x);
	pushup(cur);
}

Matrix query(int cur,int ql,int qr,int l,int r){
	if(ql<=l and r<=qr)
		return mat[cur];
	pushdown(cur,l,r);
	Matrix ret;ret.clear();
	int mid=l+r>>1;
	if(ql<=mid)
		ret=ret+query(cur<<1,ql,qr,l,mid);
	if(mid<qr)
		ret=ret+query(cur<<1|1,ql,qr,mid+1,r);
	return ret;
}

signed main(){
	dw.clear(); fir.clear();
	dw.m[1][1]=1;fir.m[1][1]=1;
	dw.m[1][2]=1;fir.m[1][2]=1;
	dw.m[2][1]=1;fir.m[2][1]=0;
	dw.m[2][2]=0;fir.m[2][2]=0;
	n=getint(),m=getint();
	for(int i=1;i<=n;i++)
		val[i]=getint();
	build(1,1,n);
	while(m--){
		if(getint()==1){
			int l=getint(),r=getint(),x=getint();
			modify(1,l,r,1,n,ksm(dw,x));
		}
		else{
			int l=getint(),r=getint();
			printf("%lld\n",query(1,l,r,1,n).m[1][2]%mod);
		}
	}
	return 0;
}
