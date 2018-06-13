#pragma once



using namespace System;

namespace ExprParser {

ref class ParseItem 
{

public:

	int pos_;
	int length_; 
	int type_;
	int specialType_ ; 
	double number_ ;
	System::String^ numberStr_ ;
	bool mark_; 
	int bracketPriority_ ; 
	bool isNegative_ ; 
	bool isX_;
	bool isY_;
	bool isPrior_; 
	

	ParseItem ^leftChildrenItem_ ;
	ParseItem ^rightChildrenItem_ ;
	ParseItem ^centerChildrenItem_ ;

	ParseItem ^parentItem_ ;



	static const int MUL = 0 ; 
	static const int DIV = 1 ;
	static const int ADD  = 2 ;
	static const int SUBTR = 3 ;
	static const int NUMBER = 4 ;
	static const int POW = 5 ;

	static const int BRACKET_OPEN = 6 ;
	static const int BRACKET_CLOSE = 7;

	static const int SIN = 8;
	static const int COS = 9;
	static const int TAN = 10;
	static const int ABS = 11;
	static const int EXP = 12;
	static const int SQRT = 13;

	static const int ACOS  = 14;
	static const int ASIN  = 15;
	static const int ATAN  = 16;
	static const int COSH  = 17;
	static const int LOG   = 18;
	static const int LOG10 = 19;
	static const int SINH  = 21;
	static const int TANH  = 22;
	

  ParseItem(int type);
  ParseItem(System::String^ number);
  
  void setBracketPriority(int bracketPriority);
  int getBracketPriority();

  double calculate(double number1 ,double number2);
  double calculate(double number1);
  bool checkChildrenItems();

};
}