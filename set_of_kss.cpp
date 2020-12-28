#include "set_of_kss.h"

void set_of_kss::add_ks(std::string name, int num_of_shops, int num_of_active_shops, double efficiency)
{
    kss.push_back(ks(ks_count, name, num_of_shops, num_of_active_shops, efficiency));
    ks_count++;
}

void set_of_kss::delete_ks(int index)
{
    kss[index] = kss.back();
    kss.pop_back();
    ks_count--;
}

void set_of_kss::print_to_console(int index)
{
    std::cout << "\tID �������������  �������: " << kss[index].id << std::endl
        << "\t���: " << kss[index].name << std::endl
        << "\t���������� �����: " << kss[index].num_of_shops << std::endl
        << "\t���������� �������� �����: " << kss[index].num_of_active_shops << std::endl
        << "\t�������������: " << kss[index].efficiency * 100 << "%" << std::endl;
    std::cout << std::endl;
}

void set_of_kss::print_selected_kss_to_console(void)
{
    if (selected_ks.empty())
        std::cout << "\t��� ��������� ������������� �������" << std::endl;
    else
    {
        std::cout << "\t��� ��������� ������������� �������:" << std::endl;
        for (size_t i = 0; i < selected_ks.size(); i++)
            print_to_console(selected_ks[i]);
    }
}

void set_of_kss::select_ks(int id)
{
    if (std::find(selected_ks.begin(), selected_ks.end(), id) == selected_ks.end())
    {
        selected_ks.push_back(id);
        std::cout << "\t������������� ������� ID " << id << " ��������� � ���������" << std::endl;
    }
    else
        std::cout << "\t������������� ������� ��� ���� �������";
}

void set_of_kss::deselect_ks(int id)
{
    auto pos = std::find(selected_ks.begin(), selected_ks.end(), id);
    if (pos != selected_ks.end())
    {
        *pos = selected_ks.back();
        selected_ks.pop_back();
        std::cout << "\t������������� ������� ������� ������� �� ���������" << std::endl;
    }
    else
        std::cout << "\t������ ������������� ������� �� ���� �������" << std::endl;
}

void set_of_kss::close_shop(int index)
{
    if (kss[index].num_of_active_shops > 0)
    {
        kss[index].num_of_active_shops--;
        std::cout << "\t��� (������������� ������� ID " << index << ") ������� ������" << std::endl;
    }
    else
        std::cout << "\t��� ���� ������� (������� " << kss[index].num_of_active_shops << "/" << kss[index].num_of_shops << ")" << std::endl;
}

void set_of_kss::open_shop(int index)
{
    if (kss[index].num_of_active_shops < kss[index].num_of_shops)
    {
        kss[index].num_of_active_shops++;
        std::cout << "\t��� (������������� ������� ID " << index << ") ������� ������" << std::endl;
    }
    else
        std::cout << "\t��� ���� ������� (������� " << kss[index].num_of_active_shops << "/" << kss[index].num_of_shops << ")" << std::endl;
}

void set_of_kss::print_all_kss_to_console(void)
{
    if (ks_count == 0)
        std::cout << "\t��� ����������� ������������� �������" << std::endl;
    else
    {
        std::cout << "\t��� ������������� �������:" << std::endl << std::endl;
        for (unsigned int i = 0; i < ks_count; i++)
            print_to_console(i);
    }        
}

void set_of_kss::save_to_file(void)
{
    std::ofstream file;
    std::string filename;
    std::cout << "\t������� ��� ������������ �����: ";
    std::cin >> filename;
    file.open(filename + ".ks", std::ofstream::out);
    file << ks_count << std::endl;
    for (unsigned int i = 0; i < ks_count; i++)
        file << kss[i].name << ' '
        << kss[i].num_of_shops << ' '
        << kss[i].num_of_active_shops << ' '
        << kss[i].efficiency << std::endl;
    std::cout << "\t������ ������� ��������� � ���� " << filename + ".ks" << std::endl;
    file.close();
}

void set_of_kss::load_from_file(void)
{
    std::ifstream file;
    std::string filename;
    std::cout << "\t������� ��� ������������ �����: ";
    std::cin >> filename;
    file.open(filename, std::ofstream::in);
    if (file.is_open())
    {
        unsigned int extra_ks_count;
        file >> extra_ks_count;
        for (size_t i = ks_count; i < ks_count + extra_ks_count; i++)
        {
            std::string name_tmp;
            int num_of_shops_tmp;
            int num_of_active_shops_tmp;
            double efficiency_tmp;
            file >> name_tmp >> num_of_shops_tmp >> num_of_active_shops_tmp >> efficiency_tmp;
            kss.push_back(ks(i, name_tmp, num_of_shops_tmp, num_of_active_shops_tmp, efficiency_tmp));
        }
        ks_count += extra_ks_count;
        std::cout << "\t��������� " << extra_ks_count << " ������������� �������" << std::endl;
        file.close();
    }
    else
    {
        std::cout << "\t��������� �� ������ ����� ��������� ����" << std::endl;
        std::cout << "\t��������� ����� ������� �����? (��� - 0 | �� - 1): ";
        int msg = get_number(0, 1);
        if (msg == 1)
            load_from_file();
        else
            std::cout << "\t������ � ���� ��������" << std::endl;
    }
}

unsigned int set_of_kss::return_ks_count(void)
{
    return ks_count;
}

bool set_of_kss::is_node(int index)
{
    return kss[index].is_node;
}

void set_of_kss::set_node(int index, bool status)
{
    kss[index].is_node = status;
}

