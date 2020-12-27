#ifndef LW_SET_OF_PIPES_H_
#define LW_SET_OF_PIPES_H_

#include <algorithm>
#include <fstream>
#include <iostream>
#include <vector> 

unsigned int get_number(unsigned int min, unsigned int max);

class set_of_pipes {
private:
    class pipe {
    public:
        unsigned int id;
        double length; //� ������
        double diameter; //� ����������� �� 500 �� 1420
        bool inRepair;
        bool is_edge = false;
        pipe(unsigned int param0, double param1, double param2, bool param3 = false)
        {
            id = param0;
            length = param1;
            diameter = param2;
            inRepair = param3;
        }
        double return_parameter(int parameter_id)
        {
            if (parameter_id == 0)
                return id;
            else if (parameter_id == 1)
                return length;
            else if (parameter_id == 2)
                return diameter;
            else
                return (inRepair ? 1.0 : 0.0);
        }

        template<typename T>
        void change_parameter(T new_value, int parameter_id)
        {
            if (parameter_id == 1)
                length = new_value;
            else if (parameter_id == 2)
                diameter = new_value;
            else
            {
                if (new_value == 0)
                    inRepair = true;
                else
                    inRepair = false;
            }
        }
    };

    std::vector<pipe> pipes; //������, �������� ��� ����� 
    std::vector<int> selected_pipes; //������, �������� ��� ��������� �����
    std::vector<int> searched_pipes; //������, �������� ��� ��������� ����� (������ ���������� ���������� �������)
    unsigned int pipe_count; //������� ����� ����
public:
    void add_pipe(double, double); //���������� �����
    void delete_pipe(int); //�������� �����
    void print_to_console(int); //������ ����� � ������� �� �������
    void print_selected_pipes_to_console(void); //������ ���� ��������� ���� � �������
    void select_pipe(int); //����� ������������ ����� �� �������
    void deselect_pipe(int); //�������� ������ � ������������ ����� �� �������
    void change_repair_status(int); //��������� ��������� "�������" ����� �� �������
    void print_all_pipes_to_console(void); //������ ���� ���� � �������
    void save_to_file(void); //���������� ���� ���� � ����
    void load_from_file(void); //�������� ���� �� �����
    void set_edge(int, bool);
    bool is_edge(int); 
    int return_pipe_count(void); //������� ����� ����

    template<typename T> //����� ����� � ��������� �� ��������� 
    void search_pipe(T, T, int);

    template<typename T> //��������� ���������� ��������� � ���� ��������� ����
    void bunch_editing_pipe(T, int);
};

template<typename T>
inline void set_of_pipes::search_pipe(T left, T right, int parameter_id)
{
    std::vector<int> ids;
    searched_pipes.clear();
    std::for_each(pipes.begin(), pipes.end(), [&](pipe p) mutable {
        if (left <= p.return_parameter(parameter_id) && p.return_parameter(parameter_id) <= right)
            searched_pipes.push_back(p.id); });
    std::cout << "\t������� " << searched_pipes.size() << " ����" << std::endl;
    std::cout << "\t�������� ��������� ����� � ���������? (��� - 0 | �� - 1): ";
 
    int msg = get_number(0, 1);

    if (msg == 1)
    {
        for (auto it = searched_pipes.begin(); it != searched_pipes.end(); it++)
            selected_pipes.push_back(*it);
        std::cout << "\t����� ������� ��������� � ���������" << std::endl;
    }
}

template<typename T> 
inline void set_of_pipes::bunch_editing_pipe(T new_value, int parameter_id)
{
    std::for_each(selected_pipes.begin(), selected_pipes.end(), [&](int index) {pipes[index].change_parameter(new_value, parameter_id); });
    std::cout << "\t��������� ��������� ������� ��������� � ��������� ������" << std::endl;
}

#endif