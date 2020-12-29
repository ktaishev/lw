﻿#ifndef LW_UTILITY_H_
#define LW_UTILITY_H_

#include <iostream>

#define PRINT_HASH_LINE std::cout << std::endl << "#################################################################" << std::endl << std::endl;

//Функция печатающая основное меню
void print_main_menu(void)
{
    std::cout << std::endl << "#################################################################" << std::endl
        << "#\t 1. Работа с трубами                              \t#" << std::endl
        << "#\t 2. Работа с компрессорными станциями             \t#" << std::endl
        << "#\t 3. Работа с нефтесетью                           \t#" << std::endl
        << "#\t 4. Помощь                                        \t#" << std::endl
        << "#\t 0. Выход                                         \t#" << std::endl
        << "#################################################################" << std::endl << std::endl;
}

//Функция печатающая меню при работе с трубами
void print_pipe_menu(void)
{
    std::cout << std::endl << "#################################################################" << std::endl
        << "#\t 1. Добавить трубу                                \t#" << std::endl
        << "#\t 2. Удалить трубу                                 \t#" << std::endl
        << "#\t 3. Изменить состояние трубы (Работает/На ремонте)\t#" << std::endl
        << "#\t 4. Напечатать все трубы                          \t#" << std::endl
        << "#\t 5. Выбрать трубу                                 \t#" << std::endl
        << "#\t 6. Удалить трубу из выбранных                    \t#" << std::endl
        << "#\t 7. Напечатать выбранные трубы                    \t#" << std::endl
        << "#\t 8. Поиск по параметру                            \t#" << std::endl
        << "#\t 9. Изменение выбранных труб                      \t#" << std::endl
        << "#\t10. Сохранение в файл                             \t#" << std::endl
        << "#\t11. Загрузка из файла                             \t#" << std::endl
        << "#\t12. Помощь                                        \t#" << std::endl
        << "#\t0. Возврат в главное меню                         \t#" << std::endl
        << "#################################################################" << std::endl << std::endl;
}

//Функция печатающая меню при работе с компрессорными станциями
void print_ks_menu(void)
{
    std::cout << std::endl << "#################################################################" << std::endl
        << "#\t 1. Добавить компрессорную станцию                \t#" << std::endl
        << "#\t 2. Удалить компрессорную станцию                 \t#" << std::endl
        << "#\t 3. Закрыть цех                                   \t#" << std::endl
        << "#\t 4. Открыть цех                                   \t#" << std::endl
        << "#\t 5. Напечатать все компрессорные станции          \t#" << std::endl
        << "#\t 6. Выбрать компрессорную станцию                 \t#" << std::endl
        << "#\t 7. Удалить компрессорную станцию из выбранных    \t#" << std::endl
        << "#\t 8. Напечатать выбранные компрессорные станции    \t#" << std::endl
        << "#\t 9. Поиск по параметру                            \t#" << std::endl
        << "#\t10. Изменение выбранных компрессорных станций     \t#" << std::endl
        << "#\t11. Сохранение в файл                             \t#" << std::endl
        << "#\t12. Загрузка из файла                             \t#" << std::endl
        << "#\t13. Помощь                                        \t#" << std::endl
        << "#\t0. Возврат в главное меню                         \t#" << std::endl
        << "#################################################################" << std::endl << std::endl;
}

//Функция печатающая меню при работе с графами
void print_graph_menu(void)
{
    std::cout << std::endl << "#################################################################" << std::endl
        << "#\t  1. Добавить компрессорную станцию в вершины      \t#" << std::endl
        << "#\t  2. Удалить компрессорную станцию из вершин       \t#" << std::endl
        << "#\t  3. Посмотреть вершину                            \t#" << std::endl
        << "#\t  4. Посмотреть список вершин                      \t#" << std::endl
        << "#\t  5. Соединить две вершины трубой                  \t#" << std::endl
        << "#\t  6. Убрать соединение между двумя вершинами       \t#" << std::endl
        << "#\t  7. Переориентировать дугу                        \t#" << std::endl
        << "#\t  8. Топологическая сортировка                     \t#" << std::endl
        << "#\t  9. Минимальная дистанция между вершинами         \t#" << std::endl
        << "#\t 10. Помощь                                        \t#" << std::endl
        << "#\t 0. Возврат в главное меню                         \t#" << std::endl
        << "#################################################################" << std::endl << std::endl;
}

//Функция возвращающая число в случае успешного ввода, 
//которое принадлежит заданному интервалу
unsigned int get_number(unsigned int min, unsigned int max)
{
    unsigned int n;
    while ((std::cin >> n).fail() || n < min || n > max)
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "\tНеккоректный ввод. Введите число в диапазоне " << min << "-" << max << ": ";
    }
    return n;
}
#endif