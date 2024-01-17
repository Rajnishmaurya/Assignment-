#include<bits/stdc++.h>
using namespace std;

struct Point{
    double X,Y;
};

struct Circle{
    Point C;
    double R;
};

double distance(Point&a,Point&b)
{
    return sqrt(pow(a.X-b.X,2)+pow(a.Y-b.Y,2));
}

bool is_points_inside(Circle& c , Point& p)
{
    return distance(c.C,p)<=c.R;
}

bool is_all_points_inside(Circle& c ,vector<Point>& P)
{
    for(auto temp:P)
    {
        if(!is_points_inside(c,temp))
        return false;
    }
    return true;
}

Circle circle_from(Point& A, Point& B)
{
    Point C={(A.X+B.X)/2,(A.Y+B.Y)/2};
    return {C,distance(A,B)};
}

Point get_circle_center(double bx,double by,double cx,double cy)
{
    double B=bx*bx+by*by;
    double C=cx*cx+cy*cy;
    double D=bx*cy-by*cx;
    return {
        (cy*B-by*C)/(2*D),(bx*C-cx*B)/(2*D)
    };
}

Circle circle_from(Point& A,Point& B,Point& C)
{
    Point I=get_circle_center(B.X-A.X,B.Y-A.Y,C.X-A.X,C.Y-A.Y);
    I.X+=A.X;
    I.Y+=A.Y;
    return {I,distance(I,A)};
}

Circle smallest_area_circle(vector<Point>& P,int n)
{
    if(n==0)
    {
        return {{0,0},0};
    }
    if(n==1)
    {
        return {P[0],0};
    }

    Circle temp={{0,0},INT_MAX};

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            Circle curr=circle_from(P[i],P[j]);

            if(curr.R < temp.R && is_all_points_inside(curr,P))
            {
                temp=curr;
            }
        }
    }

    for(int i=0;i<n;i++)
    {
        for(int j=i+1;j<n;j++)
        {
            for(int k=j+1;k<n;k++)
            {
                Circle curr=circle_from(P[i],P[j],P[k]);

                if(curr.R < temp.R && is_all_points_inside(curr,P))
                {
                    temp=curr;
                }
            }
        }
    }
    return temp;

}
int main()
{
    int n;
    cin>>n;
    vector<Point>P;
    for(int i=0;i<n;i++)
    {
        double x,y;
        cin>>x>>y;
        P.push_back({x,y});
    }

    Circle result=smallest_area_circle(P,n);
    cout<<result.C.X <<" "<<result.C.Y<<" "<<result.R;

}
