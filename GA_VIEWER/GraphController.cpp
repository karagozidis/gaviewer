#include "StdAfx.h"
#include "GraphController.h"

GraphController::GraphController(void)
{
	graphSet_ = false ;
	paintGrainGraph_ = true; 
	paintLineGraph_ = false ; 
    paintGrayGraph_ = false ; 
	axes_ = gcnew Axes();
}

GraphController::~GraphController(void)
{
	delete this->graph_;
	delete this->axes_;
}

void  GraphController::createNewGraph(StartValues^ startValues)
	{
	graph_ = gcnew Graph(startValues);
	graphSet_ = true ; 
	}

void GraphController::paintGraph()
{
		if (graphSet_ == true)
			{
			if (paintGrainGraph_ == true)
				graph_->paintGraph();
			if (paintLineGraph_ == true)
				graph_->paintLineGraph();
			if (paintGrayGraph_ == true)
				graph_->paintGrayGraph();
			
		graph_->paintNumbers();
			}
}

void GraphController::paintAxes()
{	
	axes_->paintAxes();
}

void GraphController::paintOppositeAxes()
{
	axes_->paintOppositeAxes();
}