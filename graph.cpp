#include "graph.h"

void graph::add_node(unsigned int index)
{
	for (auto it = matrix.begin(); it != matrix.end(); it++)
		(*it).push_back(-1);
	node_count++;
	std::vector<int> v(node_count, -1);
	matrix.push_back(v);

	std::cout << "\tВершина добавлена в граф" << std::endl;
}

void graph::delete_node(unsigned int index)
{
	if (node_count < index)
		std::cout << "\tВершина не присутсвовала в графе";
	else
	{
		/*
		//При удалении просто "отсоединяем вершину"
		for (auto it = matrix.begin(); it != matrix.end(); it++)
			(*it)[index] = 0;

		for (size_t i = 0; i < node_count; i++)
			for (auto it = matrix[index].begin(); it != matrix[index].end(); it++)
				*it = 0;

		std::cout << "\tВершина удалена из графа" << std::endl;
		node_count--;
		*/

		/*
		//Сдвиг вершин
		//part a
		for (size_t i = 0; i < index; i++)
			for (size_t j = index; j < node_count - 1; j++)
				matrix[i][j] = matrix[i][j + 1];
		//part b
		for (size_t i = 0; i < index; i++)
			for (size_t j = index; j < node_count - 1; j++)
				matrix[j][i] = matrix[j][i + 1];
		//part c
		for (size_t i = index + 1; i < node_count; i++)
			for (size_t j = index + 1; j < node_count; j++)
				matrix[i - 1][j - 1] = matrix[i][j];

		node_count--;
		std::cout << "\tВершина удалена из графа" << std::endl;

		*/
	}
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

void graph::connect_two_nodes(unsigned int node1, unsigned int node2, unsigned int pipe_id)
{
	matrix[node1][node2] = pipe_id;
	std::cout << "\tВершины успешно соединены";
}

unsigned int graph::return_node_count(void)
{
	return node_count;
}