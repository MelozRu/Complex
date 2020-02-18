#pragma once
#include <iostream>
#include <fstream>

using namespace std;

/* Объявление класса комплексных чисел */

class Complex {

  // публичные поля с полями и методами (у нас просто с методами), доступными пользователю  вашего класса
public:
  Complex();                                         // конструктор по умолчанию
  Complex(const Complex &c);                         // конструктор копирования
  Complex(double _re, double _im);                   // конструктор инициализации
  Complex(double d);                                 // конструктор преобразования типа

  ~Complex();                                        // деструктор

  void output();                                     // функция вывода на экран комплексного числа
  Complex Add(const Complex& c);                     // функция сложения

  // перегрузка операторов
  Complex& operator=(const Complex& c);              // перегруженный оператор присваивания

  bool operator==(const Complex& c);                 // дз

  Complex operator+(const Complex& c);               // перегруженные оператор сложения
  Complex operator-(const Complex& c);               // дз
  Complex operator*(const Complex& c);               // дз
  Complex operator/(const Complex& c);               // дз

  // Следующие функции рассмотрим на занятии вместе (можно попробовать самим вперёд)
  friend Complex operator+(double d, const Complex& c);
  friend Complex operator-(double d, const Complex& c);
  friend Complex operator*(double d, const Complex& c);
  friend Complex operator/(double d, const Complex& c);

  friend ostream& operator<<(ostream& stream, const Complex& c);
  friend istream& operator>>(istream& stream, Complex& c);

  // скрытые от пользователя поля и методы (у нас просто поля)
private:
  double re;                                         // действительная часть числа
  double im;                                         // мнимая часть числа

};                                                   // ВАЖНО: не забывайте ставить тут ;

/* Реализации конструкторов и деструктора*/

/// конструктор по умолчанию
Complex::Complex() {
  re = 0.0;
  this->im = 0.0;
}

/// конструктор копирования
Complex::Complex(const Complex &c) {
  re = c.re;
  im = c.im;
}

/// конструктор инициализации
Complex::Complex(double _re, double _im) : re(_re), im(_im) {  }

/// конструктор преобразования типа
Complex::Complex(double _re) {
  re = _re;
  im = 0.0;
}

/// деструктор (удаление)
Complex::~Complex() {
  re = 0.0;
  im = 0.0;
}

/* Реализации перегрузок операторов */

/// оператор присваивания
Complex& Complex::operator=(const Complex& c) {
  (*this).re = c.re;
  im = c.im;
  return *this;
}

/// операторы сравнения
bool Complex::operator==(const Complex& c) {
  bool res = 0;
  if (re == c.re && im == c.im) {
    return true;
  }
  else {
    return false;
  }
  return res;
}

/* Замечание: для комплексных чисел имеет смысл только эта операция сравнения
              (поле комплексных чисел не может быть упорядочено), поэтому
              перегрузка операторов > < >= <= не имеет смысла!
*/

/// функция сложения
Complex Complex::Add(const Complex& c) {
  Complex res;
  res.re = re + c.re;
  res.im = im + c.im;
  return res;
}

/// оператор сложения
Complex Complex::operator+(const Complex& c) {
  Complex res;
  res.re = re + c.re;
  res.im = im + c.im;
  return res;
}

/// оператор вычитания
Complex Complex::operator-(const Complex& c) {
  Complex res;
  res.re = re - c.re;
  res.im = im - c.im;
  return res;
}

/// оператор умножения
Complex Complex::operator*(const Complex& c) {
  Complex res;
  res.re = re * c.re - im * c.im;
  res.im = im * c.re + re * c.im;
  return res;
}

/// оператор деления
Complex Complex::operator/(const Complex& c) {
  Complex res;
  if ((c.re != 0) && (c.im != 0))
  {
    res.re = (re * c.re + im * c.im) / (c.re * c.re + c.im * c.im);
    res.im = (im * c.re - re * c.im) / (c.re * c.re + c.im * c.im);
  }
  else if ((c.re == 0) && (c.im == 0)) cout << "Нельзя делить на ноль" << endl;
  return res;
}

/* Прочие функции */

/// вывод комплексного числа на экран
void Complex::output() {
  cout << re;
  if (im > 0) { cout << " + " << im << "i"; }
  else if (im < 0) { cout << " - " << -im << "i"; }
  cout << endl;
}

ostream& operator<<(ostream& stream, const Complex& c)
{
  stream << c.re;
  if (c.im > 0) { stream << " + " << c.im << "i"; }
  else if (c.im < 0) { stream << " - " << -c.im << "i"; }
  return stream;
}

istream& operator>>(istream& stream, Complex& c)
{
  stream >> c.re >> c.im;
  return stream;
}
