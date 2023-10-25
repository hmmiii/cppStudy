#include <iostream>
using namespace std;

// 클래스란, 표현하고자 하는 대상(객체)의 데이터(속성)과 함께 그 대상이 할 수 있는 동작을 나타내는 함수(행위)들을 묶어서 선언한 것.
// c++에서 구조체와 클래스는 거의 유사하다.

constexpr double PI{3.14};

struct C2dType{
    double x, y;
};

class CircleClass{
    // 공개되지 않는 정보
    C2dType center;
    double radius;

    public: // 공개되는 정보, 여기서 공개란 외부에서 사용할 수 있음을 의미한다. 예를 들어 c1.init(0,0,10)은 가능하지만 c1.radius는 불가능.

        // 원을 만드는 함수
        const void init(double cx, double cy, double cr){
            center.x = cx;
            center.y = cy;
            radius = cr;
        };

        // 원의 넗이를 return하는 함수
        const double area() {
            return radius * radius * PI;
        };
};

int main()
{
    CircleClass c1, c2;

    c1.init(0,0,50);
    c2.init(20,-40,100);

    cout << "원1의 면적 : " << c1.area() << endl;
    cout << "원2의 면적 : " << c2.area() << endl;
    
    return 0;
}
