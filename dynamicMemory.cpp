#include <iostream>
using namespace std;

/*
동적 메모리 할당 : 프로그램 동작 중에 기억공간의 필요성 및 소요량을 결정하여 필요한 공간을 할당한다.
일반적인 변수는 프로그램 종료시에, 함수나 블록 내의 변수는 해당 함수나 블록 종료시에 소멸되지만, 이 경우 프로그래머가 결정한다.

기억 공간의 생성 시점 : new 연산자 실행시점
기억 공간의 소멸 시점 : delete 연산자의 실행 시점

동적으로 할당된 메모리는 이름이 없기 때문에, 동적 메모리 할당은 포인터 변수가 할당된 기억 공간을 가르키게 해야 한다. 
*/

int main()
{

    // 포인터 선언
    int* iPtr;
    int* iPtr2;

    // 동적 메모리 할당 (힙에서 할당)
    iPtr = new int;
    iPtr2 = new int[3];

    // 해당 메모리에 값 할당
    *iPtr = 4;

    // 동적 정수 배열의 여러 가지 접근 방법
    *iPtr2 = 10;
    iPtr2[1] = 20;
    *(iPtr2+2) = 30;

    cout << *iPtr << endl;
    cout << *iPtr2 << " " << iPtr2[1] << " " << *(iPtr2+2) << endl;
    
    // 동적 메모리 반납
    delete iPtr;
    delete [] iPtr2;
    
    // 아무 값도 가르키지 않음을 명시적으로 표기
    iPtr = nullptr;
    iPtr2 = nullptr;
    
    return 0;
}
