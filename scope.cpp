#include <iostream> 
using namespace std;

int a{0}; // 선언된 프로그램 전체 영역에서 사용 가능

static int b{10}; // 선언된 이후 소속 파일의 전체 영역에서 사용 가능

int f(){
    int c{20}, d{30}; // 선언된 이후 소속 함수의 전체 영역에서 사용 가능

    {
        int d{40}; // name hiding
        int e{50}; // 선언된 이후 소속 블록의 전체 영역에서 사용 가능
    }

    return 0;
}

int main()
{
    cout << b;
    
    return 0;
}