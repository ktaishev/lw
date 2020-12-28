#ifndef LW_GRAPH_H_
#define LW_GRAPH_H_

#include <iostream>
#include <vector> 

class graph {
    unsigned int node_count = 0;
    std::vector<std::vector<int>> matrix;
public:
    void init(unsigned int);
    void add_node(unsigned int);
    std::vector<unsigned int> delete_node(unsigned int);
    void print_node(unsigned int);
    void print_nodes(void);
    void print_matrix(void);
    void connect_two_nodes(unsigned int, unsigned int, unsigned int);
    int disconnect_two_nodes(unsigned int, unsigned int);
    void redirect_arc(unsigned int, unsigned int);
    unsigned int return_node_count(void);
};

#endif 