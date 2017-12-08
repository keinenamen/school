#include <iostream>
#include <cmath>
#include <cstdio>
using namespace std;
const double eps=1e-5;
const int maxn=1005;
struct node{
	double x,y;
}p[maxn];
double area(node a,node b)
{
	return (a.x*b.y-a.y*b.x)/2.0;
}
int main()
{
	int T,n,i;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		for(i=0;i<n;i++)
			scanf("%lf%lf",&p[i].x,&p[i].y);
		double sum=0,ans=0,x=0,y=0;
		for(i=1;i<=n;i++)
		{
			double tp=area(p[i%n],p[i-1]);
			sum+=tp;
			x+=tp*(p[i%n].x+p[i-1].x)/3.0;
			y+=tp*(p[i%n].y+p[i-1].y)/3.0;
		}
		if(fabs(sum)<=eps)
			printf("0.000 0.000\n");
		else
			printf("%.3lf %.3lf\n",fabs(sum),(x+y)/sum);

	}
	return 0;
}

