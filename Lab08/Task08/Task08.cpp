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
	STARTUPINFO si;
	PROCESS_INFORMATION pi;
	ZeroMemory(&si, sizeof(STARTUPINFO));
	si.cb = sizeof(si);
	ZeroMemory(&pi, sizeof(PROCESS_INFORMATION));

	// Установка кириллицы
	setlocale(LC_ALL, "Russian");
	Deque* deque = new Deque;

	fillBuffer(deque);

	CreateProcess(L"AddElements.exe", NULL, NULL, NULL, FALSE, CREATE_NEW_CONSOLE, NULL, NULL, &si, &pi);
	WaitForSingleObject(pi.hProcess, INFINITE);
	CloseHandle(pi.hProcess);
	CloseHandle(pi.hThread);
	std::cout << "\n\n\n" << std::endl;
	char* strDeque = ReadFromFile();
	deque = stringToDeque(strDeque);
	std::cout << "Дека: " << std::endl;
	OutputAll(deque);
	std::cout << "Тесты завершены" << std::endl;
	system("pause");
}