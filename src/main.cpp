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

int main() {
    LibrarySystem library;  // Create library system instance
    library.mainMenu();     // Start the main program loop
    return 0;              // Exit program
}