#ifndef LW_GRAPH_H_
#define LW_GRAPH_H_

#include <iostream>
#include <vector> 
#include <queue>
#include <fstream>

unsigned int get_number(unsigned int min, unsigned int max);

class graph {
    unsigned int node_count = 0; //����� ������ 
    std::vector<std::vector<int>> matrix; //������� ���������
    void swap_nodes(std::queue<unsigned int>); //����� ���� ������ �������
public:
    void init(unsigned int); //������������� �����
    void add_node(unsigned int); //���������� ������� � ����
    std::vector<unsigned int> delete_node(unsigned int); //�������� ������� �� ����� 
    void print_node(unsigned int); //������ ���������� � ���������� �������
    void print_nodes(void); //������ ���������� � ���� ��������
    void print_matrix(void); //��������� �������, ���������� ������� ���������
    void connect_two_nodes(unsigned int, unsigned int, unsigned int); //���������� ���� ������ ������
    int disconnect_two_nodes(unsigned int, unsigned int); //�������� ���� ����� ����� ���������
    void redirect_arc(unsigned int, unsigned int); //��������������� ���� ����� ����� ���������
    void save_to_file(void); //���������� ����� � ����
    void load_from_file(void); //�������� ����� �� �����
    void top_sort(void); //�������������� ����������
    unsigned int return_node_count(void); //������� ����� ������
};

#endif 