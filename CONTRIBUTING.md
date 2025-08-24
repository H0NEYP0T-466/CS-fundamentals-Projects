# Contributing to CS-fundamentals-Projects

Thank you for your interest in contributing to CS-fundamentals-Projects! 🎉 We welcome contributions from developers of all skill levels, whether you're a student learning C++ or an experienced programmer looking to help others learn.

## 📋 Table of Contents

- [🚀 Getting Started](#-getting-started)
- [🔄 How to Contribute](#-how-to-contribute)
- [🎨 Code Style Guidelines](#-code-style-guidelines)
- [🐛 Bug Reports](#-bug-reports)
- [✨ Feature Requests](#-feature-requests)
- [🧪 Testing Guidelines](#-testing-guidelines)
- [📚 Documentation Updates](#-documentation-updates)
- [💬 Community Guidelines](#-community-guidelines)

## 🚀 Getting Started

### Fork the Repository

1. **Fork the project** on GitHub by clicking the "Fork" button
2. **Clone your fork** locally:
   ```bash
   git clone https://github.com/YOUR_USERNAME/CS-fundamentals-Projects.git
   cd CS-fundamentals-Projects
   ```
3. **Create a new branch** for your feature or fix:
   ```bash
   git checkout -b feature/amazing-feature
   # or
   git checkout -b fix/bug-description
   ```

### Development Environment Setup

1. **Install a C++ Compiler**:
   - **Windows**: MinGW or Visual Studio
   - **Linux**: GCC (`sudo apt install g++` on Ubuntu)
   - **macOS**: Xcode Command Line Tools

2. **Choose an IDE/Editor**:
   - Code::Blocks
   - Visual Studio Code with C++ extension
   - Dev-C++
   - CLion

3. **Test your setup**:
   ```bash
   cd Projects/Drug_Store_Project
   g++ -o test projct.cpp
   ./test  # ./test.exe on Windows
   ```

## 🔄 How to Contribute

### 1. Choose Your Contribution Type

- **🐛 Bug Fix**: Fix existing issues in the codebase
- **✨ New Feature**: Add new functionality or projects
- **📚 Documentation**: Improve README, comments, or guides
- **🧹 Code Cleanup**: Refactor code for better readability
- **🎓 Educational Content**: Add examples or tutorials

### 2. Make Your Changes

1. **Follow the existing code structure**
2. **Write clear, readable code**
3. **Add comments for complex logic**
4. **Test your changes thoroughly**
5. **Update documentation if needed**

### 3. Submit Your Contribution

1. **Commit your changes**:
   ```bash
   git add .
   git commit -m "✨ Add: Brief description of your changes"
   ```

2. **Push to your fork**:
   ```bash
   git push origin feature/amazing-feature
   ```

3. **Open a Pull Request**:
   - Go to the original repository on GitHub
   - Click "New Pull Request"
   - Choose your branch
   - Fill out the PR template with details

## 🎨 Code Style Guidelines

### C++ Coding Standards

#### **Naming Conventions**
```cpp
// Classes: PascalCase
class DrugStore {
    // Private members: camelCase with underscore prefix
private:
    string _drugName;
    double _price;
    
    // Public methods: camelCase
public:
    void addDrug();
    void displayInfo();
    
    // Constants: UPPER_CASE
    static const int MAX_DRUGS = 100;
};

// Functions: camelCase
void processOrder();
void calculateTotal();

// Variables: camelCase
string userName;
int totalPrice;
```

#### **Code Formatting**
```cpp
// Use consistent indentation (4 spaces)
class Example {
public:
    void function() {
        if (condition) {
            // Do something
            for (int i = 0; i < 10; ++i) {
                processItem(i);
            }
        }
    }
};

// Include proper spacing
int result = calculateSum(a, b, c);
```

#### **File Organization**
```cpp
// File header with description
/*
 * Project: CS-fundamentals-Projects
 * File: example.cpp
 * Description: Brief description of file purpose
 * Author: Your Name
 * Date: YYYY-MM-DD
 */

#include <iostream>
#include <string>
#include <fstream>
// ... other includes

using namespace std;

// Class declarations
class MyClass {
    // Implementation
};

// Function implementations
int main() {
    // Main function logic
    return 0;
}
```

### Documentation Standards

#### **Class Documentation**
```cpp
/**
 * @class DrugStore
 * @brief Manages pharmaceutical inventory and sales
 * 
 * This class provides functionality for managing a drug store's
 * inventory, including adding new drugs, processing sales, and
 * generating reports.
 */
class DrugStore {
    /**
     * @brief Adds a new drug to the inventory
     * @param name The name of the drug
     * @param price The price per unit
     * @param quantity The initial stock quantity
     * @return true if successfully added, false otherwise
     */
    bool addDrug(const string& name, double price, int quantity);
};
```

#### **Function Documentation**
```cpp
/**
 * @brief Calculates the total cost including tax
 * @param basePrice The base price before tax
 * @param taxRate The tax rate as a decimal (e.g., 0.08 for 8%)
 * @return The total price including tax
 * @throws invalid_argument if taxRate is negative
 */
double calculateTotalWithTax(double basePrice, double taxRate) {
    if (taxRate < 0) {
        throw invalid_argument("Tax rate cannot be negative");
    }
    return basePrice * (1 + taxRate);
}
```

## 🐛 Bug Reports

When reporting bugs, please include:

### Required Information
- **Operating System**: Windows 10, Ubuntu 20.04, macOS Big Sur, etc.
- **Compiler**: GCC 9.4.0, Visual Studio 2019, etc.
- **Project**: Which specific project (Drug Store, Shopping, etc.)
- **Steps to Reproduce**: Detailed steps to trigger the bug
- **Expected Behavior**: What should happen
- **Actual Behavior**: What actually happens
- **Error Messages**: Complete error messages or output

### Example Bug Report
```markdown
**Bug**: Program crashes when adding invalid drug price

**Environment**:
- OS: Windows 10
- Compiler: MinGW GCC 8.1.0
- Project: Drug Store Project

**Steps to Reproduce**:
1. Run the drug store program
2. Choose "Add New Drug"
3. Enter a negative price value
4. Program crashes with segmentation fault

**Expected**: Program should display error message and prompt again
**Actual**: Program crashes immediately

**Error Message**:
```
Segmentation fault (core dumped)
```
```

## ✨ Feature Requests

### Before Submitting a Feature Request

1. **Check existing issues** to avoid duplicates
2. **Consider the scope** - does it fit the educational purpose?
3. **Think about implementation** - provide technical details if possible

### Feature Request Template

```markdown
**Feature Request**: Add database connectivity to Drug Store

**Problem**: Currently using text files for data storage, which is limiting

**Proposed Solution**: 
- Integrate SQLite database
- Create database schema for drugs, customers, sales
- Implement CRUD operations with SQL

**Benefits**:
- Better data integrity
- Improved performance
- Real-world database experience for students

**Implementation Ideas**:
- Use SQLite C++ library
- Create DatabaseManager class
- Maintain backward compatibility with file system

**Additional Context**:
This would help students learn database concepts alongside OOP.
```

## 🧪 Testing Guidelines

### Manual Testing Requirements

Before submitting any code changes:

1. **Compile Successfully**:
   ```bash
   g++ -Wall -Wextra -std=c++11 -o program source.cpp
   ```

2. **Test All Menu Options**:
   - Try all available menu choices
   - Test invalid input handling
   - Verify file operations work correctly

3. **Edge Case Testing**:
   - Empty inputs
   - Very large numbers
   - Special characters
   - File permission issues

4. **Memory Management**:
   - Check for memory leaks (if using dynamic allocation)
   - Verify proper destructor calls
   - Test exception handling

### Testing Checklist

- [ ] Code compiles without warnings
- [ ] All menu options work correctly
- [ ] Invalid input is handled gracefully
- [ ] File operations succeed and fail appropriately
- [ ] Program exits cleanly
- [ ] No memory leaks detected
- [ ] Documentation is updated

## 📚 Documentation Updates

### When to Update Documentation

- Adding new features or projects
- Changing existing functionality
- Fixing bugs that affect usage
- Improving code clarity
- Adding educational examples

### Documentation Types

1. **README.md**: Project overview and setup instructions
2. **Code Comments**: Inline documentation for complex logic
3. **Function Headers**: Parameter and return value descriptions
4. **Usage Examples**: Practical implementation demonstrations

### Documentation Style

- Use clear, concise language
- Include practical examples
- Keep formatting consistent
- Update all affected files
- Test all provided examples

## 💬 Community Guidelines

### Our Commitment

We are committed to providing a welcoming and educational environment for all contributors, regardless of experience level.

### Expected Behavior

- **Be Respectful**: Treat all community members with respect
- **Be Helpful**: Assist newcomers and answer questions patiently
- **Be Constructive**: Provide helpful feedback on code and ideas
- **Be Educational**: Share knowledge and learning resources
- **Be Professional**: Maintain appropriate language and tone

### Unacceptable Behavior

- Harassment or discrimination of any kind
- Trolling, insulting, or derogatory comments
- Publishing others' private information
- Any conduct that could be considered inappropriate in a professional setting

### Code Review Process

1. **Automated Checks**: Code will be checked for compilation and basic standards
2. **Peer Review**: Other contributors will review your code for:
   - Functionality and correctness
   - Code style and readability
   - Educational value
   - Documentation quality
3. **Maintainer Review**: Final review by project maintainers
4. **Feedback Integration**: Address any requested changes
5. **Merge**: Once approved, your contribution will be merged

### Recognition

All contributors will be:
- Listed in the project's contributors section
- Acknowledged in release notes for significant contributions
- Given credit in any academic or professional references to the project

---

## 🚀 Ready to Contribute?

1. **Start Small**: Look for issues labeled `good first issue` or `help wanted`
2. **Ask Questions**: Don't hesitate to ask for clarification in issues or discussions
3. **Share Ideas**: Open an issue to discuss new features before implementing
4. **Learn Together**: This is an educational project - we're all learning!

Thank you for contributing to CS-fundamentals-Projects! Your efforts help create better learning resources for students worldwide. 🌟

---

**Questions?** Open an issue or reach out to the maintainers. We're here to help!