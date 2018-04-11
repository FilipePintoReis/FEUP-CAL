/*
 * Graph.h
 */
#ifndef GRAPH_H_
#define GRAPH_H_

#include <vector>
#include <queue>
#include <limits.h>
#include "MutablePriorityQueue.h"
#include "Trip.h"


using namespace std;

template <class T> class Edge;
template <class T> class Graph;
template <class T> class Vertex;


/****************** VERTEX  ********************/

template <class T>
class Vertex {
	T info;                // contents
	vector<Edge<T> > adj;  // list of outgoing edges
	bool visited;          // auxiliary field used by dfs and bfs
	bool processing;       // auxiliary field used by isDAG
	int indegree;
	double dist;			// auxiliary field used by topsort

public:
	Vertex(T in);
	friend class Graph<T>;
	void addEdge(Vertex<T> *dest, double w);
	bool removeEdgeTo(Vertex<T> *d);
	T getInfo() const;
	void setInfo(T info);
	double getDist() const;
	int getIndegree() const;
	vector<Edge<T>> getAdj() const;
	Vertex<T>* getPath() const;

	Vertex* path;
	bool operator<(const Vertex<T> v);
};

template<class T>
struct vertexCloser {

	bool operator()(Vertex<T>* a, Vertex<T>* b) const {

		return a->getDist() > b->getDist();
	}
};

template <class T>
Vertex<T>::Vertex(T in): info(in), visited(false), processing(false), indegree(0), dist(0) {
	path = NULL;
}

template <class T>
void Vertex<T>::addEdge(Vertex<T> *dest, double w){

	Edge<T> edgeD(dest, w);
	adj.push_back(edgeD);
}

template <class T>
bool Vertex<T>::removeEdgeTo(Vertex<T> *d) {
	for (auto it = adj.begin(); it != adj.end(); it++)
		if (it->dest  == d) {
			adj.erase(it);
			return true;
		}
	return false;
}

template <class T>
T Vertex<T>::getInfo() const {

	return this->info;
}

template<class T>
void Vertex<T>::setInfo(T info){

	this->info = info;
}

template<class T>
double Vertex<T>::getDist() const {

	return this->dist;
}

template<class T>
int Vertex<T>::getIndegree() const {

	return this->indegree;
}

template<class T>
vector<Edge<T>> Vertex<T>::getAdj() const {

	return this->adj;
}

template<class T>
Vertex<T>* Vertex<T>::getPath() const {

	return this->path;
}


/******************EDGE  ********************/

template <class T>
class Edge {
	T info;                // contents
	Vertex<T> * dest;
	double weight;         // edge weight
public:
	Edge(Vertex<T> *d, double w);
	T getInfo() const;
	double getWeight() const;
	Vertex<T>* getDest() const;
	bool operator<(const Edge<T> &other) const;

	friend class Graph<T>;
	friend class Vertex<T>;

};


template<class T>
struct egdeGreater {
	bool operator()(Edge<T> a, Edge<T> b) const {
		return a.getWeight() > b.getWeight();
	}
};

template <class T>
Edge<T>::Edge(Vertex<T> *d, double w): dest(d), weight(w) {
}

template<class T>
double Edge<T>::getWeight() const {

	return this->weight;
}

template<class T>
Vertex<T>* Edge<T>::getDest() const {

	return this->dest;
}

template<class T>
bool Edge<T>::operator<(const Edge<T> &o) const {

	return this->weight < o->weight;
}

template <class T>
T Edge<T>::getInfo() const {

	return this->info;
}

/****************** GRAPH  ********************/

template <class T>
class Graph {
	vector<Vertex<T> *> vertexSet;    // vertex set
	void dfsVisit(Vertex<T> *v,  vector<T> & res) const;

	bool dfsIsDAG(Vertex<T> *v) const;
public:
	int getNumVertex() const;
	vector<Vertex<T> *> getVertexSet();
	bool addVertex(const T &in);
	bool removeVertex(const T &in);
	bool addEdge(const T &sourc, const T &dest, double w);
	bool removeEdge(const T &sourc, const T &dest);
	vector<T> dfs() const;
	vector<T> bfs(const T &source) const;
	int maxNewChildren(const T &source, T &inf) const;
	bool isDAG() const;
	Vertex<T> *initSingleSource(const T &origin);
	bool relax(Vertex<T> *v, Vertex<T> *w, double weight);
	void dijkstraShortestPath(const T &origin);
	vector<T> getPath(const T &origin, const T &dest) const;
	Vertex<T> *findVertex(const T &in) const;
	Vertex<T> *findVertexID(int id) const;

    Vertex<T>*  findVertexName(string nome) const;
};

template <class T>
int Graph<T>::getNumVertex() const {
	return vertexSet.size();
}

template <class T>
vector<Vertex<T> *> Graph<T>::getVertexSet(){
	return vertexSet;
}

//template <class T>
//Vertex<T> * Graph<T>::findVertex(const T &in) const {
//	for (auto v : vertexSet)
//		if (v->info ==  in)
//			return v;
//	return NULL;
//}

template <class T>
Vertex<T> * Graph<T>::findVertexID(int id) const {
	for (auto v : vertexSet)
		if (v->info.getID() == id)
			return v;
	return NULL;
}

template <class T>
bool Graph<T>::addVertex(const T &in) {
	if ( findVertex(in) != NULL)
		return false;
	vertexSet.push_back(new Vertex<T>(in));
	return true;
}

template <class T>
bool Graph<T>::addEdge(const T &sourc, const T &dest, double w) {
	auto v1 = findVertex(sourc);
	auto v2 = findVertex(dest);
	if (v1 == NULL || v2 == NULL)
		return false;
	v1->addEdge(v2,w);
	return true;
}

template <class T>
bool Graph<T>::removeEdge(const T &sourc, const T &dest) {
	auto v1 = findVertex(sourc);
	auto v2 = findVertex(dest);
	if (v1 == NULL || v2 == NULL)
		return false;
	return v1->removeEdgeTo(v2);
}

template <class T>
bool Graph<T>::removeVertex(const T &in) {
	for (auto it = vertexSet.begin(); it != vertexSet.end(); it++)
		if ((*it)->info  == in) {
			auto v = *it;
			vertexSet.erase(it);
			for (auto u : vertexSet)
				u->removeEdgeTo(v);
			delete v;
			return true;
		}
	return false;
}

template <class T>
vector<T> Graph<T>::dfs() const {
	vector<T> res;
	for (auto v : vertexSet)
		v->visited = false;
	for (auto v : vertexSet)
		if (! v->visited)
			dfsVisit(v, res);
	return res;
}

template <class T>
void Graph<T>::dfsVisit(Vertex<T> *v, vector<T> & res) const {
	v->visited = true;
	res.push_back(v->info);
	for (auto & e : v->adj) {
		auto w = e.dest;
		if ( ! w->visited)
			dfsVisit(w, res);
	}
}

template <class T>
vector<T> Graph<T>::bfs(const T & source) const {
	vector<T> res;
	auto s = findVertex(source);
	if (s == NULL)
		return res;
	queue<Vertex<T> *> q;
	for (auto v : vertexSet)
		v->visited = false;
	q.push(s);
	s->visited = true;
	while (!q.empty()) {
		auto v = q.front();
		q.pop();
		res.push_back(v->info);
		for (auto & e : v->adj) {
			auto w = e.dest;
			if ( ! w->visited ) {
				q.push(w);
				w->visited = true;
			}
		}
	}
	return res;
}

template <class T>
int Graph<T>::maxNewChildren(const T & source, T &inf) const {
	auto s = findVertex(source);
	if (s == NULL)
		return 0;
	queue<Vertex<T> *> q;
	int maxChildren = 0;
	inf = s->info;
	for (auto v : vertexSet)
		v->visited = false;
	q.push(s);
	s->visited = true;
	while (!q.empty()) {
		auto v = q.front();
		q.pop();
		int nChildren=0;
		for (auto & e : v->adj) {
			auto w = e.dest;
			if ( ! w->visited ) {
				w->visited = true;
				q.push(w);
				nChildren++;
			}
		}
		if (nChildren>maxChildren) {
			maxChildren = nChildren;
			inf = v->info;
		}
	}
	return maxChildren;
}

template <class T>
bool Graph<T>::isDAG() const {
	for (auto v : vertexSet) {
		v->visited = false;
		v->processing = false;
	}
	for (auto v : vertexSet)
		if (! v->visited)
			if ( ! dfsIsDAG(v) )
				return false;
	return true;
}

template <class T>
bool Graph<T>::dfsIsDAG(Vertex<T> *v) const {
	v->visited = true;
	v->processing = true;
	for (auto & e : v->adj) {
		auto w = e.dest;
		if (w->processing)
			return false;
		if (! w->visited)
			if (! dfsIsDAG(w))
				return false;
	}
	v->processing = false;
	return true;
}


/****************** Dijkstra  ********************/

template<class T>
Vertex<T> * Graph<T>::initSingleSource(const T &origin) {
	for (auto v : vertexSet) {
		v->dist = INT_MAX;
		v->path = nullptr;
	}
	auto s = findVertex(origin);
	s->dist = 0;
	return s;
}

template<class T>
bool Graph<T>::relax(Vertex<T> *v, Vertex<T> *w, double weight) {
	if (v->dist + weight < w->dist) {
		w->dist = v->dist + weight;
		w->path = v;
		return true;
	}
	else
		return false;
}

template<class T>
Vertex<T>* Graph<T>::findVertexName(string nome) const{
    for (auto v : vertexSet)
        if (v->info.getName() == nome)
            return v;
    return NULL;
}

template <class T>
Vertex<T> * Graph<T>::findVertex(const T &in) const {
    for (auto v : vertexSet)
        if (v->info == in)
            return v;
    return NULL;
}

/**
 * Dijkstra algorithm.
 */
template<class T>
void Graph<T>::dijkstraShortestPath(const T &origin) {
	auto s = initSingleSource(origin);
	MutablePriorityQueue<Vertex<T>> q;
	q.insert(s);
	while ( ! q.empty() ) {
		auto v = q.extractMin();
		for (auto e : v->adj) {
			auto oldDist = e.dest->dist;
			if (relax(v, e.dest, e.weight)) {
				if (oldDist == INT_MAX)
					q.insert(e.dest);
				else
					q.decreaseKey(e.dest);
			}
		}
	}
}

template<class T>
vector<T> Graph<T>::getPath(const T &origin, const T &dest) const {
	vector<T> res;
	auto v = findVertex(dest);
	if (v == nullptr || v->dist == INT_MAX) // missing or disconnected
		return res;
	for ( ; v != nullptr; v = v->path)
		res.push_back(v->info);
	reverse(res.begin(), res.end());
	return res;
}

#endif /* GRAPH_H_ */
