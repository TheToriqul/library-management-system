# Library Management System - Project Plan

## 1. Project Overview

### 1.1 Basic Information
**Duration**: 4 weeks
**Language**: C++
**Storage**: File-based (.dat files)
**Required Features**: Add, Search, Update, Delete, Display records

### 1.2 Purpose
- Create a simple but professional library management system
- Demonstrate C++ programming concepts
- Implement file handling operations
- Show proper input validation
- Create user-friendly interface

## 2. Project Structure

### 2.1 File Organization
```
LibrarySystem/
├── src/
│   ├── main.cpp           # Main program entry
│   ├── library.cpp        # Implementation file
│   ├── library.h          # Header file
│   ├── validation.h       # Validation functions
│   ├── Makefile           # Build configuration
│   ├── CMakeLists.txt     # Build configuration for CMakeLists
│   └── books.dat          # Book records
├── docs/
│   ├── user_manual.txt    # User guide
│   ├── sample_output.md   # Sample output screenshots lookalike
│   └── screenshots/       # Program screenshots
│    ├── AddBooks.png     # Screenshots
│    ├── SearchBooks.png  # Screenshots         
├── report/
│    └── project_report.docx
└── README.md             
```

### 2.2 Core Components

#### Data Structure
```cpp
struct Book {
    int id;            // Unique identifier
    char title[50];    // Book title
    char author[30];   // Author name
    float price;       // Book price
    int quantity;      // Available quantity
    char status[10];   // Available/Borrowed
};
```

#### Class Structure
```cpp
class LibrarySystem {
private:
    // File handling
    fstream file;
    Book book;
    
    // Validation methods
    bool validateId(int id);
    bool validateTitle(const char* title);
    bool validateAuthor(const char* author);
    bool validatePrice(float price);
    bool validateQuantity(int qty);

public:
    // Constructor/Destructor
    LibrarySystem();
    ~LibrarySystem();
    
    // Core functions
    void addBook();
    void searchBook();
    void updateBook();
    void deleteBook();
    void displayBooks();
    
    // Menu system
    void mainMenu();
    void showHeader(const char* title);
};
```

### 2.3 Important Code Comments
```cpp
/**************************************
* Function: functionName
* Purpose: Brief description
* Parameters: List parameters
* Returns: Return value
**************************************/
```

## 3. Implementation Timeline

### Week 1: Basic Setup & Structure
- [ ] Create project folders
- [ ] Set up basic file structure
- [ ] Implement Book structure
- [ ] Create main menu interface
- [ ] Add input validation functions

### Week 2: Core Features
- [ ] Implement addBook() with validation
- [ ] Implement searchBook()
- [ ] Implement displayBooks()
- [ ] Test file operations
- [ ] Add error handling

### Week 3: Advanced Features
- [ ] Implement updateBook()
- [ ] Implement deleteBook()
- [ ] Enhance validation
- [ ] Improve UI formatting
- [ ] Test all features

### Week 4: Documentation & Finalization
- [ ] Complete code comments
- [ ] Create user manual
- [ ] Take screenshots
- [ ] Prepare presentation
- [ ] Final testing

## 4. Detailed Feature Specifications

### 4.1 User Interface Design
```
=======================================
       LIBRARY MANAGEMENT SYSTEM
=======================================
1. Add New Book
2. Search Book
3. Update Book
4. Delete Book
5. Display All Books
6. Exit
=======================================
Enter your choice (1-6): _
```

### 4.2 Data Validation Rules

#### Input Validation
- **Book ID**
  - Positive integer only
  - Auto-incrementing
  - Check for duplicates

- **Title**
  - Length: 3-50 characters
  - No special characters
  - Cannot be empty

- **Author**
  - Length: 2-30 characters
  - Letters and spaces only
  - Cannot be empty

- **Price**
  - Positive number only
  - Maximum 9999.99
  - Two decimal places

- **Quantity**
  - Non-negative integer
  - Maximum 999

### 4.3 File Operations
- Use binary file operations
- Create backup before updates
- Handle file open/close properly
- Error checking for operations

## 5. Function Specifications

### 5.1 Add Record
```cpp
void addBook() {
    // 1. Show input form
    // 2. Validate each input
    // 3. Confirm addition
    // 4. Write to file
    // 5. Show success/error message
}
```

### 5.2 Search Record
```cpp
void searchBook() {
    // 1. Get search criteria
    // 2. Read file
    // 3. Display formatted results
    // 4. Handle "not found" case
}
```

### 5.3 Update Record
```cpp
void updateBook() {
    // 1. Find record
    // 2. Show current values
    // 3. Get new values
    // 4. Validate changes
    // 5. Update file
}
```

### 5.4 Delete Record
```cpp
void deleteBook() {
    // 1. Find record
    // 2. Show record details
    // 3. Confirm deletion
    // 4. Update file
    // 5. Show result
}
```

### 5.5 Display Records
```cpp
void displayBooks() {
    // 1. Read all records
    // 2. Format header
    // 3. Show data in tables
    // 4. Handle empty file
}
```

## 6. Documentation Requirements

### 6.1 Code Documentation
- File headers with purpose
- Function documentation
- Important variable explanations
- Logic explanations for complex parts

### 6.2 User Manual
- System requirements
- How to run the program
- Feature instructions
- Sample operations
- Error message explanations

### 6.3 Project Report
- Cover page
- Table of contents
- Introduction
- Features implemented
- Technical details
- Screenshots
- Conclusion
- References

## 7. Testing Checklist

### 7.1 Validation Testing
- [ ] Invalid input handling
- [ ] Boundary values
- [ ] Special characters
- [ ] Empty inputs
- [ ] Maximum lengths

### 7.2 Function Testing
- [ ] All CRUD operations
- [ ] File operations
- [ ] Error handling
- [ ] Menu navigation
- [ ] Display formatting

## 8. Submission Requirements
- [ ] Assignment cover page
- [ ] Marking scheme
- [ ] Question paper
- [ ] Introduction
- [ ] Source code (text file)
- [ ] Sample output
- [ ] User manual (text file)
- [ ] Harvard style references

## 9. Presentation Points
1. System overview
2. Feature demonstration
3. Validation examples
4. Error handling
5. File operations
6. Code structure
7. Testing results

## 10. Quality Checklist
- [ ] Clear user interface
- [ ] Robust input validation
- [ ] Proper error messages
- [ ] Clean code formatting
- [ ] Comprehensive comments
- [ ] Working file operations
- [ ] Stable program execution
