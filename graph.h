#ifndef LW_GRAPH_H_
#define LW_GRAPH_H_

#include <iostream>
#include <set>
#include <vector> 

class graph {
    struct node {
        unsigned int ks_id;
        unsigned int edges_in_count;
        unsigned int edges_out_count;
        
        std::vector<std::pair<node, unsigned int>> connected_to; //Содержит информаци о том, в какие узлы мы можем попасть из текущего
        node(int index)
        {
            ks_id = index;
            edges_in_count = 0;
            edges_out_count = 0;
        }
    };
    std::set<node> nodes;
public:
    void add_node(int);
    void delete_node(int);
    void print_node(int);
    void print_nodes(void);
};

#endif 