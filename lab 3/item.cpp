//---------------------------------------------------------------------------

#pragma hdrstop

#include "item.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

UnicodeString Item::GetReadyStatus(){
	if(isReady) return "готов";
	return "не готов";
}
