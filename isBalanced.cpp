#include<iostream>
#include<string>
#include<algorithm>
#include<stack>
using namespace std;

bool isBalanced(string exp){
	stack<char>st;
	for(int i=0;i<exp.length();i++){
		if(exp[i]=='(' || exp[i]=='[' || exp[i]=='{'){
			st.push(exp[i]);
		}
		if(st.empty())
			return false;
		if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
			char x=st.top();
			st.pop();
			if(exp[i]==')' && x=='(')
				continue;
			else if(exp[i]=='}' && x=='{')
				continue;
			else if(exp[i]==']' && x=='[')
				continue;
			else
				return false;
		}else
			continue;
	}
	if(st.empty())
		return true;
	else
		return false;
}
*/
int priority(char opor){
	if(opor == '-' || opor == '+') return 1;
	else if(opor == '*' || opor == '/' || opor=='%') return 2;
	else if(opor == '^')return 3;
	else return 0;
}
float mathOperation(float op1,float op2 , char oper){
	if(oper=='+')return op1+op2;
	else if(oper=='-') return op1 - op2;
	else if(oper=='*') return op1 * op2;
	else if(oper=='/') return op1 / op2;
}
float postfixEvaluate(string exp){
	stack<float>st;
	for(int i=0;i<exp.length();i++){
		if(exp[i]==' ') continue;
		if(isdigit(exp[i]))
			st.push((exp[i]-'0'));
		else{
			float op2=st.top();
			st.pop();
			float op1=st.top();
			st.pop();
			float res=mathOperation(op2,op1,exp[i]);
			st.push(res);
		}	
	}
	return st.top();
	st.pop();
}
float infixToPostfix(string exp){
	//step 1 -> create empty stack and empty string
	stack<char>st;
	string output="";
	//step 2 -> loop in exp 
	for(int i=0;i<exp.length();i++){
		// if the char is space is not matter
		if(exp[i]==' ')continue;
		// is the char is digit or symbal is out
		if(isdigit(exp[i]) || isalpha(exp[i])){
			output+=exp[i];
		// if the char is ( is pushed in stack (st)
		}else if(exp[i]=='('){
			st.push(exp[i]);
		// if the char is ) pop all element in the stack until get to the open 
		}else if(exp[i]==')'){
			while(exp[i] !='('){
				output+=st.top();
				st.pop();
			}
			st.pop();
		}else{
			// if the char is operator compare it
			while(!st.empty() && priority(exp[i]) <= priority(st.top())){
				output+=st.top();
				st.pop();
			}
			st.push(exp[i]); 
		}
	}
	while(!st.empty()){
		output+=st.top();
		st.pop();
	}
	return postfixEvaluate(output);
}
int main(){
//	string exp="({}){}";
//	bool ex=isBalanced(exp);
//	ex==1?cout<<"balanced exp":cout<<"Not balanced exp";
	cout<<infixToPostfix("7 * 8 + 5 / 9")<<endl;
	return 0;
}
