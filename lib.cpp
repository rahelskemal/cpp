// from standard lib
#include <iostream>
#include <fstream>

class Library {

    int book_Id;
    char book_title;
    char author;
    int book_no;

public: 
    void control_pan();
    void add_book();
    // void show_data();
    void display_books();
    void delete_book();
};

void Library::control_pan()
{
    std::cout << "\t\t*****************************\n";
    std::cout << "\t\t\tLibrary Management System\n";
    std::cout << "\t\t\t Control Panel\n";

    std::cout << "1. Add New Book\n";
 
    std::cout << "2. Display Books\n";
    std::cout << "3. Check Specific Item\n";
    std::cout << "4. Delete Book\n";
    std::cout << "5. Exit\n";
    
}

void Library::add_book()
{
    // ofstream creates and writes to a file 
    // std::ofstream bookFile("filename.txt");
    // // ifstream reads from a file
    // std::ifstream bookFile;

    // data file that holds all books 
 
    // variables 
    // int no_book;
    int book_Id;
    std::string book_title;
    std::string author;

    // USER INPUT TO ADD NEW BOOK
    std::cout << "\n\n\t\t\t\t Add New Item: \n";
    // std::cout << "----------------------------------------------"
    //         "----------------------------\n";
    std::cout << " Book ID:  ";
    std::cin >> book_Id;

    std::cout << "Book Title: ";
    std::cin >> book_title;

    std::cout << "Author: ";
    std::cin >> author;

    

    // std::cout << "\n\n No. Of Item: ";
    // std::cin >> no_book;

    // 
    std::ofstream outf;
    outf.open("book.txt", std::ios::out | std::ios::app);
    if(!outf.is_open()) {
        std::cerr<<"\nNot able to create a file. MAJOR OS ERROR!! \n";
        outf.close();
    } 

    outf << "Book ID: " << book_Id << std::endl;
    outf << "Book Title: " << book_title << std::endl;
    outf << "Book Author: " << author << std::endl;
    // outf << no_book << std::endl;

    // outf << " " << book_Id << " " << book_title << " "
    //      << author << " " << no_book << "\n";
    // std::cout << "=============================================="
    //         "============================"
    //      << std::endl;

    if (outf.fail()) {
        std::cerr << "ERROR: Failed to write data to the file" <<std::endl;
        outf.close(); 
    } 
   
   outf.close();
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


// void Library::show_data() 
// {
//     std::cout <<"\nBook ID: " <<book_Id;
//     std::cout <<"\nBook Title: " <<book_title;
// }

void Library::display_books()
{
    std::string getcontent;
    std::ifstream inputFile;
    inputFile.open("book.txt", std::ios::in);
    // std::ifstream openfile("book.txt");
    if (!inputFile.is_open()) 
    {

        std::cerr << "Error: Unable to open the file.";
    }
    
    while(std::getline(inputFile, getcontent)) {
            std::cout << getcontent << std::endl;
        }

    inputFile.close();
    }


void Library::delete_book(){}



int main()
{
    Library l;

    l.control_pan();
    int choice;

    char x;
    std::cout << "\n\n Your Choice: ";
    std::cin >> choice;

    switch (choice)
    {
    case 1:
        do {
            l.add_book();
            std::cout << "Do You Want To add another Book? (y/n) "
                    ": ";
            std::cin >> x;
        } while (x == 'y');
        break;
    case 2: 
        {
            l.display_books();
        }
        break;
    default:
        std::cout << "\n\n Invalid Value....Please Try again";
        break;
    }

    return 0;
};