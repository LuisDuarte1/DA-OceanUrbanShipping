#include "VertexEdge.h"

Vertex::Vertex(const int &id) {
    this->id = id;
}

const int &Vertex::getId() const {
    return id;
}

std::vector<Edge *> Vertex::getEdges() const {
    return edges;
}

bool Vertex::isVisited() const {
    return visited;
}

int Vertex::getDistance() const { return distance; }

Edge *Vertex::getPath() const {
    return path;
}

std::vector<Edge *> Vertex::getIncoming() const {
    return incoming;
}

void Vertex::setPath(Edge *_path) {
    this->path = _path;
}

void Vertex::setDistance(int _distance) {
    this->distance = _distance;
}

Edge *Vertex::addEdge(Vertex *dest, double weight) {
    Edge *edge = new Edge(this, dest, weight);
    edges.push_back(edge);
    dest->incoming.push_back(edge);
    return edge;
}

bool Vertex::removeEdge(const int &dest) {
    bool removed = false;
    for (auto it = edges.begin(); it != edges.end();) {
        Edge *edge = *it;
        Vertex *v = edge->getDest();
        if (v->getId() == dest) {
            it = edges.erase(it);
            for (auto it2 = v->incoming.begin(); it2 != v->incoming.end();) {
                if ((*it2)->getOrigin()->getId() == id) {
                    it2 = v->incoming.erase(it2);
                } else it2++;
            }
            delete edge;
            removed = true;
        } else it++;
    }
    return removed;
}

Edge::Edge(Vertex *origin, Vertex *dest, double weight) {
    this->origin = origin;
    this->dest = dest;
    this->weight = weight;
}

Vertex *Edge::getOrigin() const {
    return origin;
}

Vertex *Edge::getDest() const {
    return dest;
}

int Edge::getWeight() const {
    return weight;
}

void Edge::setReverse(Edge *_reverse) {
    this->reverse = _reverse;
}

void Vertex::setVisited(bool _visited) {
    this->visited = _visited;
}



