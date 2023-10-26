#include <iostream>
#include <cstring>
#include "Person.h"
using namespace std;

// 생성자 함수 구현부

/*
이 코드에서 매개변수가 포인터인 이유는 C++에서 문자열을 다룰 때 일반적으로 사용되는 C 스타일 문자열(문자 배열)을 사용하기 때문입니다.
C 스타일 문자열은 null 종료 문자('\0')로 끝나는 문자 배열이며, 이러한 문자열을 가리키는 포인터를 사용하여 문자열을 처리합니다.

name과 addr 매개변수는 const char* 형식의 포인터로 선언되었습니다. 이것은 문자열의 시작 주소를 가리키는 포인터를 전달하는 것을 의미합니다. 이유는 다음과 같습니다:

C 스타일 문자열은 문자의 배열로 표현되며, 문자열의 시작 위치를 가리키는 포인터로 표현됩니다.
문자열의 길이를 미리 알 수 없으므로 동적으로 할당된 메모리에 문자열을 저장하고 해당 메모리의 시작 주소를 가리키는 포인터를 사용하는 것이 효율적입니다.
문자열이 가변적인 길이를 가질 수 있으므로, 문자열을 복사하는 대신 포인터를 사용하여 원본 문자열을 공유하고 메모리를 효율적으로 관리할 수 있습니다.
따라서 const char* 포인터를 사용하여 문자열을 전달하고 해당 문자열을 클래스 내에서 동적으로 할당하고 복사합니다.

매개변수를 일반적인 char로 사용했을 경우 아래와 같다.

class Person {
public:
    Person(const char name[100], const char addr[100]) {
        // 데이터 멤버에 문자열을 복사
        strncpy(this->name, name, 99);  // 99로 지정한 이유는 null 종료 문자('\0') 고려
        this->name[99] = '\0';  // null 종료 문자 추가
        strncpy(this->addr, addr, 99);
        this->addr[99] = '\0';

        std::cout << "Person 객체 생성함(" << this->name << ")" << std::endl;
    }

    void print() {
        std::cout << "이름: " << name << ", 주소: " << addr << std::endl;
    }

private:
    char name[100];
    char addr[100];
};


*/

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