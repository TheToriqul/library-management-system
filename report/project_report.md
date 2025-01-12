# Library Management System
PRG 2203E – PROGRAMMING TECHNIQUES

## Table of Contents
1. Introduction
2. System Overview
3. Technical Implementation
4. System Architecture
5. Testing and Validation
6. Conclusion
7. References

## 1. Introduction
The Library Management System is a comprehensive software solution developed in C++ that enables efficient management of library resources. This system provides essential functionalities for managing book records, including adding new books, searching existing records, updating information, and maintaining an organized database of library materials.

### 1.1 Project Objectives
- Develop a user-friendly library management system
- Implement secure file-based data storage
- Ensure data integrity through proper validation
- Provide efficient book record management
- Create an intuitive user interface

### 1.2 Scope
The system handles the following core operations:
- Book record management (Add, Search, Update, Delete)
- Data validation and error handling
- File-based persistent storage
- User interface for interaction

## 2. System Overview

### 2.1 Features
1. **Add New Books**
   - Automatic ID generation
   - Comprehensive data validation
   - Real-time status updates

2. **Search Functionality**
   - Search by book ID
   - Detailed record display
   - Quick search response

3. **Update Records**
   - Selective field updates
   - Data integrity preservation
   - Safe update operations

4. **Delete Records**
   - Safe deletion process
   - Database consistency maintenance
   - Confirmation system

5. **Display Records**
   - Paginated display
   - Formatted table output
   - Navigation options

### 2.2 Data Structure
```cpp
struct Book {
    int id;            // Unique identifier
    char title[50];    // Book title
    char author[30];   // Author name
    float price;       // Book price
    int quantity;      // Available quantity
    char status[10];   // Availability status
};
```

## 3. Technical Implementation

### 3.1 Programming Concepts Used
1. **Operators and Expressions**
   - Arithmetic operators for calculations
   - Relational operators for comparisons
   - Logical operators for conditions

2. **Selection Control Structures**
   - if-else statements for validation
   - switch-case for menu navigation
   - while loops for data processing

3. **Functions**
   - Modular design with specialized functions
   - Input/output handling functions
   - Validation utility functions

4. **File Processing**
   - Binary file operations
   - Safe file handling
   - Error checking mechanisms

5. **Arrays and Structures**
   - Structured data storage
   - Character arrays for strings
   - Record management

### 3.2 File Organization
```
LibrarySystem/
├── src/
│   ├── main.cpp           # Main program entry
│   ├── library.cpp        # Implementation file
│   ├── library.h          # Header file
│   ├── validation.h       # Validation functions
│   ├── Makefile           # Build configuration
│   └── books.dat          # Book records
├── docs/
│   ├── user_manual.txt    # User guide
│   ├── sample_output.md   # Sample output screenshots lookalike
│   └── screenshots/       # Program screenshots
│     ├── AddBooks.png     # Screenshots
│     ├── SearchBooks.png  # Screenshots         
└── report/
    └── project_report.docx
```

### 3.3 Build System
The project uses a Makefile build system with the following features:
- C++11 standard compliance
- Wall warning flags enabled
- Automatic dependency tracking
- Separate compilation of source files
- Clean target for maintenance

## 4. System Architecture

### 4.1 Class Structure
The system is built around the LibrarySystem class, which encapsulates all functionality:
```cpp
class LibrarySystem {
private:
    fstream file;
    Book book;
    // Validation methods
    // Utility functions
public:
    // CRUD operations
    // UI functions
};
```

### 4.2 Data Flow
1. User Input → Validation → Processing → File Operation → Output
2. File Operations: Read → Process → Write → Verify
3. Error Handling: Detect → Report → Recover → Continue

## 5. Testing and Validation

### 5.1 Input Validation
- Title length check (3-49 characters)
- Author name validation (letters and spaces)
- Price range validation (0.01-9999.99)
- Quantity range check (0-999)

### 5.2 File Operation Testing
- File creation verification
- Read/Write operation testing
- Error handling verification
- Data consistency checks

### 5.3 User Interface Testing
- Menu navigation testing
- Input handling verification
- Display formatting checks
- Error message verification

## 6. Conclusion
The Library Management System successfully implements all required functionalities while maintaining data integrity and providing a user-friendly interface. The system demonstrates proper use of C++ programming concepts and follows good software development practices.

## 7. References
1. Stroustrup, B. (2013). The C++ Programming Language, 4th Edition. Addison-Wesley.
2. Deitel, P., & Deitel, H. (2016). C++ How to Program, 10th Edition. Pearson.
3. Meyers, S. (2014). Effective Modern C++. O'Reilly Media.