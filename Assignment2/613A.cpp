#include<bits/stdc++.h>
using namespace std;
#define maxn 111111
#define INF 0x7f7f7f7f7f
#define PI acos(-1.0)


struct node
{
    double x,y;
}o,p[maxn];
int n;
double dis(node a,node b)
{
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double get_dis(node a,node b,node c)
{
    double A=dis(b,c),B=dis(a,c),C=dis(a,b);
    if(A*A+C*C<=B*B)return A;
    if(B*B+C*C<=A*A)return B;
    double s=abs((a.x-c.x)*(b.y-c.y)-(a.y-c.y)*(b.x-c.x));
    return s/dis(a,b);
}

int main()
{
    while(~scanf("%d%lf%lf",&n,&o.x,&o.y))
    {
        double Min=INF,Max=0;
        for(int i=0;i<n;i++)
        {
            scanf("%lf%lf",&p[i].x,&p[i].y);
            double temp=dis(p[i],o);
            Max=max(Max,temp);
        }
        for(int i=0;i<n;i++)
        {
            int j=(i+1)%n;
            Min=min(Min,get_dis(p[i],p[j],o));
        }
        printf("%.10lf\n",(Max*Max-Min*Min)*PI);
    }
    return 0;
}
