# Crafting Interpreters
https://craftinginterpreters.com/

## Chapter 2: A Map of Terriotry

### The Parts of a Language
Program as string of characters -> higher-level representation -> lower-level forms
![phases-of-language](language_mountain.png)

---
#### Frontend 

1. Scanning or Lexing (Lexical analysis)
- Takes in linear stream of characters and chunks them together into a series of "words". 
- Each of these words is called a *token* 
- eg. numbers (123), string literals ("hi!"), identifiers (min)

2. Parsing
- Syntax gets a grammar - ability to compose larger expressions and statements out of smaller parts.
- Takes flat sequence of tokens and builds a tree structure that mirrors nested nature of the grammar.
- Parse tree or abstract syntax tree AST

3. Static analysis
- Binding or resolution - for each identifier, we find out where the name is defined and wire the two together
- Scope - the region of source code where a certain name can be used to refer to a certain declaration
- Once we know where a and b are declared, we can also figure out their types. Then if those types don’t support being added to each other, we report a type error.

- Symbol table - lookup table with keys as identifiers -  names of variables and declarations. Values it associates with each key tells what the identifier refers to.

--- 
#### Middle end

1. Intermediate representations
- Frontend is specific to source language the program is written in, the backend is concerned with the final architecture where the program will run.
- The code may be stored in some intermediate representation (IR), that isn't tightly tied to either source or destination forms.
- Acts as an interface between two languages
- Well established styles of IR - control flow graph (CFG), static single-assignment, continuation passing style and three-address code.
- Write one front end for each language that produces the IR. One backend for each target architecture. Mix and match those to get every combo.

2. Optimization
- Optimize the language
- Constant folding: if some expression always evaluates to exact same value, we can do evaluation at compile time and replace the code for expression with its result.

---
Backend

1. Code generation
- Convert it to a form the machine can actually run.
- Generating code (or code gen) - primitive assembly-like instructions a CPU runs
- Here we can generate instructions for a real CPU or a virtual one.
- If real CPU code - then it'll be fast but generating will take lot of work and will be machine specific.
- Generate a virtual machine code, called p-code for portable, today we call it bytecode (each instruction is single byte long)

2. Virtual machine
- If compiler produces bytecode, we need to translate.
- 1. Write a mini-compiler for each target architecture that converts bytecode to native machine code. We can reuse this compiler pipeline across all the machines you support. (Byetecode = intermediate representation)
- 2. Write a virtual machine (VM), a program that emulates a hypothetical chip supporting virtual architecture at runtime. 
    - running bytecode in a VM is slower than translating it to native code
    - in return, we get simplicity and portability.
    - Implement VM in say C, and we can run language on any platform that has a C compiler.

3. Runtime
- If compiled to machine code, simply tell OS to load executable and off it goes.
- If compiled in bytecode, start up the VM and load the program into it.
- Need some services that the language provides while the program is running.

### Shortcuts and Alternate Routes

1. Single-pass compilers
- Some compilers mix parsing, analysis and code generation, so that they produce output code directly in the parser, without allocating any syntax tree or other IR.
- No intermediate data structure to store global information about the program, don't revist any previously parsed part of the code.
- As soon as you see expression, you need to know enough to correctly compile it.
- Syntax-directed translation: a structured technique for building these all-at-once compilers. You associate an action with each piece of the grammar, usually one that generates output code. Then, whenever the parser matches that chunk of syntax, it executes the action, building up the target code one rule at a time.

2. Tree-walk interpreters
- Some languages begin executing code right after parsing it to an AST.
- To run, the interpreter traverses syntax tree one branch and leaf at a time, evaluating each node as it goes.

3. Transpilers
- Writing a complete backend for a language can be a lot of work
- Have some existing generic IR to target language.
- Write a front end for your language, then in back end instead of doing all the work to lower the semantics to some primitive target language. (Your language -> Some other language)
- Use existing compilation tools for that language.
- source-to-source compiler or a transcompiler.

4. Just-in-time compilation
- On the end user’s machine, when the program is loaded—either from source in the case of JS, or platform-independent bytecode for the JVM and CLR—you compile it to native code for the architecture their computer supports.
