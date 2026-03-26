#include <iostream>
using namespace std;

int *getMax(int input[], int size);

int main(){
    // 값 몇개 받을지 먼저 받고,
    // 숫자 연속으로 입력 받음. 그리고 최대값이랑 총합 구하기

    int num, sum = 0;
    cout << "input num : ";
    cin >> num; // 3

    int *input = new int[num]; // 0 1 2
    for(int i=0;i<num;i++){
        cin >> input[i];
        cout << "input i : " << input[i] << "\n";
        sum += input[i];
    }
    cout << "sum : " << sum << "\n";
    int *max = getMax(input, num);
    cout << "max : " << *max  << "" << "\n";
    return 0;
}

int *getMax(int input[], int size){
    int* max = 0;
    for(int i=0;i<size;i++){
        // cout << "input num : " << input[i] << "\n";
        if(i == 0){
            max = &input[i];
        }
        // cout << *max << "||" << input[i] << "\n";
        if(*max < input[i]){
            max = &input[i];
        }
    }
    return max;
};