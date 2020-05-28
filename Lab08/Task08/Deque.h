#include <list>
#include "windows.h"
#pragma once

class Deque
{
public:
	Deque(); // Созание дека
	~Deque(); // Очищение памяти

	// Для работы с потоками
	HANDLE hHeap, hEventBufferEmpty, hEventBufferFull;
	HANDLE hThread;
	DWORD dwThreadId;

	INT buffer; // Для хранения элемента, который будет добавлен в дэк

	std::list <int> deque; // Двусвязный список
	int length; // Количество элементов в деке
};