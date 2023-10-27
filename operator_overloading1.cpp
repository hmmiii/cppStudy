#include <iostream>
#include "Pencils.h"
#include "Complex2.h"
using namespace std;

/*
다중정의(overloading)
하나의 이름에 대하여 두 가지 이상의 서로 다른 선언을 하는 것

연산자 다중정의(operator overloading)
C++에 정의된 연산자를 사용자가 선언한 클래스의 객체에 대하여 사용할 수 있도록 정의 하는 것

연산자 다중정의는 이미 c++에 구현되어 있기도 하다. 피연산자의 자료형에 따라 연산자의 처리 절차는 다르게 되어 있다.
이처럼 개념적으로는 덧셈이므로 같지만, 처리 절차가 다른 경우에 연산자 다중정의가 되어있다.
이를 이용해서 공부하면서 만든 Counter 클래스가 피연산자일 경우와 같은 처리 절차를 정의해볼 수 있다.

10 + 20 -> 피연산자의 자료형이 int
10.0 + 20.0 -> 피연산자의 자료형이 double

연산자 다중정의를 할 때 주의 사항
연산자의 의미를 임의로 바꾸지 않는다.
연산자의 고유한 특성이 유지되도록 한다.
    - 연산자의 우선순위나 피연산자 수 불변
    - 전위표기와 후위표기 연산자의 의미 유지

주요 연산자 다중정의 대상

클래스의 객체 간 대입 연산자 및 이동 대입 연산자
    특히, 동적 할당을 받는 포인터를 포함하는 경우 고려할 필요 있음
수치형 객체의 산술 연산자 다중 정의
    교환 법칙 함께 고려
두 객체를 비교하기 위한 관계 연산자의 다중 정의
스트림 입력 및 출력을 위한 >>, << 연산자

다중정의가 불가능한 연산자

멤버 선택 연산자 (.)
멤버에 대한 포인터 연산자 (.*)
유효범위 선택 연산자 (::)
조건 연산자 (? :)


단항연산자의 다중 정의
b = a++
b = ++a
a = --b
a = b--

단항 연산자 다중정의 구문
ReturnClass ClassName::operator opSymbol(int){
    ....
}

opSymbol : --, ++ 등의 단항연산자 기호
전위 표기의 경우 형식 매개변수는 없음.
후위 표기에는 전달을 하는데, 인수 전달이 아니라 후위표기임을 나타내는 용도.


이항 연산자의 다중 정의 구문
ReturnClass ClassName::operator opSymbol(argClass arg){
    ....
}
opSymbol : +, -, *, /, &&, \\ 등의 이항연산자 기호
객체 자신이 좌측 피연산자, arg가 우측 피연산자가 됨.

다만, 10 + obj 같은 경우에는 10은 int형인데 int를 새롭게 정의할 수 없다.
특정 클래스에 속하지 않는 외부 함수로 만들고 인수로 10,obj를 받은 다음, 처리한다. 
이 경우 privat 멤버를 사용하려고 하기 때문에, 문제가 발생하는데, 두 가지 해결 방법 중 선택해서 사용한다.
1. private 멤버를 엑세스 할 수 있는 pubcli 멤버 함수를 만든다.
    public:
        double real(){ return rPart; }
        double imag(){ return iPart; }

    Complex2 operator + (double r, const Complex2& c) {
        return Complex2(r + c.real(), c.imag());
    }
2. 연산자를 friend로 선언
    public:
        Complex2 operator + (double r, const Complex2& c);

    이렇게 해주면 friend로 지정된 연산자나함수에서는 private 멤버를 자유롭게 사용 가능하다.

    Complex2 operator + (double r, const Complex2& c) {
        return Complex2(r + c.rPart, c.iPart);
    }


스트림 출력 연산자 (<<) 다중정의

Complex2 c(1.0, 2.0);
cout << c;

이 경우에도 cout은 직접 만든 클래스의 멤버가 아니기 때문에, 특정 클래스에 속하지 않는 외부 함수로 만든다.

friend ostream& operator << (ostream& os, const Complex2& c);

ostream& operator << (ostream& os, const Complex2& c){
    os << "(" << c.rPart;
    if (c.iPart > 0)
        os << "+j" << c.iPart;
    else if (c.iPart < 0)
        os << "-j" << -c.iPart;
    os << ")";

    return os;
}

단, 
cout << " 반환할 값 :" << value;
인 경우, 우선 순위를 잘 설정해야 한다.
*/

// 단항 연산자 다중정의

// ++ 전위 표기
class IntClass1{
    int a;
    public:
        IntClass1(int n=0) : a{n} {}
        IntClass1& operator ++(){
            ++a;
            return *this;
        }
        int getValue() const { return a; }
};

// ++ 후위 표기
class IntClass2{
    int a;
    public:
        IntClass2(int n=0) : a{n} {}
        IntClass2 operator ++(int){
            IntClass2 tmp(*this); // 연산 전 값 저장
            ++a; // 전위 표기로 a 자체는 ++
            return tmp; // 연산 전 값을 반환
        }
        int getValue() const { return a; }
};

int main()
{
    // 단항 연산자 전위 후위 표기법 다중 정의
    cout << "-------------------다중정의 단항 연산자 전위, 후위 표기법 테스트"<< endl;

    IntClass1 i;

    cout << (++i).getValue() << endl;

    IntClass2 i2;

    cout << (i2++).getValue() << endl;

    cout << "-------------------다중정의 단항 연산자 전위, 후위 표기법 Pencils 클래스"<< endl;

    Pencils p1 = Pencils(5, 7); // 자바스크립트 스타일? 의 인스턴스 만들기
    Pencils p2(23);

    p1.display();
    (++p1).display();
    p1.display();
    p2.display();
    p1 = p2++;
    p1.display();
    p2.display();

    cout << "-------------------다중정의 이항 연산자 Complex2 클래스"<< endl;

    Complex2 a(10, 20);
    Complex2 b(5, -3);

    cout << a << " + " << b << " = " << a + b << endl;
    
    return 0;
}
