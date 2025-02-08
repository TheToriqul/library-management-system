# Library Management System - User Manual

## Table of Contents
1. System Requirements
2. Getting Started
3. Main Menu
4. Using the System
5. Troubleshooting
6. Best Practices

## 1. System Requirements

### Hardware Requirements
- Minimum 512MB RAM
- 50MB free disk space
- Basic display supporting ANSI characters

### Software Requirements
- Operating System: Windows, Linux, or macOS
- C++ Compiler (GCC 4.9 or later)
- CMake (3.5.0 or later)

## 2. Getting Started

### 2.1 File Structure
Before starting, ensure you have all required files in the correct structure:
```
LibrarySystem/
├── src/
│   ├── main.cpp           # Main program entry
│   ├── library.cpp        # Implementation file
│   ├── library.h          # Header file
│   ├── Makefile           # Build configuration
│   ├── CMakeLists.txt     # Build configuration for CMakeLists
│   └── books.dat          # Book records
```

### 2.2 Compilation and Running
1. Navigate to the src directory:
   ```bash
   cd LibrarySystem/src
   ```

2. Compile the program using make:
   ```bash
   make
   ```
   This will compile the source files and create the 'library' executable.

3. Run the program:
   ```bash
   ./library
   ```

4. To clean compiled files (optional):
   ```bash
   make clean
   ```

Note: The Makefile ensures proper compilation with C++11 standards and includes warning flags for better code quality.

### 2.3 Database Setup
- The books.dat file will be automatically created in the src directory
- No manual configuration required
- System will handle all database operations

## 3. Main Menu
Upon launching, you'll see the main menu:
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

## 4. Using the System

### 4.1 Adding a New Book
1. Select option 1
2. Enter requested information:
   - Title (3-49 characters)
   - Author (2-29 characters, letters and spaces only)
   - Price (0.01-9999.99)
   - Quantity (0-999)
3. System automatically:
   - Generates unique ID
   - Sets availability status
4. Choose to add another book or return to menu

### 4.2 Searching for a Book
1. Select option 2
2. Enter book ID
3. View results:
   - Complete book details if found
   - "Book not found" message if not found
4. Press Enter to return to menu

### 4.3 Updating Book Information
1. Select option 3
2. Enter book ID
3. Current information displays
4. For each field:
   - Press Enter to keep current value
   - Type new value to update
5. Changes saved automatically

### 4.4 Deleting a Book
1. Select option 4
2. Enter book ID
3. System will:
   - Remove book if found
   - Show confirmation message
   - Display error if not found
4. Return to menu automatically

### 4.5 Displaying All Books
1. Select option 5
2. Navigate using:
   - N: Next page
   - P: Previous page
   - Q: Return to menu
3. Each page shows up to 5 records

## 5. Troubleshooting

### 5.1 Common Issues

#### Database Error
**Problem**: "Unable to create or open database file"
**Solution**: 
- Verify src directory permissions
- Check available disk space
- Close any programs using books.dat

#### Input Rejection
**Problem**: Input not accepted
**Solution**:
- Check input length limits
- Verify character restrictions
- Ensure proper number formats

#### Display Problems
**Problem**: Misaligned output
**Solution**:
- Resize terminal window
- Verify console supports ANSI
- Check text encoding settings

## 6. Best Practices

### 6.1 Data Entry
- Use clear, descriptive titles
- Verify prices and quantities
- Follow consistent naming conventions

### 6.2 Record Management
- Update quantities regularly
- Remove obsolete records
- Verify record accuracy

### 6.3 System Care
- Maintain books.dat backups
- Monitor available space
- Check data consistency regularly

### 6.4 Error Prevention
- Double-check IDs before deletion
- Verify updates before saving
- Ensure proper data formats

## Contact Support
If you encounter persistent issues:
- Document the error
- Note the steps to reproduce
- Contact system administrator

## End Note
This manual is stored as user_manual.txt in the docs directory. Refer to it whenever needed for system operation guidance.