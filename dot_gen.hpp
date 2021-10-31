#pragma once
#include <sstream>

class Graph {
public:
    Graph();
    ~Graph();
    void save();
    void addNode(std::string nodename, int rank, bool cluster = false);
    void addSpace(int rank);
    void addEdge(std::string nodename_from, int from_rank, std::string nodename_to, int to_rank);
private:
    int m_rank{0};
    uint m_id{0};
    void addRankNode();
    std::stringstream m_out{};
    std::stringstream m_cluster_data{};
    std::stringstream m_cluster{}; 
};

/*
Graph::Graph();
Graph::~Graph();
void Graph::addRankNode();
void Graph::addNode(std::string nodename, int rank);
void Graph::addEdge(std::string nodename_from, int from_rank, std::string nodename_to, int to_rank);
void Graph::print();
*/