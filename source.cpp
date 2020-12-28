#include <iostream>
#include <fstream>
#include <locale>
#include <set>

#include "utility.h"
#include "set_of_kss.h"
#include "set_of_pipes.h"
#include "graph.h"

void pipes_setup(set_of_pipes&);
void ks_setup(set_of_kss&);
void graph_setup(set_of_pipes&, set_of_kss&, graph&);

int main()
{
    set_of_pipes pipes;
    set_of_kss kss;
    graph g;

    setlocale(LC_ALL, "Russian");
    std::cout << "������������ ������ �� 1 ������� 2 �����" << std::endl;
    bool finish = false;
    print_main_menu();
    while (!finish)
    {
        std::cout << "\t��������� �����: ";
        int msg = get_number(0, 4);
        if (msg == 0)
        {
            finish = true;
            std::cout << "\t���������� ������" << std::endl;
        }
        else if (msg == 1)
        {
            pipes_setup(pipes);
            std::cout << "\t�� � ������� ����" << std::endl;
            print_main_menu();
        }
        else if (msg == 2)
        {
            ks_setup(kss);
            std::cout << "\t�� � ������� ����" << std::endl;
            print_main_menu();
        }
        else if (msg == 3)
        {
            graph_setup(pipes, kss, g);
            std::cout << "\t�� � ������� ����" << std::endl;
            print_main_menu();
        }
        else if (msg == 4)
        {
            print_main_menu();
        }
        else
        {
            std::cout << "\t������� �� ����������. ��������� ����. ������� 4 ��� ��������� ������" << std::endl;
        }
    }
    return 0;
}

void pipes_setup(set_of_pipes& pipes)
{
    bool finish = false;
    print_pipe_menu();
    while (!finish)
    {
        std::cout << "\t��������� �����: ";
        int msg = get_number(0, 12);
        if (msg == 0)
        {
            finish = true;
        }
        else if (msg == 1)
        {
            std::cout << "\t������� ��������� �����:" << std::endl;
            std::cout << "\t������� �����: ";
            int length_tmp = get_number(0, INT_MAX);
            std::cout << "\t������� ������� (500-1420): ";
            int diameter_tmp = get_number(500, 1420);
            pipes.add_pipe(length_tmp, diameter_tmp);
            std::cout << "\t����� ������� ���������" << std::endl;
            PRINT_HASH_LINE;
        }
        else if (msg == 2)
        {
            std::cout << "\t������� ID ��������� �����: ";
            int index = get_number(0, pipes.return_pipe_count() - 1);
            pipes.delete_pipe(index);
            std::cout << "\t����� ID " << index << " ������� �������" << std::endl;
            PRINT_HASH_LINE;
        }
        else if (msg == 3)
        {
            std::cout << "\t������� ID ����� ��� ��������� ������� �������: ";
            int index = get_number(0, pipes.return_pipe_count() - 1);
            pipes.change_repair_status(index);
            PRINT_HASH_LINE;
        }
        else if (msg == 4)
        {
            pipes.print_all_pipes_to_console();
            PRINT_HASH_LINE;
        }
        else if (msg == 5)
        {
            std::cout << "\t������� ID ����� ��� ������: ";
            int index = get_number(0, pipes.return_pipe_count() - 1);
            pipes.select_pipe(index);
            PRINT_HASH_LINE;
        }
        else if (msg == 6)
        {
            std::cout << "\t������� ID ����� ��� �������� �� ���������: ";
            int index = get_number(0, pipes.return_pipe_count() - 1);
            pipes.deselect_pipe(index);
            PRINT_HASH_LINE;
        }
        else if (msg == 7)
        {
            pipes.print_selected_pipes_to_console();
            PRINT_HASH_LINE;
        }
        else if (msg == 8)
        {
            std::cout << "\t�������� �������� ��� ������ (ID - 0 | ����� - 1 | ������� - 2 | ��������� ����������������� - 3): ";
            int parametr_id = get_number(0, 3);
            if (parametr_id == 0)
            {
                std::cout << "\t������� ID: ";
                int index = get_number(0, pipes.return_pipe_count() - 1);
                pipes.search_pipe(index, index, 0);
            }
            else if (parametr_id == 1)
            {
                std::cout << "\t������� ����������� ��������: ";
                int left = get_number(0, INT_MAX);
                std::cout << "\t������� ������������ ��������: ";
                int right = get_number(left, INT_MAX);
                pipes.search_pipe(left, right, 1);
            }
            else if (parametr_id == 2)
            {
                std::cout << "\t������� ����������� ��������: ";
                int left = get_number(0, INT_MAX);
                std::cout << "\t������� ������������ ��������: ";
                int right = get_number(left, INT_MAX);
                pipes.search_pipe(left, right, 2);
            }
            else
            { 
                std::cout << "\t������� ��������� ����� ��� ������ (�������� - 0 | � ������� - 1): ";
                int param = get_number(0, 1);
                pipes.search_pipe(param, param, 3);
            }
            PRINT_HASH_LINE;
        }
        else if (msg == 9)
        {
            std::cout << "\t�������� �������� ��� ���������� ��������� (����� - 1 | ������� - 2 | ��������� ����������������� - 3): ";
            int parametr_id = get_number(1, 3);
            std::cout << "\t������� ����� ��������: ";
            int new_value;
            if (parametr_id == 1)
                new_value = get_number(0, INT_MAX);
            else if (parametr_id == 1)
                new_value = get_number(500, 1420);
            else
                new_value = get_number(0, 1);
            pipes.bunch_editing_pipe(new_value, parametr_id);
            PRINT_HASH_LINE;
        }
        else if (msg == 10)
        {
            pipes.save_to_file();
            PRINT_HASH_LINE;
        }
        else if (msg == 11)
        {
            pipes.load_from_file();
            PRINT_HASH_LINE;
        }
        else if (msg == 12)
        {
            print_pipe_menu();
        }
        else
        {
            std::cout << "\t������� �� ����������. ��������� ����. ������� 11 ��� ��������� ������" << std::endl;
            PRINT_HASH_LINE;
        }
    }
}

void ks_setup(set_of_kss& kss)
{
    bool finish = false;
    print_ks_menu();
    while (!finish)
    {
        std::cout << "\t��������� �����: ";
        int msg = get_number(0, 13);
        if (msg == 0)
        {
            finish = true;
        }
        else if (msg == 1)
        {
            std::cout << "\t������� ��������� ������������� �������:" << std::endl;
            std::cout << "\t������� ���: ";
            std::string name_tmp;
            std::cin >> name_tmp;
            std::cout << "\t������� ���������� �����: ";
            int num_of_shops_tmp = get_number(0, INT_MAX);
            std::cout << "\t������� ���������� �������� �����: ";
            int num_of_active_shops_tmp = get_number(0, num_of_shops_tmp);
            std::cout << "\t������� ������������� (0-100): ";
            int efficiency = get_number(0, 100);
            kss.add_ks(name_tmp, num_of_shops_tmp, num_of_active_shops_tmp, efficiency / 100.0);
            std::cout << "\t������������� ������� ������� ���������" << std::endl;
            PRINT_HASH_LINE;
        }
        else if (msg == 2)
        {
            std::cout << "\t������� ID ��������� ������������� �������: ";
            int index = get_number(0, kss.return_ks_count() - 1);
            kss.delete_ks(index);
            std::cout << "\t������������� ������� ID " << index << " ������� �������" << std::endl;
            PRINT_HASH_LINE;
        }
        else if (msg == 3)
        {
            std::cout << "\t������� ID ����� ��� ��������� �������� ����: ";
            int index = get_number(0, kss.return_ks_count() - 1);
            kss.close_shop(index);
            PRINT_HASH_LINE;
        }
        else if (msg == 4)
        {
            std::cout << "\t������� ID ����� ��� ��������� �������� ����: ";
            int index = get_number(0, kss.return_ks_count() - 1);
            kss.open_shop(index);
            PRINT_HASH_LINE;
        }
        else if (msg == 5)
        {
            kss.print_all_kss_to_console();
            PRINT_HASH_LINE;
        }
        else if (msg == 6)
        {
            std::cout << "\t������� ID ������������� ������� ��� ������: ";
            int index = get_number(0, kss.return_ks_count() - 1);
            kss.select_ks(index);
            PRINT_HASH_LINE;
        }
        else if (msg == 7)
        {
            std::cout << "\t������� ID ������������� ������� ��� �������� �� ���������: ";
            int index = get_number(0, kss.return_ks_count() - 1);
            kss.deselect_ks(index);
            PRINT_HASH_LINE;
        }
        else if (msg == 8)
        {
            kss.print_selected_kss_to_console();
            PRINT_HASH_LINE;
        }
        else if (msg == 9)
        {
            std::cout << "\t�������� �������� ��� ������ (ID - 0 | ��� - 1 | ���������� ����� - 2 | ���������� �������� ����� - 3 | ������������� - 4): ";
            int parametr_id = get_number(0, 4);
            if (parametr_id == 0)
            {
                std::cout << "\t������� ID: ";
                int index = get_number(0, kss.return_ks_count() - 1);
                kss.search_ks(index, index, 0);
            }
            else if (parametr_id == 1)
            {
                std::cout << "\t������� ��� ��� ������: ";
                std::string param;
                kss.search_ks(param, param, 1);
            }
            else if (parametr_id == 2)
            {
                std::cout << "\t������� ����������� ��������: ";
                int left = get_number(0, INT_MAX);
                std::cout << "\t������� ������������ ��������: ";
                int right = get_number(left, INT_MAX);
                kss.search_ks(left, right, 2);
            }
            else
            {
                std::cout << "\t������� ����������� ��������: ";
                int left = get_number(0, INT_MAX);
                std::cout << "\t������� ������������ ��������: ";
                int right = get_number(left, INT_MAX);
                kss.search_ks(left, right, 4);
            }
            std::cout << "\t�������� ������� �������" << std::endl;
            PRINT_HASH_LINE;
        }
        else if (msg == 10)
        {
            std::cout << "\t�������� �������� ��� ���������� ��������� (��� - 1 | ���������� ����� - 2 | ���������� �������� ����� - 3 | ������������� - 4): ";
            int parametr_id = get_number(1, 4);
            std::cout << "\t������� ����� ��������: ";
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
            PRINT_HASH_LINE;
        }
        else if (msg == 11)
        {
            kss.save_to_file();
            PRINT_HASH_LINE;
        }
        else if (msg == 12)
        {
            kss.load_from_file();
            PRINT_HASH_LINE;
        }
        else if (msg == 13)
        {
            print_ks_menu();
        }
        else
        {
            std::cout << "\t������� �� ����������. ��������� ����. ������� 11 ��� ��������� ������" << std::endl;
            PRINT_HASH_LINE;
        }
    }
}

void graph_setup(set_of_pipes& pipes, set_of_kss& kss, graph& g)
{
    unsigned int free_nodes_count = kss.return_ks_count();
    unsigned int free_edges_count = pipes.return_pipe_count();

    bool finish = false;
    print_graph_menu();
    g.init(kss.return_ks_count());
    while (!finish)
    {
        std::cout << "\t��������� �����: ";
        int msg = get_number(0, 9);
        if (msg == 0)
        {
            finish = true;
        }
        else if (msg == 1)
        {
            std::cout << "\t������� ID ������������� ������� ��� ���������� � ����: ";
            int index = get_number(0, kss.return_ks_count() - 1);
            if (kss.is_node(index) == true)
                std::cout << "\t������������� ������� ��� �������� ��������" << std::endl;
            else
            {
                g.add_node(index);
                kss.set_node(index, true);
            }
            PRINT_HASH_LINE;
        }
        else if (msg == 2)
        {
            std::cout << "\t������� ID ������������� ������� ��� �������� �� �����: ";
            int index = get_number(0, g.return_node_count() - 1);
            if (kss.is_node(index) == false)
                std::cout << "\t������������� ������� �� �������� ��������" << std::endl;
            else
            {
                auto edges_to_free = g.delete_node(index);
                for (auto it = edges_to_free.begin(); it != edges_to_free.end(); it++)
                    pipes.set_edge(*it, false);
                kss.set_node(index, false);
            }
            PRINT_HASH_LINE;
        }
        else if (msg == 3)
        {
            std::cout << "\t������� ID ������������� ������� ��� ���������: ";
            int index = get_number(0, g.return_node_count() - 1);
            if (kss.is_node(index) == false)
                std::cout << "\t������������� ������� �� �������� ��������" << std::endl;
            else
                g.print_node(index);
            PRINT_HASH_LINE;
        }
        else if (msg == 4)
        {
            //�������� ���������� � ���� ��������, ���� �� ������������������
            //�������� ����� ������ ������ ������ print_node ��� ���� ��, ������� �������
            std::cout << "\t��� �������:" << std::endl;
            g.print_nodes();
            PRINT_HASH_LINE;
        }
        else if (msg == 5)
        {
            //���� ��� ������ ������ vector range error, ��������� ���� � 0 �����
            //� ���������� ��������� ������ �� �������
            std::cout << "\t������� ��������� ������� ��� ����������: ";
            unsigned int node1 = get_number(0, g.return_node_count() - 1);
            std::cout << "\t������� �������� ������� ��� ����������: ";
            unsigned int node2 = get_number(0, g.return_node_count() - 1);
            if (kss.is_node(node1) == false)
                std::cout << "\t������������ ������� ID " << node1 << " �� �������� ��������" << std::endl;
            else if (kss.is_node(node2) == false)
                std::cout << "\t������������ ������� ID " << node2 << " �� �������� ��������" << std::endl;
            else if (node1 == node2)
                std::cout << "\t���������� ��������� ������� � ����� �����";
            else
            {
                std::cout << "\t������� ����������� �����: ";
                unsigned int pipe_id = get_number(0, pipes.return_pipe_count() - 1);
                if (pipes.is_edge(pipe_id) == true)
                    std::cout << "\t����� ��� ������������� � ���������, ���������� � ������� ��� �� ��������" << std::endl;
                else
                {
                    g.connect_two_nodes(node1, node2, pipe_id);
                    pipes.set_edge(pipe_id, true);
                }
            }
            PRINT_HASH_LINE;
        }
        else if (msg == 6)
        {
            std::cout << "\t������� ��������� ������� ��� ������������: ";
            unsigned int node1 = get_number(0, g.return_node_count() - 1);
            std::cout << "\t������� �������� ������� ��� ������������: ";
            unsigned int node2 = get_number(0, g.return_node_count() - 1);
            int pipe_id = g.disconnect_two_nodes(node1, node2);
            if (pipe_id != -1)
                pipes.set_edge(pipe_id, false);
            PRINT_HASH_LINE;
        }
        else if (msg == 7)
        {
            std::cout << "\t������� �������, ���� ����� �������� ����� ����������: " << std::endl;
            std::cout << "\t������� ��������� �������: ";
            unsigned int node1 = get_number(0, g.return_node_count() - 1);
            std::cout << "\t������� �������� �������: ";
            unsigned int node2 = get_number(0, g.return_node_count() - 1);
            if (node1 == node2)
                std::cout << "\t������� ��� �������� �������";
            else
                g.redirect_arc(node1, node2);
            PRINT_HASH_LINE;
        }
        else if (msg == 8)
        {
            g.top_sort();
            std::cout << "\t�������������� ���������� ���������" << std::endl;
            PRINT_HASH_LINE;
        }
        else if (msg == 9)
        {
            print_graph_menu();
        }
        else
        {
            std::cout << "\t������� �� ����������. ��������� ����. ������� 4 ��� ��������� ������" << std::endl;
        }
    }
}