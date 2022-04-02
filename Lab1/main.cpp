#include <iostream>

int main() {
    using namespace std;

    int array1[5] = {5, 3, 6, 7, 3};
    int *IArr = array1;

    double array2[5] = {1.2, 2.1, 2.3, 3.2, 4.6};
    double *dArr[5];

    char array3[2][3][1]{{{'Y'}, {'I'}, {'!'}},
                         {{'R'}, {'U'}, {'Y'}}};
    char *(ChArray3[2][2]);


    // массив целых чисел
    cout << "Output array1:" << endl;
    for (int i: array1) {
        cout << i << endl;
    }

    cout << "Input array1:" << endl;
    for (int &i: array1) {
        cin >> i;
    }

    cout << "Output array1:" << endl;
    for (int i: array1) {
        cout << i << endl;
    }

    cout << "Output pointer address:" << endl;
    cout << IArr << endl;
    cout << "Output array1 address:" << endl;
    cout << array1 << endl;

    cout << "Output pointer array1:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << IArr[i] << endl;
    }

    // массив чисел с плавующей точкой
    cout << "Output array2:" << endl;
    for (double i: array2) {
        cout << i << endl;
    }

    cout << "Input array2:" << endl;
    for (double &i: array2) {
        cin >> i;
    }

    cout << "Output array2:" << endl;
    for (double i: array2) {
        cout << i << endl;
    }

    cout << "Output pointer address:" << endl;
    cout << dArr << endl;
    cout << "Output array2 address:" << endl;
    cout << array2 << endl;

    cout << "Output pointer array2:" << endl;
    for (int i = 0; i < 5; ++i) {
        cout << dArr[i] << endl;
    }


    IArr = new int[5]{3, 4, 3, 2, 1};
    cout << "Output array4:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << IArr[i] << endl;
    }

    cout << "Input array4:" << endl;
    for (int i = 0; i < 5; i++) {
        cin >> IArr[i];
    }

    cout << "Output array4:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << IArr[i] << endl;
    }
    delete[] IArr;

    cout << "Array element:" << endl;
    cout << array3[0][0][0] << endl;
    cout << array3[1][1][0] << endl;
    cout << array3[1][0][0] << endl;
    cout << array3[0][1][0] << endl;
    cout << array3[1][2][0] << endl;
    cout << array3[0][2][0] << endl;

    cout << "Array element:" << endl;
    cout << *(array3[0][0]) << endl;
    cout << *(array3[1][1]) << endl;
    cout << *(array3[1][0]) << endl;
    cout << *(array3[0][1]) << endl;
    cout << *(array3[1][2]) << endl;
    cout << *(array3[0][2]) << endl;


    **ChArray3 = &array3[2][3][1];
    cout << "Array element:" << endl;
    cout << *(**ChArray3) << endl;

    return 0;
}