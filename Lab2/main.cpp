#include <iostream>

using namespace std;

struct Student {
    char firstname[6];
    char *lastname;
    int course;
    double age;
    double *array;
    int id;
    int size;
};

Student initialization(struct Student) {
    Student student{};
    return student;
}

void inputArray(Student &student) {
    cout << "Input size array" << endl;
    cin >> student.size;
    student.array = new double[student.size];
    cout << "Input array" << endl;
    for (int i = 0; i < student.size; ++i) {
        cin >> student.array[i];
    }
}

void outputArray(Student &student) {
    for (int i = 0; i < student.size; ++i) {
        cout << student.array[i] << endl;
    }
}

void inputInfo(Student &student) {
    cout << "Input firstname: " << endl;
    cin >> student.firstname;
    cout << "Input lastname: " << endl;
    student.lastname = new char[7];
    cin >> student.lastname;
    cout << "Input id: " << endl;
    cin >> student.id;
    cout << "Input age: " << endl;
    cin >> student.age;
    cout << "Input course: " << endl;
    cin >> student.course;
}

void outputInfo(Student &student) {
    cout << "firstname: " << student.firstname << endl;
    cout << "lastname: " << student.lastname << endl;
    cout << "id: " << student.id << endl;
    cout << "age: " << student.age << endl;
    cout << "course: " << student.course << endl;
}

void deleteStruct(Student *student1) {
    student1 = new Student[3];
    delete student1;
}

int main() {
    Student student{};
    initialization(student);
    inputArray(student);
    outputArray(student);
    inputInfo(student);
    outputInfo(student);

    Student *student1;
    student1 = new Student[3];

    for (int i = 0; i < 3; ++i) {
        initialization(student1[i]);
        inputArray(student1[i]);
        inputInfo(student1[i]);
    }

    for (int i = 0; i < 3; ++i) {
        outputInfo(student1[i]);
    }

    for (int i = 0; i < 3; ++i) {
        deleteStruct(&student1[i]);
    }

    return 0;
}