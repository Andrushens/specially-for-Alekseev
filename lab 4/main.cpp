//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "Stack.h"
#include "Calculator.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
Calculator *calc;
//---------------------------------------------------------------------------

__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

bool isInputCorrect(AnsiString str){//проверка на корректность
	if(str == "") return false;

	for(int i = 1; i <= str.Length(); i++){
		if((str[i] < '0' || str[i] > '9')
		&& (str[i] != '+' && str[i] != '-'
		&& str[i] != '*' && str[i] != '/'
		&& str[i] != '(' && str[i] != ')'
		&& str[i] != ' ' && str[i] != '.'
		&& str[i] != ','))
			return false;
	}
	return true;
}
//---------------------------------------------------------------------------

void __fastcall TForm7::GetRPN_Click(TObject *Sender)//посчитать и вывести ОПЗ
{
	Edit2->Clear();
	if(isInputCorrect(Edit1->Text)){
		calc = new Calculator();
		calc->CalculateRPN(Edit1->Text);
		Edit2->Text = calc->GetRPN();
	}
}
//---------------------------------------------------------------------------
void __fastcall TForm7::GetResClick(TObject *Sender)//посчитать и вевести результат выражения
{
	Edit3->Clear();
	if(isInputCorrect(Edit2->Text)){
		Edit3->Clear();
		calc->CalculateResult();
		Edit3->Text = calc->GetResult();

	}
}
//---------------------------------------------------------------------------

