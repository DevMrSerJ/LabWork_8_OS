#include <list>
#include "pch.h"
#include "windows.h"
#include "Deque.h"
#include "DequeFunction.h"
#include <iostream>
#include <string>
#include <stdio.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS
#pragma once
#pragma warning(disable : 4996)

using namespace std;

HANDLE hOut = GetStdHandle(STD_OUTPUT_HANDLE);
HANDLE hIn = GetStdHandle(STD_INPUT_HANDLE);
DWORD bufferDWORD;
const char* bufferConstChar;
char bufferCharArr[4];
LPCWSTR bufferLPCWSTR;
char bufferDequeStr[250];


int SizeDeque(Deque * deque)
{
	return deque->length;
}

void OutputAll(Deque * deque)
{
	for (int n : deque->deque)
		std::cout << n << " ";

	std::cout << std::endl;
}

void OutputEnd(Deque * deque)
{
	cout << "Последний элемент дека: " << deque->deque.back() << endl; // Выводим первый элемент
}

void OutputStart(Deque * deque)
{
	cout << "Первый элемент дэка: " << deque->deque.front() << endl; // Выводим первый элемент
}

void DeleteStart(Deque * deque)
{
	deque->deque.pop_front(); // Удаляем первый элемент в деке
	deque->length--;
	cout << "Число из начала удалено!" << endl;
}

void DeleteEnd(Deque * deque)
{
	deque->deque.pop_back(); // Удаляем последний элемент в деке
	deque->length--;
	cout << "Число из конца удалено!" << endl;
}

void AddStart(Deque * deque, int value)
{
	deque->deque.push_front(value); // Записываем в начало value
	deque->length++;
	cout << "Число записано в начало!" << endl;
}

void AddEnd(Deque * deque, int value)
{
	deque->deque.push_back(value); // Записываем в конец value
	deque->length++;
}

void WriteToFile(Deque * deque)
{
	string strDeque = "";
	for (DWORD i = 0; i < deque->bufferSize; i++)
	{
		strDeque += to_string(deque->buffer[i]);
		strDeque += ";";
	}

	LPCSTR LPCStrDeque = strDeque.c_str();
	HANDLE hFile;

	hFile = CreateFile(L"C:\\Users\\ivano\\OneDrive\\Документы\\Labs\\OS Labs\\LabWork_8_OS\\Lab08\\Task08\\DequeFile.txt", GENERIC_WRITE, FILE_SHARE_WRITE, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	WriteFile(hFile, LPCStrDeque, strlen(LPCStrDeque), &bufferDWORD, NULL);
	CloseHandle(hFile);
}

char* ReadFromFile()
{
	HANDLE hFile;

	hFile = CreateFile(L"C:\\Users\\ivano\\OneDrive\\Документы\\Labs\\OS Labs\\LabWork_8_OS\\Lab08\\Task08\\DequeFile.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(hFile, bufferDequeStr, 250, &bufferDWORD, NULL);
	CloseHandle(hFile);

	return bufferDequeStr;
}

Deque * stringToDeque(char * strDeque)
{
	Deque* deque = new Deque;
	std::list<int> buf;
	char *ptr;

	if ((ptr = strtok(strDeque, ";")) != nullptr)
	{
		buf.push_back(atoi(ptr)); // add element in buffer
		deque->bufferSize++;
		ptr = strtok(0, ";");

		while (ptr) {
			buf.push_back(atoi(ptr)); // add element in buffer
			deque->bufferSize++;
			ptr = strtok(0, ";");

		}
	}
	int* buffer = new int[deque->bufferSize];
	int i = 0;
	for (auto iter = buf.begin(); iter != buf.end(); iter++)
	{
		buffer[i] = *iter;
		i++;
	}
	deque->buffer = buffer;

	return deque;
}

void fillBuffer(Deque * deque)
{
	DWORD n;
	std::cout << "Введите количество элементов деки: ";
	std::cin >> n;
	std::cout << "_______________________________________________" << std::endl;
	for (DWORD i = 0; i < n; i++)
	{
		INT num = rand() % 100;
		deque->buffer[i] = num;
		deque->bufferSize++;
		std::cout << "Процесс: " << GetCurrentProcessId() << std::endl;
		std::cout << "Элемент добавлен в буффер: " << num << std::endl;
		std::cout << "_______________________________________________" << std::endl;
	}
	WriteToFile(deque);
}

void fillFromBuffer(Deque * deque)
{
	int len = deque->bufferSize;
	for (int i = 0; i < len; i++)
	{
		std::cout << "Процесс: " << GetCurrentProcessId() << std::endl;
		std::cout << "Элемент добавлен в деку: " << deque->buffer[i] << std::endl;
		AddEnd(deque, deque->buffer[i]);
		std::cout << "Дека: " << std::endl;
		OutputAll(deque);
		std::cout << "_______________________________________________" << std::endl;
	}
	WriteToFile(deque);
}