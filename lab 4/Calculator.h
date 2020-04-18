//---------------------------------------------------------------------------

#ifndef CalculatorH
#include "Stack.h"
#define CalculatorH
//---------------------------------------------------------------------------
#endif

class Calculator{
private:
	Stack<char> signs;//стек для знаков
	Stack<float> nums;//стек для чисел
	AnsiString RPN;//выражение в ОПЗ
	AnsiString result;//итоговое значение
public:
	int getPriority(char);//получить приоритет операции для расчёта ОПЗ
	void CalculateRPN(AnsiString);//перевод из инфиксной в постфиксную запись
	AnsiString GetRPN(){ return RPN; }//вернуть значение ОПЗ
	void CalculateResult();//посчитать результат используя ОПЗ
	AnsiString GetResult(){ return result; }//вернуть итоговое значение
};