#pragma once
#include <iostream>
using namespace std;

class Complex2{
    double rPart, iPart;
public:
    Complex2(double r=0, double i=0) : rPart{r}, iPart{i} {}
    Complex2 operator + (const Complex2& c) const; // + 복소수 연산자
    Complex2 operator + (double r) const; // + 실수 연산자
    friend Complex2 operator + (double r, const Complex2& c); // frined 연산자
    double real()const{ return rPart; } // 실수부 값 반환
    double imag()const{ return iPart; } // 허수부 값 반환
    Complex2 operator += (const Complex2& c); // 복합 대입 연산자
    friend ostream& operator << (ostream& os, const Complex2& c);
    void display() const;
};

Complex2 Complex2::operator + (const Complex2& c) const{
    Complex2 tmp(*this);
    tmp.rPart += c.rPart;
    tmp.iPart += c.iPart;
    return tmp;

    // return Complex2(rPart + c.rPart, iPart + c.iPart); // 와도 동일.
}

// ComplexObj1 + 10.0 을 구현.
// 사실상 이 멤버 함수는 구현하지 않아도 묵시적 형변환으로 되긴 함.
Complex2 Complex2::operator + (double r) const{
    return Complex2(rPart + r, iPart);
}

/*
Complex2 operator + (double r, const Complex2& c) {
    return Complex2(r + c.real(), c.imag());
}
*/

Complex2 operator + (double r, const Complex2& c) {
    return Complex2(r + c.rPart, c.iPart);
}

Complex2 Complex2::operator += (const Complex2& c){
    rPart += c.rPart;
    iPart += c.iPart;
    return *this;
}

ostream& operator << (ostream& os, const Complex2& c){
    os << "(" << c.rPart;
    if (c.iPart > 0)
        os << "+j" << c.iPart;
    else if (c.iPart < 0)
        os << "-j" << -c.iPart;
    os << ")";

    return os;
}