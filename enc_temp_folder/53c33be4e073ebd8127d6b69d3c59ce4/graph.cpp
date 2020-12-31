#include "graph.h"

#define OTLADKA(x, text) std::cout << "###ОТЛАДКА### " << text << ": " << x << std::endl;

void graph::swap_nodes(std::queue<unsigned int> new_order)
{
	auto matrix_old = matrix;
	auto q = new_order;
	for (size_t i = 0; i < node_count; i++, q.pop())
	{
		auto node1 = i;
		auto node2 = q.front();
		if (node1 != node2)
			for (size_t j = 0; j < node_count; j++)
				matrix[node1][j] = matrix_old[node2][j];
	}
	matrix_old = matrix;
	q = new_order;
	for (size_t i = 0; i < node_count; i++, q.pop())
	{
		auto node1 = i;
		auto node2 = q.front();
		if (node1 != node2)
			for (size_t j = 0; j < node_count; j++)
				matrix[j][node1] = matrix_old[j][node2];
	}
}

void graph::init(unsigned int size)
{
	for (size_t i = 0; i < size; i++)
	{
		std::vector<int> v(size, UINT_MAX);
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
	if (matrix[index][index] != UINT_MAX)
		edges_to_free.push_back(matrix[index][index]);
	for (size_t i = 0; i < node_count; i++)
	{
		if (i != index)
		{
			if (matrix[index][i] != UINT_MAX)
				edges_to_free.push_back(matrix[index][i]);
			if (matrix[i][index] != UINT_MAX)
				edges_to_free.push_back(matrix[index][i]);
		}
		matrix[index][i] = UINT_MAX;
		matrix[i][index] = UINT_MAX;
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
		if (matrix[index][i] != UINT_MAX)
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
		if (matrix[i][index] != UINT_MAX)
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
	edge_count++;
	std::cout << "\tВершины успешно соединены" << std::endl;
}

int graph::disconnect_two_nodes(unsigned int node1, unsigned int node2)
{
	int pipe_id = matrix[node1][node2];
	if (pipe_id != UINT_MAX)
	{
		matrix[node1][node2] = UINT_MAX;
		std::cout << "\tВершины успешно отсоединены" << std::endl;
		edge_count--;
	}
	else
		std::cout << "\tВершины не были соединены" << std::endl;

	return pipe_id;
}

void graph::redirect_arc(unsigned int node1, unsigned int node2)
{
	//В данном случае, если были две дуги то одна стирается
	//Добавить предложение пользователю или развернуть вторую дугу, или предупредить о ее стирании
	if (matrix[node1][node2] != UINT_MAX)
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
	filename += ".graph";
	file.open(filename, std::ofstream::in);
	if (file.is_open())
	{
		unsigned int node_count_tmp;
		file >> node_count_tmp;
		init(node_count_tmp);
		for (size_t i = 0; i < node_count_tmp; i++)
			for (size_t j = 0; j < node_count_tmp; j++)
			{
				file >> matrix[i][j];
				if (matrix[i][j] != UINT_MAX)
					edge_count++;
			}
		file.close();
		std::cout << "\tГраф успешно загружен (Число вершин: " << node_count_tmp << " )" << std::endl;
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

	std::queue<unsigned int> q; //Стек, заполняющийся ко второй части алгоритма
	std::vector<unsigned int> table(node_count, 0); //Таблица, хранящая степени вершин. Значение i-того элемента равно степени i-той вершины
	bool is_chain = false; //При появлении цепи топологическая сортировка невозможна
	//Заполнение таблицы степенями
	for (size_t i = 0; i < node_count; i++)
		for (size_t j = 0; j < node_count; j++)
			if (matrix[j][i] != UINT_MAX)
				table[i]++;

	//Нахождение нового порядка (Часть 1)
	while (q.size() < node_count && !is_chain)
	{
		auto pos = std::find(table.begin(), table.end(), 0);
		if (pos == table.end())
		{
			std::cout << "\tВ графе присутсвует цепь, топологическая сортировка невозможна" << std::endl;
			is_chain = true;
		}
		else
		{
			*pos = UINT_MAX;
			auto index = std::distance(table.begin(), pos);
			q.push(index);
			for (size_t i = 0; i < node_count; i++)
				if (matrix[index][i] != UINT_MAX)
					table[i]--;
		}
	}
	if(!is_chain)
		//Установка нового порядка вершин в графе (Часть 2)
		swap_nodes(q);
}

double graph::max_flow(unsigned int start_node, unsigned int end_node, set_of_pipes& pipes)
{
	auto tmp_matrix = matrix;
	double flow = 0;
	std::vector<std::pair<double, double>> flows(edge_count);
	std::cout << "edge count " << edge_count << std::endl;
	//Заполняем кортежи (ID трубы - текущий поток (0) - максимальный поток)
	for (size_t i = 0; i < node_count; i++)
		for (size_t j = 0; j < node_count; j++)
			if (matrix[i][j] != UINT_MAX)
			{
				pipes.set_nodes(matrix[i][j], i, j);
				flows[matrix[i][j]] = std::make_pair(0, pipes.return_performance(matrix[i][j]));
			}
	
	auto matrix_orig = matrix;
	bool finish = false;
	while (!finish)
	{
		auto [distance, path] = minimal_distance(start_node, end_node, pipes);
		std::cout << "Поток : " << flow << "Дистанция " << distance << " Путь : ";
		for (auto& T : path)
			std::cout << " " << T;
		std::cout << std::endl;

		if (distance != UINT_MAX)
		{
			unsigned int minimal_flow_pipe = 0; //ID трубы с минимальным потоком
			double minimal_flow = flows[minimal_flow_pipe].second - flows[minimal_flow_pipe].first;
			for (size_t i = 1; i < path.size(); i++)
				if (flows[i].second - flows[i].first < flows[minimal_flow_pipe].second - flows[minimal_flow_pipe].first)
					minimal_flow_pipe = i;
			flow += flows[minimal_flow_pipe].second - flows[minimal_flow_pipe].first;
			for (size_t i = 0; i < path.size(); i++)
			{
				flows[i].first = flows[minimal_flow_pipe].second - flows[minimal_flow_pipe].first;
				if (flows[i].first == flows[i].second)
				{
					auto nodes = pipes.return_nodes(i);
					disconnect_two_nodes(nodes.first, nodes.second);
				}
			}
		}
		else
			finish = true;
	}
	matrix = matrix_orig;
	return flow;
}

std::tuple<unsigned int, std::vector<unsigned int>> graph::minimal_distance(unsigned int start_node, unsigned int end_node, set_of_pipes& pipes)
{
	std::vector<unsigned int> distance(node_count, UINT_MAX); //Дистанции от текущей до всех прочих, изначально бесконечно большие
	std::vector<bool> is_visited(node_count, false); //Трекер посещенных вершин
	std::vector<unsigned int> prev_node(node_count, start_node); //Храним информацию о вершине, из которой вел кратчайший путь
	std::vector<unsigned int> path; //Кратчайший путь
	std::queue<unsigned int> q; //очередь вершин для посещений

	//Нахождение кратчайшего пути 
	q.push(start_node); //Начинаем с начальной вершины
	distance[start_node] = 0; //Дистанция в начальную вершину равна 0
	is_visited[0] = true;
	while (q.size() > 0) //Пока есть необработанные вершины
	{
		unsigned int current_node = q.front(); //Достаем следующую из очереди
		q.pop(); 

		//Для нахождения смежных вершин проверяем все
		for (size_t i = 0; i < node_count; i++)
		{
			unsigned int connecting_pipe = matrix[current_node][i];
			if (connecting_pipe != UINT_MAX) //Если вершина смежная
			{
				//Считаем новое расстояние как расстояние до текущей + длина трубы
				unsigned int new_distance = distance[current_node] + pipes.return_pipe_cost(connecting_pipe);
				if (new_distance < distance[i]) //Если дистанция вышла меньше той, что на данный момент в таблице, заменяем
				{
					distance[i] = new_distance;
					prev_node[i] = current_node; //Если из текущей вершины путь кратчайший, то меняем значение предыдущей вершины для соседа
				}
				if (is_visited[i] == false) //Если соседняя вершина еще не была посещена, добавляем ее в очередь
				{
					q.push(i);
					is_visited[i] = true;
				}
			}
		}
	}

	//Восстанавливаем кратчайший путь
	bool finish = false;
	path.push_back(end_node);
	while (!finish)
	{
		path.push_back(prev_node[end_node]);
		if (prev_node[end_node] != start_node)
			end_node = prev_node[end_node];
		else
			finish = true;
	}

	return std::make_tuple(distance[end_node], path); //Возвращаем дистанцию до заданного узла
	/* 
	* Возможно есть более эффективные методы, в которые начало алгоритма исходит из конечной вершины
	* Так, что часть вершин будет пропущена. В текущем алгоритме посещаются все вершины, что затратно по ресурсам
	*/
}

unsigned int graph::return_node_count(void)
{
	return node_count;
}

unsigned int graph::return_edge_count(void)
{
	return edge_count;
}
