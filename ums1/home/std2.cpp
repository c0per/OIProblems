#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
using namespace std;
const int inf=1000000010;//要比hp大
struct node{
    int u,v,w,next;}e[100010];//边数组开双倍
int n,m,hp,tot=0;
int b[10010],c[10010];
int head[10010],d[10010];
bool vis[10010];
priority_queue<int,vector<int>,greater<int> >q;//小根堆
void addedge(int x,int y,int t){
    tot++;
    e[tot].u=x;
    e[tot].v=y;
    e[tot].w=t;
    e[tot].next=head[x];
    head[x]=tot;
    return;}
bool check(int x){
    if(x<b[1]||x<b[n])return false;
    int i;
    for(i=1;i<=n;i++)d[i]=inf;
    for(i=1;i<=n;i++)
        if(b[i]>x)vis[i]=true;
            else vis[i]=false;
    d[1]=0;q.push(1);
    while(!q.empty()){
        int now=q.top();
        q.pop();
        if(vis[now])continue;
        vis[now]=true;
        for(i=head[now];i;i=e[i].next)
            if(d[e[i].v]>e[i].w+d[now]){
                d[e[i].v]=e[i].w+d[now];
                q.push(e[i].v);}}
    if(d[n]<=hp)return true;
        else return false;}
int main(){
    int i,j,k,t,ans,maxcost=0;
    scanf("%d%d%d",&n,&m,&hp);
    for(i=1;i<=n;i++){
        scanf("%d",&b[i]);
        c[i]=b[i];}
    for(i=1;i<=m;i++){
        scanf("%d%d%d",&j,&k,&t);
        if(j==k)continue;
        addedge(j,k,t);
        addedge(k,j,t);}
    sort(c+1,c+n+1);//二分c数组更快 否则会T一个点
    int l=1,r=n,mid;
    if(!check(c[n])){
        printf("AFK\n");return 0;}
    ans=c[n];
    while(l<=r){
        mid=(l+r)>>1;
        if(check(c[mid])){
            ans=c[mid];
            r=mid-1;}
            else l=mid+1;}
    printf("%d\n",ans);
return 0;}
