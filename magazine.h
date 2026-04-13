#ifndef MAGAZINE_H
#define MAGAZINE_H
#include "publication.h"
#include <iostream>
#include <fstream>


using namespace std;
// magazine class inherits from publication
class Magazine: public Publication {
    private:
        int issueNum;
    public:
        //constructor
        Magazine(string ID, string title, string author, string genre, int pageCount, int isAvail, int issueNum) 
        : Publication(ID, title, author, genre, pageCount, isAvail) {
            this->issueNum = issueNum;
            if (issueNum < 0){
                throw invalid_argument("issueNum cannot be negative");
            }
        }

        //destructor
        ~Magazine(){
            //cout << "Destroying a magazine" << endl;
        }

        //getter and setter for issueNum
        void setIssueNum(int issue) {
            issueNum = issue;
        }

        int getIssueNum() {
            return issueNum;
        }
};
#endif