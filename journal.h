#ifndef JOURNAL_H
#define JOURNAL_H
#include "publication.h"
#include <iostream>
#include <fstream>
#include <string>


using namespace std;
// journal class inherits from publication
class Journal: public Publication {
    private:
        int volume;
    public:
        //constructor
        Journal(string ID, string title, string author, string genre, int pageCount, int isAvail, int volume) 
        : Publication(ID, title, author, genre, pageCount, isAvail) {
            this->volume = volume;
            if (volume < 0){
                throw invalid_argument("volume cannot be negative");
            }
        }

        //destructor
        ~Journal(){
            //cout << "Destroying a journal" << endl;
        }

        //getter and setter for volume
        void setVolume(int v) {   
            volume = v;
        }       

        int getVolume() {
            return volume;
        }
};
#endif