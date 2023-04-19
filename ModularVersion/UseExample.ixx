module;

#include <string>
#include <dummy.h>
#include <sqlite3.h>



#ifndef WHATS_APP
#error Not included
#endif

export module UseExample;
// export import storage;
// export import table;
// export import column;
export import sqlite_orm;

using namespace sqlite_orm;

export
{

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

}



