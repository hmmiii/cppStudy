#include <iostream>
#include <Python.h>
using namespace std;

int main()
{
    // 파이썬 인터프리터 초기화
    Py_Initialize();

    // 파이썬 코드 실행
    PyRun_SimpleString("print('Hello from Python!')");

    // 파이썬 인터프리터 정리
    Py_Finalize();
    
    return 0;
}
