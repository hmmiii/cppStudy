#include <iostream> 
using namespace std;

int a{10}; // 전역변수 - 정적 유효기간, 파일이 종료될때까지 유지

int f(){
    int b{20}, c{30}; // 지역변수 - 자동 유효기간, 함수가 사라질때까지 유지
    static int e{40}; // 정적 지역변수 - 정적 유효기간

    return 0;
}

int main()
{
    return 0;
}