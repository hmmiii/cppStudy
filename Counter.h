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
        const void count(){
            ++value;
        }
        const int getValue(){
            return value;
        }
};

#endif // COUNTER_H_INCLUDED