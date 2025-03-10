#ifndef ARRAY_H
#define ARRAY_H

#include <iostream>

class ArrayException {}; // Класс исключений для массива

class Array {
private:
  int *ptr;     // Указатель на динамическое выделение массива
  int size;     // Текущий размер массива
  int capacity; // Текущая емкость массива
  void increaseCapacity(int newCapacity); // Метод для увелечения емкости
                                          // массива
  int getSize() const; // Метод возвращающий текущий размер массива

public:
  int &operator[](int index); // Перегружаеммый оператор для доступа по индексу
  void insert(int elem);      // Метод для добавление элементов
  void
  insert(int elem,
         int index); // Метод для добавляение элементов по определенному индексу
  void remove(int index); // Метод для удаление элементаа по индексу
  explicit Array(int startCapacity = DEFAULT_CAPACITY); // констркуктор
  ~Array();                                             // Деструктор
  Array(const Array &arr);            // конструктор копирования
  Array &operator=(const Array &arr); // Перегружаемый оператор присваивания
  int operator[](
      int index) const; // Оператор для доступа к элементов через индекс
  friend std::ostream &
  operator<<(std::ostream &out,
             const Array
                 &arr); // Перегружаемый оператор для вывода элементов на экраны

  static const int DEFAULT_CAPACITY = 10;
};

#endif
