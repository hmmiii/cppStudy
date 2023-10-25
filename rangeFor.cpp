#include <iostream>
using namespace std;

int main()
{
    int arr[3] = {1,2,3};
    int sum = 0;

    for (int i : arr){
        sum+=i;
    }

    cout << "합계 : " << sum << endl;
    

    return 0;
}
