#ifndef COUNTERM_H_INCLUDED
#define COUNTERM_H_INCLUDED

class CounterM{
    const int maxValue;
    int value;

    public:
        CounterM(int mVal) : maxValue{mVal}, value{0} {}
        void reset() {value=0;}
        void count(){
            value = value < maxValue ? value+1 : 0;
        }
};

#endif // COUNTERM_H_INCLUDED