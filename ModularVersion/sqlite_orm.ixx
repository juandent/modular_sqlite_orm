module;

#include "config.h"
#include "cxx_core_features.h"

export module sqlite_orm;

export import type_traits;
export import error_code;
export import type_printer;
export import collate_argument;
export import constraints;
export import type_is_nullable;
export import operators;
export import column;
export import field_printer;
export import conditions;
export import alias;
export import core_functions;
export import select_constraints;
export import table_info;
export import triggers;
export import statement_finalizer;
export import arithmetic_tag;
export import pointer_value;
export import statement_binder;
export import row_extractor;
export import sync_schema_result;
export import index;
export import rowid;
export import table;
export import storage_impl;
export import default_value_extractor;
export import storage;
export import get_prepared_statement;
export import carray;
export import sqlite_schema_table;
export import dbstat;
export import interface_definitions;



// #include "../../dev/functional/start_macros.h"
// // though each header is required to include everything it needs
// // we include the configuration and all underlying c++ core features in order to make it universally available
// #include "../../dev/functional/config.h"
// #include "../../dev/type_traits.h"
// #include "../../dev/error_code.h"
// #include "../../dev/type_printer.h"
// #include "../../dev/collate_argument.h"
// #include "../../dev/constraints.h"
// #include "../../dev/type_is_nullable.h"
// #include "../../dev/operators.h"
// #include "../../dev/column.h"
// #include "../../dev/field_printer.h"
// #include "../../dev/conditions.h"
// #include "../../dev/alias.h"
// #include "../../dev/core_functions.h"
// #include "../../dev/select_constraints.h"
// #include "../../dev/table_info.h"
// #include "../../dev/triggers.h"
// #include "../../dev/statement_finalizer.h"
// #include "../../dev/arithmetic_tag.h"
// #include "../../dev/pointer_value.h"
// #include "../../dev/statement_binder.h"
// #include "../../dev/row_extractor.h"
// #include "../../dev/sync_schema_result.h"
// #include "../../dev/index.h"
// #include "../../dev/rowid.h"
// #include "../../dev/table.h"
// #include "../../dev/storage_impl.h"
// #include "../../dev/default_value_extractor.h"
// #include "../../dev/storage.h"
// #include "../../dev/get_prepared_statement.h"
// #include "../../dev/carray.h"
// #include "../../dev/sqlite_schema_table.h"
// #include "../../dev/eponymous_vtabs/dbstat.h"
// #include "../../dev/interface_definitions.h"
// #include "../../dev/functional/finish_macros.h"
