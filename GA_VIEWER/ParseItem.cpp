#include "StdAfx.h"
#include "ParseItem.h"



ExprParser::ParseItem::ParseItem(int type)
 {
	 this->number_ = 0;


	 this->type_ = type; 
	 isNegative_ = false ; 
	 mark_ = false; 
	 isX_ = false;
	 isY_ = false;
	 isPrior_ = false;

	 this->leftChildrenItem_ = nullptr;
	 this->rightChildrenItem_ = nullptr;
	 this->centerChildrenItem_ = nullptr;
	 this->parentItem_ = nullptr;
 }
ExprParser::ParseItem:: ParseItem(System::String^ number)
 {
	 this->type_ = ParseItem::NUMBER;
	 this->numberStr_ = number ; 
	 this->number_ =System::Convert::ToDouble(number) ; // atof(number.c_str());
	 isNegative_ = false ; 
	 mark_ = false ; 
	 isX_ = false;
	 isY_ = false;
	 isPrior_ = false;


	 this->leftChildrenItem_ = nullptr;
	 this->rightChildrenItem_ = nullptr;
	 this->centerChildrenItem_ = nullptr;
	 this->parentItem_ = nullptr;
 }

void ExprParser::ParseItem::setBracketPriority(int bracketPriority)
 {
	 this->bracketPriority_ = bracketPriority ; 
 }

int ExprParser::ParseItem::getBracketPriority()
 {
	 return this->bracketPriority_ ; 
 }


double ExprParser::ParseItem::calculate(double number1 ,double number2)
{
double result = 0; 


try{
	if (this->type_ == ParseItem::ADD)
		result = number1 + number2;

	if (this->type_ == ParseItem::SUBTR)
		result = number1 - number2;

	if (this->type_ == ParseItem::MUL)
		result = number1 * number2;

	if (this->type_ == ParseItem::DIV)
		if (number2 == 0)
				result = 0; 
		else
				result = number1 / number2;

	if (this->type_ == ParseItem::POW)
		result = Math::Pow(number1, number2);

}catch(System::Exception^ e){throw e;}
	
	return result ;
}

double ExprParser::ParseItem::calculate(double number1)
{
double result = 0; 

try{
	if (this->type_ == ParseItem::BRACKET_OPEN)
		result = number1;

	if (this->type_ == ParseItem::COS)
		result = Math::Cos(number1);

	if (this->type_ == ParseItem::SIN)
		result = Math::Sin(number1);

	if (this->type_ == ParseItem::TAN)
result = Math::Tan(number1);

	if (this->type_ == ParseItem::ABS)
		result = Math::Abs(number1);

	if (this->type_ == ParseItem::SQRT)
		{
		if (number1 < 0) 
					result = 0 ;
		else
					result = Math::Sqrt(number1);
		}

	if (this->type_ == ParseItem::EXP)
		result = Math::Exp(number1);

if (this->type_ == ParseItem::ACOS)
		result = Math::Acos(number1);

if (this->type_ == ParseItem::ASIN)
		result = Math::Asin(number1);
	
if (this->type_ == ParseItem::ATAN)
		result = Math::Atan(number1);

if (this->type_ == ParseItem::COSH)
		result = Math::Cosh(number1);

if (this->type_ == ParseItem::LOG)
		result = Math::Log(number1);

if (this->type_ == ParseItem::LOG10)
result = Math::Log10(number1);


if (this->type_ == ParseItem::SINH)
result = Math::Sinh(number1);

if (this->type_ == ParseItem::TANH)
result = Math::Tanh(number1);

	

	if (this->isNegative_ == true)
		result = result * (-1); 

}catch(/*exception*/ System::Exception^ e){throw e;}

return result ; 
}

bool ExprParser::ParseItem::checkChildrenItems()
{
	if (this->type_ == ExprParser::ParseItem::ADD || this->type_ == ExprParser::ParseItem::SUBTR ||  
		this->type_ == ExprParser::ParseItem::MUL ||this->type_ == ExprParser::ParseItem::DIV  || this->type_ == ExprParser::ParseItem::POW )
		{
			if (this->leftChildrenItem_ == nullptr || this->rightChildrenItem_ == nullptr) return false;
			else return true;
		}

	else if(this->type_ == ExprParser::ParseItem::NUMBER)
		{
			if (this->leftChildrenItem_ != nullptr || this->rightChildrenItem_ != nullptr || this->centerChildrenItem_ != nullptr) return false;
			else return true;
		}
	else //if type ==  SIN COS TAN ABS EXP SQRT ACOS ASIN ATAN COSH LOG LOG10 SINH TANH 
		{
			if(this->centerChildrenItem_ == nullptr) return false;
			else return true;
		}
	
return false;
}
