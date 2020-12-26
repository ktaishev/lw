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
    set_of_pipes pipes;
    set_of_kss kss;

    setlocale(LC_ALL, "Russian");
    std::cout << "Лабораторная работа за 1 семестр 2 курса" << std::endl;
    bool finish = false;
    print_main_menu();
    while (!finish)
    {
        std::cout << "\tВыбранный пункт: ";
        int msg = get_number(0, 4);
        if (msg == 0)
        {
            finish = true;
            std::cout << "\tЗавершение работы" << std::endl;
        }
        else if (msg == 1)
        {
            pipes_setup(pipes);
            std::cout << "\tВы в главном меню" << std::endl;
            print_main_menu();
        }
        else if (msg == 2)
        {
            ks_setup(kss);
            std::cout << "\tВы в главном меню" << std::endl;
            print_main_menu();
        }
        else if (msg == 3)
        {
            //graph_setup();
            std::cout << "\tВы в главном меню" << std::endl;
            print_main_menu();
        }
        else if (msg == 4)
        {
            print_main_menu();
        }
        else
        {
            std::cout << "\tКоманда не распознана. Повторите ввод. Введите 4 для получения помощи" << std::endl;
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
        std::cout << "\tВыбранный пункт: ";
        int msg = get_number(0, 12);
        if (msg == 0)
        {
            finish = true;
        }
        else if (msg == 1)
        {
            std::cout << "\tВведите параметры трубы:" << std::endl;
            std::cout << "\tВведите длину: ";
            int length_tmp = get_number(0, INT_MAX);
            std::cout << "\tВведите диаметр (500-1420): ";
            int diameter_tmp = get_number(500, 1420);
            pipes.add_pipe(length_tmp, diameter_tmp);
            std::cout << "\tТруба успешно добавлена" << std::endl;
            PRINT_HASH_LINE;
        }
        else if (msg == 2)
        {
            std::cout << "\tВведите ID удаляемой трубы: ";
            int index = get_number(0, pipes.return_pipe_count() - 1);
            pipes.delete_pipe(index);
            std::cout << "\tТруба ID " << index << " успешно удалена" << std::endl;
            PRINT_HASH_LINE;
        }
        else if (msg == 3)
        {
            std::cout << "\tВведите ID трубы для изменения статуса ремонта: ";
            int index = get_number(0, pipes.return_pipe_count() - 1);
            pipes.change_repair_status(index);
            PRINT_HASH_LINE;
        }
        else if (msg == 4)
        {
            std::cout << "\tВсе трубы:" << std::endl << std::endl;
            pipes.print_all_pipes_to_console();
            PRINT_HASH_LINE;
        }
        else if (msg == 5)
        {
            std::cout << "\tВведите ID трубы для выбора: ";
            int index = get_number(0, pipes.return_pipe_count() - 1);
            pipes.select_pipe(index);
            PRINT_HASH_LINE;
        }
        else if (msg == 6)
        {
            std::cout << "\tВведите ID трубы для удаления из выбранных: ";
            int index = get_number(0, pipes.return_pipe_count() - 1);
            pipes.deselect_pipe(index);
            PRINT_HASH_LINE;
        }
        else if (msg == 7)
        {
            std::cout << "\tВсе выбранные трубы:" << std::endl;
            pipes.print_selected_pipes_to_console();
            PRINT_HASH_LINE;
        }
        else if (msg == 8)
        {
            std::cout << "\tВыберите параметр для поиска (ID - 0 | Длина - 1 | Диаметр - 2 | Состояние работоспособности - 3): ";
            int parametr_id = get_number(0, 3);
            if (parametr_id == 0)
            {
                std::cout << "\tВведите ID: ";
                int index = get_number(0, pipes.return_pipe_count() - 1);
                pipes.search_pipe(index, index, 0);
            }
            else if (parametr_id == 1)
            {
                std::cout << "\tВведите минимальное значение: ";
                int left = get_number(0, INT_MAX);
                std::cout << "\tВведите максимальное значение: ";
                int right = get_number(left, INT_MAX);
                pipes.search_pipe(left, right, 1);
            }
            else if (parametr_id == 2)
            {
                std::cout << "\tВведите минимальное значение: ";
                int left = get_number(0, INT_MAX);
                std::cout << "\tВведите максимальное значение: ";
                int right = get_number(left, INT_MAX);
                pipes.search_pipe(left, right, 2);
            }
            else
            { 
                std::cout << "\tВведите состояние трубы для поиска (Работает - 0 | В ремонте - 1): ";
                int param = get_number(0, 1);
                pipes.search_pipe(param, param, 3);
            }
            PRINT_HASH_LINE;
        }
        else if (msg == 9)
        {
            std::cout << "\tВыберите параметр для группового изменения (Длина - 1 | Диаметр - 2 | Состояние работоспособности - 3): ";
            int parametr_id = get_number(1, 3);
            std::cout << "\tВведите новое значение: ";
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
            std::cout << "\tКоманда не распознана. Повторите ввод. Введите 11 для получения помощи" << std::endl;
            PRINT_HASH_LINE;
        }
    }
}

void ks_setup(set_of_kss kss)
{
    bool finish = false;
    print_ks_menu();
    while (!finish)
    {
        std::cout << "Выбранный пункт: ";
        int msg = get_number(0, 12);
        if (msg == 0)
        {
            finish = true;
        }
        else if (msg == 1)
        {
            std::cout << "Введите параметры компрессорной станции:" << std::endl;
            std::cout << "Введите имя: ";
            std::string name_tmp;
            std::cin >> name_tmp;
            std::cout << "Введите количество цехов: ";
            int num_of_shops_tmp = get_number(0, INT_MAX);
            std::cout << "Введите количество активных цехов: ";
            int num_of_active_shops_tmp = get_number(0, num_of_shops_tmp);
            std::cout << "Введите эффективность (0-100): ";
            int efficiency = get_number(0, 100);
            kss.add_ks(name_tmp, num_of_shops_tmp, num_of_active_shops_tmp, efficiency / 100.0);
        }
        else if (msg == 2)
        {
            std::cout << "Введите ID удаляемой компрессорной станции: ";
            int index = get_number(0, kss.return_ks_count() - 1);
            kss.delete_ks(index);
        }
        else if (msg == 3)
        {
            std::cout << "Введите ID трубы для изменения закрытия цеха: ";
            int index = get_number(0, kss.return_ks_count() - 1);
            kss.close_shop(index);
        }
        else if (msg == 4)
        {
            std::cout << "Введите ID трубы для изменения открытия цеха: ";
            int index = get_number(0, kss.return_ks_count() - 1);
            kss.open_shop(index);
        }
        else if (msg == 5)
        {
            kss.print_all_kss_to_console();
        }
        else if (msg == 6)
        {
            std::cout << "Введите ID компрессорной станции для выбора: ";
            int index = get_number(0, kss.return_ks_count() - 1);
            kss.select_ks(index);
        }
        else if (msg == 7)
        {
            kss.print_selected_kss_to_console();
        }
        else if (msg == 8)
        {
            std::cout << "Выберите параметр для поиска (ID - 0 | Имя - 1 | Количество цехов - 2 | Количество активных цехов - 3 | Эффективность - 4): ";
            int parametr_id = get_number(0, 4);
            if (parametr_id == 0)
            {
                std::cout << "Введите ID: ";
                int index = get_number(0, kss.return_ks_count() - 1);
                kss.search_ks(index, index, 0);
            }
            else if (parametr_id == 1)
            {
                std::cout << "Введите имя для поиска: ";
                std::string param;
                kss.search_ks(param, param, 1);
            }
            else if (parametr_id == 2)
            {
                std::cout << "Введите минимальное значение: ";
                int left = get_number(0, INT_MAX);
                std::cout << "Введите максимальное значение: ";
                int right = get_number(left, INT_MAX);
                kss.search_ks(left, right, 2);
            }
            else
            {
                std::cout << "Введите минимальное значение: ";
                int left = get_number(0, INT_MAX);
                std::cout << "Введите максимальное значение: ";
                int right = get_number(left, INT_MAX);
                kss.search_ks(left, right, 4);
            }
            std::cout << "Параметр успешно изменен" << std::endl;
        }
        else if (msg == 9)
        {
            std::cout << "Выберите параметр для группового изменения (Имя - 1 | Количество цехов - 2 | Количество активных цехов - 3 | Эффективность - 4): ";
            int parametr_id = get_number(1, 4);
            std::cout << "Введите новое значение: ";
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
            std::cout << "Команда не распознана. Повторите ввод. Введите 11 для получения помощи" << std::endl;
        }
    }
}

void graph_setup(void)
{

}