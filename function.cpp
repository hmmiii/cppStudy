#include <iostream>
using namespace std;
/*
함수의 선언

ReturnType functionName(fParameterList){
    Type localVar; // 지역변수 선언

    statement // 처리할 실행문
    ...

    return returnExpression // 결과값 반환

}

* ReturnType : 함수가 반환하는 값의 자료형, 리턴하는 값이 없다면 void로 선언.
* functionName : 함수의 이름
* fParameterList : 함수의 인수 리스트
* main 함수에서 return 문이 없다면, return 0;을 만난 것과 같다. 0을 리턴하면 정상적으로 프로그램을 종료한 것을 의미.
* void 형인 경우, 혹은 아닌 경우
functionName();

* return을 하는 경우
varName = functionName();

이런 식의 함수 호출도 가능.

* 실매개변수와 형식매개변수
fuctnion factorial(int n){} 에서 Int n은 형식 매개변수, factorial(3)에서 3은 실매개변수이다.

* 재귀 함수 or 순환호출
함수 안에서 함수를 또 호출한다. 순환 호출이라고도 한다.

* 참조호출

실 매개변수의 참조를 형식 매개변수에 전달하는 방식

* 참조호출의 용도

함수에서 처리한 결과를 매개변수를 통해 받아오고자 할 때
    - 함수에서 형식매개변수의 값을 변경하면 실 매개변수의 값을 변경하는 것과 같아진다.

많은 양의 데이터로 구성되는 구조체나 객체와 같은 인수를 함수에 효율적으로 전달하고자 할 때
    - 형식 매개변수에 복사되는 데이터의 양은 실 매개변수의 크기와 관계없이 일정함

* 다중정의(overloading)

동일한 이름에 대하여 여러 가지 의미를 부여하는 것

* 함수의 다중정의

동일한 이름을 갖는 함수를 여러 개 정의하는 것
동일한 개념의 처리를 여러 가지 데이터나 객체에 대해 각각에 맞는 처리를 해야 할 경우 사용
다중정의된 함수의 구분은 인수의 개수 및 자료형으로 한다. 단, 함수의 반환 자료형으로는 구분 불가능.

* inline 함수

inline 키워드를 함수 선언 앞에 붙여 함수를 선언하는 방법이다.
기존 함수는 호출부에서 선언부로 갔다가 함수 종료시 다시 호출부 이후에 코드가 진행되기 때문에 메모리 사용이 추가적으로 있다.
inline는 호출 위치에 함수의 처리 문장이 삽입되게 번역하도록 선언된 함수이다.
함수의 모듈화의 장점을 살리면서 함수 호출에 따른 부수적 처리 시간이 생략됨.
함수 호출에서 선언으로 넘어가는 부분의 코드 최적화가 가능
inline 함수는 종종 헤더 파일에 선언되고 정의됩니다. 이렇게 하면 함수를 여러 소스 파일에서 사용할 수 있으며, 링크 오류를 방지할 수 있습니다.
inline 함수는 컴파일 시점에서 함수 호출을 함수 내용으로 대체하므로, 함수 정의가 여러 소스 파일에 나누어 있어도 문제가 없습니다.

    => 매우 빈번히 호출되며 빠른 실행이 요구되는 함수를 inline 함수로 선언하면 성능을 높이는데 도움이 된다.

! inline 함수 주의할 점

inline 함수로 선언했다고 모두 inline 함수로 번역되지는 않는다.

inline 함수 선언을 무시하고 일반 함수로 번역되는 경우
    - 함수가 너무 크다
    - 순환 호출(recursive call)을 할 경우
    - 프로그램 내에서 그 함수에 대한 포인터를 사용하는 경우

*/


// 재귀 함수 or 순환호출. 팩토리얼 함수.
int factorial(int n){
    if (n<=1)
        return 1;
    else
        return n * factorial(n-1);
    
}

// 참조호출 예시
// 함수의 원형. 참조형으로 형식 매개변수를 선언했기 때문에, 함수 내에서 값이 바뀌면 실매개변수로 넣었던 값도 바뀌게 된다.
void SwapValues(int& x, int& y){
    int temp = x;
    x = y;
    y = temp;
}

// 참조호출로 인수를 효율적으로 전달하기
// 이 경우 이전 경우처럼 실매개변수가 변경되지 않게 하려면 const 키워드를 형식매개변수에 사용해준다.

// 많은 양의 데이터로 구성된 구조체
struct SalesRec {
    char pID[10];
    int dYear, dMonth, dDate;
    char deliverAddr[40];
};

// 일반함수, 데이터가 너무 많다. 용량이 매우 크다. 호출의 경우에는 실매개변수의 값을 매번 복사해온다.
void PrSalesRec(SalesRec srec){
    cout << "품목코드 : " << srec.pID << endl;  
    cout << "배달일자 : " << srec.dYear << "년";  
    cout << srec.dMonth << "월";  
    cout << srec.dDate << "일" << endl;  
    cout << "배달주소 : " << srec.deliverAddr << endl;  
}

// 참조호출을 이용하는 경우 참조이므로 4바이트만 복사가 된다.
void PrSalesRec2(const SalesRec& srec){
    cout << "품목코드 : " << srec.pID << endl;  
    cout << "배달일자 : " << srec.dYear << "년";  
    cout << srec.dMonth << "월";  
    cout << srec.dDate << "일" << endl;  
    cout << "배달주소 : " << srec.deliverAddr << endl;  
}


// 함수 다중정의

// 시간구조체 TimeRec
struct TimeRec{
    int hours;
    int minutes;
};

// AddTime 함수의 다중정의, 시간을 더하는 함수
// 구조체 TimeRec 변수를 두개 받는 AddTime은 두 시간:분을 더한다.
void AddTime(TimeRec& t1, const TimeRec t2){
    t1.minutes += t2.minutes;
    t1.hours += t2.hours + t1.minutes / 60;
    t1.minutes %= 60;
}
// 구조체 TimeRec 변수와 분을 int로 받는 AddTime은 시간:분 + 분 을 더한다.
void AddTime(TimeRec& t, int minutes){
    t.minutes += minutes;
    t.hours += minutes / 60;
    t.minutes %= 60;
}

// 인라인 함수
inline int Add(int a, int b) {
    return a + b;
}

int main()
{
    // 재귀 함수
    cout << factorial(3) << endl; // 6

    // 참조 호출
    int a, b;
    
    cout << "두 수를 입력하시오. : ";
    cin >> a >> b;

    if(a < b) SwapValues(a, b);
    cout << "큰 수 : " << a << " 작은 수 : " << b << endl;

    // 인라인 함수
    int result = Add(3, 4); // 컴파일러는 이 부분을 Add 함수의 내용으로 대체
    
    return 0;
}
