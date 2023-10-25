#include <iostream>
using namespace std;

/*
참조
- 어떤 대상을 가리키는 값(포인터와 유사)
- 참조 변수는 참조대상의 별명처럼 사용 가능
- 포인터와 달리 반드시 초기화 필요.
- 참조 변수는 초기화로 지정된 참조대상을 변경할 수 없다. 참조의 유효기간동안 하나의 대상만 참조가 가능.
- l-value 참조와 r-value 참조를 구분하는데, 각각 대입연산자의 left, right 쪽에 있다는 뜻.
- l-value 참조 : 실체가 있는 대상 (l-value)에 대한 참조
- const 참조 : l-value 참조와 동일하지만, 변경 불가능.
- r-value 참조 : 사용한 후에 그 값을 더 이상 사용할 필요가 없는 대상을 참조 / 용도 : 객체의 값을 다른 객체로 이동

l-value 참조 변수의 선언 방식
TypeName& refVal = varName;

TypeName : 참조 대상의 자료형
refVal : 참조 변수의 이름
varName : 참조 대상
*/

int main()
{
    // l-value 참조 & const 참조

    int a = 10;
    int b = 20;
    int& aRef = a;
    const int& aRefConst = a;

    cout << "a : " << a << endl; // 10
    cout << "b : " << b << endl; // 20
    cout << "aRef : " << aRef << endl; // 10
    cout << "aRefConst : " << aRefConst << endl; // 10

    // 일반 변수처럼 재할당이 자유롭다. 포인터보다 편리하게 사용 가능.    
    aRef = b;

    cout << "aRef : " << aRef << endl; // 20
    
    return 0;
}
