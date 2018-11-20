#ifndef BASE_H
#define BASE_H

#include <string.h>

class Base {

    private:
        char* representation;

    public:
        /* Constructors */
        Base() {}
        Base(char* rep) { 
          this->representation = new char[strlen(rep)+ 1];
          strncpy(this->representation, rep, strlen(rep) + 1 );
          this->representation[strlen(rep)] = '\0';
        }
        
        
        Base(const Base& RHS){
          int size = 0;
          while(RHS.representation[size]){
            size++;
          }
          representation = new char[size + 1];
          representation[size] = '\0';
          for (int i = 0; i < size; i++){
            representation[i] = RHS.representation[i];
          }
        }
        
        
        ~Base(){
          delete[] representation;
        }
        
        
        Base& operator =(const Base& RHS){
          if(representation){
            delete[] representation;
          }
          int size = 0;
          while(RHS.representation[size]){
            size++;
          }
          representation = new char[size + 1];
          representation[size] = '\0';
          for (int i = 0; i < size; i++){
            representation[i] = RHS.representation[i];
          }
          return *this;
        }
        
        /* Accessor function */
        char* getRep() { return this->representation; }

        /* Mutator function */
        void setRep(char* rep) { this->representation = rep; }

        /* Pure Virtual functions */
        virtual void run() = 0;
        virtual void add(Base* obj) = 0;

};


#endif