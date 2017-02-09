/*
 * Problem : Orchard Trees
 * Link : https://uva.onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&page=show_problem&problem=79
 */



#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

typedef struct point{
    double x,y;
    point(){
        
    }
    point(double _x,double _y){
        x=_x;
        y=_y;
    }
}point;

double triangle_area(point a, point b, point c) {
    double area = (a.x*b.y - a.y*b.x + b.x*c.y - b.y*c.x + c.x*a.y - c.y*a.x) / 2.0;
    if (area < 0) return -area;
    return area;
}

bool is_inside(point p1, point p2, point p3, point p){
    double sum_area,t_area;
    t_area=triangle_area(p1,p2,p3);
    sum_area=triangle_area(p1,p2,p);
    sum_area+=triangle_area(p1,p,p3);
    sum_area+=triangle_area(p,p2,p3);
    if(sum_area<=t_area+1e-7)
        return true;
    else
        return false;
    
}

double min_of_three(double x,double y, double z){
    return min(x,min(y,z));
    
}

double max_of_three(double x,double y, double z){
    return max(x,max(y,z));
}

int main(){
    while(1)
    {
        double x1,y1,x2,y2,x3,y3;
        cin>>x1>>y1>>x2>>y2>>x3>>y3;
        point a(x1,y1),b(x2,y2),c(x3,y3),p;
        if(x1==0 && y1==0 && x2==0 && y2==0 && x3==0 && y3==0)
            break;
        int lowx,lowy,highx,highy;
        int counter=0;
        lowx=ceil(min_of_three(x1,x2,x3));
        highx=floor(max_of_three(x1,x2,x3));
        lowy=ceil(min_of_three(y1,y2,y3));
        highy=floor(max_of_three(y1,y2,y3));
        lowx = max(lowx,1);
        highx = min(highx,99);
        lowy = max(lowy,1);
        highy= min(highy,99);
        for(int i=lowx;i<=highx;i++){
            for(int j=lowy;j<=highy;j++){
                p.x=i;
                p.y=j;
                if(is_inside(a,b,c,p))
                    counter++;
            }
        }
     printf("%4d\n",counter);   
    }    
}
