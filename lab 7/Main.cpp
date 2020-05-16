//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "MyHashTable.h"
#include <ctime>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm7 *Form7;
MyHashTable<int> *ht;
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm7::CreateTableButtonClick(TObject *Sender)
{
	Memo1->Clear();
	ComboBox1->Clear();
	ComboBox2->Clear();
	if(NumOfKeysEdit->Text == "") return;

	int size = StrToInt(NumOfKeysEdit->Text);
	ht = new MyHashTable<int>(size);

	ht->ShowTableKeys(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm7::FormCreate(TObject *Sender)
{
	srand(time(NULL));
	Memo1->Clear();
    Memo2->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm7::FillRandomButtonClick(TObject *Sender)
{
	if (NumOfKeysToAddEdit->Text == "") return;
	int n = StrToInt(NumOfKeysToAddEdit->Text);

	for(int i = 0; i < n; i++)
	{
		int key = rand() % 100;
		bool flag = true;
		ht->Insert(key, rand() % 100);

		for(int i = 0; i < ComboBox1->Items->Count; i++)
		{
			if(IntToStr(key) == ComboBox1->Items->Strings[i] || ht->GetFreeSlots() == 0)
			{
				flag = false;
				break;
			}
		}

		if(flag)
		{
			ComboBox1->AddItem(IntToStr(key), ComboBox1);
			ComboBox2->AddItem(IntToStr(key), ComboBox2);
		}
	}

	ht->ShowTableKeys(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm7::TaskButtonClick(TObject *Sender)
{
	ht->Task();

	ComboBox1->Clear();
	ComboBox2->Clear();

	for(int i = 0; i < ht->GetSize(); i++)
	{
		int key = ht->GetKey(i);
		ComboBox1->AddItem(IntToStr(key), ComboBox1);
		ComboBox2->AddItem(IntToStr(key), ComboBox2);
    }

	ht->ShowTableKeys(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm7::DeleteKeyButtonClick(TObject *Sender)
{
	if(ComboBox1->Text == "") return;
	int i, key = StrToInt(ComboBox1->Text);
	ht->Remove(key);

	i = ComboBox1->Items->IndexOf(ComboBox1->Text);
	ComboBox1->Items->Delete(i);
	ComboBox2->Items->Delete(i);

	ht->ShowTableKeys(Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm7::AddNewButtonClick(TObject *Sender)
{
	if(AddNewKeyEdit->Text == "" || AddNewDataEdit->Text == "")
	{
		return;
	}
	int key = StrToInt(AddNewKeyEdit->Text);
	int data = StrToInt(AddNewDataEdit->Text);
	bool flag = true;

    for(int i = 0; i < ComboBox1->Items->Count; i++)
	{
		if(IntToStr(key) == ComboBox1->Items->Strings[i])
		{
			flag = false;
			break;
		}
	}

	if(flag)
	{
		ComboBox1->AddItem(IntToStr(key), ComboBox1);
		ComboBox2->AddItem(IntToStr(key), ComboBox2);
	}

	ht->Insert(key, data);
	ht->ShowTableKeys(Memo1);
}
//---------------------------------------------------------------------------


void __fastcall TForm7::ShowKeyDataButtonClick(TObject *Sender)
{
	if(ComboBox2->Text == "") return;
	ht->ShowKeyData(Memo2, StrToInt(ComboBox2->Text));
}
//---------------------------------------------------------------------------

