#include <iostream>
#include <cstring>
#include "Person.h"
using namespace std;

// 생성자 함수 구현부
Person::Person(const char* name, const char* addr){

    // 이름을 저장할 공간 할당, c스타일 이므로 문자열보다 1 크게
    this -> name = new char[strlen(name)+1];

    // 데이터 멤버 name에 이름을 복사
    strcpy(this->name, name);

    // 주소을 저장할 공간 할당, c스타일 이므로 문자열보다 1 크게
    this -> addr = new char[strlen(addr)+1];

    // 데이터 멤버 addr에 주소를 복사
    strcpy(this->addr, addr);

    cout << "Person 객체 생성함(" << name << ")" << endl;
}

// 소멸자 함수 구현부
Person::~Person(){
    cout << "Person 객체 제거함(" << name << ")" << endl;
    delete [] name;
    delete [] addr;
}

void Person::print() const {
    cout << addr << "에 사는" << name << "입니다." << endl;
}

void Person::chAddr(const char* newAddr){
    delete [] addr; // 기존 공간 반납
    addr = new char[strlen(addr)+1];
    strcpy(this->addr, addr); // 데이터 멤버 addr에 새로운 주소를 복사


}