#ifndef PARSE_H
#define PARSE_H

#include <sstream>
#include <string>
#include "base.h"
#include "command.h"
#include "argument.h"
#include "comment.h"
#include "separator.h"
#include "and.h"
#include "or.h"


class Parse {

private:
    std::string input;
    Base* head;
    Base* currentCmnd;
 
public:
    /* Constructors */
    Parse() {}
    Parse(std::string inpt) 
        : input(inpt), head(nullptr), currentCmnd(nullptr) {}
    /* Helper Function */
    char* cStringConv(std::string text);
    /* Mutators */
    void setInput(std::string inpt) { 
        this->input = inpt;
        if (head != nullptr) {
            delete head;
            head = nullptr;
        }
        currentCmnd = nullptr;
    }
    Base* process();
    void preprocess();
    /* Destructor */
    ~Parse() { if (head != nullptr) delete head; }
};


// Public Member Functions

char* Parse::cStringConv(std::string text) {
    char* cStr = new char[text.size() + 1];
    text.copy(cStr, text.size() + 1);
    cStr[text.size()] = '\0';
    return cStr;
}

Base* Parse::process() {
    preprocess();
    std::stringstream ss(input);
    std::string token;
    bool takeCommand = true;

    while (ss >> token) {
        // Commands
        if (takeCommand) {
            currentCmnd = new Command(cStringConv(token));
            takeCommand = false;
            // First Command
            if (head == nullptr)
                head = currentCmnd;
            // All other Commands
            else
                head->add(currentCmnd);
        } 
        // Separator(semi-colon)
        else if (token == ";") {
            // Breaks off string from semi-colon
            head = new Separator(head);                 // Pass old head,
            takeCommand = true;                         // then set new head
        }
        else if (token == "&&") { 
            head = new And(head);                       // Pass old head,
            takeCommand = true;                         // then set new head 
        }
        else if (token == "||") {
            head = new Or(head);                        // Pass old head,
            takeCommand = true;                         // then set new head
        }
        // Arguments
        else {    
            Base* temp = new Argument(cStringConv(token));
            currentCmnd->add(temp);
        } 
    }
    return head;
}

void Parse::preprocess(){
  input = input.substr(0, input.find("#"));
  for(int i = 0; i < input.length(); i++){ 
    if(input[i] == ';'){
      input.insert(i, " ");
      i++;
    }
    else if(input[i] == '('){
      input.insert(i+1, " ");
    }
    else if(input[i] == ')'){
      input.insert(i, " ");
      i++;
    }
  }
}

#endif
