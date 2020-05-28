#include "pch.h"
#include "Deque.h"
#include "DequeFunction.h"
#include <list>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma once
#pragma warning(disable : 4996)

using namespace std;
#define STRLEN(x) (sizeof(x)/sizeof(TCHAR) - 1)

int main()
{
	// Установка кириллицы
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Deque* dq = new Deque;

	InputElements(dq);
	WaitForSingleObject(dq->hEventBufferEmpty, INFINITE);
	std::cout << "Тест закончен" << std::endl;
	system("pause");
}