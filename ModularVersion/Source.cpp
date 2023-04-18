//import sqlite_orm;
import storage;
import table;
import column;

using namespace sqlite_orm;

#include <string>

struct Persona
{
	std::string name;
	int age;
};

void use()
{

	auto storage = make_storage("pruebamodular.sqlite", make_table("Personas", make_column("name", &Persona::name), make_column("age", &Persona::age)));
	storage.sync_schema();


}
