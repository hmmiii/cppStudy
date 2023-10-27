#ifndef VECF_H_INCLUDED
#define VECF_H_INCLUDED
#include <iostream>
#include <cstring>
using namespace std;

/*
    VecF :
    백터 객체를 만들 수 있는 클래스.
    저장할 수 있는 float의 값을 인수로 지정해서 생성.
    저장할 배열의 값이 지정된 경우 그 값으로 초기화
    인수로 전달된 VecF 객체와 덧셈한 결과를 반환할 수 있음
    객체에 저장된 벡터를 출력할 수 있음.

*/

class VecF{
    int n;
    float* arr;
public:
    VecF(int d, const float* a=nullptr) : n{d} {
        arr = new float[d];
        // memcpy : 메모리 복사, 메모리 크기까지 인수로 받는다.
        // memcpy(dest, source, size)
        // 여기서는 float의 크기 x n의 값을 사이즈로 설정한다.
        // 즉, a가 기본값이 아니라 따로 인수를 받았을 경우 a의 주소를 복사하고 크기는 float * n만큼 설정.
        if(a) memcpy(arr, a, sizeof(float) * n);
    }
    // 깊은 복사를 위한 복사 생성자.
    VecF(const VecF& fv) : VecF(fv.n, fv.arr) {}
    // 이동 생성자
    VecF(VecF&& fv) : n{fv.n}, arr{fv.arr}{
        fv.arr = nullptr; // rvalue의 포인터 메모리 공간을 끊음 delete는 nullptr일 경우 작동하지 않기 때문에 꼭 필요.
        fv.n = 0; // rvalue의 n을 0으로 초기화
    }
    ~VecF(){
        delete [] arr;
    }
    VecF add(const VecF& fv) const {
        VecF tmp(n); // -> tmp(n, nullptr)과 동일
        for(int i = 0; i < n; i++)
            tmp.arr[i] = arr[i] + fv.arr[i];
        return tmp;
    }
    void print() const {
        cout << "[ ";
        for(int i = 0; i < n; i++)
            cout << arr[i] << " ";
        cout << "]";
    }

};

#endif // VECF_H_INCLUDED

