#pragma once
#include <iostream>
using namespace std;

/*
문자를 최대 20글자까지 저장할 수 있는 스택 객체를 만드는 클래스
문자 데이터를 저장(push) 할 수 있다.
문자 데이터를 인출(pop)할 수 있다.
스택이 가득 차 있는지 확인할 수 있다.
스택이 비어 있는지 확인할 수 있다.
*/

class CharStack{
    enum {size=20}; // 스택의 크기
    int top; // 마지막 데이터를 가리키는 포인터
    char buf[size]; // 스택의 저장 공간
    public:
        CharStack() : top{size} {}
        bool chkEmpty() const { // 스택이 비어 있으면 True
            return top == size;
        }
        bool chkFull() const { // 스택이 가득 차 있으면 True
            return !top;
        }
        bool push(char ch);
        char pop();
};

bool CharStack::push(char ch){
    if(chkFull()){
        cout << "Stack is Full!" << endl;
        return false;
    }else{
        buf[--top] = ch;
        return true;
    }
}

char CharStack::pop(){
    if(chkEmpty()){
        cout << "Stack is Empty!" << endl;
        return 0;
    }
    // 리턴을 하면서 지울 필요는 없다. top을 한 칸 밑으로 내리기 때문에, push 시에 한 칸 올리면서 값이 덮어씌워진다.
    return buf[top++]; 
    
}