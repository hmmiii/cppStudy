#include <iostream>
using namespace std;

/*
어떠한 대상이 위치한 곳(주소)를 가르키는 변수가 포인터이다.
가르키는 대상 : 포인터에 저장된 자료형에 해당하는 변수, 동적으로 할당된 메모리, 함수 등

포인터를 사용할 때는 포인터가 유효한 대상을 가르키게 한 후 사용해야만 오류가 발생하지 않는다.

형식
TypeName* ptrVar;
가리킬 값의 자료형과 포인터 변수의 이름 식으로 선언.
*/

int main()
{
    int* iPtr;

    int val = 10;

    // & : 주소 계산 연산자

    // 이제 iPtr은 val과 같은 메모리 공간을 가르킴.
    iPtr = &val;

    // 가르키는 공간의 값을 변경함. 따라서 val의 값도 동시에 20이 됨.
    *iPtr = 20;

    cout << iPtr << endl; // 주소값
    cout << *iPtr << endl; // 20
    cout << val << endl; // 20
    
    return 0;
}
