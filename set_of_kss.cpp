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
    std::cout << "\tID компрессорной  станции: " << kss[index].id << std::endl
        << "\tИмя: " << kss[index].name << std::endl
        << "\tКоличество цехов: " << kss[index].num_of_shops << std::endl
        << "\tКоличество активных цехов: " << kss[index].num_of_active_shops << std::endl
        << "\tЭффективность: " << kss[index].efficiency * 100 << "%" << std::endl;
    std::cout << std::endl;
}

void set_of_kss::print_selected_kss_to_console(void)
{
    if (selected_ks.empty())
        std::cout << "\tНет выбранных компрессорных станций" << std::endl;
    else
    {
        std::cout << "\tВсе выбранные компрессорные станции:" << std::endl;
        for (size_t i = 0; i < selected_ks.size(); i++)
            print_to_console(selected_ks[i]);
    }
}

void set_of_kss::select_ks(int id)
{
    if (std::find(selected_ks.begin(), selected_ks.end(), id) == selected_ks.end())
    {
        selected_ks.push_back(id);
        std::cout << "\tКомпрессорная станция ID " << id << " добавлена к выбранным" << std::endl;
    }
    else
        std::cout << "\tКомпрессорная станция уже была выбрана";
}

void set_of_kss::deselect_ks(int id)
{
    auto pos = std::find(selected_ks.begin(), selected_ks.end(), id);
    if (pos != selected_ks.end())
    {
        *pos = selected_ks.back();
        selected_ks.pop_back();
        std::cout << "\tКомперссорная станция успешно удалена из выбранных" << std::endl;
    }
    else
        std::cout << "\tДанная компрессорная станция не была выбрана" << std::endl;
}

void set_of_kss::close_shop(int index)
{
    if (kss[index].num_of_active_shops > 0)
    {
        kss[index].num_of_active_shops--;
        std::cout << "\tЦех (Компрессорная станция ID " << index << ") успешно закрыт" << std::endl;
    }
    else
        std::cout << "\tВсе цеха закрыты (Открыто " << kss[index].num_of_active_shops << "/" << kss[index].num_of_shops << ")" << std::endl;
}

void set_of_kss::open_shop(int index)
{
    if (kss[index].num_of_active_shops < kss[index].num_of_shops)
    {
        kss[index].num_of_active_shops++;
        std::cout << "\tЦех (Компрессорная станция ID " << index << ") успешно открыт" << std::endl;
    }
    else
        std::cout << "\tВсе цеха открыты (Открыто " << kss[index].num_of_active_shops << "/" << kss[index].num_of_shops << ")" << std::endl;
}

void set_of_kss::print_all_kss_to_console(void)
{
    if (ks_count == 0)
        std::cout << "\tНет добавленных компрессорных станций" << std::endl;
    else
    {
        std::cout << "\tВсе компрессорные станции:" << std::endl << std::endl;
        for (unsigned int i = 0; i < ks_count; i++)
            print_to_console(i);
    }        
}

void set_of_kss::save_to_file(void)
{
    std::ofstream file;
    std::string filename;
    std::cout << "\tВведите имя сохраняемого файла: ";
    std::cin >> filename;
    file.open(filename + ".ks", std::ofstream::out);
    file << ks_count << std::endl;
    for (unsigned int i = 0; i < ks_count; i++)
        file << kss[i].name << ' '
        << kss[i].num_of_shops << ' '
        << kss[i].num_of_active_shops << ' '
        << kss[i].efficiency << std::endl;
    std::cout << "\tДанные успешно сохранены в файл " << filename + ".ks" << std::endl;
    file.close();
}

void set_of_kss::load_from_file(void)
{
    std::ifstream file;
    std::string filename;
    std::cout << "\tВведите имя загружаемого файла: ";
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
        std::cout << "\tЗагружено " << extra_ks_count << " компрессорных станций" << std::endl;
        file.close();
    }
    else
    {
        std::cout << "\tПрограмма не смогла найти указанный файл" << std::endl;
        std::cout << "\tЗапустить поиск другого файла? (Нет - 0 | Да - 1): ";
        int msg = get_number(0, 1);
        if (msg == 1)
            load_from_file();
        else
            std::cout << "\tОшибка в ходе загрузки" << std::endl;
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

