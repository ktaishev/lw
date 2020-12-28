#include "graph.h"

void graph::init(unsigned int size)
{
	node_count = size;
	for (size_t i = 0; i < size; i++)
	{
		std::vector<int> v(size, -1);
		matrix.push_back(v);
	}			
}

void graph::add_node(unsigned int index)
{
	std::cout << "\t������� ��������� � ����" << std::endl;
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

	std::cout << "\t������� ������� �� �����" << std::endl;
	return edges_to_free;
	/*
	if (node_count < index)
		std::cout << "\t������� �� ������������� � �����";
	else
	{
		/*
		//��� �������� ������ "����������� �������"
		for (auto it = matrix.begin(); it != matrix.end(); it++)
			(*it)[index] = 0;

		for (size_t i = 0; i < node_count; i++)
			for (auto it = matrix[index].begin(); it != matrix[index].end(); it++)
				*it = 0;

		std::cout << "\t������� ������� �� �����" << std::endl;
		node_count--;

		//����� ������
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
		std::cout << "\t������� ������� �� �����" << std::endl;

	}
	*/
}

void graph::print_node(unsigned int index)
{
	bool is_way = false;
	std::cout << "\t�� ������� " << index << " ����� ������� � �������: ";
	for (size_t i = 0; i < node_count; i++)
		if (matrix[index][i] != -1)
		{
			std::cout << i << " ";
			is_way = true;
		}
	if (!is_way)
		std::cout << "\t�� ������� ��� ��������� �����" << std::endl;
	else
		std::cout << std::endl;
	is_way = false;
	std::cout << "\t� ������� " << index << " ����� ������� �� ������: ";
	for (size_t i = 0; i < node_count; i++)
		if (matrix[i][index] != -1)
		{
			std::cout << i << " ";
			is_way = true;
		}
	if (!is_way)
		std::cout << "\t� ������� ��� �������� �����" << std::endl;
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
	std::cout << "\t������� ������� ���������" << std::endl;
}

int graph::disconnect_two_nodes(unsigned int node1, unsigned int node2)
{
	int pipe_id = matrix[node1][node2];
	if (pipe_id != -1)
	{
		matrix[node1][node2] = -1;
		std::cout << "\t������� ������� �����������" << std::endl;
	}
	else
		std::cout << "\t������� �� ���� ���������" << std::endl;

	return pipe_id;
}

void graph::redirect_arc(unsigned int node1, unsigned int node2)
{
	//� ������ ������, ���� ���� ��� ���� �� ���� ���������
	//�������� ����������� ������������ ��� ���������� ������ ����, ��� ������������ � �� ��������
	if (matrix[node1][node2] != -1)
	{
		matrix[node2][node1] = matrix[node1][node2];
		std::cout << "\t���� ����������" << std::endl;
	}
	else
		std::cout << "\t����� ���������� ��������� ��� ���" << std::endl;
}

unsigned int graph::return_node_count(void)
{
	return node_count;
}