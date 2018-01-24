#include<iostream>
using namespace std;

class Area
{
public:
    float dim1;
    float dim2;
    public float area(float x,float y)
    {
        return x*y;
    }
};
class Perimeter
{
public:
    float dim3;
    float dim4;
    public float perimeter(float x,float y)
    {
        return (2*(x + y));
    }
};
class rectangle : public Area,public Perimeter
{
    rectangle(float x,float y)
    {
        dim1 =x;
        dim2 =y;
    }
};
int main()
{
    float x,y;
    rectangle r;
    x = r.Area(4.5,5.5);
    y = r.Perimeter(4.5,5.5);
    cout<<"area is "<<x;
    cout<<"perimeter is "<<y;
    return 0;
}
