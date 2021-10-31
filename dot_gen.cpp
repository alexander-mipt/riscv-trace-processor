#include <cassert>
#include <iostream>
#include "dot_gen.hpp"
#include <fstream>

#define DOT_FILE "dfg.dot"

Graph::Graph() {
    m_out << "digraph G {\n" << "\trankdir=UD\n" << "\tnode [shape=plaintext]\n";
    m_cluster << "\tsubgraph cluster_0 {\n";
    m_cluster_data << "\tsubgraph cluster_1 {\n";
}

Graph::~Graph() {
    m_out << m_cluster_data.str() << "\t}\n\n" << m_cluster.str() << "\t}\n" << "}\n";
    save();
}

void Graph::addRankNode() {
    m_out << "\t" << m_rank << "[style=invis]\n";
    if (m_rank > 0) {
        m_out << "\t" << m_rank-1 << "->" << m_rank << "[style=invis]\n";
    }
    m_rank++;
}

void Graph::addSpace(int rank) {
    m_out << "\tx" << m_id << " [style=invis]\n";
    m_out << "\t{ rank=same " << rank << " x" << m_id << "}\n";
    m_id++;
}

void Graph::addNode(std::string nodename, int rank, bool cluster) {
    
    assert(rank <= m_rank);
    if (rank == m_rank) {
        addRankNode();
    }

    if (cluster) {
        m_cluster << "\t\t\"" << nodename << rank << "\"" << " [label=\"" << nodename << "\"]\n";
        m_cluster << "\t{ rank=same " << rank << " \"" << nodename << rank << "\" }\n" ;
    } else {
        m_cluster_data << "\t\"" << nodename << rank << "\"" << " [label=\"" << nodename << "\"]\n";
        m_cluster_data << "\t{ rank=same " << rank << " \"" << nodename << rank << "\" }\n" ;
    }
    
    
    
}

void Graph::addEdge(std::string nodename_from, int from_rank, std::string nodename_to, int to_rank) {
    assert(from_rank <= m_rank && to_rank <= m_rank);
    m_out << "\t\"" << nodename_from << from_rank << "\" -> \"" << nodename_to << to_rank << "\"\n";
}

void Graph::save() {
    std::ofstream file(DOT_FILE);
    if (file.is_open()) {
        file << m_out.str();
        file.close();
    }
}