#pragma once
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <map>
#include <string>
#include <iomanip>
#include <sstream>

void ArrayShow(int** Array, const int& arraySize);

void ArrayInputInit(int** Array, const int& arraySize);

void ArrayRandomInit(int** Array, const int& arraySize);

void FindMinAndMultTen(int** Array, const int& arraySize);

int FindMaxAndSumMainD(int** Array, const int& arraySize);

void FindMaxWord(const std::string& myStr);

void FindMaxLetterAtTheEnd(const std::string& myStr);