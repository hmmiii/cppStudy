#pragma once
#include <iostream>
using namespace std;

/*
n다스 m자루 형태로 연필의 개수를 표현하는 클래스 (1다스는 12자루)
낱개의 수를 1개 추가하는 전위 및 후위 표기 ++ 연산자를 포함한다.
연필의 수량을 출력하는 멤버 함수를 포함한다.
*/

class Pencils{
    int dosens;
    int np;
public:
    Pencils() : dosens{0}, np{0} {}
    Pencils(int n){
        dosens = n / 12;
        np = n % 12;
    }
    Pencils(int d, int n) : dosens{d}, np{n} {}
    Pencils& operator ++();
    Pencils operator ++(int);
    void display() const;
};

Pencils& Pencils::operator ++(){
    if(np++ >= 12)
        ++dosens, np = 0;
    return *this;
};

Pencils Pencils::operator ++(int){
    Pencils tmp(*this);
    if(np++ >= 12)
        ++dosens, np = 0;
    return tmp;
};

void Pencils::display() const {
    if(dosens){
        cout << dosens << " 다스 ";
        if(np) cout << np << " 자루" << endl;
        else cout << endl;
    }
    else
        cout << np << " 자루" << endl;
};

