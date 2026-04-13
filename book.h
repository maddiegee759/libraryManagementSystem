#ifndef BOOK_H
#define BOOK_H
#include "publication.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;
// book class inherits from publication
class Book: public Publication 
{
    public:
        //constructor
        Book(string ID, string title, string author, string genre, int pageCount, int isAvail) 
        : Publication(ID, title, author, genre, pageCount, isAvail) {
        }

        //destructor
        ~Book(){
            //cout << "Destroying a book" << endl;
        }
    
};
#endif