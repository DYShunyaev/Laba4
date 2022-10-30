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


    cout << "Лабораторная работа №4" << endl;
    cout << "-----------------------------------------" << endl;

    int size = selectArrayLength();
    tmas array;

    selectArrayNumbers(size, array);

    cout << "Исходный массив: " << endl;
    printArray(array, size);

    selectionSort(array, size);

    cout << "Отсортированный массив: " << endl;
    printArray(array, size);

    arrayConversion(array, size);

    cout << "Преобразованный массив: " << endl;
    printArray(array, size);

    return 0;
}

int selectArrayLength() {                                                 //функция для определения размера массива;
    int size = 1;
    while (size % 2 != 0)                                                 //выполняем проверку, чтобы размер массива имел четное значение;
        {
            setlocale(LC_ALL, "Russian");
            cout << "  Введите четное число размера массива: ";
            cin >> size;
        }
    return size;
}

void selectArrayNumbers(int size, int array[]) {                                 //функция для заполнения массива значениями;
    for (int i = 0; i < size; i++)
    {
        setlocale(LC_ALL, "Russian");
        cout << "    Введите число №" << i + 1 << ": ";

        int number;
        cin >> number;
        array[i] = number;
    }
}

void printArray(int array[], int size) {                                  //функция для вывода массива в консоль;
    for (int i = 0; i < size; i++) {
        cout << array[i] << " ";
    }
    cout << endl;
}

void selectionSort(int array[], int size) {                               //функция для выполнения сортировки массива, в порядке возрастания;
    for (int i = 0; i < size; i++) {
        int min = array[i];                                               //создаем переменную минимального значения массива;
        int min_i = i;                                                    //выводим индекс минимального значения массива;
        for (int j = i + 1; j < size; j++) {
            if (array[j] < min) {                                         //сравниваем последующее значение массива, с предыдущим;
                min = array[j];                                           //если последующее значение массива меньше предыдущего,
                //то перезыписываем переменную min; 
                min_i = j;                                                //эту же операцию проделываем с индексом массива;
            }
        }
        if (i != min_i) {
            int tmp = array[i];                                           //записываем переменную с индексом i;
            array[i] = array[min_i];                                      //присваеваем индексу i новое значение;
            array[min_i] = tmp;                                           //присваеваем индексу j новое значение;
        }
    }                                                                     //данный алгоритм называется "Сортировка Пузырьком";
}

void arrayConversion(int array[], int size) {                             //преобразовываем массив к заданным задачей параметрам;
    for (int i = size / 2 - 1; i >= 0; i--) {                             //преобразование будет проводиться в 2 этапа, по половине массива,
        //для этого разделим размер массива на 2 и вычтем 1, чтобы равенство было верным;
        int max = array[i];                                               //объявляем переменную, в котором будет находиться максимальное значение половины массива;
        int max_i = i;                                                    //объявляем переменную в которой будет находиться индекс макс. значения массива;
        for (int j = i - 1; j >= 0; j--) {                                //вложенный цикл для сравнения остальных значений с прерменной max;
            if (array[j] < max) {                                         //если предыдущее значение меньше максимального, то перезаписываем значение переменной;
                max = array[j];
                max_i = j;
            }
        }
        if (i != max_i) {                                                 //если индекс i не равен индексу в пременной max_i, то меняем местами занчения в массиве;
            int tmp = array[i];
            array[i] = array[max_i];
            array[max_i] = tmp;
        }
    }                                                                     //данную операцию проводим до тех пор, пока 1я половина массива не преобразуется в обратном порядке;

    for (int i = size - 1; i >= size / 2; i--) {                          //проводим ту же операцию со второй половиной массива;
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
    //с помощью данного цикла преобразовываем вторую половину массива к виду, который задан условиями задачи;
}