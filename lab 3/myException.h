//---------------------------------------------------------------------------

#ifndef myExceptionH
#define myExceptionH

//---------------------------------------------------------------------------
#endif

class MyException : public Exception{
	private:
	public:
		MyException(char *msg) : Exception(msg){}

		void CheckIndexValue(UnicodeString);
		void CheckOnlyLetters(UnicodeString);
        void CheckIsButtonAvailable(UnicodeString);
};