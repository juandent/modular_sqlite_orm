module;

#include <sqlite3.h>
#include <memory>  // std::unique_ptr
#include <type_traits>  // std::integral_constant


export module statement_finalizer;

export
{
    namespace sqlite_orm {

        /**
         *  Guard class which finalizes `sqlite3_stmt` in dtor
         */
        using statement_finalizer =
            std::unique_ptr<sqlite3_stmt, std::integral_constant<decltype(&sqlite3_finalize), sqlite3_finalize>>;
    }
}
