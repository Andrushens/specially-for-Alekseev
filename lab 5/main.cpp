//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "myQueue.h"
#include "queue.h"
#include "main.h"
#include <ctime>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
MyQueue<int> queue1;
MyQueue<int> queue2;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
	srand(time(0));
}
//---------------------------------------------------------------------------
void __fastcall TForm7::GetQueue1ButtonClick(TObject *Sender)
{
	ListBox1->Clear();
    queue1.clear();

	for(int i = 0; i < rand() % 5 + 6; i++){
		int x = rand() % 10;

		ListBox1->Items->Add(x);
		queue1.push(x);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm7::GetQueue2ButtonClick(TObject *Sender)
{
	ListBox2->Clear();
	queue2.clear();

	for(int i = 0; i < rand() % 5 + 6; i++){
		int x = rand() % 10;

		ListBox2->Items->Add(x);
		queue2.push(x);
	}
}
//---------------------------------------------------------------------------


void __fastcall TForm7::CombineButtonClick(TObject *Sender)
{
	ListBox3->Clear();

	if(ListBox1->Items->Count){
		if(queue1.isEmpty())
			for(int i = 0; i < ListBox1->Items->Count; i++)
				queue1.push(StrToInt(ListBox1->Items->Strings[i]));

		if(queue2.isEmpty())
			for(int i = 0; i < ListBox2->Items->Count; i++)
				queue2.push(StrToInt(ListBox2->Items->Strings[i]));
		queue1.insert(&queue2, queue1.GetIndexOfMax() + 1);

		while(queue1.GetSize()){
			ListBox3->Items->Add(queue1.front());
			queue1.pop();
		}

	}
}
//---------------------------------------------------------------------------


void __fastcall TForm7::PushQueue1ButtonClick(TObject *Sender)
{
    if(queue1.isEmpty())
		for(int i = 0; i < ListBox1->Items->Count; i++)
			queue1.push(StrToInt(ListBox1->Items->Strings[i]));
	queue1.push(StrToInt(Edit1->Text));
	ListBox1->Items->Add(Edit1->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm7::PushQueue2ButtonClick(TObject *Sender)
{
	if(queue2.isEmpty())
		for(int i = 0; i < ListBox2->Items->Count; i++)
			queue2.push(StrToInt(ListBox2->Items->Strings[i]));
	queue2.push(StrToInt(Edit2->Text));
	ListBox2->Items->Add(Edit2->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm7::PopQueue1ButtonClick(TObject *Sender)
{
	if(queue1.isEmpty())
		for(int i = 0; i < ListBox1->Items->Count; i++)
			queue1.push(StrToInt(ListBox1->Items->Strings[i]));

	if(!queue1.isEmpty()){
		queue1.pop();
		ListBox1->Items->Delete(0);
	}
}
//---------------------------------------------------------------------------

void __fastcall TForm7::PopQueue2ButtonClick(TObject *Sender)
{   if(queue2.isEmpty())
		for(int i = 0; i < ListBox2->Items->Count; i++)
			queue2.push(StrToInt(ListBox2->Items->Strings[i]));

	if(!queue2.isEmpty()){
		queue2.pop();
		ListBox2->Items->Delete(0);
	}
}
//---------------------------------------------------------------------------

