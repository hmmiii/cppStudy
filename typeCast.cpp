#include <iostream>
using namespace std;

int main()
{

    int x = 10;
    double y = static_cast<double>(x); // 정수를 부동 소수점으로 변환

    int a = 5;
    char b = static_cast<char>(a); // 정수를 문자로 변환

    float c = 3.14f;
    int d = static_cast<int>(c); // 부동 소수점을 정수로 변환

    int e = 65;
    char f = static_cast<char>(e); // 정수를 문자로 변환 (ASCII 코드)

    return 0;
}