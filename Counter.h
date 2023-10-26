// COUNTER_H_INCLUDED 가 정의되지 않았을 경우 실행됨. 중복 include를 막기 위함.
// 동일한 기능을 위해 #pragma once 를 이용할 수도 있다.
#ifndef COUNTER_H_INCLUDED
#define COUNTER_H_INCLUDED

class Counter{
    int value; // private 데이터 멤버

    public:
        Counter(){ // 생성자 함수
            value = 0;
        }
        void reset(){
            value = 0;
        }
        // count 함수의 블록에 const 지정 시 함수 호출시 오류발생한다. 멤버 변수 변경 시도이기 때문.
        void count(){
            ++value;
        }
        // 멤버 함수에서는 블록에 대해서 const 키워드 지정이 가능. 멤버 변수를 변경하지 않음을 나타냄.
        // 멤버 변수를 변경하지 않는 것이 명확하다면, 반드시 명시적으로 const를 적용하자.

        /*

        아래의 경우 명시하지 않으면 오류가 발생한다.

        void g(const Counter& c){
            cout << c.getValue();
            ...
        }        
        
        */


        int getValue() const {
            return value;
        }
};

#endif // COUNTER_H_INCLUDED