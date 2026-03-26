#include <iostream>
using namespace std;

struct Student1 {
    int id;
    int totalScore;
};
struct Student {
    int id;
    double score;
};
struct Product {
    string name;
    int price;
    string manufac;
};

// 구조체 포인터를 매개변수로 받는 함수
void updateScore(Student* s) {
    s->score = 100.0;   // 포인터로 직접 수정
}

int main(){
    Product product;
    product.price = 1;
    Product* product1 = &product;
    /*
    int int_a = 1;
    int* int_p_a = &int_a;
    cout << "int_a : " << int_a << "\n";
    cout << "int_a address:" << &int_a << "\n";
    cout << "int_p_a address: " << int_p_a << "\n"; // 값이 있는 주소값!
    cout << "int_p_a : " << *int_p_a << "\n"; // 실제 값!
    cout << "int_p_a : " << &int_p_a << "\n"; // 이 변수의 주소값!
    */

    Student1 student1;
    student1.id = 1;
    student1.totalScore = 95;

    cout << "student1 id : " << student1.id << "\n";
    cout << "student1 totalScore : " << student1.totalScore << "\n";

    Student1* pStudent1 = &student1;
    pStudent1->totalScore = 100;

    cout << "pStudent1 id : " << pStudent1->id << "\n";
    cout << "pStudent1 totalScore : " << pStudent1->totalScore << "\n";

    cout << "pStudent1!! : " << (*pStudent1).id << "\n";


    /*
    int a = 10;
    int* p = &a;

    cout << "a : " << a << "\n";
    cout << "p : " << *p << "\n";
    cout << "p : " << &p << "\n";

    Student s;
    s.id = 1;
    s.score = 95.5;

    Student* pp = &s;
    pp->score = 100;

    Student ss = {1, 85.5};
    cout << ss.id << " " << ss.score << endl;  // 1 85.5

    updateScore(&ss);  // 주소 전달

    cout << s.id << " " << s.score << endl;  // 1 100.0

    cout << "s : " << s.id << " / " << s.score << "\n";
    cout << "pp : " << &pp->id << " / " << pp->score << "\n";
    cout << "pp : " << (*pp).id << " / " << (*pp).score << "\n";
    */
    return 0;
}