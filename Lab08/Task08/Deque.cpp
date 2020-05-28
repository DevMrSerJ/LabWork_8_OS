#include "pch.h"
#include "Deque.h"
#include "DequeFunction.h"
#include <iostream>

#define _CRT_SECURE_NO_WARNINGS
#pragma once
#pragma warning(disable : 4996)

using namespace std;


Deque::Deque()
{
	deque.resize(0); // Задаём 0 длину
	length = 0; // Храним длину равную 0

	hHeap = HeapCreate(0, 2 * sizeof(INT*), 0);
	hThread = CreateThread(NULL, 0, inputStartElements, this, 0, &dwThreadId);
	hEventBufferEmpty = CreateEvent(NULL, FALSE, TRUE, NULL);
	hEventBufferFull = CreateEvent(NULL, FALSE, FALSE, NULL);
}

Deque::~Deque()
{
	deque.clear(); // Удаляем все элементы дека
	length = 0; // Храним длину равную 0
}