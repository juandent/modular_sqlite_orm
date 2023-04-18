// UseModularVersion.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include <iostream>
#include <string>

import sqlite_orm;



//import UseExample;
// import AModule;
//import CModule;

//import storage;
//import table;
//import column;



//

using namespace sqlite_orm;

struct Persona
{
	std::string name;
	int age;
};


int main()
{
   
  //  use();
    // auto x = add(2, 7);
    std::cout << "Hello World!\n";
    //MyFunc();
    //Vector<int> v {new int};
    auto storage = make_storage("pruebamodular.sqlite", make_table("Personas", make_column("name", &Persona::name), make_column("age", &Persona::age)));
     auto vec = storage.get_all<Persona>();
     sync_schema_result res;
     Persona pers{};
     storage.insert<Persona>(pers);
     auto r = storage.sync_schema();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
