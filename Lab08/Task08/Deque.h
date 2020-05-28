#include <list>
#include "windows.h"
#pragma once

class Deque
{
public:
	Deque(); // ������� ����
	~Deque(); // �������� ������

	// ��� ������ � ��������
	HANDLE hHeap, hEventBufferEmpty, hEventBufferFull;
	HANDLE hThread;
	DWORD dwThreadId;

	INT buffer; // ��� �������� ��������, ������� ����� �������� � ���

	std::list <int> deque; // ���������� ������
	int length; // ���������� ��������� � ����
};