#ifndef INPUTREDIRECT_H
#define INPUTREDIRECT_H

#include "connector.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


class InputRedirect: public Connector{

public:
  /* Constructors */
  InputRedirect():Connector("<"){}
  InputRedirect(Base* left) : Connector("<", left){}
  /* Copy Constructor */
  InputRedirect(const InputRedirect& RHS) : Connector(dynamic_cast<const Connector&>(RHS)) {}

  /* Assignment Operator */
  InputRedirect& operator= (InputRedirect RHS) {
    swap(*this, RHS);
    return *this;
  }
  /* Processor */
  void run();
  /* Destructor */
  ~InputRedirect() = default;

  /* Friend Function */
  friend void swap(InputRedirect& a, InputRedirect& b);
};

void InputRedirect::run(){
  //exit if invalid tree
  if (this->getLeft() == nullptr || this->getRight() == nullptr) {
    exit(4);
  }
  else{
    int inputFile = open(this->getRight()->getRep(), O_RDONLY);
    dup2(inputFile, 0);
    this->getLeft()->run();
    exit(errno);
  }
}

/* Non-member Function */
void swap(InputRedirect& a, InputRedirect& b) {
    swap(dynamic_cast<Connector&>(a), dynamic_cast<Connector&>(b));
}

#endif
