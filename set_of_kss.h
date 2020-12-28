#ifndef LW_SET_OF_KS_H_
#define LW_SET_OF_KS_H_

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

unsigned int get_number(unsigned int min, unsigned int max);

class set_of_kss {
private:
    class ks {
    public:
        unsigned int id; 
        std::string name;
        int num_of_shops; //���������� �����
        int num_of_active_shops; //���������� �������� �����
        double efficiency; //����� � ��������� 0-1, ��������� ����� ������� ����� �� ����
        bool is_node = false; //��� ������ � ����������, �������� �������� �� �� ��������
        ks(unsigned int param0, std::string param1, int param2, int param3, double param4)
        {
            id = param0;
            name = param1;
            num_of_shops = param2;
            num_of_active_shops = param3;
            efficiency = param4;
        }

        /*
        template<typename T>
        T return_parameter(int parameter_id)
        {
            if (parameter_id == 1)
                return name;
            else if (parameter_id == 2)
                return num_of_shops;
            else if (parameter_id == 3)
                return num_of_active_shops;
            else
                return efficiency;
        }

        template<typename T>
        void change_parameter(T new_value, int parameter_id)
        {
            if (parameter_id == 1)
                name = new_value;
            else if (parameter_id == 2)
                num_of_shops = new_value;
            else if (parameter_id == 2)
                num_of_active_shops = new_value;
            else
                efficiency = new_value;
        }
        */
    };

    std::vector<ks> kss; //������, �������� ��� ������������� ������� 
    std::vector<int> selected_ks; //������, �������� ��� ��������� ������������� ������� 
    std::vector<int> searched_ks; //������, �������� ��� ��������� ������������� ������� (������ ���������� ���������� �������)
    unsigned int ks_count; //������� ����� ������������� ������� 
public:
    void add_ks(std::string, int, int, double); //���������� ������������� �������
    void delete_ks(int); //�������� ������������� �������
    void print_to_console(int); //������ ������������� ������� � ������� �� �������
    void print_selected_kss_to_console(void); //������ ���� ��������� ������������� ������� � �������
    void select_ks(int); //����� ������������ ������������� ������� �� �������
    void deselect_ks(int); //�������� ������ � ������������ ������������� ������� �� �������
    void close_shop(int); //�������� ���� ������������� ������� �� �������
    void open_shop(int); //�������� ���� ������������� ������� �� �������
    void print_all_kss_to_console(void); //������ ���� ������������� ������� � �������
    void save_to_file(void); //���������� ���� ������������� ������� � ����
    void load_from_file(void); //�������� ������������� ������� �� �����
    void set_node(int, bool); //��������� �������� �� �� �������� 
    unsigned int return_ks_count(void); //������� ����� ������������� �������
    bool is_node(int); //�������� �������� �� �� ��������

    template<typename T> //����� ������������� ������� � ��������� �� ��������� 
    void search_ks(T, T, int);

    template<typename T> //��������� ���������� ��������� � ���� ��������� ������������� ������� 
    void bunch_editing_ks(T, int);
};

template<typename T> 
inline void set_of_kss::search_ks(T left, T right, int parameter_id)
{
    std::vector<int> ids;
    searched_ks.clear();
    /*
    for_each(kss.begin(), kss.end(), 
        [&](ks p) mutable {
            if (left <= p.return_parameter(parameter_id) && p.return_parameter(parameter_id) <= right)
                searched_ks.push_back(p.id);
        });
        */

    std::cout << "�������� ��������� ������������� ������� � ���������? (��� - 0 | �� - 1): ";
    
    int msg = get_number(0, 1);

    if (msg == 1)
        for (auto it = searched_ks.begin(); it != searched_ks.end(); it++)
            selected_ks.push_back(*it);
}

template<typename T>
inline void set_of_kss::bunch_editing_ks(T new_value, int parameter_id)
{
    //for_each(selected_ks.begin(), selected_ks.end(), [&](int index) {kss[index].change_parameter(new_value, parameter_id); });
}

#endif