module;

#include "config.h"
#include <string>  //  std::string
#include <utility>  //  std::move

#include "cxx_core_features.h"
//#include "conditions.h"
//#include "alias_traits.h"


export module column_pointer;
import cxx_type_traits_polyfill;
import conditions;
import alias_traits;

export
{
    namespace sqlite_orm {
        namespace internal {
            /**
             *  This class is used to store explicit mapped type T and its column descriptor (member pointer/getter/setter).
             *  Is useful when mapped type is derived from other type and base class has members mapped to a storage.
             */
            template<class T, class F>
            struct column_pointer {
                using self = column_pointer<T, F>;
                using type = T;
                using field_type = F;

                field_type field;

                template<class R>
                is_equal_t<self, R> operator==(R rhs) const {
                    return { *this, std::move(rhs) };
                }

                template<class R>
                is_not_equal_t<self, R> operator!=(R rhs) const {
                    return { *this, std::move(rhs) };
                }

                template<class R>
                lesser_than_t<self, R> operator<(R rhs) const {
                    return { *this, std::move(rhs) };
                }

                template<class R>
                lesser_or_equal_t<self, R> operator<=(R rhs) const {
                    return { *this, std::move(rhs) };
                }

                template<class R>
                greater_than_t<self, R> operator>(R rhs) const {
                    return { *this, std::move(rhs) };
                }

                template<class R>
                greater_or_equal_t<self, R> operator>=(R rhs) const {
                    return { *this, std::move(rhs) };
                }
            };

            template<class T>
            SQLITE_ORM_INLINE_VAR constexpr bool is_column_pointer_v = polyfill::is_specialization_of_v<T, column_pointer>;

            template<class T>
            using is_column_pointer = polyfill::bool_constant<is_column_pointer_v<T>>;

#if 1   // JDH moved from conditions module to deal with cyclic dependencies
            /**
             *  USING argument holder.
             */
            template<class T, class M>
            struct using_t {
                column_pointer<T, M> column;

                operator std::string() const {
                    return "USING";
                }
            };
#endif

        }
#if 1   // JDH moved from conditions module to deal with cyclic dependencies
        template<class F, class O>
        internal::using_t<O, F O::*> using_(F O::* p) {
            return { p };
        }
        template<class T, class M>
        internal::using_t<T, M> using_(internal::column_pointer<T, M> cp) {
            return { std::move(cp) };
        }
#endif

    }
}
