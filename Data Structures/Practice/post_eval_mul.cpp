#include <iostream>
using namespace std;
#include "stack_header.h"

int main(){
    string inp;
    cout << "Enter string: ";
    cin >> inp;
    stack <int> s;
    int num;
    for(int i=0;i<inp.length();i++){
        char c = inp[i];
        if(isalpha(c)){
            cout << "Enter value of " << c << ": ";
            cin >> num;
            s.push(num);
        }
        else if(c==' ')
            continue;
        else{
            int a = s.pop();
            int b = s.pop();
            cout << b << " " << c << " " << a << endl;
            switch(c){
                case '*':
                    s.push(b*a);
                    break;
                case '/':
                    s.push(b/a);
                    break;
                case '+':
                    s.push(b+a);
                    break;
                case '-':
                    s.push(b-a);
                    break;
                default:
                    break;
            }
        }
    }
    cout << s.peek() << endl;
}
