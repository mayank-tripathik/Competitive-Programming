/*
 * Problem: http://www.spoj.com/problems/VMILI/
 * Solution: Repeatedly finding convex hull by removing previous hull points
 */
 

#include<bits/stdc++.h>
#define PI 3.141592
const double eps=1e-9;
using namespace std;


struct point{
    int x,y,index;
    point(){
       
     }
    point(int _x, int _y){
        x=_x;
        y=_y;
    }
};

point start;

void set_p0_as_min_point(vector<point> &points){
    point min_point=points[0];
    int min_point_index=0;
    for(int i=1;i<points.size();i++){
        if((points[i].y<min_point.y) || ((points[i].y==min_point.y) && (points[i].x<min_point.x))){
            min_point=points[i];
            min_point_index=i;
        }
    }
    swap(points[0],points[min_point_index]);
    start=points[0];
}

int dist(point p1, point p2){
    int distt;
    distt=pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2);
    return distt;
}

point next_to_top(stack<point> &mystack){
    point point_top=mystack.top();
    mystack.pop();
    point next_top=mystack.top();
    mystack.push(point_top);
    return next_top;
}


int orientation(point p, point q, point r)
{
    int val = (q.y - p.y) * (r.x - q.x) -
            (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;
    return (val > 0)? 1: 2; 
}

int comp(const void *vp1, const void *vp2)
{
	point *p1 = (point *)vp1;
	point *p2 = (point *)vp2;

	int o = orientation(start, *p1, *p2);
	if (o == 0)
		return (dist(start, *p2) >= dist(start, *p1))? -1 : 1;

	return (o == 2)? -1: 1;
}

stack<point> convex_hull(vector<point> &points){
    set_p0_as_min_point(points);
    int n=points.size();
	if(n>1)
		qsort(&points[1], points.size()-1, sizeof(point), comp);
    stack<point> S;
	S.push(points[0]);
	if(n>2)
	{
		int i=0;
		while((!orientation(points[i],points[i+1],points[i+2]))&&(i<n-2))
		{
			i++;
		}
		if(i<(n-2))
		{
			S.push(points[++i]);
			S.push(points[++i]);
			for (; i < n; i++)
			{
				while (orientation(next_to_top(S), S.top(), points[i]) != 2)
					S.pop();
				S.push(points[i]);
			}
		}
		else
		{
			S.push(points[i+1]);
		}
	}
	else if(n==2)
	{
		S.push(points[1]);
	}
    return S;
}
       
int main() {
    int n,fences=0;
    cin>>n;
    vector<point> points(n);
    vector<bool> included(n,false);
    for(int i=0;i<n;i++){
        int x,y;
        scanf("%d%d",&x,&y);
        points[i].x=x;
        points[i].y=y; 
        points[i].index=i;
    }
	while(n>=3)
	{
		stack<point> S=convex_hull(points);
		int hull_point_count=0;        
		while(!S.empty())
		{
			point p=S.top();
			S.pop();
			hull_point_count++;
			included[p.index]=1;
		}
        vector<point> temp;
		for(int i=0;i<points.size();i++)
		{
			if(!included[points[i].index])
				temp.push_back(points[i]);
		}
        points.clear();
		for(int i=0;i<temp.size();i++)
		{
			points.push_back(temp[i]);
		}
		n=n-hull_point_count;
		fences++;
	}
	printf("%d\n",fences);
	return 0;
}
