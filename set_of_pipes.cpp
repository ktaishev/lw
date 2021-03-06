﻿#include "set_of_pipes.h"

void set_of_pipes::add_pipe(double length, double diameter)
{
    pipes.push_back(pipe(pipe_count, length, diameter)); //Добавляем трубу в вектом
    pipe_count++; //Увеличиваем счетчик всех на 1 
}

void set_of_pipes::delete_pipe(int index)
{
    //Если труба была в выбранных, то при ее удалении автоматические деселектим ее
    if (std::find(selected_pipes.begin(), selected_pipes.end(), pipes[index].id) != selected_pipes.end())
        deselect_pipe(pipes[index].id);

    //Чтобы не тратить время удаление (сдвиг элементов стоящих после нашего в векторе), время вплоть до O(n)
    //Ставим на место удаляемого последний элемент, так как отсортированность не важна
    //Последний элемент удаляем, время O(1)
    pipes[index] = pipes.back();  
    pipes[index].id = index;
    pipes.pop_back();
    pipe_count--; //Уменьшаем счетчик всех труб
}

void set_of_pipes::print_to_console(int index)
{
    //Печать трубы по индексу
    std::cout << "\tID трубы: " << pipes[index].id << std::endl
        << "\tДлина трубы: " << pipes[index].length << std::endl
        << "\tДиаметр трубы: " << pipes[index].diameter << std::endl
        << (pipes[index].inRepair ? "\tТруба в ремонте" : "\tТруба работает") << std::endl
        << "\tПроизводительность: " << pipes[index].performance << std::endl;
    std::cout << std::endl;
}

void set_of_pipes::print_selected_pipes_to_console(void)
{
    //Если труб не выбрано, сообщаем пользователю, иначе выводим их на печать
    if (selected_pipes.empty())
        std::cout << "\tНет выбранных труб" << std::endl;
    else
    {
        std::cout << "\tВсе выбранные трубы:" << std::endl;
        for (size_t i = 0; i < selected_pipes.size(); i++)
            print_to_console(selected_pipes[i]); //Последовательно отправляем на печать все трубы из выбранных
    }
}

void set_of_pipes::select_pipe(int id)
{
    //Если труба ранее не была выбрана, выбираем ее
    if (std::find(selected_pipes.begin(), selected_pipes.end(), id) == selected_pipes.end())
    {
        selected_pipes.push_back(id);
        std::cout << "\tТруба ID " << id << " добавлена к выбранным" << std::endl;
    }
    else
        std::cout << "\tТруба уже была выбрана";
}

void set_of_pipes::deselect_pipe(int id)
{
    //Если труба не была выбрана, сообщаем пользователю
    //Иначе добавляем к выбранным
    auto pos = std::find(selected_pipes.begin(), selected_pipes.end(), id);
    if (pos != selected_pipes.end())
    {
        *pos = selected_pipes.back();
        selected_pipes.pop_back();
        std::cout << "\tТруба успешно удалена из выбранных" << std::endl;
    }
    else
        std::cout << "\tДанная труба не была выбрана" << std::endl;
}

void set_of_pipes::change_repair_status(int index)
{
    //Меняем статус ремонта на обратный
    pipes[index].inRepair = !pipes[index].inRepair;
    std::cout << "\tТруба ID " << index << ((pipes[index].inRepair) ? " отправлена на ремонт" : " снова работает") << std::endl;
    if (pipes[index].inRepair)
        pipes[index].performance = 0;
    else
        pipes[index].performance = std::round(10000 * sqrt(pow5(pipes[index].diameter / 1000) / pipes[index].length));
}

void set_of_pipes::print_all_pipes_to_console(void)
{
    //Печатаем последовательно все трубы
    if (pipe_count == 0)
        std::cout << "\tНет добавленных труб" << std::endl;
    else
    {
        std::cout << "\tВсе трубы:" << std::endl << std::endl;
        for (unsigned int i = 0; i < pipe_count; i++)
            print_to_console(i);
    }
}

void set_of_pipes::save_to_file(void)
{
    std::ofstream file;
    std::string filename;
    std::cout << "\tВведите имя сохраняемого файла: ";
    std::cin >> filename;
    file.open(filename + ".pipe", std::ofstream::out);
    if (file.is_open())
    {
        file << pipe_count << std::endl;
        for (unsigned int i = 0; i < pipe_count; i++)
            file << pipes[i].length << ' '
            << pipes[i].diameter << ' '
            << pipes[i].inRepair << std::endl;
        std::cout << "\tДанные успешно сохранены в файл " << filename + ".pipe" << std::endl;
        file.close();
    }
    else
        std::cout << "Ошибка при попытке сохранения: не удалось открыть файл" << std::endl;
}

void set_of_pipes::load_from_file(void)
{
    std::ifstream file;
    std::string filename;
    std::cout << "\tВведите имя загружаемого файла: ";
    std::cin >> filename;
    filename += ".pipe";
    file.open(filename, std::ofstream::in);
    if (file.is_open())
    {
        unsigned int extra_pipe_count;
        file >> extra_pipe_count;
        for (size_t i = pipe_count; i < pipe_count + extra_pipe_count; i++)
        {
            double length_tmp;
            double diameter_tmp;
            bool inRepait_tmp;
            file >> length_tmp >> diameter_tmp >> inRepait_tmp;
            pipes.push_back(pipe(i, length_tmp, diameter_tmp, inRepait_tmp));
        }
        pipe_count += extra_pipe_count;
        std::cout << "\tЗагружено " << extra_pipe_count << " труб (из " << filename << ")" << std::endl;
        file.close();
    }
    else
    {
        std::cout << "\tПрограмма не смогла найти указанный файл (" << filename << ")" << std::endl;
        std::cout << "\tЗапустить поиск другого файла? (Нет - 0 | Да - 1): ";
        int msg = get_number(0, 1);
        if (msg == 1)
            load_from_file();
        else
            std::cout << "\tОшибка в ходе загрузки" << std::endl;
    }
}

void set_of_pipes::set_edge(int index, bool status)
{
    pipes[index].is_edge = status;
}

void set_of_pipes::set_nodes(int index, unsigned int node1, unsigned int node2)
{
    pipes[index].first_node = node1;
    pipes[index].second_node = node2;
}

bool set_of_pipes::is_edge(int index)
{
    return pipes[index].is_edge;
}

std::pair<unsigned int, unsigned int> set_of_pipes::return_nodes(int index)
{
    return std::make_pair(pipes[index].first_node, pipes[index].second_node);
}

unsigned int set_of_pipes::return_pipe_count(void)
{
    return pipe_count;
}

unsigned int set_of_pipes::return_pipe_cost(unsigned int index)
{
    if (pipes[index].inRepair)
        return UINT_MAX;
    else
        return unsigned int(pipes[index].length);
}

double set_of_pipes::return_performance(unsigned int index)
{
    return pipes[index].performance;
}