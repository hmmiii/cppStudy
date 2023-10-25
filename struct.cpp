#include <iostream>
using namespace std;

// 구조체 : 여러 가지 자료형의 데이터 집합을 저장할 수 있는 새로운 자료형을 정의한 것
// 자바스크립트로 치면 배열과 유사하다. 자바스크립트의 배열에는 기본적으로 모든 자료형을 담을 수 있다.

// 구조체 데이터를 처리하는 함수는 C언어에서는 구조체와 별개의 함수로 정의해야 하지만, C++에서는 하나의 함수로 묶을 수 있음.

struct Person {
    char name[50];
    int age;

    void initialize(const char *name, int age) {
        strncpy(this->name, name, sizeof(this->name));
        this->age = age;
    }
};

// 다만 이런 일은 클래스를 사용해서 하곤 한다.

constexpr double PI{3.14};

struct structName{
    int age;
    char name[20];
};

structName person = {29, "KIM"};

struct C2dType{
    double x, y;
};

struct CircleType{
    C2dType center;
    double radius;
};

double circleArea(CircleType c){
    return c.radius * c.radius * PI;
}

int main()
{
    CircleType c1 ={{0,0}, 40};

    cout << "원의 면적 : " << circleArea(c1) << endl;
    
    return 0;
}
