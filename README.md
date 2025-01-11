# 📚 Library Management System

<div align="center">

[![Build Status](https://img.shields.io/badge/build-passing-brightgreen.svg)](https://github.com/TheToriqul/library-system)
[![License](https://img.shields.io/badge/license-MIT-blue.svg)](https://github.com/TheToriqul/library-system/blob/main/LICENSE)
[![C++](https://img.shields.io/badge/C++-17-blue.svg)](https://isocpp.org/)
[![PRs Welcome](https://img.shields.io/badge/PRs-welcome-brightgreen.svg)](https://github.com/TheToriqul/library-system/pulls)

A modern, efficient C++ library management system with file-based storage and an intuitive command-line interface.

[Explore Demo](#usage) • [View Documentation](#documentation) • [Report Bug](https://github.com/TheToriqul/library-system/issues) • [Request Feature](https://github.com/TheToriqul/library-system/issues)

</div>

## ✨ Features

🔹 **Book Management**
  - 📝 Add new books with automatic ID generation
  - 🔍 Search books by ID with detailed display
  - 🔄 Update existing book information
  - 🗑️ Delete books with safe record removal
  - 📋 Display all books with pagination

🔹 **Data Validation**
  - ✅ Title length validation (3-49 characters)
  - ✅ Author name verification (letters and spaces only)
  - ✅ Price range checks (0.01-9999.99)
  - ✅ Quantity limits (0-999)
  - ✅ Automatic status updates based on quantity

🔹 **File Operations**
  - 💾 Binary file storage for efficiency
  - 🛡️ Safe file handling with error checking
  - 🔄 Automatic database creation
  - ✅ Data consistency maintenance

## 🔧 System Requirements

- C++ Compiler (GCC 4.9 or later)
- CMake 3.5.0 or later
- 512MB RAM minimum
- 50MB free disk space
- Operating System: Windows, Linux, or macOS

## 📁 Project Structure

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
│    ├── AddBooks.png     # Screenshots
│    ├── SearchBooks.png  # Screenshots         
├── report/
│    └── project_report.docx
└── README.md              # This file
```

## 🚀 Quick Start

1. Clone the repository:
   ```bash
   git clone https://github.com/TheToriqul/library-system.git
   cd library-system
   ```
   Follow the [user manual](./docs/user_manual.txt)

## 📖 Documentation

### Usage

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

2. Navigate through the intuitive menu system:
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
   ```

### 💡 Input Guidelines

| Field    | Requirements                    |
|----------|--------------------------------|
| Title    | 3-49 characters                |
| Author   | 2-29 characters, letters only  |
| Price    | 0.01 - 9999.99                |
| Quantity | 0 - 999                       |

## 🤝 Contributing

We welcome contributions! Here's how you can help:

1. Fork the repository
2. Create your feature branch (`git checkout -b feature/AmazingFeature`)
3. Commit your changes (`git commit -m 'Add some AmazingFeature'`)
4. Push to the branch (`git push origin feature/AmazingFeature`)
5. Open a Pull Request

## 📝 License

This project is licensed under the MIT License - see the [LICENSE](https://github.com/TheToriqul/library-system/blob/main/LICENSE) file for details.

## 👤 Author

**Toriqul Islam**
- GitHub: [@TheToriqul](https://github.com/TheToriqul)
- Website: [thetoriqul.com](https://thetoriqul.com)
- LinkedIn: [Toriqul Islam](https://www.linkedin.com/in/thetoriqul/)

## 🌟 Acknowledgments

- Project structure inspired by modern C++ best practices
- File handling approach based on standard library implementations
- Input validation techniques from industry standards

## 📬 Contact

Have questions? Feel free to reach out:
- Email: toriqul.int@gmail.com
- Phone: +65 8936 7705, +8801765 939006

---
<div align="center">
⭐ Star us on GitHub — it helps!

[Report Bug](https://github.com/TheToriqul/library-system/issues) • [Request Feature](https://github.com/TheToriqul/library-system/issues)
</div>