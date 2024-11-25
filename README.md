# Mini C Compiler

A compiler for a subset of the C programming language, implemented as part of CSE310 (Compiler Sessional) at BUET. This compiler performs lexical analysis, syntax and semantic analysis, and generates optimized 8086 assembly code.

## Project Structure

The compiler was developed through four progressive assignments:

1. **Symbol Table Implementation**
   - Custom hash table implementation using SDBM hash function
   - Scope management for local and global variables
   - Operations: Insert, Delete, Lookup, Enter/Exit Scope
   - Memory-efficient linked list of scope tables

2. **Lexical Analysis (Using Flex)**
   - Token recognition for C subset
   - Handles: keywords, operators, identifiers, constants, strings, comments
   - Error detection for malformed tokens
   - Line number tracking and error reporting
   - Generates detailed token and error logs

3. **Syntax & Semantic Analysis (Using Bison)**
   - Parser implementation for C subset grammar
   - Symbol table integration for scope handling
   - Type checking and semantic validation
   - Function signature verification
   - Comprehensive error detection and reporting

4. **Intermediate Code Generation**
   - Generates 8086 assembly code
   - Stack-based variable and parameter handling
   - Peephole optimization implementation
   - Support for control structures and function calls
   - Integrated println() function support

## Features

### Language Support
- Basic data types: int, float, char
- Arrays and functions
- Control structures: if-else, loops
- Global and local variables
- Function parameters and return values
- Arithmetic and logical operations

### Error Handling
- Detailed error messages with line numbers
- Lexical error detection
- Syntax error reporting
- Semantic validation
- Type mismatch identification

### Optimization
- Peephole optimization techniques
- Redundant instruction elimination
- Dead code removal
- Stack operation optimization

## Build Instructions

```bash
# Clone the repository
git clone [repository-url]

# Navigate to project directory
cd mini-c-compiler

# Build the compiler
make

# Run the compiler
./compiler input.c

## Usage Example

```c
// sample.c
int main() {
    int a = 5;
    println(a);  // Built-in print function
    return 0;
}
Generated files:

token.txt: Lexical analysis output
log.txt: Compilation process log
error.txt: Any error messages
code.asm: Assembly code output
optimized_code.asm: Optimized assembly code

Requirements

Linux/Unix environment
Flex (Fast Lexical Analyzer)
Bison (Parser Generator)
GCC/G++ Compiler
EMU8086 (for running assembly code)

Limitations

No preprocessor directive support
Limited to subset of C language
No struct/union support
Basic optimization techniques only
No floating-point operation support in code generation

License
This project is submitted as part of CSE310 course requirements. Academic integrity rules apply.















