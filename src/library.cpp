// Constructor - explain initialization of filenames and file handling

/* Key points:
    - Initializes three important files: main database, temporary, and backup
    - Implements fail-safe file opening
    - Throws runtime_error if database initialization fails
*/

#include "library.h"

LibrarySystem::LibrarySystem() : 
    filename("books.dat"),
    tempFilename("books.tmp"),
    backupFilename("books.bak") {
    if (!openFile("")) {
        throw runtime_error("Failed to initialize database");
    }
}

LibrarySystem::~LibrarySystem() {
    closeFile();
}

// File operation methods - critical for data persistence
/* Remember:
    - Handles multiple file opening modes (read/write/append)
    - Creates file if it doesn't exist
    - Ensures proper file access for all operations
*/
bool LibrarySystem::openFile(const string& mode) {
    if (file.is_open()) {
        file.close();
    }
    
    ios_base::openmode openMode = ios::binary | ios::in | ios::out | ios::app;
    if (!mode.empty()) {
        if (mode == "in") openMode = ios::binary | ios::in;
        else if (mode == "out") openMode = ios::binary | ios::out;
    }
    
    file.open(filename, openMode);
    if (!file) {
        file.clear();
        file.open(filename, ios::binary | ios::out);
        if (!file) {
            return false;
        }
        file.close();
        file.open(filename, openMode);
    }
    
    return file.is_open();
}

bool LibrarySystem::closeFile() {
    if (file.is_open()) {
        file.close();
    }
    return true;
}

/**
 * Creates a backup of the current database file
 * Critical for data safety during modifications
 * Used before any operation that modifies data
 * Returns false if backup creation fails
 */
bool LibrarySystem::createBackup() {
    if (!closeFile()) return false;
    
    ifstream src(filename, ios::binary);
    ofstream dst(backupFilename, ios::binary);
    
    if (!src || !dst) {
        return false;
    }
    
    dst << src.rdbuf();
    
    src.close();
    dst.close();
    
    return openFile("");
}

/**
 * Restores database from backup file
 * Used when an operation fails to maintain data integrity
 * Ensures system can recover from failed operations
 * Returns false if restoration fails
 */
bool LibrarySystem::restoreBackup() {
    closeFile();
    
    if (remove(filename.c_str()) != 0) {
        return false;
    }
    
    if (rename(backupFilename.c_str(), filename.c_str()) != 0) {
        return false;
    }
    
    return openFile("");
}

bool LibrarySystem::commitChanges() {
    closeFile();
    
    if (remove(filename.c_str()) != 0) {
        return false;
    }
    
    if (rename(tempFilename.c_str(), filename.c_str()) != 0) {
        return false;
    }
    
    return openFile("");
}

void LibrarySystem::clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void LibrarySystem::showHeader(const string& title) {
    #ifdef _WIN32
        system("cls");
    #else
        cout << "\033[2J\033[H";
    #endif
    
    cout << "\n=======================================\n";
    cout << "       " << title << "\n";
    cout << "=======================================\n";
}

void LibrarySystem::pauseScreen() {
    cout << "\nPress Enter to continue...";
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

string LibrarySystem::formatId(int id) {
    ostringstream ss;
    ss << setw(4) << setfill('0') << id;
    return ss.str();
}

void LibrarySystem::safeStrCopy(char* dest, const string& src, size_t maxLen) {
    if (src.empty()) {
        dest[0] = '\0';
    } else {
        strncpy(dest, src.c_str(), maxLen - 1);
        dest[maxLen - 1] = '\0';
    }
}

/**
 * Safe numeric input handler for float values
 * Features:
 * - Validates decimal number format
 * - Prevents buffer overflow
 * - Handles invalid input gracefully
 * - Supports price input validation
 */
bool LibrarySystem::getNumericInput(float& value) {
    string input;
    getline(cin, input);
    
    if (input.empty()) return false;
    
    // Check if the input contains only digits and decimal point
    bool hasDecimal = false;
    bool isValid = true;
    for (size_t i = 0; i < input.length(); i++) {
        if (input[i] == '.') {
            if (hasDecimal) { // Second decimal point found
                isValid = false;
                break;
            }
            hasDecimal = true;
            continue;
        }
        if (!isdigit(input[i])) {
            isValid = false;
            break;
        }
    }
    
    if (!isValid) {
        cout << "Invalid input! Please enter a positive numeric value.\n";
        return false;
    }
    
    try {
        value = stof(input);
        return true;
    } catch (...) {
        cout << "Invalid input! Please enter a valid positive number.\n";
        return false;
    }
}

bool LibrarySystem::getNumericInput(int& value) {
    string input;
    getline(cin, input);
    
    if (input.empty()) return false;
    
    // Check if the input contains only digits
    bool isValid = all_of(input.begin(), input.end(), ::isdigit);
    
    if (!isValid) {
        cout << "Invalid input! Please enter a positive whole number.\n";
        return false;
    }
    
    try {
        value = stoi(input);
        return true;
    } catch (const out_of_range&) {
        cout << "Input number is out of range! Please enter a valid integer.\n";
        return false;
    } catch (...) {
        cout << "Invalid input! Please enter a valid positive integer.\n";
        return false;
    }
}

bool LibrarySystem::getStringInput(string& value, size_t maxLen) {
    getline(cin, value);
    if (value.empty()) return false;
    if (value.length() > maxLen - 1) {
        value = value.substr(0, maxLen - 1);
    }
    return true;
}

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

/**
 * Title validation ensures:
 * - Minimum length of 3 characters
 * - Maximum length within array bounds
 * - Proper string termination
 * - Returns false if validation fails
 */
bool LibrarySystem::validateTitle(const string& title) {
    if (title.length() < 3 || title.length() >= MAX_TITLE_LENGTH) return false;
    return true;
}

bool LibrarySystem::validateAuthor(const string& author) {
    if (author.length() < 2 || author.length() >= MAX_AUTHOR_LENGTH) return false;
    return all_of(author.begin(), author.end(), 
                 [](char c) { return isalpha(c) || isspace(c); });
}

bool LibrarySystem::validatePrice(float price) {
    return price >= MIN_PRICE && price <= MAX_PRICE;
}

bool LibrarySystem::validateQuantity(int qty) {
    return qty >= MIN_QUANTITY && qty <= MAX_QUANTITY;
}

/**
 * Adds new book to database with comprehensive validation:
 * 1. Automatic ID generation
 * 2. Input validation for all fields
 * 3. Automatic status setting
 * 4. Data backup before writing
 * 5. Multiple book addition support
 */
void LibrarySystem::addBook() {
    char continueAdding;
    string input;
    
    do {
        showHeader("ADD NEW BOOK");
        
        // Get the next ID
        file.clear();
        file.seekg(0, ios::end);
        int lastPos = file.tellg();
        int newId = 1;
        
        if (lastPos > 0) {
            file.seekg(lastPos - sizeof(Book));
            Book lastBook;
            if (file.read(reinterpret_cast<char*>(&lastBook), sizeof(Book))) {
                newId = lastBook.id + 1;
            }
        }
        
        book.id = newId;
        
        // Get title
        do {
            cout << "\nEnter Book Title: ";
            if (!getStringInput(input, MAX_TITLE_LENGTH)) continue;
            if (!validateTitle(input)) {
                cout << "Invalid title! Title must be between 3 and " 
                     << (MAX_TITLE_LENGTH - 1) << " characters.\n";
                continue;
            }
            break;
        } while (true);
        safeStrCopy(book.title, input, MAX_TITLE_LENGTH);
        
        // Get author
        do {
            cout << "Enter Author Name: ";
            if (!getStringInput(input, MAX_AUTHOR_LENGTH)) continue;
            if (!validateAuthor(input)) {
                cout << "Invalid author name! Use only letters and spaces (2-" 
                     << (MAX_AUTHOR_LENGTH - 1) << " characters).\n";
                continue;
            }
            break;
        } while (true);
        safeStrCopy(book.author, input, MAX_AUTHOR_LENGTH);
        
        // Get price
        float price;
        do {
            cout << "Enter Price ($" << MIN_PRICE << " - $" << MAX_PRICE << "): ";
            if (!getNumericInput(price)) {
                continue;
            }
            if (!validatePrice(price)) {
                cout << "Invalid price! Please enter a value between $" 
                     << MIN_PRICE << " and $" << MAX_PRICE << ".\n";
                continue;
            }
            break;
        } while (true);
        book.price = price;
        
        // Get quantity
        int quantity;
        do {
            cout << "Enter Quantity (" << MIN_QUANTITY << " - " << MAX_QUANTITY << "): ";
            if (!getNumericInput(quantity)) {
                continue;
            }
            if (!validateQuantity(quantity)) {
                cout << "Invalid quantity! Please enter a value between " 
                     << MIN_QUANTITY << " and " << MAX_QUANTITY << ".\n";
                continue;
            }
            break;
        } while (true);
        book.quantity = quantity;
        
        // Set status
        safeStrCopy(book.status, quantity > 0 ? "Available" : "Out", MAX_STATUS_LENGTH);
        
        // Create backup before writing
        if (!createBackup()) {
            cout << "\nError: Unable to create backup. Operation cancelled.\n";
            pauseScreen();
            continue;
        }
        
        // Write to file
        file.clear();
        file.seekp(0, ios::end);
        if (!file.write(reinterpret_cast<char*>(&book), sizeof(Book))) {
            cout << "\nError: Failed to write book record.\n";
            restoreBackup();
            pauseScreen();
            continue;
        }
        
        file.flush();
        cout << "\nBook added successfully!\n";
        
        do {
            cout << "\nDo you want to add another book? (Y/N): ";
            cin >> continueAdding;
            clearInputBuffer();
            continueAdding = toupper(continueAdding);
            if (continueAdding != 'Y' && continueAdding != 'N') {
                cout << "Please enter Y or N.\n";
            }
        } while (continueAdding != 'Y' && continueAdding != 'N');
        
    } while (continueAdding == 'Y');
}

void LibrarySystem::searchBook() {
    showHeader("SEARCH BOOK");
    
    int searchId;
    cout << "\nEnter Book ID to search: ";
    if (!getNumericInput(searchId)) {
        cout << "\nInvalid ID format!\n";
        pauseScreen();
        return;
    }
    
    bool found = false;
    file.clear();
    file.seekg(0, ios::beg);
    
    while (file.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
        if (book.id == searchId) {
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
 * Updates existing book record:
 * 1. Locates book by ID
 * 2. Shows current values
 * 3. Allows selective field updates
 * 4. Maintains data integrity
 * 5. Updates status automatically
 */
void LibrarySystem::updateBook() {
    showHeader("UPDATE BOOK");
    
    int updateId;
    cout << "\nEnter Book ID to update: ";
    if (!getNumericInput(updateId)) {
        cout << "\nInvalid ID format!\n";
        pauseScreen();
        return;
    }
    
    // Create temporary file
    fstream tempFile(tempFilename, ios::binary | ios::out);
    if (!tempFile) {
        cout << "\nError: Unable to create temporary file!\n";
        pauseScreen();
        return;
    }
    
    bool found = false;
    file.clear();
    file.seekg(0, ios::beg);
    
    while (file.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
        if (book.id == updateId) {
            cout << "\nCurrent Book Details:\n";
            cout << "ID: " << formatId(book.id) << endl;
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Price: $" << fixed << setprecision(2) << book.price << endl;
            cout << "Quantity: " << book.quantity << endl;
            
            Book updatedBook = book;
            string input;
            
            // Update title
            cout << "\nEnter new Title (press Enter to keep current): ";
            if (getStringInput(input, MAX_TITLE_LENGTH) && validateTitle(input)) {
                safeStrCopy(updatedBook.title, input, MAX_TITLE_LENGTH);
            }
            
            // Update author
            cout << "Enter new Author (press Enter to keep current): ";
            if (getStringInput(input, MAX_AUTHOR_LENGTH) && validateAuthor(input)) {
                safeStrCopy(updatedBook.author, input, MAX_AUTHOR_LENGTH);
            }
            
            // Update price
            float newPrice;
            cout << "Enter new Price (press Enter to keep current): ";
            if (getNumericInput(newPrice) && validatePrice(newPrice)) {
                updatedBook.price = newPrice;
            }
            
            // Update quantity
            int newQty;
            cout << "Enter new Quantity (press Enter to keep current): ";
            if (getNumericInput(newQty) && validateQuantity(newQty)) {
                updatedBook.quantity = newQty;
                safeStrCopy(updatedBook.status, newQty > 0 ? "Available" : "Out", MAX_STATUS_LENGTH);
            }
            
            tempFile.write(reinterpret_cast<char*>(&updatedBook), sizeof(Book));
            found = true;
        } else {
            tempFile.write(reinterpret_cast<char*>(&book), sizeof(Book));
        }
    }
    
    tempFile.close();
    closeFile();
    
    if (found) {
        if (commitChanges()) {
            cout << "\nBook updated successfully!";
        } else {
            cout << "\nError: Unable to update database!";
            remove(tempFilename.c_str());
        }
    } else {
        cout << "\nBook not found!";
        remove(tempFilename.c_str());
    }
    
    openFile("");
    cout << "\n";
    pauseScreen();
}

void LibrarySystem::deleteBook() {
    showHeader("DELETE BOOK");
    
    int deleteId;
    cout << "\nEnter Book ID to delete: ";
    if (!getNumericInput(deleteId)) {
        cout << "\nInvalid ID format!\n";
        pauseScreen();
        return;
    }
    
    // Create temporary file
    fstream tempFile(tempFilename, ios::binary | ios::out);
    if (!tempFile) {
        cout << "\nError: Unable to create temporary file!\n";
        pauseScreen();
        return;
    }
    
    // First find the book to confirm deletion
    file.clear();
    file.seekg(0, ios::beg);
    bool found = false;
    
    while (file.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
        if (book.id == deleteId) {
            cout << "\nBook Details to Delete:\n";
            cout << "ID: " << formatId(book.id) << endl;
            cout << "Title: " << book.title << endl;
            cout << "Author: " << book.author << endl;
            cout << "Price: $" << fixed << setprecision(2) << book.price << endl;
            cout << "Quantity: " << book.quantity << endl;
            
            char confirm;
            do {
                cout << "\nAre you sure you want to delete this book? (Y/N): ";
                cin >> confirm;
                clearInputBuffer();
            } while (toupper(confirm) != 'Y' && toupper(confirm) != 'N');
            
            if (toupper(confirm) == 'N') {
                cout << "\nDeletion cancelled.\n";
                tempFile.close();
                remove(tempFilename.c_str());
                pauseScreen();
                return;
            }
            
            found = true;
            break;
        }
    }
    
    if (!found) {
        cout << "\nBook not found!\n";
        tempFile.close();
        remove(tempFilename.c_str());
        pauseScreen();
        return;
    }
    
    // Create backup before deletion
    if (!createBackup()) {
        cout << "\nError: Unable to create backup. Operation cancelled.\n";
        tempFile.close();
        remove(tempFilename.c_str());
        pauseScreen();
        return;
    }
    
    // Copy all records except the one to be deleted
    file.clear();
    file.seekg(0, ios::beg);
    
    while (file.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
        if (book.id != deleteId) {
            tempFile.write(reinterpret_cast<char*>(&book), sizeof(Book));
        }
    }
    
    tempFile.close();
    closeFile();
    
    if (commitChanges()) {
        cout << "\nBook deleted successfully!\n";
    } else {
        cout << "\nError: Unable to delete book!\n";
        restoreBackup();
        remove(tempFilename.c_str());
    }
    
    openFile("");
    pauseScreen();
}

/**
 * Displays book records with advanced features:
 * 1. Pagination (RECORDS_PER_PAGE items per page)
 * 2. Navigation (Next/Previous/Quit)
 * 3. Formatted table output
 * 4. Dynamic page calculation
 * 5. Empty database handling
 */
void LibrarySystem::displayBooks() {
    int currentPage = 1;
    int totalRecords = 0;
    char choice;
    
    // Count total records
    file.clear();
    file.seekg(0, ios::beg);
    Book tempBook;
    while (file.read(reinterpret_cast<char*>(&tempBook), sizeof(Book))) {
        totalRecords++;
    }
    
    if (totalRecords == 0) {
        showHeader("DISPLAY ALL BOOKS");
        cout << "\nNo books found in the system!\n";
        pauseScreen();
        return;
    }
    
    int totalPages = (totalRecords + RECORDS_PER_PAGE - 1) / RECORDS_PER_PAGE;
    
    do {
        showHeader("DISPLAY ALL BOOKS");
        cout << "\nPage " << currentPage << " of " << totalPages << endl;
        
        // Display table header
        cout << "\n"
            << left << setw(6) << "ID" 
            << setw(35) << "Title"
            << setw(20) << "Author"
            << right << setw(10) << "Price"
            << setw(10) << "Qty"
            << setw(12) << "Status" << endl;
        cout << string(93, '-') << endl;
        
        // Calculate starting record for current page
        int startRecord = (currentPage - 1) * RECORDS_PER_PAGE;
        file.clear();
        file.seekg(startRecord * sizeof(Book));
        
        // Display records for current page
        int displayedRecords = 0;
        while (displayedRecords < RECORDS_PER_PAGE && 
            file.read(reinterpret_cast<char*>(&book), sizeof(Book))) {
            // Ensure proper string termination for display
            book.title[MAX_TITLE_LENGTH - 1] = '\0';
            book.author[MAX_AUTHOR_LENGTH - 1] = '\0';
            book.status[MAX_STATUS_LENGTH - 1] = '\0';
            
            // Format and display record
            cout << left << setw(6) << formatId(book.id);
            
            // Truncate long strings for display
            string title(book.title);
            string author(book.author);
            if (title.length() > 32) title = title.substr(0, 29) + "...";
            if (author.length() > 17) author = author.substr(0, 14) + "...";
            
            cout << setw(35) << left << title;           
            cout << setw(20) << left << author;          
            cout << right << setw(10) << fixed << setprecision(2) << book.price;  
            cout << setw(10) << book.quantity;            
            cout << setw(12) << book.status;            
            cout << endl;
            
            displayedRecords++;
        }
        
        // Display navigation options
        cout << "\n----------------------------------------\n";
        cout << "Total Books: " << totalRecords << " | Page " << currentPage << " of " << totalPages;
        cout << "\nN: Next Page | P: Previous Page | Q: Return to Main Menu";
        cout << "\nEnter your choice: ";
        
        cin >> choice;
        choice = toupper(choice);
        clearInputBuffer();
        
        switch (choice) {
            case 'N':
                if (currentPage < totalPages) {
                    currentPage++;
                }
                break;
                
            case 'P':
                if (currentPage > 1) {
                    currentPage--;
                }
                break;
                
            case 'Q':
                return;
                
            default:
                cout << "\nInvalid choice!";
                pauseScreen();
        }
        
    } while (true);
}

void LibrarySystem::mainMenu() {
    int choice;
    string input;
    
    do {
        showHeader("LIBRARY MANAGEMENT SYSTEM");
        cout << "\n1. Add New Book";
        cout << "\n2. Search Book";
        cout << "\n3. Update Book";
        cout << "\n4. Delete Book";
        cout << "\n5. Display All Books";
        cout << "\n6. Exit";
        cout << "\n\nEnter your choice (1-6): ";
        
        if (!getNumericInput(choice)) {
            cout << "\nInvalid choice! Please enter a number between 1 and 6.\n";
            pauseScreen();
            continue;
        }
        
        try {
            switch (choice) {
                case 1: addBook(); break;
                case 2: searchBook(); break;
                case 3: updateBook(); break;
                case 4: deleteBook(); break;
                case 5: displayBooks(); break;
                case 6: 
                    cout << "\nThank you for using Library Management System!\n";
                    break;
                default:
                    cout << "\nInvalid choice! Please enter a number between 1 and 6.\n";
                    pauseScreen();
            }
        } catch (const exception& e) {
            cout << "\nAn error occurred: " << e.what() << endl;
            pauseScreen();
        } catch (...) {
            cout << "\nAn unexpected error occurred!\n";
            pauseScreen();
        }
    } while (choice != 6);
}