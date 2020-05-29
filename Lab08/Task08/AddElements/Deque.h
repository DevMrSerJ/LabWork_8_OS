#include <list>
#include "windows.h"
#pragma once

class Deque
{
public:
	Deque(); // Созание дека
	~Deque(); // Очищение памяти

	int* buffer;
	DWORD bufferSize;
	HANDLE hHeap;
	DWORD dwThreadId;

	std::list <int> deque; // Двусвязный список
	int length; // Количество элементов в деке
};