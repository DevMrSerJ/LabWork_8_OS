#include <list>
#include "windows.h"
#include "Deque.h"
#pragma once

DWORD WINAPI inputStartElements(LPVOID ptr);

int SizeDeque(Deque *deque); // Размер дека
void OutputAll(Deque *deque); // вывести все элементы дека
void OutputEnd(Deque *deque); // Выводит последний элемент
void OutputStart(Deque *deque); // Выводит первый элемент
void DeleteStart(Deque *deque); // Удалить первый элемент
void DeleteEnd(Deque *deque); //Удалить последний элемент
void AddStart(Deque *deque, int value); // Добавить элемент в начало
void AddEnd(Deque *deque, int value); // Добавить элемент в конец
void WriteToFile(Deque *deque); // Запись дэка в файл
char* ReadFromFile(); // Чтение дэка из файла

Deque* stringToDeque(char* str_deque); // String deque in struct Deque
void fillBuffer(Deque* deque); // Add elements in buffer deque