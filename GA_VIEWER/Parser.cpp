#include "StdAfx.h"
#include "Parser.h"
ExprParser::Parser::Parser(void)
{
}

/************************************************************************************/
/************************************************************************************/
/****************************    Create Buffer    ***********************************/
/************************************************************************************/
/************************************************************************************/
void ExprParser::Parser::createBuffer(System::String^ expr)
{

	itemsBufferPosition_ = 0 ; 
	currentBracketPriority_ = 0 ; 
	maxBracketPriority_ = 0 ; 
	this->prevBracketPriorityBuffer_ = gcnew System::Collections::Generic::List<int>();
	this->prevBracketPriorityBuffer_->Add(0);
	this->initialBuffer_ = gcnew System::Collections::Generic::List<ParseItem^>();

	xItemsBuffer_ = gcnew System::Collections::Generic::List<ParseItem^>();
	yItemsBuffer_ = gcnew System::Collections::Generic::List<ParseItem^>();
	bool result = false; 


	this->expr_ = expr ; 

	result = this->checkBruckets();
	if (result == false) throw -1; 

	result = this->checkCharacters();
	if (result == false) throw -1; 
	
	result = this->checkCharactersDetailed();
	if (result == false) throw -1;


	this->createInitialBuffer(expr);

	result = this->checkInitialBuffer();
	if (result == false) throw -1; 


	this->currentBracketPriority_ = this->initialBuffer_[0]->getBracketPriority() ;
	this->createTree();

	//result = this->checkTree();
	//if (result == false) throw -1;

}

/************************************************************************************/
/************************************************************************************/
/****************************Create initial buffer***********************************/
/************************************************************************************/
/************************************************************************************/
void ExprParser::Parser::createInitialBuffer(System::String^ expr)
{
	ParseItem^ parseItem;
	int i = 0 ; 
	int len = expr->Length;
	System::String^ posStr = ""; 
	System::String^ pos3Str = "";
	System::String^ pos4Str = "";
	System::String^ tempNum = "";
	bool previousIsNum = false;
	this->currentBracketPriority_ = 0 ; 
	bool isNegative = false ; 
	bool firstNegativeInBracket = false ; 
	bool firstPositiveInBracket = false ; 

for(i = 0 ; i < len ; i++ )
	{
		
		if (i+1 <= this->expr_->Length ) posStr = expr->Substring(i,1);
		else posStr = "" ;
		if (i+3 <= this->expr_->Length ) pos3Str = expr->Substring(i,3);
		else pos3Str = "" ;
		if (i+4 <= this->expr_->Length ) pos4Str = expr->Substring(i,4);
		else pos4Str = "" ;

			/*****************************************************/
	if(posStr == "x")
			{
				if (previousIsNum == true)
					{
					parseItem = gcnew ParseItem(tempNum);
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}

				parseItem = gcnew ParseItem(ParseItem::NUMBER);
				parseItem->isX_ = true ; 
				parseItem->setBracketPriority(this->currentBracketPriority_);
				this->initialBuffer_->Add(parseItem);
				this->xItemsBuffer_->Add(parseItem);
				posStr = ""; 
			}

/*****************************************************/
	if(posStr == "y")
			{
				if (previousIsNum == true)
					{
					parseItem = gcnew ParseItem(tempNum);
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}

				parseItem = gcnew ParseItem(ParseItem::NUMBER);
				parseItem->isY_ = true; 
				parseItem->setBracketPriority(this->currentBracketPriority_);
				this->initialBuffer_->Add(parseItem);
				this->yItemsBuffer_->Add(parseItem);

				posStr = ""; 
			}

/*****************************************************/

		if(posStr == "+")
			{
				if (previousIsNum == true)
					{
					parseItem = gcnew ParseItem(tempNum );
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}

				if ( this->initialBuffer_->Count > 0 )
					if ( this->initialBuffer_[this->initialBuffer_->Count-1]->getBracketPriority() != this->currentBracketPriority_ )
											firstPositiveInBracket = true ; 

			if (i == 0 || firstNegativeInBracket == true)
				{
				previousIsNum = true;
				firstPositiveInBracket = false ; 
				tempNum = "+";
				posStr = ""; 
				}
			else
				{
				parseItem = gcnew ParseItem(ParseItem::ADD);
				parseItem->setBracketPriority(this->currentBracketPriority_);
				initialBuffer_->Add(parseItem);
				posStr = ""; 
				}
			}

/*****************************************************/

		if(posStr == "-")
			{
				if (previousIsNum == true)
					{
					parseItem = gcnew ParseItem(tempNum );
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}
				
				if ( this->initialBuffer_->Count > 0 )
				{
				firstNegativeInBracket = true ; 
				  for(int k = 0 ; k < this->initialBuffer_->Count; k++)
					if ( this->initialBuffer_[k]->getBracketPriority() == this->currentBracketPriority_ )
								firstNegativeInBracket = false ; 
				}

			if (i == 0 || firstNegativeInBracket == true)
				{
				previousIsNum = true;
				firstNegativeInBracket = false; 
				tempNum = "-";
				posStr = ""; 
				}
			else 
				{
				parseItem = gcnew ParseItem(ParseItem::SUBTR);
				parseItem->setBracketPriority(this->currentBracketPriority_);
				initialBuffer_->Add(parseItem);
				posStr = ""; 
				}
			}

/*****************************************************/

		if(posStr == "*")
			{
				if (previousIsNum == true)
					{
					parseItem = gcnew ParseItem(tempNum );
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}

				parseItem = gcnew ParseItem(ParseItem::MUL);
				parseItem->setBracketPriority(this->currentBracketPriority_);
				initialBuffer_->Add(parseItem);

				posStr = ""; 
			}

/*****************************************************/

		if(posStr == "/")
			{
				if (previousIsNum == true)
					{
					parseItem = gcnew ParseItem(tempNum );
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}

				parseItem = gcnew ParseItem(ParseItem::DIV);
				parseItem->setBracketPriority(this->currentBracketPriority_);
				initialBuffer_->Add(parseItem);

				posStr = ""; 
			}

/*****************************************************/

		if(posStr == "^")
			{
				if (previousIsNum == true)
					{
					parseItem = gcnew ParseItem(tempNum);
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}

				parseItem = gcnew ParseItem(ParseItem::POW);
				parseItem->setBracketPriority(this->currentBracketPriority_);
				initialBuffer_->Add(parseItem);

				posStr = ""; 
			}

/**************************************************/
		if(pos4Str == "sqrt")
			{
				pos3Str = "";
				if (previousIsNum == true && tempNum != "-")
					{
					parseItem = gcnew ParseItem(tempNum);
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}

				else if (previousIsNum == true && tempNum == "-")
					{
					isNegative = true ; 
					previousIsNum = false ; 
					tempNum = ""; 
					} 
				
				parseItem = gcnew ParseItem(ParseItem::SQRT);
				parseItem->setBracketPriority(this->currentBracketPriority_);
				parseItem->isNegative_ = isNegative ; 
				isNegative = false ; 
				initialBuffer_->Add(parseItem);

				i=i+3;

				posStr = ""; 
				pos4Str = ""; 
			}

/**************************************************/

		if(pos4Str == "acos")
			{
				pos3Str = "";
				if (previousIsNum == true && tempNum != "-")
					{
					parseItem = gcnew ParseItem(tempNum);
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}

				else if (previousIsNum == true && tempNum == "-")
					{
					isNegative = true ; 
					previousIsNum = false ; 
					tempNum = ""; 
					} 
				
				parseItem = gcnew ParseItem(ParseItem::ACOS);
				parseItem->setBracketPriority(this->currentBracketPriority_);
				parseItem->isNegative_ = isNegative ; 
				isNegative = false ; 
				initialBuffer_->Add(parseItem);

				i=i+3;

				posStr = ""; 
				pos4Str = ""; 
			}

/**************************************************/

		if(pos4Str == "asin")
			{
				pos3Str = "";
				if (previousIsNum == true && tempNum != "-")
					{
					parseItem = gcnew ParseItem(tempNum);
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}

				else if (previousIsNum == true && tempNum == "-")
					{
					isNegative = true ; 
					previousIsNum = false ; 
					tempNum = ""; 
					} 
				
				parseItem = gcnew ParseItem(ParseItem::ASIN);
				parseItem->setBracketPriority(this->currentBracketPriority_);
				parseItem->isNegative_ = isNegative ; 
				isNegative = false ; 
				initialBuffer_->Add(parseItem);

				i=i+3;

				posStr = ""; 
				pos4Str = ""; 
			}

/**************************************************/

		if(pos4Str == "atan")
			{
				pos3Str = "";
				if (previousIsNum == true && tempNum != "-")
					{
					parseItem = gcnew ParseItem(tempNum);
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}

				else if (previousIsNum == true && tempNum == "-")
					{
					isNegative = true ; 
					previousIsNum = false ; 
					tempNum = ""; 
					} 
				
				parseItem = gcnew ParseItem(ParseItem::ATAN);
				parseItem->setBracketPriority(this->currentBracketPriority_);
				parseItem->isNegative_ = isNegative ; 
				isNegative = false ; 
				initialBuffer_->Add(parseItem);

				i=i+3;

				posStr = ""; 
				pos4Str = ""; 
			}

/**************************************************/

		if(pos4Str == "cosh")
			{
				pos3Str = "";
				if (previousIsNum == true && tempNum != "-")
					{
					parseItem = gcnew ParseItem(tempNum);
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}

				else if (previousIsNum == true && tempNum == "-")
					{
					isNegative = true ; 
					previousIsNum = false ; 
					tempNum = ""; 
					} 
				
				parseItem = gcnew ParseItem(ParseItem::COSH);
				parseItem->setBracketPriority(this->currentBracketPriority_);
				parseItem->isNegative_ = isNegative ; 
				isNegative = false ; 
				initialBuffer_->Add(parseItem);

				i=i+3;

				posStr = ""; 
				pos4Str = ""; 
			}

/**************************************************/

		if(pos4Str == "logt")
			{
				pos3Str = "";
				if (previousIsNum == true && tempNum != "-")
					{
					parseItem = gcnew ParseItem(tempNum);
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}

				else if (previousIsNum == true && tempNum == "-")
					{
					isNegative = true ; 
					previousIsNum = false ; 
					tempNum = ""; 
					} 
				
				parseItem = gcnew ParseItem(ParseItem::LOG10);
				parseItem->setBracketPriority(this->currentBracketPriority_);
				parseItem->isNegative_ = isNegative ; 
				isNegative = false ; 
				initialBuffer_->Add(parseItem);

				i=i+3;

				posStr = ""; 
				pos4Str = ""; 
			}

/**************************************************/

		if(pos4Str == "sinh")
			{
				pos3Str = "";
				if (previousIsNum == true && tempNum != "-")
					{
					parseItem = gcnew ParseItem(tempNum);
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}

				else if (previousIsNum == true && tempNum == "-")
					{
					isNegative = true ; 
					previousIsNum = false ; 
					tempNum = ""; 
					} 
				
				parseItem = gcnew ParseItem(ParseItem::SINH);
				parseItem->setBracketPriority(this->currentBracketPriority_);
				parseItem->isNegative_ = isNegative ; 
				isNegative = false ; 
				initialBuffer_->Add(parseItem);

				i=i+3;

				posStr = ""; 
				pos4Str = ""; 
			}

/**************************************************/

		if(pos4Str == "tanh")
			{
				pos3Str = "";
				if (previousIsNum == true && tempNum != "-")
					{
					parseItem = gcnew ParseItem(tempNum);
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}

				else if (previousIsNum == true && tempNum == "-")
					{
					isNegative = true ; 
					previousIsNum = false ; 
					tempNum = ""; 
					} 
				
				parseItem = gcnew ParseItem(ParseItem::TANH);
				parseItem->setBracketPriority(this->currentBracketPriority_);
				parseItem->isNegative_ = isNegative ; 
				isNegative = false ; 
				initialBuffer_->Add(parseItem);

				i=i+3;

				posStr = ""; 
				pos4Str = ""; 
			}

/**************************************************/

		if(posStr == "e")
			{
				if (previousIsNum == true && tempNum != "-")
					{
					parseItem = gcnew ParseItem(tempNum);
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}
				else if (previousIsNum == true && tempNum == "-")
					{
					isNegative = true ; 
					previousIsNum = false ; 
					tempNum = ""; 
					} 
			
				parseItem = gcnew ParseItem(ParseItem::EXP);
				parseItem->setBracketPriority(this->currentBracketPriority_);
				parseItem->isNegative_ = isNegative ; 
				isNegative = false ; 
				initialBuffer_->Add(parseItem);

				posStr = ""; 
			}

/**************************************************/

		if(pos3Str == "abs")
			{
				if (previousIsNum == true && tempNum != "-")
					{
					parseItem = gcnew ParseItem(tempNum);
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}
				else if (previousIsNum == true && tempNum == "-")
					{
					isNegative = true ; 
					previousIsNum = false ; 
					tempNum = ""; 
					} 
			
				parseItem = gcnew ParseItem(ParseItem::ABS);
				parseItem->setBracketPriority(this->currentBracketPriority_);
				parseItem->isNegative_ = isNegative ; 
				isNegative = false ; 
				initialBuffer_->Add(parseItem);

				i=i+2;

				posStr = ""; 
				pos3Str = ""; 
			}

/**************************************************/

		if(pos3Str == "tan")
			{
				if (previousIsNum == true && tempNum != "-")
					{
					parseItem = gcnew ParseItem(tempNum);
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}
				else if (previousIsNum == true && tempNum == "-")
					{
					isNegative = true ; 
					previousIsNum = false ; 
					tempNum = ""; 
					} 
				
				parseItem = gcnew ParseItem(ParseItem::TAN);
				parseItem->setBracketPriority(this->currentBracketPriority_);
				parseItem->isNegative_ = isNegative ; 
				isNegative = false ; 
				initialBuffer_->Add(parseItem);

				i=i+2;

				posStr = ""; 
				pos3Str = ""; 
			}

/**************************************************/

		if(pos3Str == "cos")
			{
				if (previousIsNum == true && tempNum != "-")
					{
					parseItem = gcnew ParseItem(tempNum);
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}
				else if (previousIsNum == true && tempNum == "-")
					{
					isNegative = true ; 
					previousIsNum = false ; 
					tempNum = ""; 
					}  
				
				parseItem = gcnew ParseItem(ParseItem::COS);
				parseItem->setBracketPriority(this->currentBracketPriority_);
				parseItem->isNegative_ = isNegative ; 
				isNegative = false ; 
				initialBuffer_->Add(parseItem);

				i=i+2;

				posStr = ""; 
				pos3Str = ""; 
			}

/**************************************************/

		if(pos3Str == "sin")
			{
				if (previousIsNum == true && tempNum != "-")
					{
					parseItem = gcnew ParseItem(tempNum);
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}
				else if (previousIsNum == true && tempNum == "-")
					{
					isNegative = true ; 
					previousIsNum = false ; 
					tempNum = ""; 
					}  
				
				parseItem = gcnew ParseItem(ParseItem::SIN);
				parseItem->setBracketPriority(this->currentBracketPriority_);
				parseItem->isNegative_ = isNegative ; 
				isNegative = false ; 
				initialBuffer_->Add(parseItem);

				i=i+2;

				posStr = ""; 
				pos3Str = ""; 
			}

/**************************************************/

if(pos3Str == "log")
			{
				if (previousIsNum == true && tempNum != "-")
					{
					parseItem = gcnew ParseItem(tempNum);
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}
				else if (previousIsNum == true && tempNum == "-")
					{
					isNegative = true ; 
					previousIsNum = false ; 
					tempNum = ""; 
					}  
				
				parseItem = gcnew ParseItem(ParseItem::LOG);
				parseItem->setBracketPriority(this->currentBracketPriority_);
				parseItem->isNegative_ = isNegative ; 
				isNegative = false ; 
				initialBuffer_->Add(parseItem);

				i=i+2;

				posStr = ""; 
				pos3Str = ""; 
			}

/**************************************************/

		if(posStr == "(")
			{
				if (previousIsNum == true  && tempNum != "-")
					{
					parseItem = gcnew ParseItem(tempNum);
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}
				else if (previousIsNum == true && tempNum == "-")
					{ 
					previousIsNum = false ; 
					tempNum = ""; 

					parseItem = gcnew ParseItem(ParseItem::BRACKET_OPEN);
					parseItem->setBracketPriority(this->currentBracketPriority_);
					parseItem->isNegative_ = true ;  
					initialBuffer_->Add(parseItem);
					} 


				this->prevBracketPriorityBuffer_->Add( this->currentBracketPriority_);
				this->maxBracketPriority_ ++ ; 
				this->currentBracketPriority_ = this->maxBracketPriority_  ; 

				posStr = ""; 
			}

/**************************************************/

		if(posStr == ")")
			{
				if (previousIsNum == true)
					{
					parseItem = gcnew ParseItem(tempNum);
					parseItem->setBracketPriority(this->currentBracketPriority_);
					initialBuffer_->Add(parseItem);

					previousIsNum = false ; 
					tempNum = ""; 
					}

				//this->currentBracketPriority_ = this->prevBracketPriorityBuffer_->back();
				//this->prevBracketPriorityBuffer_->pop_back(); 
				this->currentBracketPriority_ =  this->prevBracketPriorityBuffer_[ this->prevBracketPriorityBuffer_->Count - 1 ] ; 
				this->prevBracketPriorityBuffer_->RemoveAt( this->prevBracketPriorityBuffer_->Count - 1 );



				posStr = ""; 
			}
			
/**************************************************/

		if(posStr == "0" || posStr == "1" || posStr == "2" || posStr == "3" || posStr == "4" || posStr == "5" || posStr == "6" || posStr == "7" || posStr == "8" || posStr == "9" || posStr == ".")
			{
			tempNum = tempNum + posStr ;
			previousIsNum = true ; 
			posStr = "";
			}

	posStr = "";
	}

	if (previousIsNum == true)
			{
			parseItem = gcnew ParseItem(tempNum);
			parseItem->setBracketPriority(this->currentBracketPriority_);
			initialBuffer_->Add(parseItem);
			} 
}

/************************************************************************************/
/************************************************************************************/
/****************************Print initial buffer ***********************************/
/************************************************************************************/
/************************************************************************************/
void ExprParser::Parser::printInitialBuffer()
{
/*	int i = 0 ; 
	cout << endl << endl ; 
	cout << "Initial buffer" << endl ;
	for (i = 0 ;  i < this->initialBuffer_->Count; i++)
		{
			if(this->initialBuffer_[i]->type_ == ParseItem::ADD)
				cout << " +(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

			if(this->initialBuffer_[i]->type_ == ParseItem::DIV)
				cout << " /(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

			if(this->initialBuffer_[i]->type_ == ParseItem::MUL)
				cout << " *(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

			if(this->initialBuffer_[i]->type_ == ParseItem::SUBTR)
				cout << " -(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

			if(this->initialBuffer_[i]->type_ == ParseItem::POW)
				cout << " ^(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

			if(this->initialBuffer_[i]->type_ == ParseItem::BRACKET_OPEN && this->initialBuffer_[i]->isNegative_ == false )
				cout << " ((" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

			if(this->initialBuffer_[i]->type_ == ParseItem::ABS && this->initialBuffer_[i]->isNegative_ == false )
				cout << " abs(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;
					
			if(this->initialBuffer_[i]->type_ == ParseItem::SIN && this->initialBuffer_[i]->isNegative_ == false )
				cout << " sin(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;
					
			if(this->initialBuffer_[i]->type_ == ParseItem::COS && this->initialBuffer_[i]->isNegative_ == false )
				cout << " cos(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;
							
			if(this->initialBuffer_[i]->type_ == ParseItem::TAN && this->initialBuffer_[i]->isNegative_ == false )
				cout << " tan(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

			if(this->initialBuffer_[i]->type_ == ParseItem::EXP && this->initialBuffer_[i]->isNegative_ == false )
				cout << " exp(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;
					
			if(this->initialBuffer_[i]->type_ == ParseItem::SQRT && this->initialBuffer_[i]->isNegative_ == false )
				cout << " sqrt(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;




if(this->initialBuffer_[i]->type_ == ParseItem::ACOS && this->initialBuffer_[i]->isNegative_ == false )
				cout << " acos(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

if(this->initialBuffer_[i]->type_ == ParseItem::ASIN && this->initialBuffer_[i]->isNegative_ == false )
				cout << " asin(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

if(this->initialBuffer_[i]->type_ == ParseItem::ATAN && this->initialBuffer_[i]->isNegative_ == false )
				cout << " atan(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

if(this->initialBuffer_[i]->type_ == ParseItem::COSH && this->initialBuffer_[i]->isNegative_ == false )
				cout << " cosh(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

if(this->initialBuffer_[i]->type_ == ParseItem::LOG && this->initialBuffer_[i]->isNegative_ == false )
				cout << " log(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

if(this->initialBuffer_[i]->type_ == ParseItem::LOG10 && this->initialBuffer_[i]->isNegative_ == false )
				cout << " logt(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

if(this->initialBuffer_[i]->type_ == ParseItem::SINH && this->initialBuffer_[i]->isNegative_ == false )
				cout << " sinh(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

if(this->initialBuffer_[i]->type_ == ParseItem::TANH && this->initialBuffer_[i]->isNegative_ == false )
				cout << " tanh(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;






			if(this->initialBuffer_[i]->type_ == ParseItem::BRACKET_OPEN && this->initialBuffer_[i]->isNegative_ == true )
				cout << " -((" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

			if(this->initialBuffer_[i]->type_ == ParseItem::ABS && this->initialBuffer_[i]->isNegative_ == true )
				cout << " -abs(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;
					
			if(this->initialBuffer_[i]->type_ == ParseItem::SIN && this->initialBuffer_[i]->isNegative_ == true )
				cout << " -sin(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;
					
			if(this->initialBuffer_[i]->type_ == ParseItem::COS && this->initialBuffer_[i]->isNegative_ == true )
				cout << " -cos(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;
							
			if(this->initialBuffer_[i]->type_ == ParseItem::TAN && this->initialBuffer_[i]->isNegative_ == true )
				cout << " -tan(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

			if(this->initialBuffer_[i]->type_ == ParseItem::EXP && this->initialBuffer_[i]->isNegative_ == true )
				cout << " -exp(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;
					
			if(this->initialBuffer_[i]->type_ == ParseItem::SQRT && this->initialBuffer_[i]->isNegative_ == true )
				cout << " -sqrt(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;



		if(this->initialBuffer_[i]->type_ == ParseItem::ACOS && this->initialBuffer_[i]->isNegative_ == true )
				cout << " -acos(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

if(this->initialBuffer_[i]->type_ == ParseItem::ASIN && this->initialBuffer_[i]->isNegative_ == true )
				cout << " -asin(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

if(this->initialBuffer_[i]->type_ == ParseItem::ATAN && this->initialBuffer_[i]->isNegative_ == true )
				cout << " -atan(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

if(this->initialBuffer_[i]->type_ == ParseItem::COSH && this->initialBuffer_[i]->isNegative_ == true )
				cout << " -cosh(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

if(this->initialBuffer_[i]->type_ == ParseItem::LOG && this->initialBuffer_[i]->isNegative_ == true )
				cout << " -log(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

if(this->initialBuffer_[i]->type_ == ParseItem::LOG10 && this->initialBuffer_[i]->isNegative_ == true )
				cout << " -logt(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

if(this->initialBuffer_[i]->type_ == ParseItem::SINH && this->initialBuffer_[i]->isNegative_ == true )
				cout << " -sinh(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;

if(this->initialBuffer_[i]->type_ == ParseItem::TANH && this->initialBuffer_[i]->isNegative_ == true )
				cout << " -tanh(" << this->initialBuffer_[i]->getBracketPriority() << ")" ;


			if(this->initialBuffer_[i]->type_ == ParseItem::NUMBER)
				cout <<" "<< this->initialBuffer_[i]->numberStr_ <<"("<<this->initialBuffer_[i]->getBracketPriority() << ")" ;


		}

	cout << endl << endl ;
	*/
}

/************************************************************************************/
/************************************************************************************/
/************************* initialBufferToItemsBuffer *******************************/
/************************************************************************************/
/************************************************************************************/
void ExprParser::Parser::createTree()
{
int i = 0 ; 
int currentBracketPriority = this->currentBracketPriority_ ;
int len = this->initialBuffer_->Count;


//Search for SIN COS TAN SQRT ABS EXP ACOS ASIN ATAN COSH LOG LOG10 SINH TANH
		for( i = 0 ; i < len ; i++ )
			{
				if ( 
							( this->initialBuffer_[i]->type_ == ParseItem::SIN || this->initialBuffer_[i]->type_ == ParseItem::COS || 
								this->initialBuffer_[i]->type_ == ParseItem::TAN || this->initialBuffer_[i]->type_ == ParseItem::ABS || 
								this->initialBuffer_[i]->type_ == ParseItem::EXP || this->initialBuffer_[i]->type_ == ParseItem::SQRT ||
								this->initialBuffer_[i]->type_ == ParseItem::ACOS || this->initialBuffer_[i]->type_ == ParseItem::ASIN ||
								this->initialBuffer_[i]->type_ == ParseItem::ATAN || this->initialBuffer_[i]->type_ == ParseItem::COSH ||
								this->initialBuffer_[i]->type_ == ParseItem::LOG || this->initialBuffer_[i]->type_ == ParseItem::LOG10 ||
								this->initialBuffer_[i]->type_ == ParseItem::SINH || this->initialBuffer_[i]->type_ == ParseItem::TANH ||
								this->initialBuffer_[i]->type_ == ParseItem::BRACKET_OPEN
							)
					&& this->initialBuffer_[i]->getBracketPriority() == currentBracketPriority
				  )
					{

					   if( (i+1) < len)
					    {
							this->currentBracketPriority_ = this->initialBuffer_[i+1]->getBracketPriority() ;
							this->createTree();
							this->currentBracketPriority_ = currentBracketPriority ;  
					   }	

							this->initialBuffer_[i]->mark_ = true;
							
							this->baseParseItem_ = this->initialBuffer_[i];
							this->initialBuffer_[i]->centerChildrenItem_ = this->getUpperLayerItem(i+1);
							(this->getUpperLayerItem(i+1))->parentItem_ = this->initialBuffer_[i];
					}
			}


		//Search for POWER
		for( i = 0 ; i < len ; i++ )
			{
				if (this->initialBuffer_[i]->type_ == ParseItem::POW && this->initialBuffer_[i]->getBracketPriority() == currentBracketPriority)
					{
					   if ( (i-1) >= 0)
						{
						if (this->initialBuffer_[i-1]->mark_ == false && this->initialBuffer_[i-1]->getBracketPriority() == currentBracketPriority ) // Normal case , if it is not yet selected and on
							{
							this->initialBuffer_[i-1]->mark_ = true;
							}
						else if ( this->initialBuffer_[i-1]->getBracketPriority() !=  currentBracketPriority )
							{
							this->currentBracketPriority_ = this->initialBuffer_[i-1]->getBracketPriority() ;
							this->createTree();
							this->currentBracketPriority_ = currentBracketPriority ;  
							}
					   }

					   if( (i+1) < len)
					    {
						if (this->initialBuffer_[i+1]->mark_ == false && this->initialBuffer_[i+1]->getBracketPriority() ==  currentBracketPriority)
							{
							this->initialBuffer_[i+1]->mark_ = true;
							}


						else if ( this->initialBuffer_[i+1]->getBracketPriority() !=  currentBracketPriority )
							{
							this->currentBracketPriority_ = this->initialBuffer_[i+1]->getBracketPriority() ;
							this->createTree();
							this->currentBracketPriority_ = currentBracketPriority ;  
							}
					   }	

						this->initialBuffer_[i]->mark_ = true;
							
						this->baseParseItem_ = this->initialBuffer_[i];
						this->initialBuffer_[i]->rightChildrenItem_ = this->getUpperLayerItem(i-1);
						this->initialBuffer_[i]->leftChildrenItem_  = this->getUpperLayerItem(i+1);
						(this->getUpperLayerItem(i-1))->parentItem_ = this->initialBuffer_[i];
						(this->getUpperLayerItem(i+1))->parentItem_ = this->initialBuffer_[i];
					}
			}


		//Search for MUL , DIV
		for( i = 0 ; i < len ; i++ )
			{
			if (   (  (this->initialBuffer_[i]->type_ == ParseItem::MUL) || (this->initialBuffer_[i]->type_ == ParseItem::DIV) ) && this->initialBuffer_[i]->getBracketPriority() == currentBracketPriority  )
				{
					  if ( (i-1) >= 0)
					   {
						if (this->initialBuffer_[i-1]->mark_ == false && this->initialBuffer_[i-1]->getBracketPriority() ==  currentBracketPriority )
							{
							this->initialBuffer_[i-1]->mark_ = true;
							}
						else if ( this->initialBuffer_[i-1]->getBracketPriority() !=  currentBracketPriority )
							{
							this->currentBracketPriority_ = this->initialBuffer_[i-1]->getBracketPriority() ;
							this->createTree();
							this->currentBracketPriority_ = currentBracketPriority ;  
							}
					  }

					 if( (i+1) < len)
					  {
						if (this->initialBuffer_[i+1]->mark_ == false && this->initialBuffer_[i+1]->getBracketPriority() ==  currentBracketPriority )
							{
							this->initialBuffer_[i+1]->mark_ = true;
							}
						else if ( this->initialBuffer_[i+1]->getBracketPriority() !=  currentBracketPriority )
							{
							this->currentBracketPriority_ = this->initialBuffer_[i+1]->getBracketPriority() ;
							this->createTree();
							this->currentBracketPriority_ = currentBracketPriority ; 
							}
					  }

						this->initialBuffer_[i]->mark_ = true;
							
						this->baseParseItem_ = this->initialBuffer_[i];
						this->initialBuffer_[i]->rightChildrenItem_ = this->getUpperLayerItem(i-1);
						this->initialBuffer_[i]->leftChildrenItem_  = this->getUpperLayerItem(i+1);
						(this->getUpperLayerItem(i-1))->parentItem_ = this->initialBuffer_[i];
						(this->getUpperLayerItem(i+1))->parentItem_ = this->initialBuffer_[i];

				}
			}




		//Search for ADD , SUBTR
		for( i = 0 ; i < len ; i++ )
			{
			if ( (  (this->initialBuffer_[i]->type_ == ParseItem::ADD) || (this->initialBuffer_[i]->type_ == ParseItem::SUBTR) ) && this->initialBuffer_[i]->getBracketPriority() == currentBracketPriority  )
				{
					  if ( (i-1) >= 0)
					   {
						if (this->initialBuffer_[i-1]->mark_ == false && this->initialBuffer_[i-1]->getBracketPriority() ==  currentBracketPriority )
							{
							this->initialBuffer_[i-1]->mark_ = true;
							}
						else if ( this->initialBuffer_[i-1]->getBracketPriority() !=  currentBracketPriority )
							{
							this->currentBracketPriority_ = this->initialBuffer_[i-1]->getBracketPriority() ;
							this->createTree();
							this->currentBracketPriority_ = currentBracketPriority ;  
							}
					  }

					if( (i+1) < len)				
					  {
						if (this->initialBuffer_[i+1]->mark_ == false && this->initialBuffer_[i+1]->getBracketPriority() ==  currentBracketPriority )
							{
							this->initialBuffer_[i+1]->mark_ = true;
							}
						else if ( this->initialBuffer_[i+1]->getBracketPriority() !=  currentBracketPriority )
							{
							this->currentBracketPriority_ = this->initialBuffer_[i+1]->getBracketPriority() ;
							this->createTree();
							this->currentBracketPriority_ = currentBracketPriority ;  
							}
					  }
						this->initialBuffer_[i]->mark_ = true;
							
						this->baseParseItem_ = this->initialBuffer_[i];
						this->initialBuffer_[i]->rightChildrenItem_ = this->getUpperLayerItem(i-1);
						this->initialBuffer_[i]->leftChildrenItem_  = this->getUpperLayerItem(i+1);
						(this->getUpperLayerItem(i-1))->parentItem_ = this->initialBuffer_[i];
						(this->getUpperLayerItem(i+1))->parentItem_ = this->initialBuffer_[i];
				}
			}


//Search for remained NUMBER
		for( i = 0 ; i < len ; i++ )
			{
				if ( (this->initialBuffer_[i]->type_ == ParseItem::NUMBER)  && this->initialBuffer_[i]->getBracketPriority() == currentBracketPriority  )
					{

						if (this->initialBuffer_[i]->mark_ == false )
							{
							this->initialBuffer_[i]->mark_ = true;

							this->baseParseItem_ = this->initialBuffer_[i];
							}

					}
			}


}


ExprParser::ParseItem^ ExprParser::Parser::getUpperLayerItem(int pos)
{
ParseItem^ uperItem ;
uperItem = this->initialBuffer_[pos];

	while(true)
		{
		if(uperItem->parentItem_ == nullptr ) return uperItem;
		else uperItem = uperItem->parentItem_;
		}
}
/************************************************************************************/
/************************************************************************************/
/*****************************Print items Buffer ************************************/
/************************************************************************************/
/************************************************************************************/
/*void ExprParser::Parser::printItemsBuffer()
{
 	int i = 0 ; 

	cout << endl << endl ; 
	cout << "Items buffer"<<endl;

	
	for(i = 0 ; i < this->itemsBuffer_->Count ; i++ )
		{
			if(this->itemsBuffer_[i]->type_ == ParseItem::ADD)
				cout << "+" ;

			if(this->itemsBuffer_[i]->type_ == ParseItem::DIV)
				cout << "/" ;

			if(this->itemsBuffer_[i]->type_ == ParseItem::MUL)
				cout << "*" ;

			if(this->itemsBuffer_[i]->type_ == ParseItem::SUBTR)
				cout << "-" ;

			if(this->itemsBuffer_[i]->type_ == ParseItem::POW)
				cout << "^" ;

//*********************************************************************************
			if(this->itemsBuffer_[i]->type_ == ParseItem::BRACKET_OPEN && this->itemsBuffer_[i]->isNegative_ == false)
				cout << " (" ;

			if(this->itemsBuffer_[i]->type_ == ParseItem::SIN && this->itemsBuffer_[i]->isNegative_ == false)
				cout << "sin" ;

			if(this->itemsBuffer_[i]->type_ == ParseItem::COS && this->itemsBuffer_[i]->isNegative_ == false)
				cout << "cos" ;

			if(this->itemsBuffer_[i]->type_ == ParseItem::TAN && this->itemsBuffer_[i]->isNegative_ == false)
				cout << "tan" ;

			if(this->itemsBuffer_[i]->type_ == ParseItem::EXP && this->itemsBuffer_[i]->isNegative_ == false)
				cout << "exp" ;

			if(this->itemsBuffer_[i]->type_ == ParseItem::ABS && this->itemsBuffer_[i]->isNegative_ == false)
				cout << "abs" ;

			if(this->itemsBuffer_[i]->type_ == ParseItem::SQRT && this->itemsBuffer_[i]->isNegative_ == false)
				cout << "sqrt" ;


if(this->itemsBuffer_[i]->type_ == ParseItem::ACOS && this->itemsBuffer_[i]->isNegative_ == false)
				cout << "acos" ;

if(this->itemsBuffer_[i]->type_ == ParseItem::ASIN && this->itemsBuffer_[i]->isNegative_ == false)
				cout << "asin" ;

if(this->itemsBuffer_[i]->type_ == ParseItem::ATAN && this->itemsBuffer_[i]->isNegative_ == false)
				cout << "atan" ;

if(this->itemsBuffer_[i]->type_ == ParseItem::COSH && this->itemsBuffer_[i]->isNegative_ == false)
				cout << "cosh" ;

if(this->itemsBuffer_[i]->type_ == ParseItem::LOG && this->itemsBuffer_[i]->isNegative_ == false)
				cout << "log" ;

if(this->itemsBuffer_[i]->type_ == ParseItem::LOG10 && this->itemsBuffer_[i]->isNegative_ == false)
				cout << "logt" ;

if(this->itemsBuffer_[i]->type_ == ParseItem::SINH && this->itemsBuffer_[i]->isNegative_ == false)
				cout << "sinh" ;

if(this->itemsBuffer_[i]->type_ == ParseItem::TANH && this->itemsBuffer_[i]->isNegative_ == false)
				cout << "tanh" ;



//*********************************************************************************
			if(this->itemsBuffer_[i]->type_ == ParseItem::BRACKET_OPEN && this->itemsBuffer_[i]->isNegative_ == true)
				cout << " -(" ;

			if(this->itemsBuffer_[i]->type_ == ParseItem::SIN && this->itemsBuffer_[i]->isNegative_ == true)
				cout << "-sin" ;

			if(this->itemsBuffer_[i]->type_ == ParseItem::COS && this->itemsBuffer_[i]->isNegative_ == true)
				cout << "-cos" ;

			if(this->itemsBuffer_[i]->type_ == ParseItem::TAN && this->itemsBuffer_[i]->isNegative_ == true)
				cout << "-tan" ;

			if(this->itemsBuffer_[i]->type_ == ParseItem::EXP && this->itemsBuffer_[i]->isNegative_ == true)
				cout << "-exp" ;

			if(this->itemsBuffer_[i]->type_ == ParseItem::ABS && this->itemsBuffer_[i]->isNegative_ == true)
				cout << "-abs" ;

			if(this->itemsBuffer_[i]->type_ == ParseItem::SQRT && this->itemsBuffer_[i]->isNegative_ == true)
				cout << "-sqrt" ;


if(this->itemsBuffer_[i]->type_ == ParseItem::ACOS && this->itemsBuffer_[i]->isNegative_ == true)
				cout << "-acos" ;

if(this->itemsBuffer_[i]->type_ == ParseItem::ASIN && this->itemsBuffer_[i]->isNegative_ == true)
				cout << "-asin" ;

if(this->itemsBuffer_[i]->type_ == ParseItem::ATAN && this->itemsBuffer_[i]->isNegative_ == true)
				cout << "-atan" ;

if(this->itemsBuffer_[i]->type_ == ParseItem::COSH && this->itemsBuffer_[i]->isNegative_ == true)
				cout << "-cosh" ;

if(this->itemsBuffer_[i]->type_ == ParseItem::LOG && this->itemsBuffer_[i]->isNegative_ == true)
				cout << "-log" ;

if(this->itemsBuffer_[i]->type_ == ParseItem::LOG10 && this->itemsBuffer_[i]->isNegative_ == true)
				cout << "-logt" ;

if(this->itemsBuffer_[i]->type_ == ParseItem::SINH && this->itemsBuffer_[i]->isNegative_ == true)
				cout << "-sinh" ;

if(this->itemsBuffer_[i]->type_ == ParseItem::TANH && this->itemsBuffer_[i]->isNegative_ == true)
				cout << "-tanh" ;


			if(this->itemsBuffer_[i]->type_ == ParseItem::NUMBER)
				cout << this->itemsBuffer_[i]->numberStr_ ;

			if(this->itemsBuffer_[i]->isPrior_ == true )
				cout << " (Prior)";

		cout << endl;

				
		}

	cout << endl << endl ;
}

*/

/************************************************************************************/
/************************************************************************************/
/**********************************Calculate*****************************************/
/************************************************************************************/
/************************************************************************************/
double ExprParser::Parser::calculate(ParseItem^ baseParseItem)
{
	double result  ; 
	double number1 ; 
	double number2 ;   

try{



	//Action 1 if this item is a number (no branches)  
	if (baseParseItem->type_ == ParseItem::NUMBER)
		{
			return baseParseItem->number_ ; 
		}



	//Action 2 if this item DIV MUL ADD SUBTR POW (2 possible branches)
	else if (     baseParseItem->type_ == ParseItem::ADD  || 
			      baseParseItem->type_ == ParseItem::SUBTR  ||
				  baseParseItem->type_ == ParseItem::MUL  ||
				  baseParseItem->type_ == ParseItem::DIV  ||
				  baseParseItem->type_ == ParseItem::POW  )
		{
				  											

			if(baseParseItem->rightChildrenItem_->type_ == ParseItem::NUMBER )
				{
				number1 =baseParseItem->rightChildrenItem_->number_ ; 
				}
			else 
				{
				number1 = this->calculate(baseParseItem->rightChildrenItem_) ; 
				}


			if(baseParseItem->leftChildrenItem_->type_ == ParseItem::NUMBER )
				{
					number2 = baseParseItem->leftChildrenItem_->number_ ; 
				}
			else 
				{
				number2 = this->calculate(baseParseItem->leftChildrenItem_) ; 
				}
			result = baseParseItem->calculate(number1 , number2);
		}



	//Action 3 if this item DIV MUL ADD SUBTR POW (1 possible branches)
	else if (    baseParseItem->type_ == ParseItem::SQRT  || 
		baseParseItem->type_ == ParseItem::SIN  ||
		baseParseItem->type_ == ParseItem::COS ||
		baseParseItem->type_ == ParseItem::TAN ||
		baseParseItem->type_ == ParseItem::ABS ||
		baseParseItem->type_ == ParseItem::EXP ||
		baseParseItem->type_ == ParseItem::ACOS ||
		baseParseItem->type_ == ParseItem::ASIN ||
		baseParseItem->type_ == ParseItem::ATAN ||
		baseParseItem->type_ == ParseItem::COSH ||
		baseParseItem->type_ == ParseItem::LOG ||
		baseParseItem->type_ == ParseItem::LOG10 ||
		baseParseItem->type_ == ParseItem::SINH ||
		baseParseItem->type_ == ParseItem::TANH ||
		baseParseItem->type_ == ParseItem::BRACKET_OPEN
		)

		{
				  											
			if(baseParseItem->centerChildrenItem_->type_ == ParseItem::NUMBER )
				{
				number1 =baseParseItem->centerChildrenItem_->number_ ; 
				}
			else 
				{
				number1 = this->calculate(baseParseItem->centerChildrenItem_) ; 
				}

	
		result = baseParseItem->calculate(number1);
		}

	}catch(exception e){throw e;}

	return result;
}

/************************************************************************************/
/************************************************************************************/
/*************************      checkBruckets         *******************************/
/************************************************************************************/
/************************************************************************************/

bool ExprParser::Parser::checkBruckets()
{
int opened = 0 ; 
int closed = 0 ; 
int size = this->expr_->Length;
int i = 0 ; 
System::String^ charAtPos = ""; 

for (i=0; i<size; i++)
	{
		charAtPos = this->expr_->Substring(i,1);
		if (charAtPos == "(") opened++;
		if (charAtPos == ")") closed++;
	}

if (opened == closed) return true;
else return false;
}

/************************************************************************************/
/************************************************************************************/
/*************************     checkCharacters        *******************************/
/************************************************************************************/
/************************************************************************************/

bool ExprParser::Parser::checkCharacters()
{
int i ;
int size = this->expr_->Length;
System::String^ charAtPos = "";
 

for(i = 0 ; i < size ; i++)
	{
	charAtPos = this->expr_->Substring(i,1);
	if (charAtPos != "(" && charAtPos != ")" &&  charAtPos != "1" && charAtPos != "2" && charAtPos != "3" && charAtPos != "4" && charAtPos != "5" && charAtPos != "6" && charAtPos != "7" &&
		 charAtPos != "8" && charAtPos != "9" && charAtPos != "0" && charAtPos != "+" && charAtPos != "-" && charAtPos != "*" && charAtPos != "/" && charAtPos != "c" && charAtPos != "o" &&
		 charAtPos != "s" && charAtPos != "i" && charAtPos != "n" && charAtPos != "t" && charAtPos != "a" && charAtPos != "^" && charAtPos != "." && charAtPos != "q" && charAtPos != "r" &&
		 charAtPos != "x" && charAtPos != "y" && charAtPos != "b"&& charAtPos != "h" && charAtPos != "l" && charAtPos != "g" && charAtPos != "e" )
		{
		return false; 

	if (charAtPos != " " )
		return false; 

		}

	}
return true; 
}

/************************************************************************************/
/************************************************************************************/
/************************* checkInitialBuffer         *******************************/
/************************************************************************************/
/************************************************************************************/

bool ExprParser::Parser::checkInitialBuffer()
{
	int size = this->initialBuffer_->Count;
	int i = 0 ; 


	for(i = 0 ; i < size-1 ; i++)
		{
			if (this->initialBuffer_[i]->type_ == ParseItem::NUMBER && this->initialBuffer_[i+1]->type_ == ParseItem::NUMBER
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ; 

			if (this->initialBuffer_[i]->type_ == ParseItem::MUL && this->initialBuffer_[i+1]->type_ == ParseItem::MUL
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::DIV && this->initialBuffer_[i+1]->type_ == ParseItem::DIV
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::ADD && this->initialBuffer_[i+1]->type_ == ParseItem::ADD
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::SUBTR && this->initialBuffer_[i+1]->type_ == ParseItem::SUBTR
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::POW && this->initialBuffer_[i+1]->type_ == ParseItem::POW
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::COS && this->initialBuffer_[i+1]->type_ == ParseItem::COS
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::SIN && this->initialBuffer_[i+1]->type_ == ParseItem::SIN
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::TAN && this->initialBuffer_[i+1]->type_ == ParseItem::TAN
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::SQRT && this->initialBuffer_[i+1]->type_ == ParseItem::SQRT
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::ABS && this->initialBuffer_[i+1]->type_ == ParseItem::ABS
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::ACOS && this->initialBuffer_[i+1]->type_ == ParseItem::ACOS
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::ASIN && this->initialBuffer_[i+1]->type_ == ParseItem::ASIN
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::ATAN && this->initialBuffer_[i+1]->type_ == ParseItem::ATAN
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::COSH && this->initialBuffer_[i+1]->type_ == ParseItem::COSH
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::LOG && this->initialBuffer_[i+1]->type_ == ParseItem::LOG
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::LOG10 && this->initialBuffer_[i+1]->type_ == ParseItem::LOG10
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::SINH && this->initialBuffer_[i+1]->type_ == ParseItem::SINH
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::TANH && this->initialBuffer_[i+1]->type_ == ParseItem::TANH
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if ( this->initialBuffer_[i]->getBracketPriority() < this->initialBuffer_[i+1]->getBracketPriority() &&  //Example:  sin(*1)
				(this->initialBuffer_[i+1]->type_ == ParseItem::MUL || this->initialBuffer_[i+1]->type_ == ParseItem::DIV)	)return false;

			if ( this->initialBuffer_[i]->getBracketPriority() > this->initialBuffer_[i+1]->getBracketPriority() && //Example: sin(1-) , cos(1*)
				(this->initialBuffer_[i]->type_ == ParseItem::ADD || this->initialBuffer_[i]->type_ == ParseItem::SUBTR ||
				 this->initialBuffer_[i]->type_ == ParseItem::MUL || this->initialBuffer_[i]->type_ == ParseItem::DIV	|| 
				 this->initialBuffer_[i]->type_ == ParseItem::POW)  )return false;


			if (this->initialBuffer_[i]->type_ == ParseItem::ADD && this->initialBuffer_[i+1]->type_ == ParseItem::ADD
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;
			
			if (this->initialBuffer_[i]->type_ == ParseItem::ADD && this->initialBuffer_[i+1]->type_ == ParseItem::SUBTR
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::ADD && this->initialBuffer_[i+1]->type_ == ParseItem::MUL
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;
			
			if (this->initialBuffer_[i]->type_ == ParseItem::ADD && this->initialBuffer_[i+1]->type_ == ParseItem::DIV
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::ADD && this->initialBuffer_[i+1]->type_ == ParseItem::POW
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;


			
			if (this->initialBuffer_[i]->type_ == ParseItem::SUBTR && this->initialBuffer_[i+1]->type_ == ParseItem::ADD
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::SUBTR && this->initialBuffer_[i+1]->type_ == ParseItem::SUBTR
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::SUBTR && this->initialBuffer_[i+1]->type_ == ParseItem::MUL
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::SUBTR && this->initialBuffer_[i+1]->type_ == ParseItem::DIV
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::SUBTR && this->initialBuffer_[i+1]->type_ == ParseItem::POW
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;


			if (this->initialBuffer_[i]->type_ == ParseItem::MUL && this->initialBuffer_[i+1]->type_ == ParseItem::ADD
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;
			
			if (this->initialBuffer_[i]->type_ == ParseItem::MUL && this->initialBuffer_[i+1]->type_ == ParseItem::SUBTR
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::MUL && this->initialBuffer_[i+1]->type_ == ParseItem::MUL
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;
			
			if (this->initialBuffer_[i]->type_ == ParseItem::MUL && this->initialBuffer_[i+1]->type_ == ParseItem::DIV
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;
			
			if (this->initialBuffer_[i]->type_ == ParseItem::MUL && this->initialBuffer_[i+1]->type_ == ParseItem::POW
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;



			
			if (this->initialBuffer_[i]->type_ == ParseItem::DIV && this->initialBuffer_[i+1]->type_ == ParseItem::ADD
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::DIV && this->initialBuffer_[i+1]->type_ == ParseItem::SUBTR
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::DIV && this->initialBuffer_[i+1]->type_ == ParseItem::MUL
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::DIV && this->initialBuffer_[i+1]->type_ == ParseItem::DIV
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::DIV && this->initialBuffer_[i+1]->type_ == ParseItem::POW
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;



			if (this->initialBuffer_[i]->type_ == ParseItem::POW && this->initialBuffer_[i+1]->type_ == ParseItem::ADD
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::POW && this->initialBuffer_[i+1]->type_ == ParseItem::SUBTR
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::POW && this->initialBuffer_[i+1]->type_ == ParseItem::MUL
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::POW && this->initialBuffer_[i+1]->type_ == ParseItem::DIV
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;

			if (this->initialBuffer_[i]->type_ == ParseItem::POW && this->initialBuffer_[i+1]->type_ == ParseItem::POW
				&& this->initialBuffer_[i]->getBracketPriority() == this->initialBuffer_[i+1]->getBracketPriority()) return false ;


		}

			if(this->initialBuffer_[0]->type_ == ParseItem::MUL || this->initialBuffer_[0]->type_ == ParseItem::DIV ||
			   this->initialBuffer_[0]->type_ == ParseItem::POW ) return false;	

			if(this->initialBuffer_[ size-1]->type_ == ParseItem::ADD || this->initialBuffer_[ size-1]->type_ == ParseItem::SUBTR ||
			   this->initialBuffer_[ size-1]->type_ == ParseItem::MUL || this->initialBuffer_[ size-1]->type_ == ParseItem::DIV ||
			   this->initialBuffer_[ size-1]->type_ == ParseItem::POW ) return false; 

return true ; 
}

/************************************************************************************/
/************************************************************************************/
/************************* checkInitialBuffer         *******************************/
/************************************************************************************/
/************************************************************************************/
bool ExprParser::Parser::checkTree()
{
int i = 0 ; 
int size = this->initialBuffer_->Count;
for(i = 0; i < size ; i++)
	if(this->initialBuffer_[i]->checkChildrenItems() == false ) return false;

return true;
}

/************************************************************************************/
/************************************************************************************/
/*************************           setXY            *******************************/
/************************************************************************************/
/************************************************************************************/
void ExprParser::Parser::setXY(double x , double y)
{
int size = this->xItemsBuffer_->Count;
int i = 0 ; 

	for (i=0 ; i < size ; i++ )
		{
			this->xItemsBuffer_[i]->number_ = x ; 
		}

	size = this->yItemsBuffer_->Count;
		for (i=0 ; i < size ; i++ )
		{
			this->yItemsBuffer_[i]->number_ = y ; 
		}

}
/************************************************************************************/
/************************************************************************************/
/*************************  checkCharactersDetailed   *******************************/
/************************************************************************************/
/************************************************************************************/
bool ExprParser::Parser::checkCharactersDetailed()
{
int i =0 ; 
System::String^ posStr = "";
System::String^ pos4Str = ""; 
System::String^ pos5Str = "";
int len = this->expr_->Length;

for(i = 0 ; i < len ; i++ )
	{
		if (i+1 <= this->expr_->Length ) posStr = this->expr_->Substring(i,1);
		else posStr = "";

		if (i+4 <= this->expr_->Length ) pos4Str = this->expr_->Substring(i,4);
		else pos4Str = "";

		if (i+5 <= this->expr_->Length ) pos5Str = this->expr_->Substring(i,5);
		else pos5Str = "";


		if(pos5Str == "sqrt(" || pos5Str == "acos(" || pos5Str == "asin(" || pos5Str == "atan(" || pos5Str == "cosh(" || pos5Str == "logt(" || pos5Str == "sinh(" || pos5Str == "tanh(")
			{
			i=i+4;
			}

		else if(pos4Str == "abs(" || pos4Str == "tan(" || pos4Str == "cos(" || pos4Str == "sin(" || pos4Str == "log(")
			{
			i=i+3;
			}

		else if(posStr == "x" || posStr == "y" || posStr == "+" || posStr == "-" || posStr == "*" || posStr == "/" ||
			posStr == "^" || posStr == "e" || posStr == "(" || posStr == ")" ||
			posStr == "0" || posStr == "1" || posStr == "2" || posStr == "3" || posStr == "4" || posStr == "5" || posStr == "6" || posStr == "7" || 
			posStr == "8" || posStr == "9" || posStr == "."
			)
			{
		//	posStr = ""; 
			}

		else return false;
	}

return true;
}

/************************************************************************************/
/************************************************************************************/
/*************************  checkCharactersDetailed   *******************************/
/************************************************************************************/
/************************************************************************************/
bool ExprParser::Parser::validateExpression(System::String^ expr)
{
	bool result = false; 
	this->expr_ = expr ; 
	//cout << endl << expr << endl;

	if (expr_ == "") return false ;

	result = this->checkBruckets();
	if (result == false) return false; 

	result = this->checkCharacters();
	if (result == false)return false; 
	
	result = this->checkCharactersDetailed();
	if (result == false) return false;


	itemsBufferPosition_ = 0 ; 
	currentBracketPriority_ = 0 ; 
	maxBracketPriority_ = 0 ; 
	this->prevBracketPriorityBuffer_ = gcnew System::Collections::Generic::List<int>();
	this->prevBracketPriorityBuffer_->Add(0);
	this->initialBuffer_ = gcnew System::Collections::Generic::List<ParseItem^>();
	xItemsBuffer_ = gcnew System::Collections::Generic::List<ParseItem^>();
	yItemsBuffer_ = gcnew System::Collections::Generic::List<ParseItem^>();

	this->createInitialBuffer(expr);

	result = this->checkInitialBuffer();
	if (result == false) return false; 

	return true;
}

/************************************************************************************/
/************************************************************************************/
/*************************  calculateExpression   *******************************/
/************************************************************************************/
/************************************************************************************/
double ExprParser::Parser::calculateExpression()
{
try{
	this->itemsBufferPosition_ = 0 ;

	return this->calculate(this->baseParseItem_);
	}catch(exception e){throw e;}
}

/************************************************************************************/
/************************************************************************************/
/*************************            setX            *******************************/
/************************************************************************************/
/************************************************************************************/
void ExprParser::Parser::setX(double x)
{
int size = this->xItemsBuffer_->Count;
int i = 0 ; 

	for (i=0 ; i < size ; i++ )
		{
			this->xItemsBuffer_[i]->number_ = x ; 
		}
}

/************************************************************************************/
/************************************************************************************/
/*************************             setY           *******************************/
/************************************************************************************/
/************************************************************************************/
void ExprParser::Parser::setY(double y)
{
int size = 0 ;
int i = 0 ; 

	size = this->yItemsBuffer_->Count;
		for (i=0 ; i < size ; i++ )
		{
			this->yItemsBuffer_[i]->number_ = y ; 
		}
}