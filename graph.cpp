#include "graph.h"

void graph::add_node(int index)
{
	nodes.insert(index);
	std::cout << "\tВершина добавлена в граф" << std::endl;
}

void graph::delete_node(int index)
{
	auto pos = std::find(nodes.begin(), nodes.end(), index);
	if (pos != nodes.end())
	{
		nodes.erase(pos);
		std::cout << "\tВершина успешно удалена" << std::endl;
	}
	else
		std::cout << "\tКомпрессорная станция не была вершиной" << std::endl;
}

void graph::print_node(int index)
{
	for(auto it = nodes.begin(); it != nodes.end(); it++)
		if (it->ks_id == index)
		{

		}
}

void graph::print_nodes(void)
{
	for (auto it = nodes.begin(); it != nodes.end(); it++)
		print_node(it->ks_id);
}


