#ifndef INPUTOUTPUTREDIRECTAPPEND_H
#define INPUTOUTPUTREDIRECTAPPEND_H

#include "connector.h"
#include <unistd.h>
#include <fcntl.h>


class InputOutputRedirect: public Connector{
public:
  /* Constructors */
  InputOutputRedirect():Connector("<>"){}
  InputOutputRedirect(Base* left) : Connector("<>", left){}
  /* Copy Constructor */
  InputOutputRedirect(const InputOutputRedirect& RHS) : Connector(dynamic_cast<const Connector&>(RHS)) {}
  /* Assignment Operator */
  InputOutputRedirect& operator= (InputOutputRedirect RHS) {
    swap(*this, RHS);
    return *this;
  }
  /* Processor */
  void run();
  /* Destructor */
  ~InputOutputRedirect() = default;

  /* Friend Function */
  friend void swap(InputOutputRedirect& a, InputOutputRedirect& b);
};

void InputOutputRedirect::run(){
  //exit if invalid tree
  if (this->getLeft() == nullptr || this->getRight() == nullptr) {
    exit(4);
  }
  else{
    int inputOutputFile = open(this->getRight()->getRep(), O_RDWR | O_APPEND |  O_CREAT, S_IREAD | S_IWRITE | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );
    dup2(inputOutputFile, 1);
    dup2(inputOutputFile, 0);
    this->getLeft()->run();
    exit(errno);
  }
}

/* Non-member Function */
void swap(InputOutputRedirect& a, InputOutputRedirect& b) {
    swap(dynamic_cast<Connector&>(a), dynamic_cast<Connector&>(b));
}


#endif
