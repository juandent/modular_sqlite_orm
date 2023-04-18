module;

#include <tuple>  //  std::tuple

//#include "cxx_type_traits_polyfill.h"
//#include "tuple_filter.h"
//#include "tuple_transformer.h"
//#include "type_traits.h"
//#include "storage_lookup.h"


export module storage_traits;
import cxx_type_traits_polyfill;
import tuple_filter;
import tuple_transformer;
import type_traits;
import storage_lookup;
import column;

export
{
    namespace sqlite_orm {

        namespace internal {

            namespace storage_traits {

                /**
                 *  DBO - db object (table)
                 */
                template<class DBO>
                struct storage_mapped_columns_impl
                    : tuple_transformer<filter_tuple_t<elements_type_t<DBO>, is_column>, field_type_t> {};

                template<>
                struct storage_mapped_columns_impl<polyfill::nonesuch> {
                    using type = std::tuple<>;
                };

                /**
                 *  DBOs - db_objects_tuple type
                 *  Lookup - mapped or unmapped data type
                 */
                template<class DBOs, class Lookup>
                struct storage_mapped_columns : storage_mapped_columns_impl<storage_find_table_t<Lookup, DBOs>> {};
            }
        }
    }
}

