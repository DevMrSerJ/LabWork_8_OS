#include <list>
#include "windows.h"
#include "Deque.h"
#pragma once

DWORD WINAPI inputStartElements(LPVOID ptr);

int SizeDeque(Deque *deque); // ������ ����
void OutputAll(Deque *deque); // ������� ��� �������� ����
void OutputEnd(Deque *deque); // ������� ��������� �������
void OutputStart(Deque *deque); // ������� ������ �������
void DeleteStart(Deque *deque); // ������� ������ �������
void DeleteEnd(Deque *deque); //������� ��������� �������
void AddStart(Deque *deque, int value); // �������� ������� � ������
void AddEnd(Deque *deque, int value); // �������� ������� � �����
void WriteToFile(Deque *deque); // ������ ���� � ����
void ReadFromFile(Deque *deque); // ������ ���� �� �����

void InputElements(Deque *deque); // ���������� ��������� � ���