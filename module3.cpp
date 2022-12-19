#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;

void parseAssignments(stringstream& s);

int main()
{
    
    Expression* expression;
    char comma;
    char line[50];
    int choice;
    ifstream input;
    string fileName;
    
    
    cout << "Enter 1 to open input file 1 " << endl;
    cout << "Enter 2 to open input file 2 " << endl;
    cout << "Enter 3 to open input file 3 " << endl;
    cout << "Enter 4 to input file name: ";
    
    while (true) {
        cin >> choice;
    
        if (choice == 1) {
            input.open("in.txt");
            break;
        }
        else if (choice == 2) {
            input.open("in2.txt");
            break;
        }
        else if (choice == 3) {
            input.open("in3.txt");
            break;
        }
        else if (choice == 4) {
            cout << "enter file name: "<<endl;
            cin >> fileName;
            input.open(fileName);
            break;
        }
        else {
            cout << "invalid choice" << endl;
            cout << "\nEnter 1 to open input file 1 " << endl;
            cout << "Enter 2 to open input file 2 " << endl;
            cout << "Enter 3 to open input file 3 " << endl;
            cout << "Enter 4 to input file name: ";
            cin.clear();
            cin.ignore(100, '\n');
        }
    }
    cout << '\n';
    if (input) {
        while (true) {
            input.getline(line, 50);
            if (!input) {
                break;
            }
            cout << line << endl;
            stringstream ss(line, ios_base::in);
            expression = SubExpression::parse(ss);
            ss >> comma;
            parseAssignments(ss);
            cout << "Value = " << expression->evaluate() << endl;
            cout << '\n';
            symbolTable.clear();
    }
    cout << "Thank you for using the evaluator. good bye"<< endl;
    return 1;
    }
    else {
        cout << "file not found" << endl;
        return 0;
    }
}

void parseAssignments(stringstream& s)
{
    char assignop, delimiter;
    string variable;
    double value;
    do
    {
        variable = parseName(s);
        s >> ws >> assignop >> value >> delimiter;
        cout << variable + " = " << value << endl;
        
        symbolTable.insert(variable, value);
    }
    while (delimiter == ',');
}
   
