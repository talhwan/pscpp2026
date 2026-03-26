#include <iostream>
using namespace std;

struct Student2 {
    int id;
    int totalGrade;
};
struct Student {
    int id;
    double score;
};
struct Product{
    string name;
    int price;
    string manufac;
};

// 구조체 포인터를 매개변수로 받는 함수
void updateScore(Student* s) {
    s->score = 100.0;   // 포인터로 직접 수정
}

int main(){
    /*
    int var_a = 0; // 일반 변수
    int* var_a_p = &var_a;
    var_a = 2;
    cout << "var_a : " << var_a << ", address : " << &var_a << "\n";
    cout << "var_a_p : " << var_a_p << "\n";
    cout << "*var_a_p : " << *var_a_p << "\n";
    cout << "&var_a_p : " << &var_a_p << "\n";
    */

    Student2 student2;
    student2.id = 1;
    student2.totalGrade = 4;

    cout << "student2.id : " << student2.id << "\n";
    cout << "student2.totalGrade : " << student2.totalGrade << "\n";

    Student2* student2p;
    student2p = &student2;
    student2p->totalGrade = 5;
    cout << "student2p.id : " << student2p->id << "\n";
    cout << "student2p.totalGrade : " << student2p->totalGrade << "\n";
    cout << "student2p.id : " << (*student2p).id << "\n";
    
    /*
    int int_a = 1;
    int* int_p_a = &int_a;
    cout << "int_a : " << int_a << "\n";
    cout << "int_a address:" << &int_a << "\n";
    cout << "int_p_a address: " << int_p_a << "\n"; // 값이 있는 주소값!
    cout << "int_p_a : " << *int_p_a << "\n"; // 실제 값!
    cout << "int_p_a : " << &int_p_a << "\n"; // 이 변수의 주소값!
    */

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