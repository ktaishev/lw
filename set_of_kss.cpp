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
    std::cout << "ID компрессорной  станции: " << kss[index].id << std::endl
        << "Имя: " << kss[index].name << std::endl
        << "Количество цехов: " << kss[index].num_of_shops << std::endl
        << "Количество активных цехов: " << kss[index].num_of_active_shops << std::endl
        << "Эффективность: " << kss[index].efficiency << std::endl;
    std::cout << std::endl;
}

void set_of_kss::print_selected_kss_to_console(void)
{
    if (selected_ks.empty())
    {
        std::cout << "Нет выбранных компрессорных станций" << std::endl;
    }
    else
    {
        for (size_t i = 0; i < selected_ks.size(); i++)
        {
            int index = selected_ks[i];
            std::cout << "ID компрессорной  станции: " << kss[index].id << std::endl
                << "Имя: " << kss[index].name << std::endl
                << "Количество цехов: " << kss[index].num_of_shops << std::endl
                << "Количество активных цехов: " << kss[index].num_of_active_shops << std::endl
                << "Эффективность: " << kss[index].efficiency << std::endl;
            std::cout << std::endl;
        }
    }
}

void set_of_kss::select_ks(int id)
{
    if (std::find(selected_ks.begin(), selected_ks.end(), id) == selected_ks.end())
    {
        selected_ks.push_back(id);
        std::cout << "Компрессорная станция ID " << id << " добавлена к выбранным" << std::endl;
    }
    else
        std::cout << "Компрессорная станция уже была выбрана";
}

void set_of_kss::deselect_ks(int id)
{
    auto pos = std::find(selected_ks.begin(), selected_ks.end(), id);
    *pos = selected_ks.back();
    selected_ks.pop_back();
}

void set_of_kss::close_shop(int index)
{
    if (kss[index].num_of_active_shops > 0)
        kss[index].num_of_active_shops--;
    else
        std::cout << "Все цеха закрыты (Открыто " << kss[index].num_of_active_shops << "/" << kss[index].num_of_shops << ")" << std::endl;
}

void set_of_kss::open_shop(int index)
{
    if (kss[index].num_of_active_shops < kss[index].num_of_shops)
        kss[index].num_of_active_shops++;
    else
        std::cout << "Все цеха открыты (Открыто " << kss[index].num_of_active_shops << "/" << kss[index].num_of_shops << ")" << std::endl;
}

void set_of_kss::print_all_kss_to_console(void)
{
    if (ks_count == 0)
    {
        std::cout << "Нет добавленных компрессорных станций" << std::endl;
    }
    else
    {
        for (unsigned int i = 0; i < ks_count; i++)
            print_to_console(i);
    }
}

void set_of_kss::save_to_file(void)
{
    std::ofstream file;
    std::string filename;
    std::cout << "Введите имя сохран¤емого файла: ";
    std::cin >> filename;
    file.open(filename + "_ks.txt", std::ofstream::out);
    file << ks_count << std::endl;
    for (unsigned int i = 0; i < ks_count; i++)
        file << kss[i].name << ' '
        << kss[i].num_of_shops << ' '
        << kss[i].num_of_active_shops << ' '
        << kss[i].efficiency << std::endl;
    std::cout << "Сохранение успешно завершено" << std::endl;
}

void set_of_kss::load_from_file(void)
{
    std::ifstream file;
    std::string filename;
    std::cout << "Введите имя загружаемого файла: ";
    std::cin >> filename;
    file.open(filename, std::ofstream::in);
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
    std::cout << "Загружено " << extra_ks_count << " компрессорных станций" << std::endl;
}

int set_of_kss::return_ks_count(void)
{
    return ks_count;
}