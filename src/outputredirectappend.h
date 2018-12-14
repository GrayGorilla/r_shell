#ifndef OUTPUTREDIRECTAPPEND_H
#define OUTPUTREDIRECTAPPEND_H

#include "connector.h"
#include <unistd.h>
#include <fcntl.h>


class OutputRedirectAppend: public Connector{
public:
  /* Constructors */
  OutputRedirectAppend():Connector(">>"){}
  OutputRedirectAppend(Base* left) : Connector(">>", left){}
  /* Copy Constructor */
  OutputRedirectAppend(const OutputRedirectAppend& RHS) : Connector(dynamic_cast<const OutputRedirectAppend&>(RHS)) {}
  /* Assignment Operator */
  OutputRedirectAppend& operator= (OutputRedirectAppend RHS) {
    swap(*this, RHS);
    return *this;
  }
  /* Processor */
  void run();
  /* Destructor */
  ~OutputRedirectAppend() = default;

  /* Friend Function */
  friend void swap(OutputRedirectAppend& a, OutputRedirectAppend& b);
};

void OutputRedirectAppend::run(){
  //exit if invalid tree
  if (this->getLeft() == nullptr || this->getRight() == nullptr) {
    exit(4);
  }
  else{
    int outputFile = open(this->getRight()->getRep(), O_WRONLY | O_APPEND |  O_CREAT, S_IREAD | S_IWRITE | S_IRGRP | S_IWGRP | S_IROTH | S_IWOTH );
    dup2(outputFile, 1);
    this->getLeft()->run();
    exit(errno);
  }
}

void swap(OutputRedirectAppend& a, OutputRedirectAppend& b) {
  swap(dynamic_cast<Connector&>(a), dynamic_cast<Connector&>(b));
}


#endif
