//---------------------------------------------------------------------------

#pragma hdrstop

#include "myException.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

void MyException::CheckIndexValue(UnicodeString str){
	for(int i = 1; i <= str.Length(); i++)
		if(str[i] > '9' || str[i] < '0')
			throw MyException("Invalid index input.\nEnter only numbers.");
}

void MyException::CheckOnlyLetters(UnicodeString str){
	for(int i = 1; i <= str.Length(); i++)
		if(str[i] <= '9' && str[i] >= '0')
			throw MyException("Invalid input.\nEnter only letters.");
}

void MyException::CheckIsButtonAvailable(UnicodeString str){
	if(str == "")
		throw MyException("Empty Field");
}
