// Test.cpp : Этот файл содержит функцию "main". Здесь начинается и заканчивается выполнение программы.
//

#include "Subroutines.h"

int main() {
    setlocale(0, "");
    int arraySize = -1;
    while (arraySize <= 0) {
        std::cout << "Введите размер матрицы" << std::endl;
        std::cin >> arraySize;
    }
    int** myArray = new int* [arraySize];   // создаем  двумерный массив
    for (int i = 0; i < arraySize; i++) {
        myArray[i] = new int[arraySize];
    }
    int userAnswer = -1;
    while (userAnswer != 0 && userAnswer != 1) {
        std::cout << "Выберите как заполнить матрцу: 0 - вручную, 1 - случайными числами" << std::endl;
        std::cin >> userAnswer;
    }
    if (userAnswer == 0)
        ArrayInputInit(myArray, arraySize);
    else
        ArrayRandomInit(myArray, arraySize);
    ArrayShow(myArray, arraySize);
    FindMinAndMultTen(myArray, arraySize);
    ArrayShow(myArray, arraySize);
    FindMaxAndSumMainD(myArray, arraySize);
    for (int i = 0; i < arraySize; i++) {
        delete[] myArray[i];  // удаляем массив
    }
    std::cout << "Введите строку: ";
    std::string myStr;
    std::getline(std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'), myStr);
    FindMaxWord(myStr);
    FindMaxLetterAtTheEnd(myStr);
    system("pause");
    return 0;
}

