#include "pch.h"
#include "Deque.h"
#include "DequeFunction.h"
#include "windows.h"
#include <list>
#include <iostream>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#define _CRT_SECURE_NO_WARNINGS
#pragma once
#pragma warning(disable : 4996)



int main(int argc, TCHAR* argv[])
{
	setlocale(LC_ALL, "Russian");
	char* strDeque = ReadFromFile();
	Deque* deque = stringToDeque(strDeque);
	//Deque* deque = NULL;
	//WriteToFile(deque);
	//char* str_deque = load_file(L"test.txt");
	//deque* _deque = string_to_deque(str_deque);
	fillFromBuffer(deque);
	std::cout << "Дочерний процесс завершил свою работу" << std::endl;
	system("pause");

	return 0;
}

