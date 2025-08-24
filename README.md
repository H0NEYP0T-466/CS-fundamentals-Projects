# CS-fundamentals-Projects

![GitHub License](https://img.shields.io/github/license/H0NEYP0T-466/CS-fundamentals-Projects?style=for-the-badge&color=brightgreen)
![GitHub Stars](https://img.shields.io/github/stars/H0NEYP0T-466/CS-fundamentals-Projects?style=for-the-badge&color=yellow)
![GitHub Forks](https://img.shields.io/github/forks/H0NEYP0T-466/CS-fundamentals-Projects?style=for-the-badge&color=blue)
![Contributions Welcome](https://img.shields.io/badge/Contributions-Welcome-brightgreen?style=for-the-badge)
![GitHub Issues](https://img.shields.io/github/issues/H0NEYP0T-466/CS-fundamentals-Projects?style=for-the-badge&color=red)

A comprehensive collection of Computer Science fundamentals projects and assignments focusing on Object-Oriented Programming (OOP) and Programming Fundamentals (PF) using C++. This repository contains practical implementations of key programming concepts, data structures, and real-world applications.

## 🔗 Links

- [📖 Documentation](#-table-of-contents)
- [🐛 Issues](https://github.com/H0NEYP0T-466/CS-fundamentals-Projects/issues)
- [🤝 Contributing](./CONTRIBUTING.md)
- [📄 License](./LICENSE)

## 📋 Table of Contents

- [🚀 Installation](#-installation)
- [💻 Usage](#-usage)
- [✨ Features](#-features)
- [📁 Project Structure](#-project-structure)
- [🏗️ Built With](#️-built-with)
- [🤝 Contributing](#-contributing)
- [📄 License](#-license)
- [🗺️ Roadmap](#️-roadmap)
- [🙏 Acknowledgements](#-acknowledgements)

## 🚀 Installation

### Prerequisites

- **C++ Compiler**: GCC (MinGW on Windows) or any C++11 compatible compiler
- **IDE/Text Editor**: Code::Blocks, Dev-C++, Visual Studio Code, or any preferred C++ IDE
- **Operating System**: Windows, Linux, or macOS

### Steps

1. **Clone the repository**
   ```bash
   git clone https://github.com/H0NEYP0T-466/CS-fundamentals-Projects.git
   cd CS-fundamentals-Projects
   ```

2. **Choose a project to compile**
   ```bash
   cd Projects/Drug_Store_Project
   g++ -o drugstore projct.cpp
   ```

3. **Run the executable**
   ```bash
   ./drugstore          # Linux/macOS
   drugstore.exe        # Windows
   ```

## 💻 Usage

### 🏥 Drug Store Management System
Navigate to `Projects/Drug_Store_Project/` and compile `projct.cpp`:
```bash
g++ -o drugstore projct.cpp
./drugstore
```
- **Admin Features**: Add, modify, delete, and view drugs
- **Customer Features**: Browse and purchase medications
- **File Management**: Persistent data storage

### 🛒 Online Shopping System
Navigate to `Projects/Online_Shoping_Project/` and compile `hamid.cpp`:
```bash
g++ -o shopping hamid.cpp
./shopping
```
- **Product Management**: Add, modify, remove products
- **Shopping Cart**: Add items and generate receipts
- **Admin Panel**: Complete inventory management

### 🐾 Virtual Pet System
Navigate to `Projects/Virtual_Pet_Project/` and compile `draft 3.cpp`:
```bash
# Note: This project requires Windows environment due to windows.h dependency
g++ -o virtualpet "draft 3.cpp"    # Windows only
./virtualpet
```
- **Pet Care**: Feed, play, rest, and groom your virtual pet
- **Save/Load**: Persistent game state
- **Multiple Species**: Dogs, Cats, and Birds
- **Platform**: Windows-specific (uses Windows.h for console colors)

### 🏪 Super Market System
Navigate to `Projects/Super_Market_Project/` and compile `A3.cpp`:
```bash
g++ -o supermarket A3.cpp
./supermarket
```
- **Inventory Management**: Complete product lifecycle management
- **Sales Processing**: Billing and receipt generation

## ✨ Features

### 🎯 Core Programming Concepts
- **Object-Oriented Programming**: Classes, inheritance, polymorphism, encapsulation
- **File I/O Operations**: Data persistence and file management
- **Exception Handling**: Robust error management
- **Template Programming**: Generic programming concepts
- **STL Usage**: Standard Template Library implementations

### 🏢 Real-World Applications
- **E-commerce Systems**: Complete shopping cart and inventory management
- **Healthcare Management**: Drug store with admin and customer interfaces  
- **Entertainment**: Interactive virtual pet simulation
- **Retail Management**: Supermarket inventory and sales system

### 📚 Educational Value
- **Academic Assignments**: Structured OOP and PF coursework
- **Progressive Learning**: From basic concepts to complex applications
- **Best Practices**: Clean code structure and documentation
- **Industry Standards**: Professional coding patterns and conventions

## 📁 Project Structure

```
CS-fundamentals-Projects/
├── Projects/
│   ├── Drug_Store_Project/          # 🏥 Healthcare management system
│   │   ├── projct.cpp              # Main source code
│   │   ├── projct.exe              # Compiled executable
│   │   └── SOLD_ITEMS.TXT          # Sales data file
│   ├── Online_Shoping_Project/      # 🛒 E-commerce platform
│   │   ├── hamid.cpp               # Main source code
│   │   ├── hamid.exe               # Compiled executable
│   │   └── savegame.txt            # Data persistence
│   ├── Super_Market_Project/        # 🏪 Retail management system
│   │   ├── A3.cpp                  # Main source code
│   │   ├── A3.exe                  # Compiled executable
│   │   └── database.txt            # Product database
│   └── Virtual_Pet_Project/         # 🐾 Interactive pet simulation
│       ├── draft 3.cpp             # Main source code
│       ├── draft 3.exe             # Compiled executable
│       └── database.txt            # Pet data storage
├── oop/                            # 📚 Object-Oriented Programming
│   ├── OOP(Assingment#1)/          # Assignment collection
│   │   ├── Atask#1.cpp to Atask#10.cpp  # Individual tasks
│   └── extrated_programs/          # Additional OOP programs
│       ├── Package management systems
│       ├── Inheritance examples
│       └── Template implementations
└── pf/                             # 💻 Programming Fundamentals
    ├── Lab assignments and tasks
    ├── Algorithm implementations
    ├── Data structure examples
    └── Basic programming concepts
```

## 🏗️ Built With

- **[C++](https://isocpp.org/)** - Primary programming language
- **[Standard Template Library (STL)](https://en.cppreference.com/w/cpp/header)** - Data structures and algorithms
- **[iostream](https://en.cppreference.com/w/cpp/header/iostream)** - Input/output operations
- **[fstream](https://en.cppreference.com/w/cpp/header/fstream)** - File stream operations
- **[string](https://en.cppreference.com/w/cpp/header/string)** - String manipulation
- **[vector](https://en.cppreference.com/w/cpp/header/vector)** - Dynamic arrays
- **[limits](https://en.cppreference.com/w/cpp/header/limits)** - Numeric limits
- **[stdexcept](https://en.cppreference.com/w/cpp/header/stdexcept)** - Exception handling

## 🤝 Contributing

Contributions are what make the open source community such an amazing place to learn, inspire, and create. Any contributions you make are **greatly appreciated**.

Please read our [Contributing Guidelines](./CONTRIBUTING.md) for details on our code of conduct and the process for submitting pull requests.

## 📄 License

Distributed under the MIT License. See [LICENSE](./LICENSE) for more information.

## 🗺️ Roadmap

### ✅ Current Features
- [x] Complete Drug Store Management System
- [x] Online Shopping Platform
- [x] Virtual Pet Simulation
- [x] Super Market Management
- [x] OOP Assignment Collection
- [x] Programming Fundamentals Examples

### 🚧 Planned Features
- [ ] **GUI Implementation**: Windows Forms or Qt-based interfaces
- [ ] **Database Integration**: MySQL/SQLite database connectivity
- [ ] **Network Features**: Multi-user support and client-server architecture
- [ ] **Advanced Algorithms**: Sorting, searching, and graph algorithms
- [ ] **Design Patterns**: Implementation of common design patterns
- [ ] **Unit Testing**: Comprehensive test suites for all projects

### 🔮 Future Vision
- [ ] **Web Integration**: REST API development for projects
- [ ] **Mobile Applications**: Cross-platform mobile versions
- [ ] **Advanced OOP**: Design patterns and enterprise architecture
- [ ] **Performance Optimization**: Algorithm efficiency improvements
- [ ] **Documentation**: Video tutorials and detailed guides

## 🙏 Acknowledgements

### 📚 Educational Resources
- **C++ Reference Documentation** - [cppreference.com](https://en.cppreference.com/)
- **Object-Oriented Programming Concepts** - Academic coursework foundation
- **Software Engineering Principles** - Industry best practices

### 🛠️ Development Tools
- **GCC Compiler** - GNU Compiler Collection
- **Code::Blocks IDE** - Integrated development environment
- **Git & GitHub** - Version control and collaboration

### 💡 Inspiration
- Real-world business applications and systems
- Academic computer science curriculum
- Open source community contributions

---

<div align="center">

**Made with ❤️ by [H0NEYP0T-466](https://github.com/H0NEYP0T-466)**

</div>