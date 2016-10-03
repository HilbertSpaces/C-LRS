#include <iostream>
#include <stack>
#include <string>

struct Bracket {
    Bracket(char type, int position):
        type(type),
        position(position)
    {}

    bool Matchc(char c) {
        if (type == '[' && c == ']')
            return true;
        if (type == '{' && c == '}')
            return true;
        if (type == '(' && c == ')')
            return true;
        return false;
    }

    char type;
    int position;
};

int main() {
    std::string text;
    int count=0;
    bool breaker=false;
    getline(std::cin, text);
    std::stack <Bracket> opening_brackets_stack;
    int trackposition;
    for (int position = 0; position < text.length(); ++position) {
        char next = text[position];
	trackposition=position;
	Bracket chars(next,position+1);
        if (next == '(' || next == '[' || next == '{') {
		count+=1;
		opening_brackets_stack.push(chars);
        }
        if (next == ')' || next == ']' || next == '}') {
		if(opening_brackets_stack.empty())
		{
			breaker=true;
			break;
		}
		else{
			if(opening_brackets_stack.top().Matchc(next))
			{
				opening_brackets_stack.pop();
			}
			else
			{
				breaker=true;
				break;
			}
		}
		}
	trackposition=position;
    }
    int size=opening_brackets_stack.size();
    // Printing answer, write your code here
    if(opening_brackets_stack.empty()&&!breaker)
	    std::cout<<"Success";
    else if(!breaker)
	    std::cout<<opening_brackets_stack.top().position;
    else
	    std::cout<<trackposition+1;
    return 0;
}
