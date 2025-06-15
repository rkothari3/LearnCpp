# Debugging Tactics

## Debugging Tactic #1: Commenting Out Code  
**Purpose**: Narrow down which part of the code causes the issue.

**Example**:
```cpp
int main()
{
    getNames();       
//    doMaintenance();   // Comment to isolate
    sortNames();       
    printNames();      

    return 0;
}
```

**Outcomes**:  
- Problem disappears → culprit found  
- No change → code likely not responsible  
- New issue appears → code was needed, but may not be the bug source  

**Tip**: Track what you comment out—use version control to revert changes easily.

## Debugging Tactic #2: Validating Function Calls  
**Purpose**: Check if functions are called as expected.

**Example**:
```cpp
#include <iostream>

int getValue()
{
    std::cerr << "getValue() called\n";
    return 4;
}

int main()
{
    std::cerr << "main() called\n";
    std::cout << getValue() << '\n'; // Fixed: added ()
    return 0;
}
```

**Tips**:  
- Use `std::cerr` (unbuffered) for debug output instead of `std::cout`  
- For clarity, leave debug lines unindented or use `// clang-format off`

## Debugging Tactic #3: Printing Variable Values  
**Purpose**: Verify if variables hold expected data.

**Bug Example**:
```cpp
int z{ add(x, 5) }; // Should be add(x, y)
```

**With Debugging**:
```cpp
#include <iostream>

int add(int x, int y)
{
    std::cerr << "add() called (x=" << x << ", y=" << y << ")\n";
    return x + y;
}

int main()
{
    int x{ getUserInput() };
    std::cerr << "main::x = " << x << '\n';

    int y{ getUserInput() };
    std::cerr << "main::y = " << y << '\n';

    int z{ add(x, y) }; // Corrected here
    std::cerr << "main::z = " << z << '\n';

    printResult(z);
    return 0;
}
```
### Improve Debugging Efficiency ###
- One way to do so it by making it easier to disable and enable debugging throughout the program by using preprocessor directives.
    - Downside is more code clutter.

```cpp
#include <iostream>

#define ENABLE_DEBUG // comment out to disable debugging

int getUserInput()
{
#ifdef ENABLE_DEBUG
    std::cerr << "getUserInput() called\n";
#endif
    std::cout << "Enter a number: ";
    int x{};
    std::cin >> x;
    return x;
}

int main()
{
#ifdef ENABLE_DEBUG
    std::cerr << "main() called\n";
#endif
    int x{ getUserInput() };
    std::cout << "You entered: " << x << '\n';

    return 0;
}
```
- Additionally, a logger can be used. It writes info to a log file separated from your program's output. 
Here's some example code. Using Plog logger (a 3rd party logger).
```cpp
#include <plog/Log.h> // Step 1: include the logger headers
#include <plog/Initializers/RollingFileInitializer.h>
#include <iostream>

int getUserInput()
{
	PLOGD << "getUserInput() called"; // PLOGD is defined by the plog library

	std::cout << "Enter a number: ";
	int x{};
	std::cin >> x;
	return x;
}

int main()
{
	plog::init(plog::debug, "Logfile.txt"); // Step 2: initialize the logger

	PLOGD << "main() called"; // Step 3: Output to the log as if you were writing to the console

	int x{ getUserInput() };
	std::cout << "You entered: " << x << '\n';

	return 0;
}

/*
* Output would be generated as follows in Logfile.txt.
2018-12-26 20:03:33.295 DEBUG [4752] [main@19] main() called
2018-12-26 20:03:33.296 DEBUG [4752] [getUserInput@7] getUserInput() called
*/
```

## Chapter Review

A syntax error is an error that occurs when you write a statement that is not valid according to the grammar of the C++ language. The compiler will catch these.

A semantic error occurs when a statement is syntactically valid, but does not do what the programmer intended.

The process of finding and removing errors from a program is called debugging.

We can use a five-step process to approach debugging:

1. Find the root cause.
2. Understand the problem.
3. Determine a fix.
4. Repair the issue.
5. Retest.

Finding an error is usually the hardest part of debugging.

Static analysis tools are tools that analyze your code and look for semantic issues that may indicate problems with your code.

Being able to reliably reproduce an issue is the first and most important step in debugging.

There are a number of tactics we can use to help find issues:

- Commenting out code.
- Using output statements to validate your code flow.
- Printing values.

When using print statements to debug, use `std::cerr` instead of `std::cout`. But even better, avoid debugging via print statements.

A log file is a file that records events that occur in a program. The process of writing information to a log file is called logging.

The process of restructuring your code without changing how it behaves is called refactoring. This is typically done to make your program more organized, modular, or performant.

Unit testing is a software testing method by which small units of source code are tested to determine whether they are correct.

Defensive programming is a technique whereby the programmer tries to anticipate all of the ways the software could be misused. These misuses can often be detected and mitigated.

All of the information tracked in a program (variable values, which functions have been called, the current point of execution) is part of the program state.

A debugger is a tool that allows the programmer to control how a program executes and examine the program state while the program is running. An integrated debugger is a debugger that integrates into the code editor.

Stepping is the name for a set of related debugging features that allow you to step through your code statement by statement.

- **Step into** executes the next statement in the normal execution path of the program, and then pauses execution. If the statement contains a function call, step into causes the program to jump to the top of the function being called.
- **Step over** executes the next statement in the normal execution path of the program, and then pauses execution. If the statement contains a function call, step over executes the function and returns control to you after the function has been executed.
- **Step out** executes all remaining code in the function currently being executed and then returns control to you when the function has returned.
- **Run to cursor** executes the program until execution reaches the statement selected by your mouse cursor.
- **Continue** runs the program, until the program terminates or a breakpoint is hit. Start is the same as continue, just from the beginning of the program.

A breakpoint is a special marker that tells the debugger to stop execution of the program when the breakpoint is reached.

The set next statement command allows us to change the point of execution to some other statement (sometimes informally called jumping). This can be used to jump the point of execution forwards and skip some code that would otherwise execute, or backwards and have something that already executed run again.

Watching a variable allows you to inspect the value of a variable while the program is executing in debug mode. The watch window allows you to examine the value of variables or expressions.

The call stack is a list of all the active functions that have been executed to get to the current point of execution. The call stack window is a debugger window that shows the call stack.
