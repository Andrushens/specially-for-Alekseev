//---------------------------------------------------------------------------

#ifndef itemH
#define itemH
//---------------------------------------------------------------------------
#endif

class Item{
	public:
        int index;
		UnicodeString type, company;
		bool isReady;
		TDateTime receiveDate;

		Item(){
			isReady = false;
		}

		UnicodeString GetReadyStatus();
};
