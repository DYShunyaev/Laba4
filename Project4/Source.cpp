#include <iostream>
#include <math.h>
#include<stdlib.h>
#include <locale.h>

using namespace std;

const int RAZ = 10;
typedef int telem;
typedef telem tmas[RAZ];

int selectArrayLength();
void selectArrayNumbers(int size, int array[]);
void printArray(int array[], int size);
void selectionSort(int array[], int size);
void arrayConversion(int array[], int size);

int main() {
    setlocale(LC_ALL, "Russian");


    cout << "������������ ������ �4" << endl;
    cout << "-----------------------------------------" << endl;

    int size = selectArrayLength();
    tmas array;

    selectArrayNumbers(size, array);

    cout << "�������� ������: " << endl;
    printArray(array, size);

    selectionSort(array, size);

    cout << "��������������� ������: " << endl;
    printArray(array, size);

    arrayConversion(array, size);

    cout << "��������������� ������: " << endl;
    printArray(array, size);

    return 0;
}

int selectArrayLength() {                                                 //������� ��� ����������� ������� �������;
    int size = 1;
    while (size % 2 != 0)                                                 //��������� ��������, ����� ������ ������� ���� ������ ��������;
        {
            setlocale(LC_ALL, "Russian");
            cout << "  ������� ������ ����� ������� �������: ";
            cin >> size;
        }
    return size;
}

void selectArrayNumbers(int size, int array[]) {                                 //������� ��� ���������� ������� ����������;
    for (int i = 0; i < size; i++)
    {
        setlocale(LC_ALL, "Russian");
        cout << "    ������� ����� �" << i + 1 << ": ";

        int number;
        cin >> number;
        array[i] = number;
    }
}

void printArray(int array[], int size) {                                  //������� ��� ������ ������� � �������;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void selectionSort(int array[], int size) {                               //������� ��� ���������� ���������� �������, � ������� �����������;
    for (int i = 0; i < size; i++) {
        int min = array[i];                                               //������� ���������� ������������ �������� �������;
        int min_i = i;                                                    //������� ������ ������������ �������� �������;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < min) {                                         //���������� ����������� �������� �������, � ����������;
                min = array[j];                                           //���� ����������� �������� ������� ������ �����������,
                //�� �������������� ���������� min; 
                min_i = j;                                                //��� �� �������� ����������� � �������� �������;
            }
        }
        if (i != min_i) {
            int tmp = array[i];                                           //���������� ���������� � �������� i;
            array[i] = array[min_i];                                      //����������� ������� i ����� ��������;
            array[min_i] = tmp;                                           //����������� ������� j ����� ��������;
        }
    }                                                                     //������ �������� ���������� "���������� ���������";
}

void arrayConversion(int array[], int size) {                             //��������������� ������ � �������� ������� ����������;
    for (int i = size / 2 - 1; i >= 0; i--) {                             //�������������� ����� ����������� � 2 �����, �� �������� �������,
        //��� ����� �������� ������ ������� �� 2 � ������ 1, ����� ��������� ���� ������;
        int max = array[i];                                               //��������� ����������, � ������� ����� ���������� ������������ �������� �������� �������;
        int max_i = i;                                                    //��������� ���������� � ������� ����� ���������� ������ ����. �������� �������;
        for (int j = i - 1; j >= 0; j--) {                                //��������� ���� ��� ��������� ��������� �������� � ���������� max;
            if (array[j] < max) {                                         //���� ���������� �������� ������ �������������, �� �������������� �������� ����������;
                max = array[j];
                max_i = j;
            }
        }
        if (i != max_i) {                                                 //���� ������ i �� ����� ������� � ��������� max_i, �� ������ ������� �������� � �������;
            int tmp = array[i];
            array[i] = array[max_i];
            array[max_i] = tmp;
        }
    }                                                                     //������ �������� �������� �� ��� ���, ���� 1� �������� ������� �� ������������� � �������� �������;

    for (int i = size - 1; i >= size / 2; i--) {                          //�������� �� �� �������� �� ������ ��������� �������;
        int max = array[i];
        int max_i = i;
        for (int j = i - 1; j >= size / 2; j--) {
            if (array[j] < max) {
                max = array[j];
                max_i = j;
            }
        }
        if (i != max_i) {
            int tmp = array[i];
            array[i] = array[max_i];
            array[max_i] = tmp;
        }
    }

    for (int i = size / 2; i < size; i++) {
        array[i] += 1;
    }
    //� ������� ������� ����� ��������������� ������ �������� ������� � ����, ������� ����� ��������� ������;
}