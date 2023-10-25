#include <iostream>
#define PI1 3.14159 // 과거 const 키워드가 없을 때 사용한 상수 선언
using namespace std;

constexpr int fac(int n){ // constexpr 함수는 모든 인수가 constexpr인 경우 컴파일할 때 값을 구함
    return n > 1 ? n * fac(n-1) : 1;
}

void f(int x){
    constexpr int a = fac(4); // 컴파일 할 때 계산하므로 효율적
    int b = fac(x); // 런타임에 계산하므로 상대적으로 비효율적
}

int main(){
    int a;
    const double PI2{3.14159}; // 원주율 정의, 상수 선언
    constexpr int C1 = PI1 + 3; // 컴파일시 값이 평가되는 constexpr.

    cout << "값을 입력하세요 : ";
    cin >> a; // a에 사용자의 입력을 받아 대입한다.

    // constexpr int C2 = a + 1; 따라서 이 경우 오류를 출력한다. 컴파일시 a의 값은 알 수 없다.
    // constexpr C3 = C1 + 4; 이 경우에도 오류를 출력한다. 컴파일 시에는 C1을 알 수 없다.

    cout << PI1 << endl;
    cout << PI2 << endl;
    cout << C1 << endl;
    cout << a << endl;

    return 0;
}