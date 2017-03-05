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

void set_p0_as_min_point(vector<point> &poles){
    point min_point=poles[0];
    int min_point_index=0;
    for(int i=1;i<poles.size();i++){
        if((poles[i].y<min_point.y) || ((poles[i].y==min_point.y) && (poles[i].x<min_point.x))){
            min_point=poles[i];
            min_point_index=i;
        }
    }
    swap(poles[0],poles[min_point_index]);
    start=poles[0];
}


float polar_angle(point p0, point p1){
    int y=p1.y-p0.y;
    int x=p1.x-p0.x;
    float ang=atan2(y,x)*180/PI;
    return ang;
}

int dist(point p1, point p2){
    int distt;
    distt=pow((p2.x-p1.x),2)+pow((p2.y-p1.y),2);
    return distt;
}

bool compare(const point &point1, const point &point2){
    float angle1=polar_angle(start,point1);
    float angle2=polar_angle(start,point2);
    if(angle1<angle2)
       return true;
    else if(angle1==angle2){
        if(dist(start,point1)<dist(start,point2))
            return true;
        else
            return false;
    }
    else
       return false;
}

point next_to_top(stack<point> &mystack){
    point point_top=mystack.top();
    mystack.pop();
    point next_top=mystack.top();
    mystack.push(point_top);
    return next_top;
}

void print(vector<point> &poles){
    cout<<"sorted point\n"<<endl;
    for(int i=0;i<poles.size();i++)
        cout<<poles[i].x<<","<<poles[i].y<<endl;
}

int orientation(point p, point q, point r)
{
	int val = (q.y - p.y) * (r.x - q.x) -
			(q.x - p.x) * (r.y - q.y);

	if (val == 0) return 0;
	return (val > 0)? 1: 2; 
}

stack<point> convex_hull(vector<point> &poles){
    stack<point> mystack;
    if(poles.size()<3){
        for(int i=0;i<poles.size();i++)
            mystack.push(poles[i]);
        return mystack;
    }
    set_p0_as_min_point(poles);
    sort(poles.begin()+1,poles.end(),compare);
    int m = 1;
    for (int i=1; i<poles.size(); i++)
    {
        while (i < poles.size()-1 && orientation(start, poles[i], poles[i+1]) == 0)
            i++;
        poles[m] = poles[i];
        m++;
    }   
    poles.resize(m);
    mystack.push(poles[0]);
    mystack.push(poles[1]);
    mystack.push(poles[2]);
    for(int i=3;i<poles.size();i++){
        while(orientation(next_to_top(mystack), mystack.top(), poles[i]) != 2){
            mystack.pop();
        }
        mystack.push(poles[i]);
    }
    return mystack;
}

bool PointInsidePolygon(const point P, const vector<point> &poly){
    bool in=0;
    int n=poly.size();
    
    for(int i=0,j=n-1;i<n;j=i++){
        if((poly[i].y <= P.y && P.y < poly[j].y) || (poly[j].y <= P.y && P.y < poly[i].y)){
            if(P.x-eps < (poly[j].x-poly[i].x)*(P.y-poly[i].y)*1.0/(poly[j].y-poly[i].y)+poly[i].x) in^=1;
        }
    }
    
    return in;
}


double signed_area(const vector<point> &poly){
    int n=poly.size();
    int S=0;
    
    for(int i=1;i<n;i++) S+=poly[i].x*(poly[i+1<n? i+1:i+1-n].y-poly[i-1].y);
    S+=poly[0].x*(poly[1].y-poly[n-1].y);
    
    return S/2.0;
}

int main() {
    vector<point> polygon[20];
    vector<bool> included(20,false);
    int k=0;
    double area=0.0;
    while(1){
        int n;
        cin>>n;
        if(n==-1)
            break;
        vector<point> houses(n);
        for(int i=0;i<n;i++){
            cin>>houses[i].x>>houses[i].y;
            houses[i].index=i;
        }
        stack<point> S=convex_hull(houses);
        int s_Size=S.size();
        while(!S.empty())
        {
            point p=S.top();
            polygon[k].push_back(p);
            S.pop();
        }
        k++;        
    }
    point a;
    vector<point> attacks;
    while(cin>>a.x){
        cin>>a.y;
        attacks.push_back(a);
    }
    for(int i=0;i<attacks.size();i++){
        point p=attacks[i];
        for(int j=0;j<k;j++){
            if(PointInsidePolygon(p, polygon[j]) && !included[j]){
                area+=fabs(signed_area(polygon[j]));
                included[j]=true;
                break;
            }
        }
    }
    cout << fixed;
    cout << setprecision(2);
    cout<<area<<endl;
    return 0;
}
