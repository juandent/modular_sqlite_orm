Modular_Sqlite_orm
==================
Library of Sqlite_orm using C++ 20 modules with Microsoft tools

# FIRST #

There are three projects in this repository:

1. ModularVersion
2. Sqlite3
3. UseModularVersion

Follow these steps to have a running version of the modular Sqlite_orm

1. Clone this repo to your local drive
2. Open the solution file with the latest version of Visual Studio 2022 Preview (currently that is v17.6.0 Preview 4)
3. Update the references amongst the 3 projects in this manner:
    1. In project #3 above, add a reference to both projects #1 and #2
4. Make sure the active configuration is Debug|x64
5. Rebuild project #3 (which will also build the other two projects)
6. Currently there will be a linkage error for an unresolved external - 
    this is being investigated by Microsoft
7. The modular sqlite_orm is contained in project #1, please take a look at it so
    as to get a feel for what building with modules looks like in C++ 20


**NOTE**: Compile only with Debug configuration at the solution level

**NOTE**: Compile UseModularVersion to reproduce linking problem
