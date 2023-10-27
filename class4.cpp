#include <iostream>
#include "Counter.h"
#include "CounterM.h"
#include "VecF.h"
#include "NameObj.h"

using namespace std;

/*

디폴트 생성자(default constructor)
매개변수가 없거나 모든 매개변수에 디폴트 인수가 지정된 생성자
따로 생성자 함수를 만들지 않아도 디폴트 생성자가 생긴다. 이를 묵시적 디폴트 생성자라 한다.

디폴트 생성자가 없는 경우
매개변수가 있고, 모든 매개변수에 디폴트 인수가 존재하지는 않는다.

class CounterM{
    const int maxValue;
    int value;

    public:
        CounterM(int mVal) : maxValue{mVal}, value{0} {}
        void reset() {value=0;}
        void count(){
            value = value < maxValue ? value++ : 0;
        }
};

복사 생성자(copy constructor)
동일 클래스의 객체를 복사하여 객체를 만드는 생성자
묵시적 복사 생성자는 객체의 데이터 멤버들을 그대로 복사하여 객체를 만들도록 묵시적으로 정의된 복사 생성자다.
묵시적 디폴트 생성자와 마찬가지로, 복사 생성자를 따로 선언하지 않으면 묵시적 복사 생성자가 생성된다.

class ClassName{
    ....
    public:
        ClassName(const Classname& obj){ // 복사생성자의 함수 원형, 동일클래스의 상수 lvalue 참조로 객체를 받는다.
            .... // 생성된 객체에 obj를 복사하는 처리
        }
}

CounterM 클래스에 이런 복사 생성자가 묵시적으로 생긴다고 봐야 한다.

class CounterM{
    const int maxValue;
    int value;

    public:
        CounterM(int mVal) : maxValue{mVal}, value{0} {}

        CounterM(const CounterM& c){} : maxValue{c.mVal}, value{c.value} {} // 묵시적 복사 생성자.

        void reset() {value=0;}
        void count(){
            value = value < maxValue ? value++ : 0;
        }
};

얕은 복사(shallow copy)
동객체를 복사할 때 객체의 데이터 멤버의 값을 그대로 복사하는 방식
일반적인 프로그램에서는 문제가 없겠지만, VecF 클래스처럼 자원을 동적으로 할당받는 프로그램에서는 문제가 발생한다.

깊은 복사(deep copy)
복사된 객체가 소스 객체와 공유하는 자원이 없는 별개의 복사본이 될 수 있도록 복사하는 방식
복사생성자를 명시적으로 선언해서 구현한다.

a = 2 + 3;
^   ^ ~
LVal RVal

lvalue
glvalue 중 xvalue를 제외한 것으로, 그 아이덴티티가 유지되어야 하는 식
identity

rvalue
prvalue 또는 xvalue에 해당되는 식
LValue에 전달할 수 있는 값 그 자체. 이름은 없어도 된다.
movable

xvalue
객glvalue 중 보유하고 있는 자원을 재활용할 수 있는(일반적으로 생명주기의 마지막에 도달하여 보유할 필요가 없게 되는 경우에 해당됨) 객체 등에 해당되는 식
아이덴티티가 있다가, 이동하면 사라지기 때문에 둘 다 갖고 있다고 볼 수 있겠다.
identity + movable

glvalue
객체 등의 아이덴티티를 결정하는 식.
lvalue + xvalue
identity

prvalue
객체 등을 초기화하거나 연산자의 피연산자 값을 계산하는 식으로, 아이덴티티는 없음
xvalue + rvalue
movable

이동 생성자(move constructor)
rvalue 참조로 전달된 같은 클래스의 객체의 내용을 이동하여 객체를 만드는 생성자
rvalue 참조는 &기호를 두 번 사용한다.

이렇게 하면 rvalue인 10을 참조한다.
int&& a = 10

이 경우 v1.add(v2) 의 반환값을 v3에 복사하므로 반환값이 따로 존재. 
VecF v3 = v1.add(v2);

이렇게 하면 add()의 반환값이 rvalue이므로 rvalue 참조가 가능. 
VecF&& v3 = v1.add(v2);

이동생성자 형식

class ClassName{
    ....
    public:
        ClassName(Classname&& obj){ // 복사생성자의 함수 원형, 동일클래스의 rvalue 참조로 객체를 받는다. 복사생성자는 상수가 아니다. 원본이 사라져야 해서.
            .... // 생성된 객체에 obj의 내용을 이동하는 처리
        }
}

static 데이터 멤버와 멤버 함수
기본적으로 데이터 멤버는 그 클래스의 객체마다 메모리 공간을 가진다
멤버 함수는 같은 클래스라면 그 공간을 공유한다.
하지만 때에 따라서 데이터 멤버도 클래스별로 공간을 공유해야 할 때가 있는데 그 때 static을 사용한다.

static 데이터 멤버
클래스에 속하는 모든 객체가 공유하는 데이터 멤버. 메모리 공간을 공유한다.
객체 생성과 관계 없이 프로그램이 시작되면 static 데이터 멤버를 위한 메모리 공간이 할당됨
일반 데이터 멤버와 달리 static 데이터 멤버는 클래스 선언문 내에서는 선언만 하고 클래스 외부에서 별도로 정의해야함.

static 멤버 함수
특정 객체에 대한 처리를 하는 것이 아니라, 소속 클래스 단위의 작업을 하는 함수
static 멤버 함수는 객체가 정의되지 않아도 사용할 수 있음.
static 멤버 함수 안에서는 일반 멤버 사용 불가능. static 멤버만 사용 가능.

*/

// static
void f(){
    NameObj trd("Third"); // 세 번째 객체 생성
    trd.display(); // 출력 후 소멸.
}

int main()
{
    // 디폴트 생성자
    cout << "-------------------디폴트 생성자"<< endl;

    //디폴트 생성자가 없다면, 매개변수가 없는 객체를 생성하려고 하면 오류가 발생한다.
    CounterM cnt1(999); // 정상
    //CounterM cnt1; // 에러

    // 디폴트 생석자가 있는경우, 객체배열을 만들어낼 수도 있다.
    Counter cntArr1[4]; // Counter의 객체를 4개 가진 배열
    Counter* pt1 = new Counter[10]; // Counter 객체 10개를 동적으로 생성.

    // CounterM cntArr2[4]; // 이 경우에는 인수를 전달할 수 없기 때문에 에러.
    CounterM cntArr2[4] = { // 이렇게 각 배열에 들어갈 객체를 직접 설정해주면 OK.
        CounterM(9),
        CounterM(20),
        CounterM(40),
        CounterM(66),
    };

    // CounterM* pt2 = new CounterM[3]; // 같은 이유로 인수를 전달할 수 없어서 에러. 동적 메모리 할당은 아예 불가능하다.


    // 복사 생성자
    cout << "-------------------복사 생성자"<< endl;

    CounterM cnt2(333);
    CounterM cnt3(cnt2); // 에러가 발생하지 않는다. 묵시적 복사 생성자 작동. cnt2의 데이터 멤버를 복사해서 cnt3 객체를 만들었다.
    CounterM cnt4 = cnt3; // cnt3을 만든 것과 동일하다.

    // 얕은 복사 및 깊은 복사, 이동생성자
    cout << "-------------------얕은 복사, 깊은 복사, 이동 생성자"<< endl;

    float a[3] = {1, 2, 3};
    VecF v1(3, a); // 1, 2, 3을 저장하는 벡터
    // v1을 그대로 복사해서 v2를 만듦, 이는 같은 메모리 공간을 가르키는 얕은 복사이다.
    // main 함수가 끝날 때 v1의 소멸자 함수를 통해 사라지고, v2도 소멸자 함수를 통해 사라져야 한다.
    // 그런데, v1은 이미 소멸되었는데 v2에서 또 소멸을 하려고 하면 시스템에 에러가 발생한다.
    
    VecF v2 = v1; 
    v1.print();
    cout << endl;
    v2.print();
    cout << endl;
    VecF v3 = v1.add(v2);
    v3.print();
    cout << endl;

    // static
    cout << "-------------------static"<< endl;

    cout << "NameObj 클래스의 객체 수 : " << NameObj::nObj() << endl;
    NameObj fst("First"); // 첫 번째 객체 생성
    NameObj sec("Second"); // 두 번째 객체 생성
    cout << "NameObj 클래스의 객체 수 : " << NameObj::nObj() << endl;
    f();
    cout << "NameObj 클래스의 객체 수 : " << NameObj::nObj() << endl;
    NameObj fort("Fourth"); // 네 번째 객체 색성
    fort.display();
    cout << "NameObj 클래스의 객체 수 : " << NameObj::nObj() << endl;

    return 0;
}
