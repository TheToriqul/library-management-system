# LIBRARY MANAGEMENT SYSTEM
### USER MANUAL
### Version 1.0

## Table of Contents
1. Introduction
2. System Requirements
3. Installation
4. System Functions
5. Detailed Operations Guide
   - Adding Books
   - Searching Books
   - Updating Books
   - Deleting Books
   - Displaying Books
6. Data Validation Rules
7. Error Messages
8. Troubleshooting
9. Best Practices
10. Technical Support


## 1. Introduction
The Library Management System is a comprehensive software solution designed for managing library resources efficiently. This manual provides detailed instructions for installation, operation, and maintenance of the system.
- Efficient book record management
- Real-time inventory tracking
- Secure data storage
- User-friendly interface
- Multi-platform compatibility

### 1.1 System Overview
The Library Management System provides five core operations:
1. Add New Book (Option 1)
2. Search Book (Option 2)
3. Update Book (Option 3)
4. Delete Book (Option 4)
5. Display All Books (Option 5)


## 2. System Requirements
### 2.1 Hardware Requirements
- Processor: 1 GHz or faster
- RAM: Minimum 512MB
- Storage: 50MB free disk space
- Display: 1024x768 resolution or higher

### 2.2 Software Requirements
- Operating System: Windows 7/10/11, Linux, or macOS
- C++ Compiler: GCC 4.9 or later
- Build System: CMake 3.5.0 or later
- Terminal: ANSI-compatible terminal emulator


## 3. Installation
### 3.1 Pre-installation Setup
1. Verify system requirements
2. Install required compiler and build tools
3. Configure environment variables

### 3.2 Ensure the below files structures
```
LibrarySystem/
├── src/
│   ├── main.cpp           # Main program entry
│   ├── library.cpp        # Implementation file
│   ├── library.h          # Header file
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

### Structure Details:
    • LibrarySystem/: The root directory containing all project files.
    • src/ : The subdirectory containing source code, configurations, and the database.
    • main.cpp: The entry point of the program where execution begins.
    • library.cpp & library.h: Contain the main logic and declarations for managing the library system.
    • Makefile & CMakeLists.txt: Tools to compile the code.
    • books.dat: The database file storing book records. It is automatically created when the system runs for the first time.


### 3.3 Installation Steps
1. Navigate to the src directory: cd LibrarySystem/src
    - Purpose: Open terminal and confirm you are in the correct directory to retrieve both your source code and your build configuration files.
2. Compile the program using make make
    - Purpose: A make file should be used to simplify automated compilation workflow. The compilation of source code creates an executable file (library).
3. Run the program: ./library
    - Purpose: Running the compiled file activates the Library Management System interface.
4. To clean compiled files (optional): make clean
    - Purpose: The exercise helps clear temporary compiled files which create free storage space needed for building a project from scratch.

### 3.4 Database Setup
This subsection explains how the database (books.dat) works:
1. Automatic Creation: Users do not need to manually establish the database file as the program builds it when it runs for the first time.
    - Purpose: A permanent location for the storage of all book records exists.
2. No Manual Configuration Needed: The system performs all database operations through its automated mechanism to create records and read update and delete existing records.
3. The user-friendly design and simplified setup processes result from this database approach.


## 4. System Functions
### 4.1 Core Features
- Book Record Management
- Search and Retrieval
- Inventory Control
- Data Validation
- Report Generation

### 4.2 Data Management
- Automatic ID Generation
- Real-time Updates
- Data Integrity Checks
- Backup Management


## 5. Detailed Operations Guide
The system offers users a basic interface with a friendly design to access all available features through this menu. The system operates through users selecting options by typing their matching numbers between 1 and 6 and pressing Enter. When you launch the program, you'll see the following menu:
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
```

### 5.1 Adding Books (Option 1)
Users can enter new book information including title, author and price and quantity details through the system. The system automatically generates a unique ID (0001) and sets the book's availability status.

#### Steps to Add a Book:
1. Select Option 1 from main menu
2. Enter book information as prompted:

   a) Book Title:
   - Enter between 3-49 characters
   - Can include letters, numbers, and spaces
   - Example: "Programming in C++"
   - System will reject if too short/long

   b) Author Name:
   - Enter between 2-29 characters
   - Letters and spaces only
   - Example: "John Smith"
   - System rejects numbers/special characters

   c) Price:
   - Enter between 0.01 and 9999.99
   - Use decimal point for cents
   - Example: 49.99
   - System rejects negative values

   d) Quantity:
   - Enter between 0 and 999
   - Whole numbers only
   - Example: 5
   - System rejects decimal values

3. System automatically:
   - Generates unique ID
   - Sets status (Available/Out) based on quantity
   - Displays confirmation message

4. After adding:
   - Choose Y to add another book
   - Choose N to return to main menu
   
   Example Session:
   ```
   =======================================
             ADD NEW BOOK
   =======================================

   Enter Book Title: Programming in C++
   Enter Author Name: John Smith
   Enter Price: 49.99
   Enter Quantity: 5

   Book added successfully!

   Do you want to add another book? (Y/N): _
   ```

### 5.2 Searching Books (Option 2)
The system offers an option to find a particular book using its unique identifier. The application shows the book details in full if it finds a match but presents a "Book not found" notification in case the ID is invalid.

#### Steps to Search:
1. Select Option 2 from main menu
2. Enter the book ID when prompted:
   - Must be a valid numeric ID
   - Example: 1001

3. System displays:
   - Full book details if found
   - "Book not found" if ID invalid

   Example Search Result:
   ```
   =======================================
             SEARCH BOOK
   =======================================

   Enter Book ID to search: 0001

   Book Details:
   ID: 1001
   Title: Programming in C++
   Author: John Smith
   Price: $49.99
   Quantity: 5
   Status: Available

   Press Enter to continue...
   ```

### 5.3 Updating Books (Option 3)
This feature allows users to change data fields for existing books. The dialog shows real-time information that enables users to maintain existing values or modify it.

#### Steps to Update:
1. Select Option 3 from main menu
2. Enter book ID to update
3. System shows current details
4. Update fields as needed:

   a) Title Update:
   - Press Enter to keep current
   - Or enter new title (3-49 chars)

   b) Author Update:
   - Press Enter to keep current
   - Or enter new author (2-29 chars)

   c) Price Update:
   - Press Enter to keep current
   - Or enter new price (0.01-9999.99)

   d) Quantity Update:
   - Press Enter to keep current
   - Or enter new quantity (0-999)

5. System automatically:
   - Updates status based on new quantity
   - Saves changes
   - Shows confirmation

   Example Update Session:
   ```
   =======================================
             UPDATE BOOK
   =======================================

   Enter Book ID to update: 0001

   Current Book Details:
   ID: 0001
   Title: Programming in C++
   Author: John Smith
   Price: $49.99
   Quantity: 5

   Enter new Title (press Enter to keep current): Advanced Programming in C++
   Enter new Author (press Enter to keep current): 
   Enter new Price (press Enter to keep current): 59.99
   Enter new Quantity (press Enter to keep current): 10

   Book updated successfully!
   ```

### 5.4 Deleting Books (Option 4)
The interface allows database administrators to eliminate specific books using their distinct identifiers. The application will verify the deletion process unless an error emerges when the ID does not exist.

#### Steps to Delete:
1. Select Option 4 from main menu
2. Enter book ID to delete
3. System shows book details
4. Confirm deletion:
   - Y to proceed
   - N to cancel

   Example Deletion:
   ```
   =======================================
             DELETE BOOK
   =======================================

   Enter Book ID to delete: 0001

   Book Details to Delete:
   ID: 0001
   Title: Advanced Programming in C++
   Author: John Smith
   Price: $59.99
   Quantity: 10

   Are you sure you want to delete this book? (Y/N): Y

   Book deleted successfully!
   ```

### 5.5 Displaying Books (Option 5)
A paginated list displays all books present in the database system.

#### Display Features:
1. Shows books in tabular format
2. 5 books per page
3. Navigation commands:
   - N: Next page
   - P: Previous page
   - Q: Return to menu

   Example Display:
   ```
   =======================================
           DISPLAY ALL BOOKS
   =======================================
   Page 1 of 2

   ID    Title                    Author          Price    Qty    Status
   ------------------------------------------------------------------------
   0001  Programming in C++      John Smith      49.99     5    Available
   0002  Data Structures         Jane Doe        39.99     3    Available
   0003  Algorithms              Mike Brown      44.99     0    Out
   0004  Web Development         Sarah Lee       34.99     2    Available
   0005  Database Design         Tom Wilson      54.99     4    Available

   ----------------------------------------
   Total Books: 8 | Page 1 of 2
   N: Next Page | P: Previous Page | Q: Return to Main Menu
   Enter your choice: _
   ```


## 6. Data Validation Rules
### 6.1 Title Validation
- Minimum length: 3 characters, Maximum: 49 characters.
- Allowed: Letters, numbers, spaces, basic punctuation.

### 6.2 Author Validation
- Minimum: 2 characters, Maximum: 29 characters.
- Letters and spaces only.

### 6.3 Price Validation
- Minimum: $0.01, Maximum: $9999.99.
- Two decimal places maximum.

### 6.4 Quantity Validation
- Minimum: 0, Maximum: 999.
- Whole numbers only.


## 7. Error Messages and Resolution
### 7.1 Input Errors
- "Invalid title length": Enter title between 3-49 characters.
- "Invalid author name": Use only letters and spaces.
- "Invalid price": Enter price between 0.01-9999.99.
- "Invalid quantity": Enter whole number between 0-999.

### 7.2 Operation Errors
- "Book not found": Verify book ID exists.
- "Database error": Check file permissions.
- "Invalid choice": Enter valid menu option (1-6).
- "Operation cancelled": Action aborted by user.

### 7.3 File Errors
- "Unable to open database": Check books.dat exists.
- "Write error": Verify disk space and permissions.
- "Read error": Check file is not corrupted.


## 8. Troubleshooting
### 8.1 Database Issues
Problem: "Unable to create or open database file"
Solution:
  - Check src directory permissions
  - Verify available disk space
  - Close any programs using books.dat

### 8.2 Input Validation
Problem: Input rejection  
Solution:
  1. Review input requirements
  2. Check character limits
  3. Verify data format

### 8.3 Display Issues
Problem: Formatting errors  
Solution:
  1. Adjust terminal size
  2. Verify ANSI support
  3. Check character encoding


## 9. Best Practices
### 9.1 Data Entry
- Use clear, descriptive titles
- Verify prices and quantities before entry
- Follow consistent naming conventions

### 9.2 Record Management
- Update quantities regularly
- Remove obsolete records
- Verify record accuracy

### 9.3 System Care
- Maintain regular backups of books.dat
- Monitor available disk space
- Check data consistency regularly

### 9.4 Error Prevention
- Double-check IDs before deletion
- Verify updates before saving
- Ensure proper data formats


## 10. Technical Support
### 10.1 Support Procedures
1. Document the issue
2. Collect error messages
3. Note system configuration
4. Contact technical support

### 10.2 Contact Information (Dummy)
Technical Support Hours: 09:00-17:00 (GMT)
- Email: support@librarysystem.com
- Phone: +65 89367705
- Online: https://support.librarysystem.com

### 10.3 Required Information
When contacting support, provide:
1. System version
2. Error messages
3. Steps to reproduce
4. System configuration
5. Recent system changes

====================================================================

Document No: LMS-UM-2025-V1
Last Updated: 18 February 2025

====================================================================


## End Note
---
This user manual is stored as user_manual.txt in the docs directory. Refer to it whenever you need guidance on system operation, troubleshooting, or best practices. For updates and additional documentation, check the system's documentation folder.