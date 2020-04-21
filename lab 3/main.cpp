//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "list.h"
#include "item.h"
#include "main.h"
#include "myException.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
MyException *me;
Item *item;
List<Item> list;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm7::AddNewButtonClick(TObject *Sender)
{
	bool flag = true;
	item = new Item();

	try{
		me->CheckIndexValue(EditNumOfItems->Text);
		me->CheckOnlyLetters(TypeEdit->Text);
		me->CheckOnlyLetters(MarkEdit->Text);
	}
	catch(MyException &ex){
		ShowMessage(ex.Message);
		return;
	}

	item->index = StrToInt(EditNumOfItems->Text);
	item->type = TypeEdit->Text;
	item->company = MarkEdit->Text;
	item->receiveDate = DateTimePicker1->Date;
	EditNumOfItems->Text = IntToStr(StrToInt(EditNumOfItems->Text) + 1);
	ComboBox2->AddItem("заказ №" + IntToStr(item->index) + ". " + item->type + ", " + item->company, 0);

	for(int i = 0; i < ComboBox1->Items->Count; i++){
		if(item->type == ComboBox1->Items->Strings[i]){
			flag = false;
			break;
		}
	}

	if(flag){
		ComboBox1->AddItem(item->type, 0);
	}
	list.push_back(*item);
	ComboBox1Select(Sender);
	Memo1->Lines->Add("заказ №" + IntToStr(item->index) + ". " + item->type + ", " + item->company + ", " + item->receiveDate);
}
//---------------------------------------------------------------------------

void __fastcall TForm7::ExecuteButtonClick(TObject *Sender)
{
	try{
		me->CheckIsButtonAvailable(ComboBox2->Text);
	}
	catch(MyException &ex){
		ShowMessage(ex.Message);
		return;
	}

	int i = 0;
	UnicodeString check = "заказ №" +  IntToStr(list[0].index) + ". " + list[0].type + ", " + list[0].company;

	while(check != ComboBox2->Text){
		i++;
		check = "заказ №" +  IntToStr(list[i].index) + ". " + list[i].type + ", " + list[i].company;
	}
	list[i].isReady = true;
	Memo1->Clear();

	for(int i = 0; i < list.GetSize(); i++){
		if(!list[i].isReady)
			Memo1->Lines->Add("заказ №" + IntToStr(list[i].index) + ". " + list[i].type + ", " + list[i].company + ", " + list[i].receiveDate);
	}
	ComboBox2->DeleteSelected();
	Memo2->Clear();

	for(int i = 0; i < list.GetSize(); i++){
		if(list[i].isReady)
			Memo2->Lines->Add("заказ №" + IntToStr(list[i].index) + ". " + list[i].type + ", " + list[i].company + ", " + list[i].receiveDate);
	}
	ComboBox1Select(Sender);
}
//---------------------------------------------------------------------------


void __fastcall TForm7::FormCreate(TObject *Sender)
{
	Memo1->Clear();
	Memo2->Clear();
	Memo3->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm7::ComboBox1Select(TObject *Sender)
{
	Memo3->Clear();
	UnicodeString type = ComboBox1->Text;
	int k = 0;

	for(int i = 0; i < list.GetSize(); i++)
		if(list[i].type == type)
			Memo3->Lines->Add("заказ №" + IntToStr(list[i].index) + ". " + list[i].type + ", " + list[i].company + ", " + list[i].receiveDate + ", " + list[i].GetReadyStatus());
}
//---------------------------------------------------------------------------
