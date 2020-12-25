#ifndef LW_UTILITY_H_
#define LW_UTILITY_H_

#include <iostream>

//������� ���������� �������� ����
void print_main_menu(void)
{
    std::cout << "1. ������ � �������" << std::endl
        << "2. ������ � �������������� ���������" << std::endl
        << "3. ������ � ����������" << std::endl
        << "4. ������" << std::endl
        << "0. �����" << std::endl;
}

//������� ���������� ���� ��� ������ � �������
void print_pipe_menu(void)
{
    std::cout << "1. �������� �����" << std::endl
        << "2. ������� �����" << std::endl
        << "3. �������� ��������� ����� (��������/�� �������)" << std::endl
        << "4. ���������� ��� �����" << std::endl
        << "5. ������� �����" << std::endl
        << "6. ������� ����� �� ���������" << std::endl
        << "7. ���������� ��������� �����" << std::endl
        << "8. ����� �� ���������" << std::endl
        << "9. ��������� ��������� ����" << std::endl
        << "19. ���������� � ����" << std::endl
        << "11. �������� �� �����" << std::endl
        << "12. ������" << std::endl
        << "0. ������� � ������� ����" << std::endl;
}

//������� ���������� ���� ��� ������ � �������������� ���������
void print_ks_menu(void)
{
    std::cout << "1. �������� ������������� �������" << std::endl
        << "2. ������� ������������� �������" << std::endl
        << "3. ������� ���" << std::endl
        << "4. ������� ���" << std::endl
        << "5. ���������� ��� ������������� �������" << std::endl
        << "6. ������� ������������� �������" << std::endl
        << "7. ���������� ��������� ������������� �������" << std::endl
        << "8. ����� �� ���������" << std::endl
        << "9. ��������� ��������� ������������� �������" << std::endl
        << "10. ���������� � ����" << std::endl
        << "11. �������� �� �����" << std::endl
        << "12. ������" << std::endl
        << "0. ������� � ������� ����" << std::endl;
}

//������� ���������� ���� ��� ������ � �������
void print_graph_menu(void)
{
    void();
}

//������� ������������ ����� � ������ ��������� �����, 
//������� ����������� ��������� ���������
int get_number(int min, int max)
{
    int n;
    while ((std::cin >> n).fail() || n < min || n > max)
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "������������ ����. ������� ����� � ��������� " << min << "-" << max << ": ";
    }
    return n;
}
#endif