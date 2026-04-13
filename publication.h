#ifndef PUBLICATION_H
#define PUBLICATION_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Publication
{
  private:
    //B101 "The Power of Positive Thinking" "Norman Vincent Peale" "Motivational, Spirituality" 240 1
    string ID;
    string title;
    string author;
    string genre;
    int pageCount;
    int isAvail = 1;

  public:
    //constructor with parameters
    Publication(string ID, string title, string author, string genre, int pageCount, int isAvail) {
      this->ID = ID;
      this->title = title;
      this->author = author;
      this->genre = genre;
      this->pageCount = pageCount;
      this->isAvail = isAvail;

      if (pageCount < 0){
        throw invalid_argument("pageCount cannot be negative");
      }
      if(isAvail != 0 && isAvail != 1){
        throw invalid_argument("isAvail must be either 0 or 1");
      }
      
    }

    ~Publication(){
    //cout << "Destroying a publication" << endl;
    }

    //setters and getters
    //setter
    void setItemID(string id) {
      ID = id;
    }
    // getter
    string getID() {
      return ID;
    }

    void setTitle(string t) {
      title = t;
    }

    string getTitle() {
      return title;
    }

    void setAuthor(string a) {
      author = a;
    }

    string getAuthor() {
      return author;
    }

    void setGenre(string g) {
      genre = g;
    }

    string getGenre() {
      return genre;
    }

    void setPageCount(int p){
      pageCount = p;
    }

    int getPageCount() {
      return pageCount;
    }

    void setIsAvail(int avail) {
      isAvail = avail;
    }

    int getIsAvail() {
      return isAvail;
    }
};

#endif