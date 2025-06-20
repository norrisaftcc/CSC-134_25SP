# CLAUDE.md

This file provides guidance to Claude Code (claude.ai/code) when working with code in this repository.

## Repository Overview

This is a CSC-134 Introductory C++ course repository for mixed first-year college students (programming, engineering, and associate of arts/science transfer). The repository contains practical examples, assignments, and projects organized by learning modules.

**Course Context**: This is a revamped version of CSC-134 transitioning from Blackboard to Canvas. The course is designed to be clean, simple to follow, and serves three sections: face-to-face, online, and f2f high school students.

**Course Philosophy**: 
- Focus on practical coding over excessive reading
- Emphasize tool proficiency (GitHub, development environment)
- Build toward CSC-249 (Data Structures) preview in later modules
- Maintain consistent pacing across all three course sections

## Module-Based Organization

The codebase is structured into 7 learning modules, each focusing on specific C++ concepts:

### Module 1 (module1/) - Introduction & Hello World
- Basic C++ syntax, iostream, cout statements
- Entry point for absolute beginners
- Files: m1t1_norris.cpp, m1lab1_norris.cpp, m1t2_norris.cpp

### Module 2 (module2/) - Variables & Input/Output  
- Variable declarations, cin/cout, basic data types
- Files: m2t1_norris.cpp, m2t2_norris.cpp, m2lab1_norris.cpp

### Module 3 (module3/) - Control Structures
- if/else statements, switch cases, constants
- Choice-based programming examples (pokemon battles, decision trees)
- Files: m3t1_norris.c++, m3lab1_norris.cpp, m3t2_norris.c++, m3t3_norris.cpp

### Module 4 (module4/) - Loops & Iteration
- for loops, while loops, nested iterations
- Files: m4t1_norris.cpp, m4lab1_norris.c++

### Module 5 (module5/) - Functions & Arrays
- Function declarations/definitions, parameters, return values
- Array manipulation, 2D arrays
- **Note**: Module 5+ content may need restructuring - originally ended course here
- Files: M5T1_norris.c++, m5lab1_norris.cpp, array_2d_example.c++

### Module 6 (module6/) - Advanced Data Structures
- STL vectors, arrays vs vectors
- Example: Buckshot Roulette simulation using vectors
- Files: m6lab1_norris.c++, m6t1_norris.c++

### Module 7 (module7/) - Object-Oriented Programming
- Classes, constructors, getters/setters, encapsulation
- Example: Restaurant rating system
- **Note**: Course typically ends with beginning of OOP concepts
- Files: m7t1_norris.c++, m7bonus_norris.cpp, rectangle.h

### "Module Zero" - Foundational Skills
**Essential prerequisites before programming begins:**
- Tool proficiency: screenshots, file editing, submissions
- GitHub account creation and repository management
- Information literacy: search strategies vs. AI assistance
- Development environment setup

## File Naming Convention

All assignment files follow the pattern: `m[module]t[assignment]_norris.[cpp|c++]` or `m[module]lab[number]_norris.[cpp|c++]`
- Module number (1-7)
- Assignment type: 't' (task), 'lab' (laboratory), 'hw' (homework)
- Student identifier: 'norris'
- File extensions: .cpp or .c++ (both used)

## Development Environment

### Build System
- **Primary**: Manual compilation using g++
- **IDE Support**: Code::Blocks project files (.cbp) available for some assignments
- **Java Support**: Maven projects for NumberGuess and NumberProcessor examples

### Common Commands

**Compile single C++ file:**
```bash
g++ filename.cpp -o outputname
```

**Compile with debug symbols:**
```bash
g++ -g filename.cpp -o outputname
```

**Run compiled program:**
```bash
./outputname
```

**For Code::Blocks projects:**
```bash
# Navigate to project directory
cd module5/m5lab2_norris/
# Open with Code::Blocks or compile main.cpp directly
g++ main.cpp -o program
```

## Distributed Module Development

When working on this repository, focus on individual modules as self-contained learning units. Each module builds upon previous concepts:

1. **Module Dependencies**: Later modules assume knowledge from earlier ones
2. **Independent Development**: Each module can be improved/expanded separately
3. **Consistent Patterns**: Maintain the educational progression and coding style
4. **Student-Friendly**: Code should be readable for beginners with clear comments

## Future Repository Reorganization

**Planned Structure**: Separate educational content from source code within each module:
- **Student-facing content**: Tutorial examples (T assignments), instructions, guided exercises
- **Instructor resources**: Complete solutions, additional examples, assessment materials
- **Current limitation**: Students should not have access to all source code, only selected tutorial examples

**Implementation Notes**:
- Consider `src/` subdirectories within each module for complete code examples
- Maintain clear separation between tutorial code (student-accessible) and solution code (instructor-only)
- Instructions and educational materials will be added alongside existing code examples

## Code Characteristics

- **Educational Focus**: Code prioritizes clarity over optimization
- **Beginner-Friendly**: Heavy use of comments and explicit variable names
- **Incremental Complexity**: Each module introduces 1-2 new concepts
- **Practical Examples**: Game-like scenarios (Pokemon battles, restaurant reviews)
- **Mixed File Extensions**: Both .cpp and .c++ used throughout

## Special Files

- **Python Examples**: Some Python files for comparison/alternative implementations
- **Media Assets**: PNG files for visual examples
- **Text Data**: map.txt, squares.txt for file I/O examples
- **Twine Files**: .twee files for interactive fiction examples
- **Java Examples**: Maven-based projects demonstrating cross-language concepts
- **Documentation**: `docs/` directory contains:
  - Course syllabus and C++ Language Companion PDF
  - Revamp notes and planning documents
  - GitHub tutorial materials for "Module Zero"
  - Assignment templates and scheduling information

## Target Audience Considerations

When modifying or adding to this repository:
- Assume minimal programming background
- Include clear, educational comments
- Use relatable examples (games, restaurants, etc.)
- Maintain consistent difficulty progression
- Support both programming track and general education students