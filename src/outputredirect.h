#ifndef OUTPUTREDIRECT_H
#define OUTPUTREDIRECT_H

#include "connector.h"
#include <unistd.h>
#include <fcntl.h>
#include <stdio.h>


class OutputRedirect: public Connector{

public:
  /* Constructors */
  OutputRedirect():Connector(">"){}
  OutputRedirect(Base* left) : Connector(">", left){}
  /* Copy Constructor */
  OutputRedirect(const OutputRedirect& RHS) : Connector(dynamic_cast<const Connector&>(RHS)) {}
  /* Assignment Operator */
  OutputRedirect& operator= (OutputRedirect RHS) {
    swap(*this, RHS);
    return *this;
  }
  /* Processor */
  void run();
  /* Destructor */
  ~OutputRedirect() = default;

  /* Friend Function */
  friend void swap(OutputRedirect& a, OutputRedirect& b); 
};

void OutputRedirect::run(){
  //exit if invalid tree
  if (this->getLeft() == nullptr || this->getRight() == nullptr) {
    exit(4);
  }
  else{
    int outputFile = open(this->getRight()->getRep(), O_WRONLY | O_TRUNC | O_CREAT, S_IREAD | S_IWRITE | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );
    dup2(outputFile, 1);
    this->getLeft()->run();
    exit(errno);
  }
}

/* Non-member Function */
void swap(OutputRedirect& a, OutputRedirect& b) {
    swap(dynamic_cast<Connector&>(a), dynamic_cast<Connector&>(b));
}


#endif
