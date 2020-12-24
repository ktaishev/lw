#include "set_of_pipes.h"

void set_of_pipes::add_pipe(double length, double diameter)
{
    pipes.push_back(pipe(pipe_count, length, diameter));
    pipe_count++;
}

void set_of_pipes::delete_pipe(int index)
{
    pipes[index] = pipes.back();
    pipes.pop_back();
    pipe_count--;
}

void set_of_pipes::print_to_console(int index)
{
    std::cout << "ID трубы: " << pipes[index].id << std::endl
        << "Длина трубы: " << pipes[index].length << std::endl
        << "Диаметр трубы: " << pipes[index].diameter << std::endl
        << (pipes[index].inRepair ? "Труба в ремонте" : "Труба работает") << std::endl;
    std::cout << std::endl;
}

void set_of_pipes::print_selected_pipes_to_console(void)
{
    if (selected_pipes.empty())
    {
        std::cout << "Нет выбранных труб" << std::endl;
    }
    else
    {
        for (size_t i = 0; i < selected_pipes.size(); i++)
        {
            int index = selected_pipes[i];
            std::cout << "ID трубы: " << pipes[index].id << std::endl
                << "Длина трубы: " << pipes[index].length << std::endl
                << "Диаметр трубы: " << pipes[index].diameter << std::endl
                << (pipes[index].inRepair ? "Труба в ремонте" : "Труба работает") << std::endl;
            std::cout << std::endl;
        }
    }
}

void set_of_pipes::select_pipe(int id)
{
    if (std::find(selected_pipes.begin(), selected_pipes.end(), id) == selected_pipes.end())
    {
        selected_pipes.push_back(id);
        std::cout << "Труба ID " << id << " добавлена к выбранным" << std::endl;
    }
    else
        std::cout << "Труба уже была выбрана";
}

void set_of_pipes::deselect_pipe(int id)
{
    auto pos = std::find(selected_pipes.begin(), selected_pipes.end(), id);
    *pos = selected_pipes.back();
    selected_pipes.pop_back();
}

void set_of_pipes::change_repair_status(int index)
{
    pipes[index].inRepair = !pipes[index].inRepair;
}

void set_of_pipes::print_all_pipes_to_console(void)
{
    if (pipe_count == 0)
    {
        std::cout << "Нет добавленных труб" << std::endl;
    }
    else
    {
        for (unsigned int i = 0; i < pipe_count; i++)
            print_to_console(i);
    }
}

void set_of_pipes::save_to_file(void)
{
    std::ofstream file;
    std::string filename;
    std::cout << "Введите имя сохран¤емого файла: ";
    std::cin >> filename;
    file.open(filename + "_pipe.txt", std::ofstream::out);
    file << pipe_count << std::endl;
    for (unsigned int i = 0; i < pipe_count; i++)
        file << pipes[i].length << ' '
        << pipes[i].diameter << ' '
        << pipes[i].inRepair << std::endl;
    std::cout << "Сохранение успешно завершено" << std::endl;
}

void set_of_pipes::load_from_file(void)
{
    std::ifstream file;
    std::string filename;
    std::cout << "Введите имя загружаемого файла: ";
    std::cin >> filename;
    file.open(filename, std::ofstream::in);
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
    std::cout << "Загружено " << extra_pipe_count << " труб" << std::endl;
}

int set_of_pipes::return_pipe_count(void)
{
    return pipe_count;
}