#ifndef PERSON_H_INCLUDED
#define PERSON_H_INCLUDED

// 모든 함수가 함수 원형만 선언되어 있다. 별도의 cpp파일에서  구현부를 정의해야 한다. Person.cpp에서 작업.

class Person{
    char* name;
    char* addr;

    public:
        Person(const char* name, const char* addr); // 생성자
        ~Person(); // 소멸자
        void print() const; // 이름과 주소 출력
        void chAddr(const char* newAddr); // 주소 변경
};

#endif // PERSON_H_INCLUDED