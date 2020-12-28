#ifndef LW_GRAPH_H_
#define LW_GRAPH_H_

#include <iostream>
#include <vector> 

class graph {
    unsigned int node_count = 0; //Число вершин 
    std::vector<std::vector<int>> matrix; //Матрица смежности
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
    unsigned int return_node_count(void); //Возврат числа вершин
};

#endif 