# Library Management System - Expected Outputs

## 1. Main Menu
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

## 2. Add Book Operation

### 2.1 Initial Add Screen
```
=======================================
          ADD NEW BOOK
=======================================

Enter Book Title: Programming in C++
Enter Author Name: John Smith
Enter Price: 49.99
Enter Quantity: 5
```

### 2.2 Successful Addition
```
Book added successfully!

Do you want to add another book? (Y/N): _
```

### 2.3 Validation Error Example
```
Enter Book Title: P
Invalid title! Must be 3-49 characters. Try again: _

Enter Author Name: John123
Invalid author name! Use only letters and spaces: _

Enter Price: -50
Invalid price! Enter between 0.01 and 9999.99: _

Enter Quantity: 1000
Invalid quantity! Enter between 0 and 999: _
```

## 3. Search Book Operation

### 3.1 Book Found
```
=======================================
          SEARCH BOOK
=======================================

Enter Book ID to search: 1001

Book Details:
ID: 1001
Title: Programming in C++
Author: John Smith
Price: $49.99
Quantity: 5
Status: Available

Press Enter to continue...
```

### 3.2 Book Not Found
```
=======================================
          SEARCH BOOK
=======================================

Enter Book ID to search: 9999

Book not found!

Press Enter to continue...
```

## 4. Update Book Operation

### 4.1 Initial Update Screen
```
=======================================
          UPDATE BOOK
=======================================

Enter Book ID to update: 1001

Current Book Details:
ID: 1001
Title: Programming in C++
Author: John Smith
Price: $49.99
Quantity: 5

Enter new Title (press Enter to keep current): Advanced Programming in C++
Enter new Author (press Enter to keep current): 
Enter new Price (press Enter to keep current): 59.99
Enter new Quantity (press Enter to keep current): 10
```

### 4.2 Successful Update
```
Book updated successfully!

Press Enter to continue...
```

## 5. Delete Book Operation

### 5.1 Successful Deletion
```
=======================================
          DELETE BOOK
=======================================

Enter Book ID to delete: 1001

Book deleted successfully!

Press Enter to continue...
```

### 5.2 Delete Not Found
```
=======================================
          DELETE BOOK
=======================================

Enter Book ID to delete: 9999

Book not found!

Press Enter to continue...
```

## 6. Display Books Operation

### 6.1 Books List
```
=======================================
        DISPLAY ALL BOOKS
=======================================
Page 1 of 2

  ID    Title                    Author          Price    Qty    Status
------------------------------------------------------------------------
1001    Programming in C++       John Smith      49.99     5    Available
1002    Data Structures         Jane Doe        39.99     3    Available
1003    Algorithms              Mike Brown      44.99     0    Out
1004    Web Development         Sarah Lee       34.99     2    Available
1005    Database Design         Tom Wilson      54.99     4    Available

----------------------------------------
Total Books: 8 | Page 1 of 2
N: Next Page | P: Previous Page | Q: Return to Main Menu
Enter your choice: _
```

### 6.2 Empty Database
```
=======================================
        DISPLAY ALL BOOKS
=======================================

No books found in the system!

Press Enter to continue...
```

## 7. Exit Program
```
Thank you for using Library Management System!
```

## 8. Error Handling Examples

### 8.1 File Access Error
```
Error: Unable to create or open database file!
Please check file permissions and disk space.
```

### 8.2 Invalid Menu Choice
```
Invalid choice! Please try again.

Press Enter to continue...
```