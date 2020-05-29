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
	deque.resize(0); // ����� 0 �����
	length = 0; // ������ ����� ������ 0

	hHeap = HeapCreate(0, 2 * sizeof(INT*), 0);
	buffer = new int[40];
	bufferSize = 0;
}

Deque::~Deque()
{
	deque.clear(); // ������� ��� �������� ����
	length = 0; // ������ ����� ������ 0
}