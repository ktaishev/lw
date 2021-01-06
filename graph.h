#ifndef LW_GRAPH_H_
#define LW_GRAPH_H_

#include <iostream>
#include <vector> 
#include <queue>
#include <fstream>
#include <tuple>

#include "set_of_pipes.h"

template<typename T>
T get_number(T, T);

class graph {
    unsigned int node_count = 0; //Число вершин 
    unsigned int edge_count = 0; //Число ребер
    std::vector<std::vector<int>> matrix; //Матрица смежности
    void swap_nodes(std::queue<unsigned int>); //Обмен двух вершин местами
public:
    void init(unsigned int); //Инициализация графа
    void add_node(unsigned int); //Добавление вершины в граф
    std::vector<unsigned int> delete_node(unsigned int); //Удаление вершины из графа 
    void print_node(unsigned int); //Печать информации о конкретной вершине
    void print_nodes(void); //Печать информации о всех вершинах
    void print_matrix(void); //Временная функция, печатающая матрицу смежности
    void connect_two_nodes(unsigned int, unsigned int, unsigned int); //Соединение двух вершин трубой
    int disconnect_two_nodes(unsigned int, unsigned int); //Удаление дуги между двумя вершинами
    void redirect_arc(unsigned int, unsigned int); //Перенаправление дуги между двумя вершинами
    void save_to_file(void); //Сохранение графа в файл
    void load_from_file(void); //Загрузка графа из файла
    void top_sort(void); //Топологическая сортировка
    double max_flow(unsigned int start_node, unsigned int end_node, set_of_pipes& pipes); //Максимальный поток в сети
    std::tuple<unsigned int, std::vector<unsigned int>> minimal_distance(unsigned int, unsigned int, set_of_pipes&); //Кратчайший путь между двумя вершинами
    int return_node_count(void); //Возврат числа вершин
    unsigned int return_edge_count(void); //Возврат числа ребер
};

#endif 