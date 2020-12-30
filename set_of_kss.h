#ifndef LW_SET_OF_KS_H_
#define LW_SET_OF_KS_H_

#include <algorithm>
#include <fstream>
#include <iostream>
#include <string>
#include <vector>

unsigned int get_number(unsigned int min, unsigned int max);

class set_of_kss {
private:
    class ks {
    public:
        unsigned int id; 
        std::string name;
        int num_of_shops; //Количество цехов
        int num_of_active_shops; //Количество активных цехов
        double efficiency; //Число в диапазоне 0-1, отношение числа рабочих цехов ко всем
        bool is_node = false; //Для работы с нефтесетью, проверка является ли КС вершиной
        ks(unsigned int param0, std::string param1, int param2, int param3, double param4)
        {
            id = param0;
            name = param1;
            num_of_shops = param2;
            num_of_active_shops = param3;
            efficiency = param4;
        }

        std::string return_name() { return name; };
        void change_name(std::string new_value) { name = new_value; };
        double return_parameter(int parameter_id)
        {
            if (parameter_id == 0)
                return id;
            else if (parameter_id == 2)
                return num_of_shops;
            else if (parameter_id == 3)
                return num_of_active_shops;
            else if(parameter_id == 4)
                return efficiency;
            else
                return (is_node ? 1.0 : 0.0);
        }

        template<typename T>
        void change_parameter(T new_value, int parameter_id)
        {
            if (parameter_id == 2)
                num_of_shops = new_value;
            else if (parameter_id == 2)
                num_of_active_shops = new_value;
            else if (parameter_id == 3)
                num_of_active_shops = new_value;
            else
                is_node = new_value;
        }
    };

    std::vector<ks> kss; //Вектор, хранящий все компрессорные станции 
    std::vector<int> selected_ks; //Вектор, хранящий все выбранные компрессорные станции 
    std::vector<int> searched_ks; //Вектор, хранящий все найденные компрессорные станции (только результаты последного запроса)
    unsigned int ks_count; //Текущее число компрессорных станций 
public:
    void add_ks(std::string, int, int, double); //Добавление компрессорной станции
    void delete_ks(int); //Удаление компрессорной станции
    void print_to_console(int); //Печать компрессорной станции в консоль по индексу
    void print_selected_kss_to_console(void); //Печать всех выбранных компрессорных станций в консоль
    void select_ks(int); //Выбор определенной компрессорной станции по индексу
    void deselect_ks(int); //Удаление выбора с определенной компрессорной станции по индексу
    void close_shop(int); //Закрытие цеха компрессорной станции по индексу
    void open_shop(int); //Открытие цеха компрессорной станции по индексу
    void print_all_kss_to_console(void); //Печать всех компрессорных станций в консоль
    void save_to_file(void); //Сохранение всех компрессорных станций в файл
    void load_from_file(void); //Загрузка компрессорных станций из файла
    void set_node(int, bool); //Установка является ли КС вершиной 
    unsigned int return_ks_count(void); //Возврат числа компрессорных станций
    bool is_node(int); //Проверка является ли КС вершиной

    template<typename T> //Поиск компрессорной станции в диапазоне по параметру 
    void search_ks(T, T, int);

    void search_ks_by_name(std::string);

    void bunch_editing_ks_name(std::string );

    template<typename T> //Изменение выбранного параметра у всех выбранных компрессорных станций 
    void bunch_editing_ks(T, int);
};

template<typename T> 
inline void set_of_kss::search_ks(T left, T right, int parameter_id)
{
    std::vector<int> ids;
    searched_ks.clear();
    for_each(kss.begin(), kss.end(),
        [&](ks p) mutable {
            if (left <= p.return_parameter(parameter_id) && p.return_parameter(parameter_id) <= right)
                searched_ks.push_back(p.id);
        });

    std::cout << "\tНайдено " << searched_ks.size() << " КС" << std::endl;
    std::cout << "\tДобавить найденные компрессорные станции к выбранным? (Нет - 0 | Да - 1): ";
    
    int msg = get_number(0, 1);

    if (msg == 1)
        for (auto it = searched_ks.begin(); it != searched_ks.end(); it++)
            selected_ks.push_back(*it);
}

inline void set_of_kss::search_ks_by_name(std::string left)
{
    std::vector<int> ids;
    searched_ks.clear();
    for_each(kss.begin(), kss.end(),
        [&](ks p) mutable {
            if (left == p.return_name())
                searched_ks.push_back(p.id);
        });

    std::cout << "\tНайдено " << searched_ks.size() << " КС" << std::endl;
    std::cout << "\tДобавить найденные компрессорные станции к выбранным? (Нет - 0 | Да - 1): ";
    
    int msg = get_number(0, 1);

    if (msg == 1)
        for (auto it = searched_ks.begin(); it != searched_ks.end(); it++)
            selected_ks.push_back(*it);
}

template<typename T>
inline void set_of_kss::bunch_editing_ks(T new_value, int parameter_id)
{
    for_each(selected_ks.begin(), selected_ks.end(), [&](int index) {kss[index].change_parameter(new_value, parameter_id); });
}

inline void set_of_kss::bunch_editing_ks_name(std::string new_value)
{
    for_each(selected_ks.begin(), selected_ks.end(), [&](int index) {kss[index].change_name(new_value); });
}

#endif