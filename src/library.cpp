/**
 * Library Management System Implementation
 * Contains the core functionality for managing library books including
 * CRUD operations, file handling, and user interface components.
 */

#include "library.h"
#include "validation.h"
#include <sstream>
#include <iomanip>
#include <cstring>
#include <cctype>
#include <iostream>
#include <cstdlib>
#include <limits>

// Utility functions
static string formatId(int id) {
    ostringstream ss;
    ss << setw(4) << setfill('0') << id;
    return ss.str();
}

// Class implementation
LibrarySystem::LibrarySystem() {
    file.open("books.dat", ios::binary | ios::in | ios::out | ios::app);
    if (!file) {
        file.clear();
        file.open("books.dat", ios::binary | ios::out);
        file.close();
        file.open("books.dat", ios::binary | ios::in | ios::out | ios::app);
        if (!file) {
            cout << "Error: Unable to create or open database file!\n";
            cout << "Please check file permissions and disk space.\n";
            exit(1);
        }
    }
}

LibrarySystem::~LibrarySystem() {
    if (file.is_open()) {
        file.close();
    }
}

void LibrarySystem::clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void LibrarySystem::showHeader(const char* title) {
    #ifdef _WIN32
        system("cls");
    #else
        system("clear");
    #endif
    cout << "\n=======================================\n";
    cout << "       " << title << "\n";
    cout << "=======================================\n";
}

void LibrarySystem::pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cin.get();
}

// Validation methods
bool LibrarySystem::validateId(int id) {
    if (id <= 0) return false;
    
    file.clear();
    file.seekg(0, ios::beg);
    Book temp;
    while (file.read(reinterpret_cast<char*>(&temp), sizeof(Book))) {
        if (temp.id == id) return false;
    }
    return true;
}

bool LibrarySystem::validateTitle(const char* title) {
    return isValidLength(title, 3, 49);
}

bool LibrarySystem::validateAuthor(const char* author) {
    return isValidLength(author, 2, 29) && isAlphaSpace(author);
}

bool LibrarySystem::validatePrice(float price) {
    return isValidPrice(price);
}

bool LibrarySystem::validateQuantity(int qty) {
    return isValidQuantity(qty);
}

/**
 * Adds a new book to the library database
 * Automatically generates new book ID
 * Validates all input fields
 * Allows adding multiple books in succession
 */
void LibrarySystem::addBook() {
    char continueAdding;
    
    do {
        showHeader("ADD NEW BOOK");
        
        // Close and reopen file to ensure fresh state
        if (file.is_open()) {
            file.close();
        }
        file.open("books.dat", ios::binary | ios::in | ios::out | ios::app);
        
        // Get the next ID
        file.seekg(0, ios::end);
        int lastPos = file.tellg();
        int newId = 1;
        
        if (lastPos > 0) {
            file.seekg(lastPos - sizeof(Book));
            Book lastBook;
            file.read(reinterpret_cast<char*>(&lastBook), sizeof(Book));
            newId = lastBook.id + 1;
        }
        
        book.id = newId;
        
        clearInputBuffer();
        
        cout << "\nEnter Book Title: ";
        cin.getline(book.title, 50);
        while (!validateTitle(book.title)) {
            cout << "Invalid title! Must be 3-49 characters. Try again: ";
            cin.getline(book.title, 50);
        }
        
        cout << "Enter Author Name: ";
        cin.getline(book.author, 30);
        while (!validateAuthor(book.author)) {
            cout << "Invalid author name! Use only letters and spaces: ";
            cin.getline(book.author, 30);
        }
        
        cout << "Enter Price: ";
        cin >> book.price;
        while (!validatePrice(book.price)) {
            cout << "Invalid price! Enter between 0.01 and 9999.99: ";
            cin >> book.price;
        }
        
        cout << "Enter Quantity: ";
        cin >> book.quantity;
        while (!validateQuantity(book.quantity)) {
            cout << "Invalid quantity! Enter between 0 and 999: ";
            cin >> book.quantity;
        }
        
        strcpy(book.status, book.quantity > 0 ? "Available" : "Out");
        
        // Write to file
        file.seekp(0, ios::end);
        file.write(reinterpret_cast<char*>(&book), sizeof(Book));
        file.flush(); // Force write to disk
        
        // Close and reopen file to ensure data is written
        file.close();
        file.open("books.dat", ios::binary | ios::in | ios::out | ios::app);
        
        cout << "\nBook added successfully!\n";
        cout << "\nDo you want to add another book? (Y/N): ";
        cin >> continueAdding;
        
    } while (toupper(continueAdding) == 'Y');
}

/**
 * Searches for a book by ID
 * Displays full book details if found
 */
void LibrarySystem::searchBook() {
    showHeader("SEARCH BOOK");
    
    int searchId;
    cout << "\nEnter Book ID to search: ";
    cin >> searchId;
    
    // Search for book in database
    bool found = false;
    file.clear();
    file.seekg(0, ios::beg);
    
    while (file.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
        if (book.id == searchId) {
          // Display book details
            cout << "\nBook Details:\n";
            cout << "ID: " << formatId(book.id) << endl;
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Price: $" << fixed << setprecision(2) << book.price << endl;
            cout << "Quantity: " << book.quantity << endl;
            cout << "Status: " << book.status << endl;
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "\nBook not found!\n";
    }
    
    pauseScreen();
}

/**
 * Updates an existing book's information
 * Uses a temporary file to safely update records
 * Allows user to keep current values by pressing Enter
 * @note Creates backup before modification
 */
void LibrarySystem::updateBook() {
    showHeader("UPDATE BOOK");
    
    int updateId;
    cout << "\nEnter Book ID to update: ";
    cin >> updateId;
    
    // Create temporary file for safe update
    bool found = false;
    fstream tempFile;
    tempFile.open("temp.dat", ios::binary | ios::out);
    
    if (!tempFile) {
        cout << "\nError: Unable to create temporary file!\n";
        pauseScreen();
        return;
    }
    
    file.clear();
    file.seekg(0, ios::beg);
    
    // Search for book and process update
    while (file.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
        if (book.id == updateId) {
            // Display current book information
            cout << "\nCurrent Book Details:\n";
            cout << "ID: " << formatId(book.id) << endl;
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Price: $" << fixed << setprecision(2) << book.price << endl;
            cout << "Quantity: " << book.quantity << endl;
            
            Book updatedBook = book;
            string input;
            
            // Clear input buffer once before getting updates
            clearInputBuffer();
            
            // Update title if new value provided
            cout << "\nEnter new Title (press Enter to keep current): ";
            getline(cin, input);
            if (!input.empty() && validateTitle(input.c_str())) {
                strncpy(updatedBook.title, input.c_str(), 49);
                updatedBook.title[49] = '\0';
            }
            
            // Update author if new value provided
            cout << "Enter new Author (press Enter to keep current): ";
            getline(cin, input);
            if (!input.empty() && validateAuthor(input.c_str())) {
                strncpy(updatedBook.author, input.c_str(), 29);
                updatedBook.author[29] = '\0';
            }
            
            // Update price if new value provided
            cout << "Enter new Price (press Enter to keep current): ";
            getline(cin, input);
            if (!input.empty()) {
                float newPrice = stof(input);
                if (validatePrice(newPrice)) {
                    updatedBook.price = newPrice;
                }
            }
            
            // Update quantity if new value provided
            cout << "Enter new Quantity (press Enter to keep current): ";
            getline(cin, input);
            if (!input.empty()) {
                int newQty = stoi(input);
                if (validateQuantity(newQty)) {
                    updatedBook.quantity = newQty;
                    strcpy(updatedBook.status, newQty > 0 ? "Available" : "Out");
                }
            }
            
            // Write updated record to temporary file
            tempFile.write(reinterpret_cast<char*>(&updatedBook), sizeof(Book));
            found = true;
        } else {
            // Copy existing record to temporary file
            tempFile.write(reinterpret_cast<char*>(&book), sizeof(Book));
        }
    }
    
    // Close both files before file operations
    file.close();
    tempFile.close();
    
    if (found) {
        if (remove("books.dat") == 0 && rename("temp.dat", "books.dat") == 0) {
            cout << "\nBook updated successfully!";
        } else {
            cout << "\nError: Unable to update database!";
            if (rename("temp.dat", "books.dat") != 0) {
                remove("temp.dat");
            }
        }
    } else {
        cout << "\nBook not found!"; // Removed newline
        remove("temp.dat");
    }
    
    // Reopen main database file with proper error handling
    file.open("books.dat", ios::binary | ios::in | ios::out | ios::app);
    if (!file) {
        cout << "\nError: Unable to reopen database!\n";
        exit(1);
    }
    
    cout << "\n\nPress Enter to continue...";
    cin.get(); // Single pause at the end
}

/**
 * Deletes a book from the database
 * Uses temporary file for safe deletion
 * @note Creates backup before deletion
 */
void LibrarySystem::deleteBook() {
    showHeader("DELETE BOOK");
    
    int deleteId;
    cout << "\nEnter Book ID to delete: ";
    cin >> deleteId;
    
    // Create temporary file for safe deletion
    fstream tempFile;
    tempFile.open("temp.dat", ios::binary | ios::out);
    
    file.clear();
    file.seekg(0, ios::beg);
    bool found = false;
    
    // Copy records to temporary file, excluding the book to be deleted
    while (file.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
        if (book.id != deleteId) {
            tempFile.write(reinterpret_cast<char*>(&book), sizeof(Book));
        } else {
            found = true;
        }
    }
    
    // Close both files before file operations or perform file replacement
    file.close();
    tempFile.close();
    
    remove("books.dat");
    rename("temp.dat", "books.dat");
    
    // Reopen main database file
    file.open("books.dat", ios::binary | ios::in | ios::out | ios::app);
    
    if (found) {
        cout << "\nBook deleted successfully!\n";
    } else {
        cout << "\nBook not found!\n";
    }
    
    pauseScreen();
}

/**
 * Displays all books in a tabular format
 * Shows ID, Title, Author, Price, Quantity, and Status
 * @note Truncates long titles and author names to fit display
 */
void LibrarySystem::displayBooks() {
    const int RECORDS_PER_PAGE = 5;  // Number of records to show per page
    int currentPage = 1;
    int totalRecords = 0;
    char choice;
    
    // Count total records first
    file.clear();
    file.seekg(0, ios::beg);
    Book tempBook;
    while (file.read(reinterpret_cast<char*>(&tempBook), sizeof(Book))) {
        totalRecords++;
    }
    
    if (totalRecords == 0) {
        showHeader("DISPLAY ALL BOOKS");
        cout << "\nNo books found in the system!\n";
        this->pauseScreen();
        return;
    }
    
    int totalPages = (totalRecords + RECORDS_PER_PAGE - 1) / RECORDS_PER_PAGE;
    
    do {
        showHeader("DISPLAY ALL BOOKS");
        cout << "\nPage " << currentPage << " of " << totalPages << endl;
        
        // Display table header
        cout << "\n" << setw(6) << "ID" << setw(30) << "Title" << setw(20) << "Author";
        cout << setw(10) << "Price" << setw(10) << "Qty" << setw(12) << "Status" << endl;
        cout << string(88, '-') << endl;
        
        // Calculate starting record for current page
        int startRecord = (currentPage - 1) * RECORDS_PER_PAGE;
        file.clear();
        file.seekg(startRecord * sizeof(Book));
        
        // Display records for current page
        int displayedRecords = 0;
        while (displayedRecords < RECORDS_PER_PAGE && 
               file.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
            cout << "  " << formatId(book.id);
            cout << setw(30) << book.title;
            cout << setw(20) << book.author;
            cout << setw(10) << fixed << setprecision(2) << book.price;
            cout << setw(10) << book.quantity;
            cout << setw(12) << book.status << endl;
            displayedRecords++;
        }
        
        // Display navigation options
        cout << "\n----------------------------------------\n";
        cout << "Total Books: " << totalRecords << " | Page " << currentPage << " of " << totalPages;
        cout << "\nN: Next Page | P: Previous Page | Q: Return to Main Menu";
        cout << "\nEnter your choice: ";
        
        cin >> choice;
        choice = toupper(choice);
        
        switch (choice) {
            case 'N':  // Next page
                if (currentPage < totalPages) {
                    currentPage++;
                }
                break;
                
            case 'P':  // Previous page
                if (currentPage > 1) {
                    currentPage--;
                }
                break;
                
            case 'Q':  // Quit
                return;
                
            default:
                cout << "\nInvalid choice!";
                this->pauseScreen();
        }
        
    } while (true);
}

/**
 * Main program loop
 * Displays menu and handles user choices
 * @note Continues until user selects exit option
 */
void LibrarySystem::mainMenu() {
    int choice;
    
    do {
       // Display main menu and get user choice
        showHeader("LIBRARY MANAGEMENT SYSTEM");
        cout << "\n1. Add New Book";
        cout << "\n2. Search Book";
        cout << "\n3. Update Book";
        cout << "\n4. Delete Book";
        cout << "\n5. Display All Books";
        cout << "\n6. Exit";
        cout << "\n\nEnter your choice (1-6): ";
        
        cin >> choice;
        
        // Handle user choice and perform corresponding function
        switch (choice) {
            case 1: addBook(); break;
            case 2: searchBook(); break;
            case 3: updateBook(); break;
            case 4: deleteBook(); break;
            case 5: displayBooks(); break;
            case 6: cout << "\nThank you for using Library Management System!\n"; break;
            default: cout << "\nInvalid choice! Please try again.\n";
                    pauseScreen();
        }
    } while (choice != 6);
}