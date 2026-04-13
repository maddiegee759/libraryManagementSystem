#include <iostream>
#include "library.h"
#include "member.h"
#include "publication.h"
#include "book.h"
#include "magazine.h"
#include "journal.h"
#include <string>
using namespace std;

int main(){
    //cout << "yay assignment" << endl;
    
    Library libSystem;
    //create obj for book1
    //Publication book1("B101", "The Power of Positive Thinking", "Norman Vincent Peale", "Motivational, Spirituality", 240, 1);
    /** 
    Book book1;
    book1.bookID = "B101";
    book1.title = "tpopt";
    book1.author = "nv";
    book1.genre = "motivational";
    book1.pageCount = 240;
    book1.isAvail = 1;
    */

     
    //libSystem.publications.push_back(book1);

    //libSystem.loadMemberInfo("members.txt");
    //libSystem.displayAllMembers();
    //display books borrowed 
    
    cout << endl;
    for (int i = 0; i < libSystem.members.size(); i++){
        vector<string> items = libSystem.members[i].getItems();
        cout << "Member ID: " << libSystem.members[i].getMemberID() << " has borrowed: ";
        for (const auto& itemID : items){
            cout << itemID << " ";
        }
        cout << endl;
    }

    



    
    //int diditwork = libSystem.loadPublicationInfo("books.txt");
    //cout << "Did it work? " << diditwork << endl;    
    
    //menu
    int userChoice = -1;
    int check;
    string searchID, searchTitle;
    cout << "Welcome to the Library Management System Menu!\n";
    do {
        cout << "\n------------MENU------------";
        cout << "\n1.Display All Publications\n2.Display Available Publications\n3.Borrow Publication\n4.Return Publication\n5.Add Publication\n6.Remove Publication\n7.Find Publication by ID\n8.Find Publication by Title\n9.Add Member\n10.Remove Member\n11.Display All Members\n12.Load Publications From a File\n13.Load Members From a File\n14.Save Library\n0.Exit\n";
        cout << "Enter your choice: ";
        cin >> userChoice;

        switch (userChoice) {
            case 1:
                cout << "Display All Publications selected\n";
                libSystem.displayPubs();
                break;
            case 2:
                cout << "Display Available Publications selected\n";
                libSystem.displayAvail();
                break;
            case 3: {
                cout << "Borrow Publication selected\n";
                string pubID, memID;
                cout << "Enter Publication ID to borrow: ";
                cin >> pubID;
                cout << "Enter Member ID: ";
                cin >> memID;
                libSystem.borrowPublication(pubID, memID);
                break;
            }
            case 4: {
                cout << "Return Publication selected\n";
                string pubID, memID;
                cout << "Enter Publication ID to return: ";
                cin >> pubID;
                cout << "Enter Member ID: ";
                cin >> memID;
                libSystem.returnPublication(pubID, memID);
                break;
            }
            case 5:
                cout << "Add Publication selected\n";
                libSystem.addPublication();
                break;
            case 6: {
                cout << "Remove Publication selected\n";
                string pubID;
                cout << "Enter Publication ID to remove: ";
                cin >> pubID;
                libSystem.removePublication(pubID);
                break;
            }
            case 7:
                cout << "Find Publication by ID selected\n";
                cout << "Enter Publication ID to search: ";
                cin >> searchID;
                libSystem.findPublicationbyID(searchID);
                break;
            case 8:
                cout << "Find Publication by Title selected\n";
                cout << "Enter Publication Title to search: ";
                getline(cin >> ws, searchTitle);
                libSystem.findPublicationByTitle(searchTitle);
                break;
            case 9:
                cout << "Add Member selected\n";
                libSystem.addMember();
                break;
            case 10: {
                cout << "Remove Member selected\n";
                string memID;
                cout << "Enter Member ID to remove: ";
                cin >> memID;
                libSystem.removeMember(memID);
                break;
            }
            case 11:
                cout << "Display All Members selected\n";
                libSystem.displayAllMembers();
                break;
            case 12:
                cout << "Load Publications From a File selected\n";
                //libSystem.loadPublicationInfo("books.txt");
                check = libSystem.loadPublicationInfo();
                if (check == 1){
                    cout << "Publications loaded successfully from file" << endl;
                }
                else {
                    cout << "Failed to load publications from file" << endl;
                }
                break;
            case 13:
                cout << "Load Members From a File selected\n";
                check = libSystem.loadMemberInfo();
                if (check == 1){
                    cout << "Members loaded successfully from file" << endl;
                }
                else {
                    cout << "Failed to load members from file" << endl;
                }
                break;
            case 14:
                cout << "Save Library selected\n";
                check = libSystem.saveLibrary();
                if (check == 1){
                    cout << "Library saved successfully." << endl;
                }
                else {
                    cout << "Failed to save library" << endl;
                }
                break;
            case 0:
                cout << "Exiting the program" << endl;
                return 0;
            default:
                cout << "Invalid choice. Please try again\n" << endl;
                break;
        }
    } while (userChoice != 0);
     
    return 0;
}