// from standard lib
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream> 


class User {
    public:
        std::string name;
        int userId;
        std::vector<std::string> checkedOutBooks;
    User(const std::string&_name, int _userId) : name(_name), userId(_userId){}
};

class Library {

    int book_Id;
    std::string book_title;
    std::string author;
    // std::string book_status;

public: 
void control_pan();
void add_book();
void display_books();
void delete_book();
void update_book_status(const std::string& title, const std::string& newStatus);
};


void Library::control_pan()
{
    std::cout << "\t\t*****************************\n";
    std::cout << "\t\t\tLibrary Management System\n";
    std::cout << "\t\t\t Control Panel\n";

    std::cout << "1. Add New Book\n";
    std::cout << "2. Display Books\n";
    std::cout << "3. Delete Book\n";
    std::cout << "4. Checkout Book\n";
    std::cout << "5. Return Book\n";
    
    std::cout << "6. Exit\n";
    
}


void Library::add_book()
{

    std::ofstream outf;
    outf.open("book.txt", std::ios::out | std::ios::app);

    if (outf.is_open()) {
        std::string book_status = "Available";
        std::cout << "Enter Book ID: ";
        std::cin >> book_Id;

        std::cin.ignore(); //to clear newline char from the buffer

        std::cout << "Enter Book Title: ";
        std::getline(std::cin, book_title);

        std::cout << "Enter Author: ";
        std::getline(std::cin, author);

        outf << "Book ID: " << book_Id << std::endl;
        outf << "Book Title: " << book_title << std::endl;
        outf << "Book Author: " << author << std::endl;
        outf << "Book Status: " << book_status << std::endl;

        std::cout << "Book added successfully! \n";
        outf.close();

    } else {
        std::cerr<<"\n ERROR: Failed to open the file! \n";
    }


//    CHECK THE DATA WAS SAVED 

    std::ifstream inputFile("book.txt");
    if (inputFile) {
        inputFile.seekg(0, std::ios::end);
        if(inputFile.tellg() !=0) {
            std::cout << "Book was saved successfully in file" << std::endl;
        } else {
            std::cerr << "ERROR: File is empty" << std::endl;
        }
    } else {
        std::cerr << "ERROR: File does not exist" << std::endl;
    }
    inputFile.close();
}

void Library::update_book_status(const std::string& title, const std::string& newStatus) {
    std::ifstream inputFile("book.txt");
    std::ofstream tempFile("temp.txt");

    std::string line;

    bool bookFound = false;

    while (std::getline(inputFile, line)) {
        if (line.find("Book Title: " + title) != std::string::npos){
            bookFound = true;
            if (line.find("Book Status: Available") != std::string::npos){
                tempFile << "Book Status: " << newStatus << std::endl;
                std::cout << "Book status updated successfully!  Book is now checked out." << std::endl;
            } else {
                std::cout << "Sorry, this book is currently unavailable" << std::endl;
                tempFile << line << std::endl;
            }
        } else {
            tempFile <<line << std::endl;
        }
    }
    inputFile.close();
    tempFile.close();

    if (bookFound){
        std::remove("book.txt");
        std::rename("temp.txt", "book.txt");
    } else {
        std::cout << "Book not found." << std::endl;
        std::remove("temp.txt");
    }
}

void Library::display_books()
{
    std::string getcontent;
    std::ifstream inputFile;
    inputFile.open("book.txt", std::ios::in);
    
    if (inputFile.is_open()) 
    {
        while (std::getline(inputFile, getcontent)) {
            std::cout << getcontent << std::endl;
        }
        inputFile.close();
    } else {
        std::cerr << "Error: Unable to open the file.";
    }
}


void Library::delete_book(){
// open the file we are reading from
// in that file, look for the title we want to delete
// create a new temp file to hold the new data with all the books minus the one we want to delete

    std::ifstream inputFile("book.txt");
    
    // new file to rewrite the data

    std::ofstream newFile("updatedbooks.txt");

    std::string title;
    std::cout << "What book should we delete? ";
    std::cin.ignore();
    std::getline(std::cin, title);

    std::string line;


    while (std::getline(inputFile, line)) {
        if(line.find(title) == std::string::npos) {
            newFile << line << std::endl;
        }
    }
    inputFile.close();
    newFile.close();
    std::remove("book.txt");
    std::rename("updatedbooks.txt", "book.txt");
}


int main()
{

    User user("RK", 1);
    
    Library l;

    l.control_pan();
    int choice;
    std::string title, status;
    // char status, title;
    

    char x;
    std::cout << "\n\n Your Choice: ";
    std::cin >> choice;

    switch (choice) {
        case 1: 
        {
            do { 
                l.add_book();
                std::cout << "Add another book? (y/n): ";
                std::cin >> x;
                std::cin.ignore();
            } while (x == 'y');
            break;
        }
        case 2: 
        {
            l.display_books();
            break;
        case 3: 
            l.delete_book();
            break;
        }
        case 4: // write logic to check if a book is checkout out/returned before checking it out
        {
            std:: string title, status; 
            std::cout << "Enter the title you want to checkout: ";
            std::cin.ignore();
            std::getline(std::cin, status);

            l.update_book_status(title, status);
            std::cout << "Book Successfully checked out!" << std::endl;
            break;
        }
        default:
        {
            std::cout << "\n\n Invalid Value....Please Try again";
            break;
        }

    return 0;
    } 
};