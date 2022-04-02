#include <iostream>

using namespace std;

char name[5] = {'Y', 'u', 'r', 'i', 'y'};

struct Student {
    char firstname[5];
    int age;
    int id;
    int data;
    Student *next, *prev;
};

void insert1(Student *student, int data, int age, int id, const char name[5]) {
    auto* st = new Student;
    st->firstname[5] = name[5];
    st->age = age;
    st->id = id;
    st->data = data;
    st->next = student -> next;
    student->next = st;
}

void delete1(Student* student){
    Student* st;
    if (student -> next){
        st = student -> next;
        student -> next = st -> next;
        delete st;
    }
}

void show1(Student* student){
    Student *st = student ->next;
    while (st){
        cout << &st->firstname << ' ';
        cout << &st->data << ' ';
        cout << &st->id << ' ';
        cout << &st->age << ' ';
        st = st -> next;
        return;
    }
    cout << endl;
}

void Insert2(Student *St, int data, int age, int id, const char name[5])
{
    Student* q = new Student;
    q->firstname[5] = name[5];
    q->age = age;
    q->id = id;
    q->data = data;
    q->next = St->next;
    q->prev = St;
    St->next = q;
    if (q->next)
        q->next->prev = q;
}

void Delete2(Student* del)
{
    del->prev->next = del->next;
    if (del->next)
        del->next->prev = del->prev;
    delete del;
}

void Insert3(Student* Pred, int data, int age, int id, const char name[5])
{
    Student* Loc = new Student;
    Loc->firstname[5] = name[5];
    Loc->id = id;
    Loc->age = age;
    Loc->data = data;
    Loc->next = Pred->next;
    Loc->prev = Pred;
    Pred->next = Loc;
    Loc->next->prev = Loc;
}

void Delete3(Student *Del)
{
    Del->prev->next = Del->next;
    Del->next->prev = Del->prev;
    delete Del;
}

int main() {
    auto *St1 = new Student;
    St1->next = St1;
    St1->prev = St1;
    Insert3(St1, 5, 21, 1, name);
    show1(St1);
    Delete3(St1);
    return 0;
}