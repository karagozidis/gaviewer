#pragma once


#include "ParseItem.h"
#include <exception>

using namespace System::Collections::Generic;
using namespace std; 

namespace ExprParser {

ref class Parser
{
private: 

	List<ParseItem^>^ initialBuffer_ ;
	ParseItem^ baseParseItem_ ; 
	List<ParseItem^>^ xItemsBuffer_ ;
	List<ParseItem^>^ yItemsBuffer_ ;

	int itemsBufferPosition_; 
	int currentBracketPriority_; 
	int maxBracketPriority_ ;
	List<int>^ prevBracketPriorityBuffer_;
	System::String^ expr_; 

private:
	
	void createInitialBuffer(System::String^ expr);
	void createTree();
	double calculate(ParseItem^ baseParseItem);

	bool checkBruckets();
	bool checkCharacters();
	bool checkCharactersDetailed();
	bool checkInitialBuffer();
	bool checkTree();
	ParseItem^ getUpperLayerItem(int pos);


public:
	Parser(void);
	bool validateExpression(System::String^ expr);
	void createBuffer(System::String^ expr);
	double calculateExpression();
	void setXY(double x , double y);
	void setX(double x);
	void setY(double y);
	void printInitialBuffer();
//	void printItemsBuffer();
};

}