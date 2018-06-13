#pragma once
#include "Graph.h"
#include "Axes.h"
#include "Parser.h"
#include "StartValues.h"

ref class GraphController
{
private:
	bool graphSet_;
	Graph^ graph_;
	Axes^ axes_;

public:
	bool paintGrainGraph_ ; 
	bool paintLineGraph_ ; 
	bool paintGrayGraph_ ; 

public:
	
	GraphController(void);
	~GraphController(void);

	void createNewGraph(StartValues^ startValues);
	void paintGraph();
	void paintAxes();
	void paintOppositeAxes();
	
};
