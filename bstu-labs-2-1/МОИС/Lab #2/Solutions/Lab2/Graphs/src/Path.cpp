#include "Path.h"

Path::Path()
{}
Path::Path(const Edge& initEdge)
{
	path.push_back(initEdge);
}
GraphResponse Path::add(const Edge& nEdge)
{
	if (path.size() == 0)
	{
		path.push_back(nEdge);
		return GRAPH_OK;
	}
	if (nEdge.fVertex == path[path.size() - 1].secVertex)
	{
		path.push_back(nEdge);
		return GRAPH_OK;
	}
	if (nEdge.secVertex == path[0].fVertex)
	{
		path.push_forward(nEdge);
		return GRAPH_OK;
	}
	if (nEdge.secVertex == path[path.size() - 1].secVertex)
	{
		Edge temp;
		temp.weight = nEdge.weight;
		temp.fVertex = nEdge.secVertex;
		temp.secVertex = nEdge.fVertex;
		path.push_back(temp);
		return GRAPH_OK;
	}
	if (nEdge.fVertex == path[0].fVertex)
	{
		Edge temp;
		temp.weight = nEdge.weight;
		temp.fVertex = nEdge.secVertex;
		temp.secVertex = nEdge.fVertex;
		path.push_forward(temp);
		return GRAPH_OK;
	}
	return GRAPH_NOT_OK;
}
double Path::length()
{
	double rv_length = 0;
	for (int i = 0; i < path.size(); i++)
		rv_length += path[i].weight;
	return rv_length;
}
void Path::viewPath()
{
	for (int i = 0; i < path.size(); i++)
		std::cout << path[i].fVertex << " <-|" << path[i].weight << "|-> ";
	std::cout << path[path.size() - 1].secVertex << std::endl;
}
GraphResponse Path::changeEdge(const int id, double nWeight)
{
	try
	{
		if (id < 0)
			throw 1;
		if (id >= path.size())
			throw 2;
		path.getAccess(id).weight = nWeight;
		return GRAPH_OK;
	}
	catch (int e)
	{
		std::cout << "Path::changeEdge(const int, const Edge&)\n"
			<< "Error - " << e << std::endl;
		return GRAPH_NOT_OK;
	}
}
Edge& Path::operator[](const int id)
{
	try
	{
		if (id < 0)
			throw 1;
		if (id >= path.size())
			throw 2;
		return path.getAccess(id);
	}
	catch (int e)
	{
		std::cout << "Path::changeEdge(const int, const Edge&)\n"
			<< "Error - " << e << std::endl;
		exit(1);
	}
}
void Path::removeEdge(const int id)
{
	path.remove(id);
}


Path operator+(const Path& p, const Edge& e)
{
	Path res = p;
	res.add(e);
	return res;
}

Path& Path::operator=(const Path& obj)
{
	path = List<Edge>(obj.path);
	return (*this);
}

GraphNumberOfEdges Path::numOfE() const
{
	return path.size();
}