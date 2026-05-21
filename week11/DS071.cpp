#include <iostream>
using namespace std;

/*
Selection Sort(선택 정렬)는 가장 작은(또는 큰) 값을 선택하여 앞쪽부터 차례로 배치하는 정렬 알고리즘입니다.
비교 기반 정렬!!

    배열의 첫 번째 요소부터 시작
    현재 위치 이후의 가장 작은 요소를 찾음
    찾은 요소와 현재 요소를 교환
    다음 위치로 이동하여 반복 수행
    배열 끝까지 이를 수행하면 정렬 완료

예시:
초기 배열이 [5, 2, 4, 3, 1]일 때

    1을 찾아서 5와 교환 → [1, 2, 4, 3, 5]

    2는 그대로 → [1, 2, 4, 3, 5]

    3을 찾아서 4와 교환 → [1, 2, 3, 4, 5]

    이미 정렬 완료


     8 19 3 9 11 7 55 2
     8 [19 3 9 11 7 55 2] 8 제외 나머지 중 제일 작은 놈 비교!!
     2 19 [3 9 11 7 55 (8)]
     2 3 (19) [9 11 7 55 (8)]
     2 3 7 [9 11 (19) 55 (8)]
     2 3 7 (8) [11 (19) 55 (9)]
     2 3 7 (8)(9) [(19) 55 11]
     2 3 7 (8)(9) 11 [ 55 (19)]
     2 3 7 (8)(9) 11 (19) [55]


     =====

    삽입정렬
    1번째 애는 정렬 되었다는 가정
    2번째부터 앞으로 갈지 뒤로 갈지 결정

    버블정렬
    키순으로 줄세우기

    퀵소트(분할 정복 전략)
    반으로 나누기 ㄱㄱ

    머지 소트(일단 다 나누기 - 분할 정복!!)
    [5, 2, 4, 6, 1, 3]
-> [5, 2, 4]  [6, 1, 3]
-> [5] [2, 4]  [6] [1, 3]
-> [5] [2] [4]  [6] [1] [3]
[5] [2] -> [2, 5]
[2, 5] [4] -> [2, 4, 5]
[6] [1] -> [1, 6]
[1, 6] [3] -> [1, 3, 6]
[2, 4, 5] [1, 3, 6] -> [1, 2, 3, 4, 5, 6]

*/

void printarray(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << "[" << arr[i] << "]";
        if (i + 1 != n)
            cout << " ";
    }
    cout << endl;
}

void selectionSort(int *arr, int n)
{
    int index;
    for (int i = 0; i < n - 1; i++)
    {
        index = i;
        for (int j = i + 1; j < n; j++)
        {
            if (arr[index] > arr[j])
                index = j;
        }
        if (index != i)
        {
            swap(arr[i], arr[index]);
#ifdef DEBUG
            printarray(arr, n);
#endif
        }
    }
}

int main()
{
    int numberOfInput = 10;
    // cin >> numberOfInput;
    int a[10];
    for (int i = 0; i < numberOfInput; i++)
    {
        cin >> a[i];
    }
    int N = sizeof(a) / sizeof(a[0]);
#ifdef DEBUG
    printarray(a, N);
#endif
    selectionSort(a, N);
    printarray(a, N);
    return 0;
}