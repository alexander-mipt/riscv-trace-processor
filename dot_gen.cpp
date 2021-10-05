#include <cassert>
#include <iostream>
#include "dot_gen.hpp"

Graph::Graph() {
    m_out << "digraph G {\n" << "\trankdir=UD\n";
}

Graph::~Graph() {
    m_out << "}\n";
    print();
}

void Graph::addRankNode() {
    m_out << "\t" << m_rank << "\n";
    if (m_rank > 0) {
        m_out << "\t" << m_rank-1 << "->" << m_rank << "\n";
    }
    m_rank++;
}

void Graph::addNode(std::string nodename, int rank) {
    assert(rank <= m_rank);
    if (rank == m_rank) {
        addRankNode();
    }
    m_out << "\t\"" << nodename << rank << "\"" << " [label=\"" << nodename << "\"]\n";
    m_out << "\t{ rank=same " << rank << " \"" << nodename << rank << "\" }\n" ;
}

void Graph::addEdge(std::string nodename_from, int from_rank, std::string nodename_to, int to_rank) {
    assert(from_rank <= m_rank && to_rank <= m_rank);
    m_out << "\t" << nodename_from << from_rank << "->" << nodename_to << to_rank << "\n";
}

void Graph::print() {
    std::cout << m_out.str() << std::endl;
}