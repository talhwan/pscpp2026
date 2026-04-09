#include <iostream>
#include <string>

using namespace std;

class Student
{
private:
    double getAvg() const;

public:
    string name;
    string sid;
    int *score;
    void print() const;
};

double Student::getAvg() const
{
    return (double)(*score) / 3.00;
}

void Student::print() const
{
    cout << "[" << sid << "] " << name << endl;
    printf("The Average score is %.1f", getAvg());
}

int main()
{
    Student s1;
    int kor, eng, math;
    int total = 0;
    cin >> s1.sid >> kor >> eng >> math;
    /*
    cin.ignore(); 겟 라인 전에 바로 쓰면 버퍼가 생김.. 꼭 필요!
    getline(cin, s1.name);
    */
    cin.ignore();
    getline(cin, s1.name);

    total = kor + eng + math;
    s1.score = &total; //스코어는 주소를 저장하니까 값을 주소값 넘김!

    s1.print();

    return 0;
}