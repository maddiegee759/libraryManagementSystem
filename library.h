#ifndef LIBRARY_H
#define LIBRARY_H
#include <iostream>
#include <fstream>
#include <sstream>
#include "publication.h"
#include "book.h"
#include "magazine.h"
#include "journal.h"
#include "member.h"
#include <string>
#include <vector>
using namespace std;

class Library
{
  public:
    vector<Publication> publications;
    vector<Member> members;
    //methods
    //add/remove publications 
    void addPublication() {
      cout << "Would you like to add a book, magazine, or journal? (b/m/j)" << endl;
      char choice;
      cin >> choice;
      while (choice != 'b' && choice != 'm' && choice != 'j') {
        cerr << "Invalid choice. Please enter 'b', 'm', or 'j'." << endl;
        cin >> choice;
      }
      
      cout << "Enter publication id" << endl;
      string ID;
      getline(cin >> ws, ID);
      if (checkSpace(ID)) {
        cerr << "Invalid publication ID. ID cannot have spaces." << endl;
        return;
      };
      //check if publication with same ID already exists
      for (auto& p : publications){
        if (p.getID() == ID){
          cerr << "Publication with id " << ID << " already exists in the library system." << endl;
          return;
        }
      }

      cout << "Enter title" << endl;
      string title;
      getline(cin >> ws, title);
  
      cout << "Enter author" << endl;
      string author;
      getline(cin >> ws, author);

      cout << "Enter genre" << endl;
      string genre;
      getline(cin >> ws, genre);

      cout << "Enter page count" << endl;
      int pageCount;
      cin >> pageCount;

      cout << "Is the book available? (1 for yes, 0 for no)" << endl;
      int isAvail;
      cin >> isAvail;

      if (choice == 'b') {
        //adds book
        try {
          Book newBook(ID, title, author, genre, pageCount, isAvail);
          publications.push_back(newBook);
          cout << "Book with id " << ID << " added to library system" << endl;
        }
        catch(...){
          cerr << "Error creating book object" << endl;
          return;
        }
      }
      else if (choice == 'm') {
        //adds magazine
        cout << "Enter issue number" << endl;
        int issueNumber;
        cin >> issueNumber;

        try {
          Magazine newMagazine(ID, title, author, genre, pageCount, isAvail, issueNumber);
          publications.push_back(newMagazine);
          cout << "Magazine with id " << ID << " added to library system" << endl;
        }
        catch(...){
          cerr << "Error creating magazine object" << endl;
          return;
        }

      }
      else {
        //adds journal
        cout << "Enter volume number" << endl;
        int volume;
        cin >> volume;
        

        try {
          Journal newJournal(ID, title, author, genre, pageCount, isAvail, volume);
          publications.push_back(newJournal);
          cout << "Journal with id " << ID << " added to library system" << endl;
        }
        catch(...){
          cerr << "Error creating journal object" << endl;
          return;
        }
      }
    }
    
    int checkSpace(string str) {
      //if user input has spaces
      int count = 0;
      int N = str.length();

      for (int i = 0; i < N; ++i) {
        if (isspace(str[i])) {
          count++;
        }
      }

      if (count > 0){
        return 1;
      }
      else {
        return 0;
      }
      
    }
    //search for specific publication by title OR ID
    Publication* findPublicationByTitle(string title) {
      if (publications.empty()) {
        cerr << "No publications in the library system" << endl;
        return nullptr;
      }
      for (auto& p: publications){
        if (p.getTitle() == title) {
          cout << "Publication found: " << p.getTitle() << " with ID: " << p.getID() << endl;
          return &p;
        }
      }
      return nullptr;
    }

    Publication* findPublicationbyID(string ID){
      if (publications.empty()) {
        cerr << "No publications in the library system" << endl;
        return nullptr;
      }
      for (auto& p : publications){
        if (p.getID() == ID){
          cout << "Publication found: " << p.getTitle() << endl;
          return &p;
        }
      }
      return nullptr;
    }

    int removePublication(string ID) {
      //find book with above method and remove from collection
      Publication* p = findPublicationbyID(ID);
      if (p != nullptr) {
        publications.erase(publications.begin() + (p - &publications[0]));
        cout << "Publication with id " << ID << " is now removed from library" << endl;
        return 1;
      }
      else {
        cerr << "Publication with id " << ID << " not found" << endl;
        return 0;
      }
    }

    //display a list of available publications
    void displayAvail(){
      cout << "\n\nAvailable publications: \n" << endl;
      for (auto& p : publications){
        if (p.getIsAvail() == 1){
          cout << "ID: " << p.getID() << "\nTitle: " << p.getTitle() << "\nAuthor: " << p.getAuthor() << 
          "\nGenre: " << p.getGenre() << "\nPage Count: " << p.getPageCount() << endl;
        }
      }
    }

    void displayPubs(){
      cout << "\n\nAll publications: \n" << endl;
      for (auto& p : publications){
        cout << "ID: " << p.getID() << "\nTitle: " << p.getTitle() << "\nAuthor: " << p.getAuthor() << 
        "\nGenre: " << p.getGenre() << "\nPage Count: " << p.getPageCount() << endl;
        }
      }
    

    //add/remove members
    void addMember() {
      cout << "Enter member id" << endl;
      string memberID;
      getline(cin >> ws, memberID);
      if (checkSpace(memberID)) {
        cerr << "Invalid member ID. ID cannot have spaces." << endl;
        return;
      };

      //check if member with same ID already exists
      for (auto& m : members){
        if (m.getMemberID() == memberID){
          cerr << "Member with id " << memberID << " already exists in the library system." << endl;
          return;
        }
      }

      cout << "Enter name" << endl;
      string name;
      getline(cin >> ws, name);
      if (checkSpace(name)) {
        cerr << "Invalid name. Name cannot have spaces." << endl;
        return;
      };

      try {
        Member newMember(memberID, name, {});
        members.push_back(newMember);
        cout << "Member with id " << memberID << " added to library system" << endl;
        cout << "Member name: " << name << endl;
      }
      catch(...){
        cerr << "Error creating member object" << endl;
        return;
      }
    }

    void removeMember(string mID) {
      //check if members empty
      if (members.empty()) {
        cerr << "No members in the library system to remove" << endl;
        return;
      }

      //remove member from library system
      for (auto it = members.begin(); it != members.end(); ++it) {
        if (it->getMemberID() == mID) {
          members.erase(it);
          cout << "Member with id " << mID << " removed from library system" << endl;
          return;
        }
      }
      
    }

    //display all registered members
    void displayAllMembers() {
      cout << "\n\nRegistered members: \n" << endl;
      for (auto& m : members) {
        cout << "Member ID: " << m.getMemberID() << "\nName: " << m.getName() << endl;
      }
    }
   
  
    //load publication info from files
    int loadPublicationInfo() {
      string inputFilename;
      cout << "Enter filename to load publications from (do not include .txt): " << endl;
      getline(cin >> ws, inputFilename);
      string filename = inputFilename + ".txt";
      ifstream ReadPublicationFile(filename);
      if (!ReadPublicationFile) {
        cerr << "Unable to open file" << filename << endl;
        return 0;
      }

      string line;
      while (getline(ReadPublicationFile, line)) {

        if (line.empty()) {
          continue;
        }

        stringstream ss(line);

        string id, title, author, genre;
        int pageCount, isAvail;

        ss >> id;
        //cout << "id: " << id << endl;

        ss.ignore(1);

        getline(ss, title, '"');
        getline(ss, title, '"');

        //cout << "title: " << title << endl;

        ss.ignore(1);
        getline(ss, author, '"');
        getline(ss, author, '"');

        //cout << "author: " << author << endl;

        ss.ignore(1);
        getline(ss, genre, '"');
        getline(ss, genre, '"');

        //cout << "genre: " << genre << endl;

        ss >> pageCount;
        ss >> isAvail;
      
        //cout << "pageCount: " << pageCount << " isAvail: " << isAvail << endl;
        publications.push_back(Publication(id, title, author, genre, pageCount, isAvail));
        //displayAvail();
      }

      ReadPublicationFile.close();

      return 1;
    }


    

    //load member info from files
    int loadMemberInfo() {
      string inputFilename;
      cout << "Enter filename to load members from (do not include .txt): " << endl;
      getline(cin >> ws, inputFilename);
      string filename = inputFilename + ".txt";
      ifstream ReadMemberFile(filename);
      if (!ReadMemberFile) {
        cerr << "Unable to open file " << filename << endl;
        return 0;
      }

      string line;
      while(getline(ReadMemberFile, line)){
        if (line.empty()) {
          continue;
        }

        stringstream ss(line);
        string memberID, name;
        ss >> memberID >> name;

        Member newMember(memberID, name, {});

        vector<string> borrowedItems;
        string itemID;
        while (ss >> itemID) {
          borrowedItems.push_back(itemID);
        }

        newMember.setcurrBorrowed(borrowedItems);
        members.push_back(newMember);

        // mark borrowed books unavailable
        for (auto& p : publications){
          for (auto& bID : borrowedItems){
            if (p.getID() == bID){
              p.setIsAvail(0);
            }
          }
        }
      }
      ReadMemberFile.close();

      return 1;
    }

    //functionality to save the current state of the library  (book inventory and member records) to files
    //store new file
    int saveLibrary() {
      string filename;
      cout << "Enter filename you want to save the library as: (do not include .txt)" << endl;
      cin >> filename;

      while (filename == "books" || filename == "members") {
        cerr << "These files already exist. Please choose a different filename." << endl;
        cin >> filename;
      }

      filename += ".txt";
      //open new text file
      ofstream NewFile(filename);

      if (!NewFile) {
        cerr << "Unable to open file." << endl;
        return 0;
      }

      NewFile << "Publications: " << endl;
      for (auto& p : publications){
        NewFile << p.getID() << " \"" << p.getTitle() << "\" \"" << p.getAuthor() << "\" \"" 
        << p.getGenre() << "\" " << p.getPageCount() << " " << p.getIsAvail() << endl;
      }

      NewFile << "\n\nMembers: " << endl;
      for (auto& m : members){
        NewFile << m.getMemberID() << " " << m.getName();
        vector<string> items = m.getItems();
        for (const auto& itemID : items){
          NewFile << " " << itemID;
        }
        NewFile << endl;
      }

      cout << "Library saved to " << filename << endl;

      //close the file
      NewFile.close();
      return 1;
    }

    void borrowPublication(string pubID, string mID) {
      auto p = findPublicationbyID(pubID);
      if (p != nullptr) {
        if (p->getIsAvail() == 1) {
          //mark as borrowed
          p->setIsAvail(0);
          //add to member's borrowed list
          for (auto& m : members){
            if (m.getMemberID() == mID){
              m.borrowI(pubID);
              cout << "Publication with id " << pubID << " borrowed by member with id " << mID << endl;
              return;
            }
          }
          cerr << "Member with id " << mID << " not found" << endl;
        }
        else {
          cerr << "Publication with id " << pubID << " is not available for borrowing" << endl;
        }
      }
      else {
        cerr << "Publication with id " << pubID << " not found" << endl;
      }
    }

    void returnPublication(string pubID, string mID) {
      auto p = findPublicationbyID(pubID);
      if (p != nullptr) {
        //mark as available
        p->setIsAvail(1);
        //remove from member's borrowed list
        for (auto& m : members){
          if (m.getMemberID() == mID){
            m.returnI(pubID);
            cout << "Publication with id " << pubID << " returned by member with id " << mID << endl;
            return;
          }
        }
        cerr << "Member with id " << mID << " not found" << endl;
      }
      else {
        cerr << "Publication with id " << pubID << " not found" << endl;
      }
    }
};
#endif