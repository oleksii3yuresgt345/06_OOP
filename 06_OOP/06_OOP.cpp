#include <iostream>
using namespace std;

class Point
{
    int x;
    int y;
public:
    Point()
    {
        x = y = 0;
    }
    Point(int value)
    {
        this->x = value;
        this->y = value;
    }
    Point(int x, int y)
    {
        this->x = x;
        this->y = y;
    }
    void Print()
    {
        cout << "X : " << x << ". Y : " << y << endl;
    }
    Point Plus(const Point &other)
    {
        Point res(this->x + other.x, this->y + other.y);
        return res;
    }
    Point Minus(const Point &other)
    {
        Point res(this->x - other.x, this->y - other.y);
        return res;
    }

    //Overload operator
    //void operator [symbol operator]() {}
#pragma region Математичні оператори
    Point operator +(const Point& other)
    {
        Point res(this->x + other.x, this->y + other.y);
        return res;
    }
    Point operator -(const Point& other)
    {
        Point res(this->x - other.x, this->y - other.y);
        return res;
    }
    Point operator *(const Point& other)
    {
        Point res(this->x * other.x, this->y * other.y);
        return res;
    }
    Point operator /(const Point& other)
    {
        Point res(this->x / other.x, this->y / other.y);
        return res;
    }
#pragma endregion
#pragma region Binary Operators
    Point operator +=(const Point& other)
    {
        this->x += other.x;
        this->y += other.y;
        return *this; // розіминування this;
    }

    Point operator =(const Point& other)
    {
        this->x = other.x;
        this->y = other.y;
        return *this;
    }
#pragma endregion

#pragma region Uno Operators
    Point operator -()
    {
        //return Point(this->x * -1, this->y * -1);
        return Point(-x, -y);
    }
#pragma endregion

#pragma region Logic Operators
    bool operator > (const Point& other)
    {
        /*if ((this->x + this->y) > (other.x + other.y))
            return true;
        else
            return false;*/
        return ((this->x + this->y) > (other.x + other.y));
    }
    bool operator < (const Point& other)
    {
        return ((this->x + this->y) < (other.x + other.y));
    }
    bool operator >= (const Point& other)
    {
        return ((this->x + this->y) >= (other.x + other.y));
    }
    bool operator <= (const Point& other)
    {
        return ((this->x + this->y) <= (other.x + other.y));
    }

    bool operator == (const Point& other)
    {
        return ((this->x == other.x) && (this->y == other.y));
    }

    bool operator != (const Point& other)
    {
        //return ((this->x != other.x) || (this->y != other.y));

        return !(*this == other);
    }

#pragma endregion


};

int main()
{
    int a = 5, b = 4;
    cout << a + b << endl;
    cout << a - b << endl;
    cout << a * b << endl;

    Point p1(5, 3);
    Point p2(7, 8);
   /* Point res = p1 + p2;
    res = p1 - p2;
    res = p1 * p2;*/

    Point res = p1.Plus(p2);
    cout << "Point 1 : "; p1.Print();
    cout << "Point 2 : "; p2.Print();
    cout << "Res : "; res.Print();
    res = p1.Minus(p2);
    cout << "Res : "; res.Print();


    res = p1 + p2;//res = p1.operator+(p2);
    cout << "Res : "; res.Print();

    res = p1 - p2;//res = p1.operator-(p2);
    cout << "Res : "; res.Print();

    res = p1 * p2;//res = p1.operator*(p2);
    cout << "Res : "; res.Print();

    res = p1 / p2;//res = p1.operator/(p2);
    cout << "Res : "; res.Print();



    cout << "Point 1 : "; p1.Print();
    cout << "Point 2 : "; p2.Print();
    p1 += p2;
    cout << "Point 1 : "; p1.Print();
    cout << "Point 2 : "; p2.Print();

    res = -p1;
    cout << "Res : "; res.Print();
    cout << "------------------------------" << endl;
    cout << "Point 1 : "; p1.Print();
    cout << "Point 2 : "; p2.Print();
    cout << "Res : "; res.Print();

    res = p1 = p2;
    cout << "------------------------------" << endl;
    cout << "Point 1 : "; p1.Print();
    cout << "Point 2 : "; p2.Print();
    cout << "Res : "; res.Print();
    
    if (p1 > p2)
        cout << "p1 > p2" << endl;
    else
        cout << "p1 < p2" << endl;

    if (p1 < p2)
        cout << "p1 < p2" << endl;
    else
        cout << "p1 > p2" << endl;

    if (p1 == p2)
        cout << "p1 == p2" << endl;
    else
        cout << "p1 != p2" << endl;

    if (p1 != p2)
        cout << "p1 != p2" << endl;
    else
        cout << "p1 == p2" << endl;
}
