#ifndef LW_UTILITY_H_
#define LW_UTILITY_H_

#include <iostream>

#define PRINT_HASH_LINE std::cout << std::endl << "#################################################################" << std::endl << std::endl;

//������� ���������� �������� ����
void print_main_menu(void)
{
    std::cout << std::endl << "#################################################################" << std::endl
        << "#\t 1. ������ � �������                              \t#" << std::endl
        << "#\t 2. ������ � �������������� ���������             \t#" << std::endl
        << "#\t 3. ������ � ����������                           \t#" << std::endl
        << "#\t 4. ������                                        \t#" << std::endl
        << "#\t 0. �����                                         \t#" << std::endl
        << "#################################################################" << std::endl << std::endl;
}

//������� ���������� ���� ��� ������ � �������
void print_pipe_menu(void)
{
    std::cout << std::endl << "#################################################################" << std::endl
        << "#\t 1. �������� �����                                \t#" << std::endl
        << "#\t 2. ������� �����                                 \t#" << std::endl
        << "#\t 3. �������� ��������� ����� (��������/�� �������)\t#" << std::endl
        << "#\t 4. ���������� ��� �����                          \t#" << std::endl
        << "#\t 5. ������� �����                                 \t#" << std::endl
        << "#\t 6. ������� ����� �� ���������                    \t#" << std::endl
        << "#\t 7. ���������� ��������� �����                    \t#" << std::endl
        << "#\t 8. ����� �� ���������                            \t#" << std::endl
        << "#\t 9. ��������� ��������� ����                      \t#" << std::endl
        << "#\t10. ���������� � ����                             \t#" << std::endl
        << "#\t11. �������� �� �����                             \t#" << std::endl
        << "#\t12. ������                                        \t#" << std::endl
        << "#\t0. ������� � ������� ����                         \t#" << std::endl
        << "#################################################################" << std::endl << std::endl;
}

//������� ���������� ���� ��� ������ � �������������� ���������
void print_ks_menu(void)
{
    std::cout << std::endl << "#################################################################" << std::endl
        << "#\t 1. �������� ������������� �������                \t#" << std::endl
        << "#\t 2. ������� ������������� �������                 \t#" << std::endl
        << "#\t 3. ������� ���                                   \t#" << std::endl
        << "#\t 4. ������� ���                                   \t#" << std::endl
        << "#\t 5. ���������� ��� ������������� �������          \t#" << std::endl
        << "#\t 6. ������� ������������� �������                 \t#" << std::endl
        << "#\t 7. ������� ������������� ������� �� ���������    \t#" << std::endl
        << "#\t 8. ���������� ��������� ������������� �������    \t#" << std::endl
        << "#\t 9. ����� �� ���������                            \t#" << std::endl
        << "#\t10. ��������� ��������� ������������� �������     \t#" << std::endl
        << "#\t11. ���������� � ����                             \t#" << std::endl
        << "#\t12. �������� �� �����                             \t#" << std::endl
        << "#\t13. ������                                        \t#" << std::endl
        << "#\t0. ������� � ������� ����                         \t#" << std::endl
        << "#################################################################" << std::endl << std::endl;
}

//������� ���������� ���� ��� ������ � �������
void print_graph_menu(void)
{
    std::cout << std::endl << "#################################################################" << std::endl
        << "#\t  1. �������� ������������� ������� � �������      \t#" << std::endl
        << "#\t  2. ������� ������������� ������� �� ������       \t#" << std::endl
        << "#\t  3. ���������� �������                            \t#" << std::endl
        << "#\t  4. ���������� ������ ������                      \t#" << std::endl
        << "#\t  5. ��������� ��� ������� ������                  \t#" << std::endl
        << "#\t  6. ������ ���������� ����� ����� ���������       \t#" << std::endl
        << "#\t  7. ����������������� ����                        \t#" << std::endl
        << "#\t  8. �������������� ����������                     \t#" << std::endl
        << "#\t  9. ��������� ����                                \t#" << std::endl
        << "#\t 10. ��������� ����                                \t#" << std::endl
        << "#\t 11. ������                                        \t#" << std::endl
        << "#\t 0. ������� � ������� ����                         \t#" << std::endl
        << "#################################################################" << std::endl << std::endl;
}

//������� ������������ ����� � ������ ��������� �����, 
//������� ����������� ��������� ���������
unsigned int get_number(unsigned int min, unsigned int max)
{
    unsigned int n;
    while ((std::cin >> n).fail() || n < min || n > max)
    {
        std::cin.clear();
        std::cin.ignore(32767, '\n');
        std::cout << "\t������������ ����. ������� ����� � ��������� " << min << "-" << max << ": ";
    }
    return n;
}
#endif
