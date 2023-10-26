// COUNTER_H_INCLUDED 가 정의되지 않았을 경우 실행됨. 중복 include를 막기 위함.
// 동일한 기능을 위해 #pragma once 를 이용할 수도 있다.
#ifndef COUNTER_H_INCLUDED
#define COUNTER_H_INCLUDED

class Counter{
    int value; // private 데이터 멤버

    public:
        void reset(){
            value = 0;
        }
        // count 함수의 블록에 const 지정 시 함수 호출시 오류발생한다. value 값 변경 시도이기 때문.
        void count(){
            ++value;
        }
        // 멤버 함수에서는 블록에 대해서 const 키워드 지정이 가능
        int getValue() const {
            return value;
        }
};

#endif // COUNTER_H_INCLUDED