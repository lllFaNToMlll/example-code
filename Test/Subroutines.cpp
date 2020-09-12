#include "Subroutines.h"

void ArrayShow(int** Array, const int& arraySize) {
    for (int i = 0; i < arraySize; i++)
    {
        for (int j = 0; j < arraySize; j++)
        {
            std::cout << std::setw(9) << Array[i][j];
        }
        std::cout << std::endl;
    }
}

void ArrayInputInit(int** Array, const int& arraySize) {
    for (int i = 0; i < arraySize; i++)
        for (int j = 0; j < arraySize; j++) {
            std::cout << "Введите [" << i + 1 << "][" << j + 1 << "] элемент матрицы:" << std::endl;
            std::cin >> Array[i][j];
        }
}

void ArrayRandomInit(int** Array, const int& arraySize) {
    srand(time(nullptr));
    for (int i = 0; i < arraySize; i++)
        for (int j = 0; j < arraySize; j++)
            Array[i][j] = rand() % (60001) - 30000;   //Случайное значение от -30000 до 30000 в ячейку массива
}

void FindMinAndMultTen(int** Array, const int& arraySize) {
    int minElement = Array[0][0], minElementStrIndex = 0, minElementClmnIndex = 0;
    for (int i = 0; i < arraySize; i++)
        for (int j = 0; j < arraySize; j++) {
            if (Array[i][j] < minElement) {
                minElement = Array[i][j];
                minElementStrIndex = i;
                minElementClmnIndex = j;
            }
        }
    std::cout << std::endl;
    std::cout << "Минимальный элемент = " << minElement << " Он находится в ячейке: [" << minElementStrIndex + 1 << "][" << minElementClmnIndex + 1 << "]" << std::endl;
    Array[minElementStrIndex][minElementClmnIndex] = minElement * 10;
}

int FindMaxAndSumMainD(int** Array, const int& arraySize) {
    int sum = 0, maxElement = Array[0][0];
    for (int i = 0; i < arraySize; i++) {
        if (maxElement < Array[i][i]) {
            maxElement = Array[i][i];
        }
    }
    int buf = maxElement;
    while (buf != 0)
    {
        sum += buf % 10;
        buf /= 10;
    }
    std::cout << std::endl;
    std::cout << "Максимальное число на главной диагонали = " << maxElement << ". Сумма его цифр = " << abs(sum) << std::endl;
    return maxElement;
}

void FindMaxWord(const std::string& myStr) {
    std::string bufWord, maxWord;
    int maxLenght = 0;
    for (int i = 0; i <= myStr.size(); i++) {
        if (myStr[i] != ' ' && myStr[i] != '\0')
            bufWord.push_back(myStr[i]);
        else {
            if (maxLenght < bufWord.size()) {
                maxWord.clear();
                maxLenght = bufWord.size();
                maxWord = bufWord;
            }
            else if (maxLenght == bufWord.size()) {
                if (maxWord > bufWord) {
                    maxWord.clear();
                    maxWord = bufWord;
                }
            }
            bufWord.clear();
        }
    } //fisrt second third forth fifth sixth
    std::cout << "Самое длинное слово в введенной строке: " << maxWord << std::endl;
}

void FindMaxLetterAtTheEnd(const std::string& myStr) {
    std::multimap<char, int> myMultiMap;
    int maxLetter = 0;
    char letter;
    for (int i = 0; i < myStr.size(); i++) {
        if ((myStr[i + 1] == ' ' || myStr[i + 1] == '\0') && myStr[i] != ' ')
            myMultiMap.insert(std::pair<char, int>(myStr[i], 1));
    }
    std::map<char, int>::iterator it = myMultiMap.begin();
    for (int i = 0; it != myMultiMap.end(); it++, i++) {
        std::cout << i + 1 << ") Буква " << it->first << ", количество " << myMultiMap.count(it->first) << std::endl;
        if (maxLetter < myMultiMap.count(it->first)) {
            maxLetter = myMultiMap.count(it->first);
            letter = it->first;
        }
    }
    std::cout << "Чаще всего встречается в конце слова буква: " << letter << " Она встречается " << maxLetter << " раз(-а)" << std::endl;
}