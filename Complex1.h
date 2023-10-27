#pragma once
#include <iostream>
using namespace std;

/*
복소수를 표현하는 클래스
복소수의 사칙연산 및 켤레복소수를 구하는 멤버함수를 포함한다.
실수부의 값이 a, 허수부의 값이 b일때 a+jb로 표현할 수 있도록 한다.
*/

class Complex1{
    double rPart, iPart;
public:
    Complex1(double r=0, double i=0) : rPart{r}, iPart{i} {}
    Complex1 conj() const { // 켤레복소수 만드는 멤버 함수
        // 생성자 함수를 직접 호출해서 사용할 경우 임시 객체가 생성된다. 이런 경우 문장 실행 후 임시 객체는 소멸한다.
        return Complex1(rPart, -iPart);
    }
    Complex1 add(const Complex1& c) const { 
        return Complex1(rPart + c.rPart, iPart + c.iPart);
    }
    Complex1 sub(const Complex1& c) const {
        return Complex1(rPart - c.rPart, iPart - c.iPart);
    }
    Complex1 mul(const Complex1& c) const;
    Complex1 div(const Complex1& c) const;
    void display() const;
};

Complex1 Complex1::mul(const Complex1& c) const{
    double r = rPart * c.rPart - iPart * c.iPart;
    double i = rPart * c.rPart + iPart * c.iPart;
    return Complex1(r, i);
}

Complex1 Complex1::div(const Complex1& c) const{
    double d = c.rPart * c.rPart + c.iPart * c.iPart;
    Complex1 c1 = mul(c.conj());
    return Complex1(c.rPart/d, c.iPart/d);
}

void Complex1::display() const {

    cout << "(" << rPart;
    if (iPart > 0)
        cout << "+j" << iPart;
    else if (iPart < 0)
        cout << "-j" << -iPart;
    cout << ")";

}