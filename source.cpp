#include <iostream>
#include <fstream>
#include <locale>

#include "utility.h"
#include "set_of_kss.h"
#include "set_of_pipes.h"
#include "graph.h"

void pipes_setup(set_of_pipes);
void ks_setup(set_of_kss);
void graph_setup(void);

int main()
{
    setlocale(LC_ALL, "Russian");
    bool finish = false;
    print_main_menu();
    set_of_pipes pipes;
    set_of_kss kss;
    while (!finish)
    {
        std::cout << "��������� �����: ";
        int msg = get_number(0, 4);
        if (msg == 0)
        {
            finish = true;
            std::cout << "���������� ������" << std::endl;
        }
        else if (msg == 1)
        {
            pipes_setup(pipes);
            std::cout << "�� � ������� ����" << std::endl;
            print_main_menu();
        }
        else if (msg == 2)
        {
            ks_setup(kss);
            std::cout << "�� � ������� ����" << std::endl;
            print_main_menu();
        }
        else if (msg == 3)
        {
            //graph_setup();
            std::cout << "�� � ������� ����" << std::endl;
            print_main_menu();
        }
        else if (msg == 4)
        {
            print_main_menu();
        }
        else
        {
            std::cout << "������� �� ����������. ��������� ����. ������� 4 ��� ��������� ������" << std::endl;
        }
    }
    return 0;
}

void pipes_setup(set_of_pipes pipes)
{
    bool finish = false;
    print_pipe_menu();
    while (!finish)
    {
        std::cout << "��������� �����: ";
        int msg = get_number(0, 12);
        if (msg == 0)
        {
            finish = true;
        }
        else if (msg == 1)
        {
            std::cout << "������� ��������� �����:" << std::endl;
            std::cout << "������� �����: ";
            int length_tmp = get_number(0, INT_MAX);
            std::cout << "������� ������� (500-1420): ";
            int diameter_tmp = get_number(500, 1420);
            pipes.add_pipe(length_tmp, diameter_tmp);
        }
        else if (msg == 2)
        {
            std::cout << "������� ID ��������� �����: ";
            int index = get_number(0, pipes.return_pipe_count() - 1);
            pipes.delete_pipe(index);
        }
        else if (msg == 3)
        {
            std::cout << "������� ID ����� ��� ��������� ������� �������: ";
            int index = get_number(0, pipes.return_pipe_count() - 1);
            pipes.change_repair_status(index);
        }
        else if (msg == 4)
        {
            pipes.print_all_pipes_to_console();
        }
        else if (msg == 5)
        {
            std::cout << "������� ID ����� ��� ������: ";
            int index = get_number(0, pipes.return_pipe_count() - 1);
            pipes.select_pipe(index);
        }
        else if (msg == 6)
        {
            std::cout << "������� ID ����� ��� �������� �� ���������: ";
            int index = get_number(0, pipes.return_pipe_count() - 1);
            pipes.deselect_pipe(index);
        }
        else if (msg == 7)
        {
            pipes.print_selected_pipes_to_console();
        }
        else if (msg == 8)
        {
            std::cout << "�������� �������� ��� ������ (ID - 0 | ����� - 1 | ������� - 2 | ��������� ����������������� - 3): ";
            int parametr_id = get_number(0, 3);
            if (parametr_id == 0)
            {
                std::cout << "������� ID: ";
                int index = get_number(0, pipes.return_pipe_count() - 1);
                pipes.search_pipe(index, index, 0);
            }
            else if (parametr_id == 1)
            {
                std::cout << "������� ����������� ��������: ";
                int left = get_number(0, INT_MAX);
                std::cout << "������� ������������ ��������: ";
                int right = get_number(left, INT_MAX);
                pipes.search_pipe(left, right, 1);
            }
            else if (parametr_id == 2)
            {
                std::cout << "������� ����������� ��������: ";
                int left = get_number(0, INT_MAX);
                std::cout << "������� ������������ ��������: ";
                int right = get_number(left, INT_MAX);
                pipes.search_pipe(left, right, 2);
            }
            else
            { 
                std::cout << "������� ��������� ����� ��� ������ (�������� - 0 | � ������� - 1): ";
                int param = get_number(0, 1);
                pipes.search_pipe(param, param, 3);
            }
        }
        else if (msg == 9)
        {
            std::cout << "�������� �������� ��� ���������� ��������� (����� - 1 | ������� - 2 | ��������� ����������������� - 3): ";
            int parametr_id = get_number(1, 3);
            std::cout << "������� ����� ��������: ";
            int new_value;
            if (parametr_id == 1)
                new_value = get_number(0, INT_MAX);
            else if (parametr_id == 1)
                new_value = get_number(500, 1420);
            else
                new_value = get_number(0, 1);
            pipes.bunch_editing_pipe(new_value, parametr_id);
        }
        else if (msg == 10)
        {
            pipes.save_to_file();
        }
        else if (msg == 11)
        {
            pipes.load_from_file();
        }
        else if (msg == 12)
        {
            print_pipe_menu();
        }
        else
        {
            std::cout << "������� �� ����������. ��������� ����. ������� 11 ��� ��������� ������" << std::endl;
        }
    }
}

void ks_setup(set_of_kss kss)
{
    bool finish = false;
    print_ks_menu();
    while (!finish)
    {
        std::cout << "��������� �����: ";
        int msg = get_number(0, 12);
        if (msg == 0)
        {
            finish = true;
        }
        else if (msg == 1)
        {
            std::cout << "������� ��������� ������������� �������:" << std::endl;
            std::cout << "������� ���: ";
            std::string name_tmp;
            std::cin >> name_tmp;
            std::cout << "������� ���������� �����: ";
            int num_of_shops_tmp = get_number(0, INT_MAX);
            std::cout << "������� ���������� �������� �����: ";
            int num_of_active_shops_tmp = get_number(0, num_of_shops_tmp);
            std::cout << "������� ������������� (0-100): ";
            int efficiency = get_number(0, 100);
            kss.add_ks(name_tmp, num_of_shops_tmp, num_of_active_shops_tmp, efficiency / 100.0);
        }
        else if (msg == 2)
        {
            std::cout << "������� ID ��������� ������������� �������: ";
            int index = get_number(0, kss.return_ks_count() - 1);
            kss.delete_ks(index);
        }
        else if (msg == 3)
        {
            std::cout << "������� ID ����� ��� ��������� �������� ����: ";
            int index = get_number(0, kss.return_ks_count() - 1);
            kss.close_shop(index);
        }
        else if (msg == 4)
        {
            std::cout << "������� ID ����� ��� ��������� �������� ����: ";
            int index = get_number(0, kss.return_ks_count() - 1);
            kss.open_shop(index);
        }
        else if (msg == 5)
        {
            kss.print_all_kss_to_console();
        }
        else if (msg == 6)
        {
            std::cout << "������� ID ������������� ������� ��� ������: ";
            int index = get_number(0, kss.return_ks_count() - 1);
            kss.select_ks(index);
        }
        else if (msg == 7)
        {
            kss.print_selected_kss_to_console();
        }
        else if (msg == 8)
        {
            std::cout << "�������� �������� ��� ������ (ID - 0 | ��� - 1 | ���������� ����� - 2 | ���������� �������� ����� - 3 | ������������� - 4): ";
            int parametr_id = get_number(0, 4);
            if (parametr_id == 0)
            {
                std::cout << "������� ID: ";
                int index = get_number(0, kss.return_ks_count() - 1);
                kss.search_ks(index, index, 0);
            }
            else if (parametr_id == 1)
            {
                std::cout << "������� ��� ��� ������: ";
                std::string param;
                kss.search_ks(param, param, 1);
            }
            else if (parametr_id == 2)
            {
                std::cout << "������� ����������� ��������: ";
                int left = get_number(0, INT_MAX);
                std::cout << "������� ������������ ��������: ";
                int right = get_number(left, INT_MAX);
                kss.search_ks(left, right, 2);
            }
            else
            {
                std::cout << "������� ����������� ��������: ";
                int left = get_number(0, INT_MAX);
                std::cout << "������� ������������ ��������: ";
                int right = get_number(left, INT_MAX);
                kss.search_ks(left, right, 4);
            }
            std::cout << "�������� ������� �������" << std::endl;
        }
        else if (msg == 9)
        {
            std::cout << "�������� �������� ��� ���������� ��������� (��� - 1 | ���������� ����� - 2 | ���������� �������� ����� - 3 | ������������� - 4): ";
            int parametr_id = get_number(1, 4);
            std::cout << "������� ����� ��������: ";
            if (parametr_id == 1)
            {
                std::string new_value;
                std::cin >> new_value;
                kss.bunch_editing_ks(new_value, parametr_id);
            }
            else if (parametr_id == 2 || parametr_id == 3)
            {
                int new_value = get_number(0, INT_MAX);
                kss.bunch_editing_ks(new_value, parametr_id);
            }
            else
            {
                int new_value = get_number(0, 100);
                kss.bunch_editing_ks(new_value / 100.0 , parametr_id);
            }
        }
        else if (msg == 10)
        {
            kss.save_to_file();
        }
        else if (msg == 11)
        {
            kss.load_from_file();
        }
        else if (msg == 12)
        {
            print_ks_menu();
        }
        else
        {
            std::cout << "������� �� ����������. ��������� ����. ������� 11 ��� ��������� ������" << std::endl;
        }
    }
}

void graph_setup(void)
{

}