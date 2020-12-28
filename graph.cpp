#include "graph.h"

void graph::swap_nodes(std::queue<unsigned int> stack)
{
	auto matrix_old = matrix;
	for (size_t i = 0; i < node_count; i++, stack.pop())
	{
		auto node1 = i; 
		auto node2 = stack.front();
		if (node1 != node2)
		{
			std::vector<unsigned int> in_tmp(node_count, -1);
			std::vector<unsigned int> out_tmp(node_count, -1);
			unsigned int from_1_to_2 = matrix_old[node1][node2];
			unsigned int from_2_to_1 = matrix_old[node2][node1];

			for (size_t i = 0; i < node_count; i++)
			{
				in_tmp[i] = matrix_old[i][node1];
				out_tmp[i] = matrix_old[node1][i];
				matrix[i][node1] = matrix_old[i][node2];
				matrix[node1][i] = matrix_old[node2][i];
				matrix[i][node2] = in_tmp[i];
				matrix[node2][i] = out_tmp[i];
			}
			matrix[node1][node1] = -1;
			matrix[node2][node2] = -1;
			matrix[node1][node2] = from_2_to_1;
			matrix[node2][node1] = from_1_to_2;
		}
	}
}

void graph::init(unsigned int size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::vector<int> v(size, -1);
		matrix.push_back(v);
	}			
}

void graph::add_node(unsigned int index)
{
	node_count++;
	std::cout << "\tВершина добавлена в граф" << std::endl;
}

std::vector<unsigned int> graph::delete_node(unsigned int index)
{
	std::vector<unsigned int> edges_to_free;
	if (matrix[index][index] != -1)
		edges_to_free.push_back(matrix[index][index]);
	for (size_t i = 0; i < node_count; i++)
	{
		if (i != index)
		{
			if (matrix[index][i] != -1)
				edges_to_free.push_back(matrix[index][i]);
			if (matrix[i][index] != -1)
				edges_to_free.push_back(matrix[index][i]);
		}
		matrix[index][i] = -1;
		matrix[i][index] = -1;
	}

	std::cout << "\tВершина удалена из графа" << std::endl;
	node_count--;
	return edges_to_free;
}

void graph::print_node(unsigned int index)
{
	bool is_way = false;
	std::cout << "\tИз вершины " << index << " можно попасть в вершины: ";
	for (size_t i = 0; i < node_count; i++)
		if (matrix[index][i] != -1)
		{
			std::cout << i << " ";
			is_way = true;
		}
	if (!is_way)
		std::cout << "\tИз вершины нет исходящих путей" << std::endl;
	else
		std::cout << std::endl;
	is_way = false;
	std::cout << "\tВ вершину " << index << " можно попасть из вершин: ";
	for (size_t i = 0; i < node_count; i++)
		if (matrix[i][index] != -1)
		{
			std::cout << i << " ";
			is_way = true;
		}
	if (!is_way)
		std::cout << "\tВ вершину нет входящих путей" << std::endl;
	else
		std::cout << std::endl;
}

void graph::print_nodes(void)
{
	for (size_t i = 0; i < node_count; i++)
		print_node(i);
}

void graph::print_matrix(void)
{
	for (size_t i = 0; i < node_count; i++)
	{
		for (size_t j = 0; j < node_count; j++)
		{
			std::cout << matrix[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

void graph::connect_two_nodes(unsigned int node1, unsigned int node2, unsigned int pipe_id)
{
	matrix[node1][node2] = pipe_id;
	std::cout << "\tВершины успешно соединены" << std::endl;
}

int graph::disconnect_two_nodes(unsigned int node1, unsigned int node2)
{
	int pipe_id = matrix[node1][node2];
	if (pipe_id != -1)
	{
		matrix[node1][node2] = -1;
		std::cout << "\tВершины успешно отсоединены" << std::endl;
	}
	else
		std::cout << "\tВершины не были соединены" << std::endl;

	return pipe_id;
}

void graph::redirect_arc(unsigned int node1, unsigned int node2)
{
	//В данном случае, если были две дуги то одна стирается
	//Добавить предложение пользователю или развернуть вторую дугу, или предупредить о ее стирании
	if (matrix[node1][node2] != -1)
	{
		matrix[node2][node1] = matrix[node1][node2];
		std::cout << "\tДуга развернута" << std::endl;
	}
	else
		std::cout << "\tМежду указаннами вершинами нет дуг" << std::endl;
}

void graph::save_to_file(void)
{
	std::ofstream file;
	std::string filename;
	std::cout << "\tВведите имя сохраняемого файла: ";
	std::cin >> filename;
	file.open(filename + ".graph", std::ofstream::out);
	if (file.is_open())
	{
		file << node_count << std::endl;
		for (unsigned int i = 0; i < node_count; i++)
		{
			for (unsigned int j = 0; j < node_count; j++)
				file << matrix[i][j] << " ";
			file << std::endl;
		}
		std::cout << "\tДанные успешно сохранены в файл " << filename + ".graph" << std::endl;
		file.close();
	}
	else
		std::cout << "Ошибка при попытке сохранения: не удалось открыть файл" << std::endl;
}

void graph::load_from_file(void)
{
	std::ifstream file;
	std::string filename;
	std::cout << "\tВведите имя загружаемого файла: ";
	std::cin >> filename;
	file.open(filename, std::ofstream::in);
	if (file.is_open())
	{
		unsigned int node_count_tmp;
		file >> node_count_tmp;
		init(node_count_tmp);
		for (size_t i = 0; i < node_count; i++)
			for (size_t j = 0; j < node_count; j++)
				file >> matrix[i][j];
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

void graph::top_sort(void)
{
	//	Принцип работы алгоритма (Алгоритм Демукрона)
	/*
	* Часть 1
	* 1. Определить степени всех вершин (количесвто исходящих дуг)
	* 2. Выделить пустой стек (FIFO)
	* 3. Начать с вершины со степенью 0, поместить ее в стек
	* 4. Данную вершину отправить в стек
	* 5. У всех смежных вершин (в которые вела данные вершины) уменьшить степень на 2
	* 6. Если есть еще необработанные вершины перейти в шаг 3, если вершин со степенью 
	     0 не осталось, и обработаны не все вершины, то граф не является сетью
	* 
	* Часть 2
	* По окончании работы есть стек с номерами вершин
	* 0. Создаем счетчик i = 0
	* 1. Достаем элемент из стека (номер вершины)
	* 2. Эту вершину нумеруем как i-тую, i++
	* 3. Если стек не пуст, переходим в шаг 1
	* 4. После освобождения стека работа алгоритма завершается
	*/

	std::queue<unsigned int> stack; //Стек, заполняющийся ко второй части алгоритма
	std::vector<unsigned int> table(node_count, 0); //Таблица, хранящая степени вершин. Значение i-того элемента равно степени i-той вершины
	//Заполнение таблицы степенями
	for (size_t i = 0; i < node_count; i++)
		for (size_t j = 0; j < node_count; j++)
			if (matrix[j][i] != -1)
				table[i]++;

	//Нахождение нового порядка (Часть 1)
	while (stack.size() < node_count)
	{
		auto pos = std::find(table.begin(), table.end(), 0);
		if (pos == table.end())
			std::cout << "\tВ графе присутсвует цепь, топологическая сортировка невозможна" << std::endl;
		else
		{
			*pos = -1;
			auto index = std::distance(table.begin(), pos);
			stack.push(index);
			for (size_t i = 0; i < node_count; i++)
				if (matrix[index][i] != -1)
					table[i]--;
		}
	}

	//Установка нового порядка вершин в графе (Часть 2)
	swap_nodes(stack);
}

unsigned int graph::return_node_count(void)
{
	return node_count;
}