#ifndef NAMEOBJ_H_INCLUDED
#define NAMEOBJ_H_INCLUDED
#include <iostream>
using namespace std;

/*
이름을 갖는 객체를 만드는 클래스
객체를 생성할 때는 고유번호를 가진다
고유번호는 객체가 생성될 때 1번부터 시작해서 차례로 부여되는 일련번호이다.
객체는 자기 자신의 일련번호를 출력할 수 있다.
클래스는 현재 존재하는 NameObj 클래스의 객체의 수를 출력할 수 있다.
*/

class NameObj{
    char* name;
    int id;

    // static 데이터 멤버
    static int cConstr; // 생성된 객체의 수
    static int cDestr; // 소멸된 객체의 수

    public:
        NameObj(const char* s);
        ~NameObj();
        void display() const{
            cout << "ID : " << id << " -- > 이름 : " << name << endl;
        }

        static int nObj(){ // static 멤버 함수 : 존재하는 객체 수 반환.
            return cConstr - cDestr;
        }
};

NameObj::NameObj(const char* s){
    name = new char[strlen(s)+1];
    strcpy(name,s);
    id = ++cConstr; // 생성된 객체의 수를 증가시키고 이를 ID로 부여
}

NameObj::~NameObj(){
    ++cDestr; // 소멸된 객체의 수 증가
    delete [] name;
}

int NameObj::cConstr = 0;
int NameObj::cDestr = 0;

#endif // NAMEOBJ_H_INCLUDED