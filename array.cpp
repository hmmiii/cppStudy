#include <iostream>
using namespace std;

int a[5] = {1,2,3,4,5};
int b[5] = {1,2,3}; // b[3], b[4]는 0으로 초기화
int c[] = {1,2,3,4,5}; // c의 크기는 5.
int d[2][4] = {
    {1,2,3,4},
    {1,2,3,4}
}; // 2차원 배열

int main(){
    // 배열을 이용해서 최대값 구하기
    int data[10] = {15,35,53,69,12,390,27,100,29,10};
    int max = data[0];

    for(int i = 0; i < 10; i++){
        cout << "인덱스 : " << i << ", " << "data : " << data[i] << endl;
        if (data[i] > max)
            max = data[i];
    }

    cout << "\n\n가장 큰 수 : " << max << endl;

    return 0;
}
