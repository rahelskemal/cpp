// from standard lib
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream> 

class Library {

    int book_Id;
    std::string book_title;
    std::string author;

public: 
    void control_pan();
    void add_book();
    void add_book_v();
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
    std::cout << "3. Delete Book\n";
    std::cout << "4. Checkout Book\n";
    std::cout << "5. Return Book\n";
    
    std::cout << "6. Exit\n";
    
}

// using vectors - similar to an array but allows an array to dynamically change sizes
void Library::add_book_v(){

    // creating a vector 
    std::vector<Library> books;
    std::string input; 

    while (true) {
        Library book;
        std::cout << "Enter Book Title" << std::endl;
        std::getline(std::cin, input);

        book.book_title = input;

        std::cout << "Who is the Author?: ";
        std::getline(std::cin, input);
        std::istringstream(input) >> book.author;

        // adding to the end of a vector
        books.push_back(book);

        std::ofstream outf;
        outf.open("book.txt", std::ios::out | std::ios::app);
        if(!outf.is_open()) {
            std::cerr<<"\nNot able to create a file. MAJOR OS ERROR!! \n";
            outf.close();
        } 

        for (auto& book : books ) {
            outf << book.book_title << " " << book.author << std::endl;
        }

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

}

void Library::add_book()
{
    // ofstream creates and writes to a file 
    // std::ofstream bookFile("filename.txt");
    // // ifstream reads from a file
    // std::ifstream bookFile;

    // data file that holds all books 
 
    // variables 
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


void Library::delete_book(){
// open the file we are reading from
// in that file, look for the title we want to delete
// create a new temp file to hold the new data with all the books minus the one we want to delete

    std::ifstream inputFile("book.txt");
    
    // new file to rewrite the data

    std::ofstream newFile("updatedbooks.txt");

    std::string line;
    std::string title;

    std::cout << "What book should we delete? ";
    std::cin >> title;

    while (std::getline(inputFile, line)) {
        if(line.find(title) == std::string::npos) {
            newFile << line << std::endl;
        }
    }
    inputFile.close();
    newFile.close();
}



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
            l.add_book_v();
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
    case 3: 
        {
            l.delete_book();
        }
        break;
    default:
        std::cout << "\n\n Invalid Value....Please Try again";
        break;
    }

    return 0;
};