module;

#include "serialize_result_type.h"


export module serialize_result_type;

export
{
    namespace sqlite_orm {
        namespace internal {
#ifdef SQLITE_ORM_STRING_VIEW_SUPPORTED
            using serialize_result_type = std::string_view;
            using serialize_arg_type = std::string_view;
#else
            using serialize_result_type = std::string;
            using serialize_arg_type = const std::string&;
#endif
        }
    }
}
