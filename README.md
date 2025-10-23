# JSON_language_parser

# JSON Language Parser – Flex & Bison Implementation

This repository contains a **lexical and syntactic analyzer** implemented using **Flex** and **Bison**, as part of the *Programming Languages and Compilers* course at the **University of Patras (CEID)**. The project demonstrates how to define a custom grammar and parser capable of recognizing and validating a simplified programming language syntax inspired by **JSON and Java-like structures**.

---

## Project Overview

The goal of this exercise was to familiarize students with **language description in BNF**, as well as the fundamentals of compiler construction. Specifically, it involves creating:

* a **lexical analyzer** (`lexer.l` → `lex.yy.c`), and
* a **syntax analyzer** (`parser.y` → `parser.tab.c`, `parser.tab.h`)
  using **Flex** and **Bison**.

The implemented parser validates Java-like source code structures and outputs parsing results (success or syntax errors) for each test input file.

---


## Grammar Features

The grammar supports the recognition of key programming constructs such as:

* **Class declarations** (`public class Example { ... }`)
* **Variable declarations** (`int x, y;`)
* **Methods with return types** and optional modifiers
* **Control structures** (`if`, `while`, `for`, `switch`)
* **Operators** (`+`, `-`, `*`, `/`, `==`, `!=`, `>`, `<`, `&&`, `||`)
* **Print statements** (`out.print("text", var);`)

Example of supported syntax:

```java
public class Example {
    int x;
    int y;

    public void printX() {
        out.print("Η τιμή του x είναι:", x);
    }
}
```


##  How It Works

1. **Lexical Analysis (Flex)**
   The lexer identifies tokens such as keywords (`class`, `public`, `int`), identifiers, literals, and punctuation symbols.

2. **Parsing (Bison)**
   The parser processes these tokens according to the grammar rules defined in `parser.y` and validates the syntax.

3. **Execution Flow**

   * Correct input prints messages like: `Parsing successful!`
   * Incorrect syntax triggers an error via `yyerror()`.

---

##  Compilation & Execution

Run the following commands in your terminal:

```bash
# Step 1: Generate the scanner and parser
flex lexer.l
bison -d parser.y

# Step 2: Compile the generated C files
gcc lex.yy.c parser.tab.c -o parser -lfl

# Step 3: Run the parser on a test file
./parser < test1ARXES.txt
```

Expected output:

```
Parsing successful: input conforms to grammar.
```

Or, if there is a syntax error:

```
Syntax error near token: ...
```

---

##  Test Input Example

**File:** `test1ARXES.txt`

```java
public class Example {
    int x;
    int y;
    int z;

    public void printX() {
        out.print("Η τιμή του x είναι:", x);
    }
}
```

 **Expected Output:** Parsing successful.

---

##  Authors

**annazacharaki**,
**evelinastavropoulou**,
Department of Computer Engineering and Informatics (CEID)
University of Patras, Greece

---

## License

This project was created for educational purposes as part of the *Programming Languages and Compilers* laboratory exercise.
All code and grammar files are open-source for academic use and learning.


