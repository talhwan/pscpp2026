#include <iostream>
using namespace std;

int *maxNum(int input[], int size); //최대값을 계산해주는 함수를 선언만 먼저!!

int main(){
    //몇개 입력 받을지 정하고, 숫자 차례로 입력받음
    //총합과 최대값 구하기!

    int num, sum = 0;
    cout << "input num : ";
    cin >> num; // 3

    int *input = new int[num]; // 0 1 2
    for(int i=0;i<num;i++){
        // cout << "i : " << i << "//" << input[i] << " !! " << &input[i];
        cin >> input[i];
        sum += input[i]; // sum = sum + input[i]; 와 동일!
    }
    cout << "sum : " << sum << endl;

    int *max = maxNum(input, num);
    cout << " max : " << *max << "";

    return 0;
}

int *maxNum(int input[], int size){
    int* resultMax;
    for(int i=0;i<size;i++){
        if(i == 0){
            resultMax = &input[i];
        }
        if(*resultMax < input[i]){
            resultMax = &input[i];
        }
    }
    return resultMax;
}