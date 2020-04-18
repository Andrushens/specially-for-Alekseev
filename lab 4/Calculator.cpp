//---------------------------------------------------------------------------

#pragma hdrstop

#include "Calculator.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)

int Calculator::getPriority(char symb){
	if(symb == '(') return 1;
	if(symb == '+' || symb == '-') return 2;
	if(symb == '*' || symb == '/') return 3;
}

void Calculator::CalculateRPN(AnsiString str){
	RPN = "";

	for(int i = 1; i <= str.Length(); i++){
		AnsiString num;

		while(i <= str.Length() && ((str[i] >= '0' && str[i] <= '9') || str[i] == '.' || str[i] == ',')){
			num += str[i];
			i++;
		}

		if(num.Length())
			RPN += num + ' ';

		if(i == str.Length() + 1) break;

		if(str[i] == ' ') continue;

		if(str[i] == '('){
			signs.push(str[i]);
			continue;
		}

		if(str[i] == ')'){
			while(signs.top() != '('){
				RPN += signs.top();
				RPN += ' ';
				signs.pop();

			}
			signs.pop();
			continue;
		}

		if((signs.isEmpty() || getPriority(signs.top()) < getPriority(str[i]))){
			signs.push(str[i]);
			continue;
		}

		while(!signs.isEmpty() && getPriority(signs.top()) >= getPriority(str[i])){
			RPN += signs.top();
			RPN += ' ';
			signs.pop();
		}
		signs.push(str[i]);
	}

	while(!signs.isEmpty()){
		RPN += signs.top();
		RPN += ' ';
		signs.pop();
	}
}

void Calculator::CalculateResult(){
	for(int i = 1; i <= RPN.Length(); i++){
		if(RPN[i] == ' ') continue;

		if(RPN[i] >= '0' && RPN[i] <= '9'){
			AnsiString num;

			while(RPN[i] >= '0' && RPN[i] <= '9' && i < RPN.Length()){
				num += RPN[i++];
			}

			if((RPN[i] == '.' || RPN[i] == ',') && i < RPN.Length()){
				num += ',';
				i++;

				while(i < RPN.Length() && RPN[i] >= '0' && RPN[i] <= '9'){
					num += RPN[i++];
				}
			}

			if(RPN[i] >= '0' && RPN[i] <= '9'){
				num += RPN[i];
			}
			nums.push(StrToFloat(num));

			if(i == RPN.Length()) break;
		}
		else{
			float a = nums.top();
			nums.pop();
			float b = nums.top();
			nums.pop();
			float c;

			switch(RPN[i]){
				case '*': c = b * a; break;
				case '/':
					if(a)
						c = b / a;
					else {
						result = "Divided by zero";
						return;
					}
					break;
				case '-': c = b - a; break;
				case '+': c = b + a; break;
			}
			nums.push(c);
		}
	}
	result = FloatToStr(nums.top());

	for(int i = 1; i <= result.Length(); i++){
		if(result[i] == ',' && i + 3 <= result.Length())
			result[i+3] = '\0';
	}
	nums.pop();
}
