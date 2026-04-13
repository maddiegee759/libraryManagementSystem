# Maddie Gee - Multi-Paradigm Programming CS21003 
C++ Assignment Report
 
<img src=simpleClassDiagram.png>

In the simple class diagram three classes are included: Book, Member, Library. The Book class includes attributes holding key information about a book. The bookid can be used to identify and differentiate between books as they must all be unique. pageCount must be above 0 and isAvail must be 1 or 0. 
Member includes memberID, name and currItems. In this version of program the name attribute can only contain one string for either first or last name. This is positive for increasing client confidence as many personal details are not stored unnecessarily but members can still be identified by their memberID. currItems relates to the publications that the member has borrowed.
Library class includes all methods that provide functionality. The user can call each method through a switch case in the main part of the code. As the menu can be run indefinitely the user can perform multiple different tasks one after another. 
 

<img src=classDiagram.png>

In the above class diagram Book, Magazine and Journal inherit from Publication which enables the system to store different types of publications. This is useful for code reusability and maintainability as it can be easily edited and adapted for future publication types while keeping the original functionality. All method names are also more general and slightly adapted to fit different publication types not just book. 

### library.h
|Method|Description|
|:-|:-|
|void addPublication()|Gets user input with all publication information, validates it then adds it to the library as a book, magazine or journal|
|int checkSpace()|Checks if a string has any spaces in it|
|Publication* findPublicationByTitle(string title)|	Searches through publication titles until one matches exactly to the title entered. One disadvantage of this is that it does not account for any differences such as a misspelling or typo|
|Publication* findPublicationbyID(string ID)|	Searches through publication IDs until one matches exactly to the ID entered|
|int removePublication(string ID)|A publication is found and removed or an error is displayed|
|void displayAvail()|Displays all currently available publications|
|void displayPubs()|Displays all publications in the library system|
|void addMember()|Gets user input for a new member and adds it to the library system unless there are any invalid inputs|
|void removeMember(string mID)|Member is found using their ID and removed from the library system|
|void displayAllMembers()|Displays all members|
|int loadPublicationInfo(string filename)|Adds publications into the library system from a text file|
|int loadMemberInfo(string filename)|Adds members into the library system from a text file|
|int saveLibrary()|Saves the current library including books and members to a text file|
|void borrowPublication(string pubID, string mID)|Publication is found and set to borrowed in both the publications and the members unless an error occurs|
|void returnPublication(string pubID, string mID)|Publication is found and removed from members borrowed list and set back to available|


### member.h
|Method|Description|
|:-|:-|
|void borrowI(string b)|Adds publication onto members currently borrowed publications unless an error occurs|
|void returnI(string b)|Removes publication from members currently borrowed publications unless an error occurs|

Objects are used in order to establish a blueprint for each class as properties attributes and methods can be utilised. This helped with consistency across the program as the attributes are defined clearly. 

Input validation is also easier to implement with modular programming concepts as code can be reused and inputs do not need to be revalidated. 

 
### Testing
All tests work as expected

### Instructions
Ensure all files are in one folder: book.h, journal.h, library.h, magazine.h, main.cpp, member.h, publication.h (and any .txt files such as books.txt/members.txt)

Compile simply by typing ‘g++ main.cpp’ into the command line

Follow menu instructions to use the system

Note: books.txt is edited to set B105, B106 and B107 to available but if using the original books.txt file they will be unavailable 

### References
geeksforgeeks. dot (.) operator in C++. https://www.geeksforgeeks.org/cpp/dot-operator-in-cpp/

geeksforgeeks. Iterate over characters of a string in C++. https://www.geeksforgeeks.org/cpp/iterate-over-characters-of-a-string-in-c/

VULTR. C++ cctype isspace() - Check for Whitespace Character. https://docs.vultr.com/cpp/standard-library/cctype/isspace

w3Schools. Constructors. - https://www.w3schools.com/cpp/cpp_constructors.asp

w3Schools. C++ Exceptions. https://www.w3schools.com/cpp/cpp_exceptions.asp 

w3Schools. Vectors. https://www.w3schools.com/cpp/cpp_vectors.asp


