// /**
//  * Library Management System Header
//  * Defines the core structures and classes for the library management system
//  */

#ifndef LIBRARY_H
#define LIBRARY_H

#include <fstream>
#include <iostream>
#include <string>
#include <cstring>
#include <iomanip>
#include <stdexcept>
#include <limits>
#include <sstream>
#include <algorithm>
#include <cstdio>

using namespace std;

// Constants for validation
constexpr int MAX_TITLE_LENGTH = 50;
constexpr int MAX_AUTHOR_LENGTH = 30;
constexpr int MAX_STATUS_LENGTH = 10;
constexpr float MIN_PRICE = 0.01f;
constexpr float MAX_PRICE = 9999.99f;
constexpr int MIN_QUANTITY = 0;
constexpr int MAX_QUANTITY = 999;
constexpr int RECORDS_PER_PAGE = 5;

struct Book {
    int id;
    char title[MAX_TITLE_LENGTH];
    char author[MAX_AUTHOR_LENGTH];
    float price;
    int quantity;
    char status[MAX_STATUS_LENGTH];
};

class LibrarySystem {
private:
    fstream file;
    Book book;
    string filename;
    string tempFilename;
    string backupFilename;
    
    // File operations
    bool openFile(const string& mode);
    bool closeFile();
    bool createBackup();
    bool restoreBackup();
    bool commitChanges();
    
    // Validation methods
    bool validateId(int id);
    bool validateTitle(const string& title);
    bool validateAuthor(const string& author);
    bool validatePrice(float price);
    bool validateQuantity(int qty);
    
    // Utility methods
    void clearInputBuffer();
    void showHeader(const string& title);
    void pauseScreen();
    string formatId(int id);
    void safeStrCopy(char* dest, const string& src, size_t maxLen);
    bool getNumericInput(float& value);
    bool getNumericInput(int& value);
    bool getStringInput(string& value, size_t maxLen);
    
public:
    LibrarySystem();
    ~LibrarySystem();
    
    void addBook();
    void searchBook();
    void updateBook();
    void deleteBook();
    void displayBooks();
    void mainMenu();
};

#endif