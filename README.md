# 214-PA5

## Group Organization
### Members
<p>
Iwan de Jong (u22498037@tuks.co.za)  <a href="https://github.com/iwandejong" target="_blank"><img alt="GitHub" src="https://img.shields.io/badge/-@iwandejong-181717?style=flat-square&logo=GitHub&logoColor=white"></a>


</p>

<details>
<summary>Coding Standards</summary>
<!-- ## Coding Standards -->

### 1. Organizational

**1.1. Use a version control system**
- Never keep files checked out for long periods.
- Ensure that checked-in code doesn't break the build.

**1.2. Code Reviews**
- Peer-review other's work so that you understand what is going on and ensure their code isn't breaking your code.

**1.3. File Names**
Filenames should be all lowercase and can include underscores. 

Examples of acceptable file names:

`my_useful_class.cpp`
`myusefulclass.cpp`

### 2. Design Style

**2.1. Give entity *one* cohesive responsibility**
- For each entity, focus on one thing at a time.
- Give each entity (variable, class, function) one well-defined responsibility.
- As the entity grows, the scope increases, but it should not diverge.

**2.2. KISS**
KISS (Keep It Simple Software): 
- Correct is better than fast. 
- Simple is better than complex.
- Clear is better than cute.
- Safe is better than insecure

**2.3. Minimize global and shared data**
Sharing causes contention. Avoid shared data, like global data. This increases coupling which reduces maintainability.

**2.4. Ensure resources are owned by objects**
Never allocate more than one resource (pointer) in a single statement. This eases the process of memory deallocation.

**2.5. Optimize for the reader, not the writer**
More time is spent reading code than writing it.

### 3. Coding Style

**3.1. Use `const`proactively**
`const` (immutable) variables are easier to understand and to track. It's safe and checked at compile time.

**3.2. Declare Variables as locally as possible**
Variables introduce state, and you should have to deal with as little state as possible, with lifetimes as short as possible.

**3.3. Always initialize variables**
This is a common source of C++ bugs. Initialize variables upon definition.

**3.4. Avoid long functions**
Excessively long functions and nested code blocks are often caused by failing to give one function one cohesive responsibility (As explained in **2.1**).

**3.5. Minimize Definitional Dependencies**
Don’t be over-dependent: Don’t #include a definition when it is not needed (or included by its parent anyways).

**3.6. Always write internal #include guards**
Prevent unintended multiple inclusions by using #include guards.

**3.7. Don't use `using namespace std;`**
Rather use a using-declaration which lets you use cout/cin/string without qualification
```c++
using std::cout; 
cout << "Values:";
```

### 4. Functions and Operators
**4.1. Order parameters according to their value, pointer or reference**
Distinguish among input, output, and input/output parameters, and between value and reference parameters.

**4.2. Avoid overloaded operators as far as possible**
Overload operators only for good reasons. It's easy to misuse operator overloading and cause confusion among fellow coders.

### 5. Class Design and Inheritance
**5.1. Use design patterns!**
Because we should xD.

**5.2. Each `new` should be coupled with an `delete`**
Basic thought for memory deallocation.

**5.3. The `#define` guard**
As an example, the file `foo/src/bar/baz.h` in project `foo` should have the following guard:
```c++
#ifndef FOO_BAR_BAZ_H_
#define FOO_BAR_BAZ_H_

...

#endif  // FOO_BAR_BAZ_H_
```

**5.4. Declaration Order**
Within each section, prefer grouping similar kinds of declarations together, and prefer the following order:

- Types and type aliases (typedef, using, enum, nested structs and classes, and friend types)
- (Optionally, for structs only) non-static data members
- Static constants
- Factory functions
- Constructors and assignment operators
- Destructor
- All other functions (static and non-static member functions, and friend functions)
- All other data members (static and non-static)

### 6. Construction, Destruction and Copying ###
**6.1. Define and initialize member variables in the same order**
Agree with your constructor's parameters: member variables are initialized in the order they are declared.

### 7. Error Handling and Exceptions
Prefer using exceptions over `cout`. This keeps the output clean.

### Sources
http://micro-os-plus.github.io/develop/sutter-101/
https://google.github.io/styleguide/cppguide.html
https://stackoverflow.com/questions/1452721/why-is-using-namespace-std-considered-bad-practice

</p>
</details>
