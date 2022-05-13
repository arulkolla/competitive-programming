#include<bits/stdc++.h>
#define rep(i,s,t) for(int i=s;i<t;i++)
#define per(i,s,t) for(int i=t-1;i>=s;i--)
using namespace std;
const int mod=1e9+7;
typedef long long ll;
const int maxn=2e3+10;
int dy[]={0,0,1,-1};
int dx[]={1,-1,0,0};
char g[maxn][maxn];
bool vis[maxn][maxn];
int n,m,sx,sy,a,b;
struct node{
    int x,y,l,r;
    bool operator < (const node &b) const {
        return (l+r)>(b.l+b.r);
    }
};
bool check(int x,int y) {
    return x<0||x>=n||y<0||y>=m||vis[x][y]||g[x][y]=='*';
}
int main() {
    scanf("%d%d%d%d%d%d",&n,&m,&sx,&sy,&a,&b);
    rep(i,0,n) scanf("%s",g[i]); sx--,sy--;
    priority_queue<node> q;
    vis[sx][sy]=1; q.push({sx,sy,0,0}); int ans=1;
    while (!q.empty()) {
        node t=q.top(); q.pop();
        //cout<< t.x << " " << t.y << " " << t.l << " " << t.r <<endl;
        rep(i,0,4) {
            if (t.l+(i==3)>a||t.r+(i==2)>b) continue;
            int x=dx[i]+t.x,y=dy[i]+t.y;
            if (check(x,y)) continue; ans++;
            vis[x][y]=1; q.push({x,y,t.l+(i==3),t.r+(i==2)});
        }
    }
    //rep(i,0,n) { rep(j,0,m) printf("%d ",vis[i][j]); puts(""); }
    printf("%d\n",ans);
    return 0;
}