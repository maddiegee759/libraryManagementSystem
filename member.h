#ifndef MEMBER_H
#define MEMBER_H
#include <iostream>
#include <vector>
using namespace std;

class Member
{
  private:
    //M105 Jane B105 B107 
    string memberID;
    string name;
    vector<string> currBorrowed;

  public:
    //constructor with parameters
    Member(string memberID, string name, vector<string> currBorrowed){
      this->memberID = memberID;
      this->name = name;
      this->currBorrowed = currBorrowed;
    }

    //setters and getters
    void setMemberID(string mID){
      memberID = mID;
    }

    string getMemberID(){
      return memberID;
    }

    void setName(string n) {
      name = n;
    }

    string getName(){
      return name;
    }

    //set all items borrowed currently at same time
    void setcurrBorrowed(vector<string> newItems){
      currBorrowed = newItems;
    }
    
    //add an item (for member)
    void borrowI(string b){
      //check if book is already borrowed/exists
      for (auto& itemID : currBorrowed){
        if (itemID == b){
          cout << "Publication with id " << b << " is already borrowed by member" << endl;
          return;
        }
      }

      currBorrowed.push_back(b);
    }

    //remove an item (for member)
    void returnI(string b) {
      //find book
      int initSize = currBorrowed.size();
      for (int i = 0; i < initSize; i++){
        if (currBorrowed[i] == b) {
          currBorrowed.erase(currBorrowed.begin() + i);
          cout << "Publication with id " << b << " removed from member's current items borrowed" << endl;
          break;
        }
      }

      int newSize = currBorrowed.size();
      if (initSize == newSize) {
        cout << "Book not found in member's current items borrowed" << endl;
      }
    }

    /**
    //take off a book from end of vector
    void removeBook() {
      currBorrowed.pop_back();
    }
    */
    
    //get current books (for member)
    vector<string> getItems() {
      return currBorrowed;
    }  
};
#endif
