#include <list>
#include "windows.h"
#pragma once

class Deque
{
public:
	Deque(); // ������� ����
	~Deque(); // �������� ������

	int* buffer;
	DWORD bufferSize;
	HANDLE hHeap;
	DWORD dwThreadId;

	std::list <int> deque; // ���������� ������
	int length; // ���������� ��������� � ����
};