#include <iostream>
#include "CharStack.h"
#include "Complex1.h"
using namespace std;

/*

스택(stack)
push와 pop 연산을 이용하여 데이터를 저장하고 인출할 수 있는 자료구조로서, 나중에 저장된 데이터가 먼저 인출될 수 있는 특성(LIFO: Last In, First Out)을 갖는다.

위임 생성자(delegating constructor)
클래스의 다른 생성자를 이용하여 선언되는 생성자로서, 생성자를 작성하는 코드의 중복을 줄일 수 있다.
멤버 초기화 리스트에 클래스의 다른 생성자를 이용하여 새로운 생성자를 선언할 수 있다.
위임 생성자 : 클래스의 다른 생성자를 이용하여 선언되는 생성자
타겟 생성자 : 위임의 대상이 되는 생성자

    VecF(int d, const float* a=nullptr) : n{d} {
        arr = new float[d];
        if(a) memcpy(arr, a, sizeof(float) * n);
    }
    VecF(const VecF& fv) : n{fv.n}{
        arr = new float[n];
        memcpy(arr, fv.arr, sizeof(float) * n);
    }

위 코드는 생성자와 복사생성자인데, 매우 유사하다. 위임생성자를 응용해볼 수 있다.

    VecF(int d, const float* a=nullptr) : n{d} {
        arr = new float[d];
        if(a) memcpy(arr, a, sizeof(float) * n);
    }

    VecF(const VecF& fv) : VecF(fv.n, fv.arr) {}

초기화 리스트 생성자(initializer-list constructor)
첫 번째 매개변수가 std::initializer_list<Type>인 생성자
데이터의 갯수가 가변적일 때 유용하다. 
지정된 자료형의 값들을 {} 안에 나열한 리스트
헤더파일 : #include <initializer_list>
멤버 함수:
begin() : 첫 번째 요소에 대한 포인터를 반환
end() : 마지막 요소의 다음 요소에 대한 포인터를 반환
size() : initializer_list의 원소 수를 반환
초기화 리스트 생성자를 사용할 때는 copy라는 함수를 자주 사용한다.

VecF(initializer_list<float> lst) : n{ static_cast<int>(lst.size()) } {
    arr = new float[n];
    copy(lst.begin(), lst.end(), arr); // 처음부터 끝까지 복사해서 arr에 복사한다.
}


*/

int main()
{
    /* stack 구현 */
    cout << "-------------------stack"<< endl;
    CharStack chStack; // 20개의 문자를 저장할 수 있는 스택
    char str[20];

    cout << "영어 단어를 입력하시오 : ";
    cin >> str;

    char* pt = str; // str[0] 의 주소를 가리킴, 문자열의 시작 위치를 가리킴

    while(*pt) // pt의 마지막은 \0 이기 때문에, 마지막에 가서는 거짓이 됨.
        chStack.push(*(pt++));
    
    cout << "역순 단어 출력 : ";
    while(!chStack.chkEmpty()) // 스택이 비어 있지 않으면 반복
        cout << chStack.pop(); // 스택에서 인출한 문자를 출력
    cout << endl;

    cout << "-------------------복소수 클래스 Complex1"<< endl;
    Complex1 c1(1,2);
    Complex1 c2(2,3);
    Complex1 c3 = c1.add(c2);
    c1.display();
    cout << " + ";
    c2.display();
    cout << " = ";
    c3.display();
    cout << endl;

    c1.display();
    /*
    묵시적 형변환. 묵시적 형변환은 생성자 함수를 가지고 한다.
    이 경우 r에는 10.0, i에는 default 값인 0을 넣은 셈으로 형변환을 한다.
    */
    c3 = c1.mul(10.0);
    cout << " x 10 ";
    cout << " = ";
    c3.display();
    cout << endl; 

    return 0;
}
