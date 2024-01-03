/********************** DO NOT ADD ANY OTHER LIB******************************/
/*
    The only allowed library is iostream. You cannot use other libraries such as
    vector, map, set, stack, queue, etc.
*/
#include <iostream>
using namespace std;

/*↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓ Your code goes here ↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓↓*/
struct stack{
    char val;
    stack *prev = nullptr;
};


class CharStack {
    public:
    CharStack(string str){
        int size = str.length();
        push(str[0]);
        for(int i = 1; i<size; i++){
            if(peek() != str[i]){
                push(str[i]);
            }
            else{
                pop();
            }
        }
    }
    string eliminate(){
        string output = "";
        while(top){
            output = pop() + output;
        }
        return output;
    }
    
    private:
    void push(char c){
        stack *ptr = new stack;
        ptr->val = c;
        ptr->prev = top;
        top = ptr;
    }

    char pop(){
        char r = top->val;
        stack *ptr = top->prev;
        delete top;
        top = ptr;
        return r;
    }
    char peek(){
        if(top){
            return top->val;
        }
        else{
            return '0';
        }
    }
    stack *top = nullptr;
}; 


/*↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑ End of your code ↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑↑*/

/**************DO NOT CHANGE ANYTHING IN main()!!!******************************/
int main() {
    string str = "abcdefghigklmnopqrstuvwxyzcccccccccccccccccccdffffdccccccccccccccccccccccccccccccccccccccccccccccaaarraaaccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccczyxwvutsrqponmlkgihgfedcbaihhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhaccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccmaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaphhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhryyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyodddddddddddddddddddddddddddddddddddddddddddduffffffffffffffffffffffffffffffffffffffffffffdqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqqoccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccccfbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbybbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbouttttttttttttttttttttttttttttttttttttttttttttrffffffffffffffffffffffffffffffffffffffffffffeffffffffffffffffffffffffffffffffffffffffffffaffffffffffffffffffffffffffffffffffffffffffffchzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzingzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhheeeeezzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzzrrrffffffffffffffffffffffffffffffffffffffffffffeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeeee";
    // You should have a constructor that creates a stack object below.
    CharStack cs(str);

    // Your task is to do a naive letter eliminating via eliminate() of CharStack
    // Here is the rule:
    // 1. for any two adjecent same chars, eliminate them! 
    //    for example, if the given string is "abbbccccdddddd", the string after elimination is "ab";
    // 2. if two same chars are adjecent to each other after certain eliminations, eliminate them too!
    //    for example, if the given string is "cabbabccbd", the string after elimination is "cd";
    string eliminatedStr = cs.eliminate();
    cout << "the string after elimination is: " << eliminatedStr << endl;
    
    // once again, do not change anything in this main()
    return 0;
}