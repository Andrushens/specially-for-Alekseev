//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "SmartPointer.h"
#include "MyTree.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"

TForm7 *Form7;
MyTree<int> tree;
Node<int> *root = nullptr;
int n = 1;//для StringGrid
//---------------------------------------------------------------------------
__fastcall TForm7::TForm7(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm7::FormCreate(TObject *Sender)
{
    SG->RowCount = 1;
	SG->ColCount = 2;
	SG->Cells[0][0] = "Key";
	SG->Cells[1][0] = "Data";
	Memo1->Clear();
}
//---------------------------------------------------------------------------

void __fastcall TForm7::AddGridNewButtonClick(TObject *Sender)
{
	SG->RowCount = n + 1;
	SG->Cells[0][n] = KeyGridEdit->Text;
	SG->Cells[1][n] = DataGridEdit->Text;

	bool flag = true;
	for(int i = 0; i < ComboBox1->Items->Count; i++){
		if(ComboBox1->Items->Strings[i] == KeyGridEdit->Text){
			flag = false;
			break;
		}
	}

	if(flag){
		ComboBox1->Items->Add(KeyGridEdit->Text);
		ComboBox2->Items->Add(KeyGridEdit->Text);
	}
	n++;
	KeyGridEdit->Text = IntToStr(StrToInt(KeyGridEdit->Text) + 1);
	KeyTreeEdit->Text = IntToStr(StrToInt(KeyTreeEdit->Text) + 1);
}
//---------------------------------------------------------------------------

void ViewTree(Node<int> *node, TTreeView *treeView, int k){
	if(node == nullptr)
		return;
	if(k == -1)
		treeView->Items->AddFirst(NULL, IntToStr(node->key) + " - " + IntToStr(node->data));
	else
		treeView->Items->AddChildFirst(treeView->Items->Item[k], IntToStr(node->key) + " - " + IntToStr(node->data));
	k++;
	ViewTree(node->left, treeView, k);
	ViewTree(node->right, treeView, k);
	k--;
}
//---------------------------------------------------------------------------

void ShowTreeView(TTreeView *treeView1){
	treeView1->Items->Clear();
	ViewTree(root, treeView1, -1);
	treeView1->FullExpand();
}
//---------------------------------------------------------------------------

void __fastcall TForm7::FillTreeButtonClick(TObject *Sender)
{
	for(int i = 1; i < n; i++){
		tree.insert(StrToInt(SG->Cells[0][i]), StrToInt(SG->Cells[1][i]), &root);
	}

	ShowTreeView(treeView1);
}
//---------------------------------------------------------------------------

void __fastcall TForm7::AddNewTreeButtonClick(TObject *Sender)
{
	tree.insert(StrToInt(KeyTreeEdit->Text), StrToInt(DataTreeEdit->Text), &root);
	ShowTreeView(treeView1);

	bool flag = true;
	for(int i = 0; i < ComboBox1->Items->Count; i++){
		if(ComboBox1->Items->Strings[i] == KeyTreeEdit->Text){
			flag = false;
			break;
		}
	}

	if(flag){
		ComboBox1->Items->Add(KeyTreeEdit->Text);
		ComboBox2->Items->Add(KeyTreeEdit->Text);
	}

	KeyTreeEdit->Text = IntToStr(StrToInt(KeyTreeEdit->Text) + 1);
	KeyGridEdit->Text = IntToStr(StrToInt(KeyGridEdit->Text) + 1);
}
//---------------------------------------------------------------------------

void __fastcall TForm7::BalanceTreeButtonClick(TObject *Sender)
{
	tree.balance(&root);
	ShowTreeView(treeView1);
}
//---------------------------------------------------------------------------

void __fastcall TForm7::DeleteKeyButtonClick(TObject *Sender)
{
	for(int i = 0; i < ComboBox2->Items->Count; i++){
		if(ComboBox1->Text == ComboBox2->Items->Strings[i])
			ComboBox2->Items->Delete(i);
	}
	tree.deleteKey(StrToInt(ComboBox1->Text), &root);
	ComboBox1->DeleteSelected();
	ShowTreeView(treeView1);
}
//---------------------------------------------------------------------------

void __fastcall TForm7::ShowInfoButtonClick(TObject *Sender)
{
	ShowMessage(tree.find(StrToInt(ComboBox2->Text), root)->data);
}
//---------------------------------------------------------------------------


void __fastcall TForm7::InOrderButtonClick(TObject *Sender)
{
	Memo1->Clear();
	tree.inOrder(root, Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm7::PreOrderButtonClick(TObject *Sender)
{
	Memo1->Clear();
	tree.preOrder(root, Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm7::PostOrderButtonClick(TObject *Sender)
{
	Memo1->Clear();
	tree.postOrder(root, Memo1);
}
//---------------------------------------------------------------------------

void __fastcall TForm7::GetNumOfLeavesButtonClick(TObject *Sender)
{
	ShowMessage(tree.GetNumOfLeaves(root));
}
//---------------------------------------------------------------------------

