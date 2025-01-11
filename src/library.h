/**
 * Library Management System Header
 * Defines the core structures and classes for the library management system
 */

#ifndef LIBRARY_H
#define LIBRARY_H

#include <fstream>
#include <iostream>
#include <cstring>
#include <iomanip>
#include <cstdlib>

using namespace std;

/**
 * Book Structure
 * Represents a single book record in the library system
 */
struct Book {
    int id;            // Unique identifier for the book
    char title[50];    // Book title (max 49 chars + null terminator)
    char author[30];   // Author name (max 29 chars + null terminator)
    float price;       // Book price in currency units
    int quantity;      // Number of copies available
    char status[10];   // Current status (Available/Out)
};

/**
 * LibrarySystem Class
 * Manages all operations related to the library management system
 */
class LibrarySystem {
private:
    fstream file;      // File stream for database operations
    Book book;         // Book object for temporary storage
    
    /**
     * Input Validation Methods
     */
    bool validateId(int id);           // Validates book ID uniqueness
    bool validateTitle(const char* title);    // Validates book title
    bool validateAuthor(const char* author);  // Validates author name
    bool validatePrice(float price);          // Validates book price
    bool validateQuantity(int qty);           // Validates quantity
    void clearInputBuffer();                  // Clears cin buffer
    void pauseScreen();
    void clearScreen(); 

public:
    /**
     * Constructor
     * Opens or creates the database file
     */
    LibrarySystem();

    /**
     * Destructor
     * Ensures proper closure of file handles
     */
    ~LibrarySystem();
    
    /**
     * Core CRUD Operations
     */
    void addBook();        // Add new book to database
    void searchBook();     // Search for a book by ID
    void updateBook();     // Update existing book details
    void deleteBook();     // Remove book from database
    void displayBooks();   // Show all books with pagination
    
    /**
     * User Interface Methods
     */
    void mainMenu();       // Display main menu and handle choices
    void showHeader(const char* title);  // Display formatted headers
};

#endif