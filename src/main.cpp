/**
 * Library Management System
 * Main Program Entry Point
 * 
 * This program implements a simple library management system
 * with basic CRUD operations for managing book records.
 * 
 * Features:
 * - Add new books to the library
 * - Search for books by ID
 * - Update existing book records
 * - Delete books from the system
 * - Display all books with pagination
 * 
 * File Structure:
 * - main.cpp: Program entry point
 * - library.h: Class and structure definitions
 * - library.cpp: Implementation of library functions
 * - validation.h: Input validation utilities
 */

#include "library.h"
#include <iostream>

int main() {
    try {
        LibrarySystem library;
        library.mainMenu();
    } catch (const exception& e) {
        cerr << "Fatal error: " << e.what() << endl;
        return 1;
    } catch (...) {
        cerr << "Unknown fatal error occurred!" << endl;
        return 1;
    }
    return 0;
}