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


DWORD WINAPI inputStartElements(LPVOID ptr)
{
	HANDLE thrdSub = NULL;
	Deque* deque = (Deque*)ptr;

	while (true)
	{
		WaitForSingleObject(deque->hEventBufferFull, INFINITE);

		// ���������� �������� � ���
		AddEnd(deque, deque->buffer);
		deque->length++;

		thrdSub = GetCurrentThread();
		std::cout << "�����: " << GetThreadId(thrdSub) << std::endl;
		std::cout << "�������� ������� � ���: " << deque->buffer << std::endl;
		std::cout << "���:";
		OutputAll(deque);
		std::cout << "������ ���� � ����" << std::endl;
		WriteToFile(deque);
		std::cout << "������ ���� � ���� ������ �������" << std::endl;
		std::cout << "������ ���� �� ����" << std::endl;
		ReadFromFile(deque);
		std::cout << "��� ������� �������� �� �����. ���������: ";
		OutputAll(deque);
		std::cout << "***********************************************" << std::endl;
		ResetEvent(deque->hEventBufferFull);
		SetEvent(deque->hEventBufferEmpty);
	}

	return 0;
}

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
	cout << "��������� ������� ����: " << deque->deque.back() << endl; // ������� ������ �������
}

void OutputStart(Deque * deque)
{
	cout << "������ ������� ����: " << deque->deque.front() << endl; // ������� ������ �������
}

void DeleteStart(Deque * deque)
{
	deque->deque.pop_front(); // ������� ������ ������� � ����
	deque->length--;
	cout << "����� �� ������ �������!" << endl;
}

void DeleteEnd(Deque * deque)
{
	deque->deque.pop_back(); // ������� ��������� ������� � ����
	deque->length--;
	cout << "����� �� ����� �������!" << endl;
}

void AddStart(Deque * deque, int value)
{
	deque->deque.push_front(value); // ���������� � ������ value
	deque->length++;
	cout << "����� �������� � ������!" << endl;
}

void AddEnd(Deque * deque, int value)
{
	deque->deque.push_back(value); // ���������� � ����� value
	deque->length++;
}

void WriteToFile(Deque * deque)
{
	string strDeque = "";

	for (int n : deque->deque)
	{
		strDeque += to_string(n);
		strDeque += ";";
	}

	LPCSTR LPCStrDeque = strDeque.c_str();
	HANDLE hFile;

	hFile = CreateFile(L"DequeFile.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, CREATE_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	WriteFile(hFile, LPCStrDeque, strlen(LPCStrDeque), &bufferDWORD, NULL);
	CloseHandle(hFile);
}

void ReadFromFile(Deque * deque)
{
	deque->deque.resize(0); // ����� 0 �����
	deque->length = 0; // ������ ����� ������ 0

	HANDLE hFile;

	hFile = CreateFile(L"DequeFile.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ, NULL, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);
	ReadFile(hFile, bufferDequeStr, 250, &bufferDWORD, NULL);
	CloseHandle(hFile);

	char *ptr;

	if ((ptr = strtok(bufferDequeStr, ";")) != nullptr)
	{
		AddEnd(deque, atoi(ptr));
		ptr = strtok(0, ";");

		while (ptr) {
			AddEnd(deque, atoi(ptr));
			ptr = strtok(0, ";");

		}
	}
}

void InputElements(Deque *deque)
{
	DWORD n;
	HANDLE thrdMain = NULL;
	std::cout << "������� ���������� ��������� ����: ";
	std::cin >> n;
	std::cout << "***********************************************" << std::endl;
	for (DWORD i = 0; i < n; i++)
	{
		WaitForSingleObject(deque->hEventBufferEmpty, INFINITE);
		INT num = rand() % 100;
		deque->buffer = num;
		thrdMain = GetCurrentThread();

		std::cout << "�����: " << GetThreadId(thrdMain) << std::endl;
		std::cout << "������� ��� ������ � ���: " << num << std::endl;
		std::cout << "***********************************************" << std::endl;
		SetEvent(deque->hEventBufferFull);
	}
}