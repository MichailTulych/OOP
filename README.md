﻿# ООП на c++
## Лабораторная № 1 "Классы", Вариант №17
### Задача:
Описать класс, реализующий тип данных «вещественная матрица» и работу с ними.
Класс должен реализовывать следующие операции над матрицами:
1) Cложение, вычитание, умножение, деление (+, –, *, /) (умножение и деление как на другую матрицу, так и на число);
2) Комбинированные операции присваивания (+=, –=, *=, /=);
3) Операции сравнения на равенство (неравенство);
4) Операции вычисления обратной и транспонированной матрицы, операцию возведения в степень;
5) Методы вычисления детерминанта и нормы;
6) Методы, реализующие проверку типа матрицы (квадратная, диагональная, нулевая, единичная, симметрическая, верхняя треугольная, нижняя треугольная);
7) Операции ввода-вывода в стандартные потоки.
Написать программу, демонстрирующую работу с этим классом. Программа должна содержать меню, позволяющее осуществить проверку всех методов класса

## Лабораторная № 2 "Наследование", Вариант №17
### Задача:
Написать программу, показывающая работу с объектами двух типов, T1=Triangle и T2=Tetragon, для чего создать систему соответствующих классов. 
Каждый объект должен иметь идентификатор (в виде произвольной строки символов) и одно или несколько полей для хранения состояния (текущего значения) объекта. Клиенту (функции main) должны быть доступны следующие основные операции(методы): 
1) создать объект
2) удалить объект
3) показать значение объекта
4) Move() - Переместить объект на плоскости
5) IsIntersect(T& ob1, T& ob2) - Определить факт пересечения объектов ob1 и ob2(есть пересечение или нет)
Операции по созданию и удалению объектов инкапсулировать в классе Factory. Предусмотреть меню, позволяющее продемонстрировать заданные операции.

## Лабораторная № 3 "Шаблоны классов. Обработка исключительных ситуаций", Вариант №17
### Задача:
Требуется создать шаблон некоторого целевого класса A. В каждом варианте уточняются требования к реализации — указанием на применение некоторого серверного класса B. Это означает, что объект класса B используется как элемент класса A. В качестве серверного класса может быть указан либо класс, созданный программистом в рамках того же задания, либо класс стандартной библиотеки.
Целевой шаблонный класс: Set - Множество (повторяющиеся элементы в множество не заносятся; элементы в множестве хранятся отсортированными);
Реализация с применением: List - Двунаправленный список;
Если вместо серверного класса указан динамический массив, это означает, что для хранения элементов в целевом классе используется массив, размещаемый с помощью операции new. Во всех вариантах необходимо предусмотреть генерацию и обработку исключений для возможных ошибочных ситуаций.
Во всех вариантах показать в клиенте main использование созданного класса, включая ситуации, приводящие к генерации исключений. Показать инстанцирование
шаблона для типов int, double, std::string.

## Лабораторная № 4 "Стандартные потоки", Вариант №17
### Задача:
1. Определить класс с именем ZNAK, содержащий следующие поля:
  - Фамилия, имя;
  - Знак Зодиака;
  - День рождения (массив из трех чисел).
Определить методы доступа к этим полям и перегруженные операции извлечения и вставки для объектов типа ZNAK.
2. Написать программу, выполняющую следующие действия:
  - Ввод с клавиатуры данных в массив, состоящий из восьми объектов типа ZNAK;
  - Записи должны быть упорядочены по знакам Зодиака;
  - Вывод на экран информации о людях, родившихся в месяц, значение которого введено с клавиатуры;
  - Если таких нет, выдать на дисплей соответствующее сообщение.
