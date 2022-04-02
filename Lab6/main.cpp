#include <cstring>
#include <iostream>


using namespace std;

int size = 8;
int key = 0;
int index = 0;

double array[8] = {6, 4, 2, 5, 1, 3, 8, 7};
struct Student {
    int id = 1;
    char firstname[5] = {'Y', 'u', 'r', 'i', 'u'};
    double arr[5] = { 3, 4.5, 5.2, 3, 5};
    int age = 21;
    int data = 4;
    double *ptr = arr;
    Student* next;
};

void arraySearch(double arr[8], int key){
    int count = 0;
    for (int i = 0; i < 8; ++i) {
        if (arr[i] == key)
            cout << "Element: " << arr[i] << " index: " << count << endl;
        count++;
    }
}

double array2Search(double arr[8], int left, int right, int key){
    int mid = 0;
    while (1) {
        mid = (left + right) / 2;

        if (key < arr[mid])
            right = mid - 1;
        else if (key > arr[mid])
            left = mid + 1;
        else
            return mid;

        if (left > right)
            return -1;
    }
}

int partition(double arr[], int start, int end) {
    int pivot = arr[start];
    int count = 0;
    for (int i = start + 1; i <= end; i++) {
        if (arr[i] <= pivot)
            count++;
    }
    int pivotIndex = start + count;
    swap(arr[pivotIndex], arr[start]);
    int i = start, j = end;
    while (i < pivotIndex && j > pivotIndex) {
        while (arr[i] <= pivot) {
            i++;
        }
        while (arr[j] > pivot) {
            j--;
        }
        if (i < pivotIndex && j > pivotIndex) {
            swap(arr[i++], arr[j--]);
        }
    }
    return pivotIndex;
}

void quickSort(double arr[], int start, int end) {
    if (start >= end)
        return;
    int p = partition(arr, start, end);
    quickSort(arr, start, p - 1);
    quickSort(arr, p + 1, end);
}

void task1(double arr[], int n) {
    quickSort(arr, 0, n - 1);
    cout << "Sorted array: \n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void listSearch(Student * student) {
    Student *Cur = student;
    char ask[555];
    cout << "Input word" << endl;
    cin >> ask;

    while (Cur) {
        if (strcmp(Cur->firstname, ask) != 0){
            cout << Cur->firstname << endl << Cur->id << endl << Cur->age << endl << Cur->arr;
        } else {
            cout << "Err" << endl;
        }
        Cur = Cur->next;
    }
}

int main() {
    arraySearch(array, 4);
    task1(array, 8);
    cout << "Input number: " << endl;
    cin >> key;
    index = array2Search(array, 0, size, key);
    cout << "Index: " << index << endl;

    Student *student = new Student;
    student->next = nullptr;
    listSearch(student);

    return 0;
}
