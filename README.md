# Compiler Design Course (C and C++)

This repository contains C and C++ code implementations and exercises from the **Compiler Design** course at **American International University - Bangladesh (AIUB)**. The repository showcases key concepts related to compiler construction, focusing on the various phases of compilation, including lexical analysis, syntax analysis, and intermediate code generation.

### Course Information
For more details on the course, refer to the [AIUB Undergraduate Course Catalog](https://www.aiub.edu/faculties/fst/ug-course-catalog).  
*Note: Search for "Compiler Design" for specific course information.*

## Table of Contents
- [Overview](#overview)
- [Course Topics Covered](#course-topics-covered)
- [Technologies Used](#technologies-used)
- [How to Run](#how-to-run)
- [Contact](#contact)

## Overview

The codes in this repository represent the practical applications of compiler design principles. Each section corresponds to different components of a compiler, such as tokenization, parsing, and generating intermediate code, all implemented in **C++**.

These exercises were designed to deepen the understanding of how compilers work by implementing various algorithms and techniques used in real-world compilers.

## Course Topics Covered

1. **Lexical Analysis**  
   - **Description:** Implementation of a lexical analyzer that breaks down input into tokens such as identifiers, keywords, operators, and literals.
   - **Key Concepts:** 
     - Tokenization using regular expressions.
     - Generation of a token stream from source code.

2. **Syntax Analysis**  
   - **Description:** Creation of parsers that analyze the syntactic structure of code based on context-free grammars (CFG).
   - **Key Concepts:**
     - Construction of parse trees.
     - LL(1) and recursive descent parsing.
     - Detecting and handling syntax errors.

3. **Semantic Analysis**  
   - **Description:** Basic semantic checking, including type checking and ensuring variables are declared before use.
   - **Key Concepts:**
     - Scope management and symbol tables.
     - Checking for semantic errors, such as type mismatches.

4. **Intermediate Code Generation**  
   - **Description:** Code that translates high-level language constructs into intermediate representations (like three-address code).
   - **Key Concepts:**
     - Three-address code (TAC) generation.
     - Abstract syntax trees (AST) used for code generation.
    
## Technologies Used

- **Programming Languages:**
  - **C**
  - **C++**
    
- **Tools and Libraries:**
  - Standard C/C++ libraries
  - Manual implementation of lexer, parser, and code generation without external tools like Flex or Bison.

## How to Run


### Running C Code
To compile and run C files, follow these steps:

1. Clone the repository to your local machine:
   ```bash
   git clone https://github.com/Raihan4520/Compiler-Design.git
2. Navigate to the folder containing the specific C file you want to run.
3. Compile the C code using a C compiler such as gcc:
   ```bash
   gcc <filename>.c -o <output_name>
4. Run the compiled executable:
   ```bash
   ./<output_name>

### Example
To compile and run an example code in C:
```bash
gcc example_code.c -o example_code
./example_code
```

### Running C++ Code
To compile and run C++ files, follow these steps:

1. After cloning the repository, navigate to the folder containing the C++ file.
2. Compile the C++ code using a C++ compiler like g++:
   ```bash
   g++ <filename>.cpp -o <output_name>
3. Run the compiled executable:
   ```bash
   ./<output_name>

### Example
To compile and run an example code in C++:
```bash
g++ example_code.cpp -o example_code
./example_code
```

Each file in the repository is standalone, and comments are included in the code to guide you on the expected input and output for each program.

## Contact

If you have any questions or suggestions, feel free to reach out through the repository's issues or contact me directly.
