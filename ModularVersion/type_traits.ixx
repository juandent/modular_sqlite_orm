module;

#include "config.h"
#include "type_traits.h"


export module type_traits;

import cxx_type_traits_polyfill;

export
{
    namespace sqlite_orm {
        // C++ generic traits used throughout the library
        namespace internal {
            template<class T, class... Types>
            using is_any_of = polyfill::disjunction<std::is_same<T, Types>...>;

            // enable_if for types
            template<template<typename...> class Op, class... Args>
            using match_if = std::enable_if_t<Op<Args...>::value>;

            // enable_if for types
            template<template<typename...> class Op, class... Args>
            using match_if_not = std::enable_if_t<polyfill::negation_v<Op<Args...>>>;

            // enable_if for types
            template<class T, template<typename...> class Primary>
            using match_specialization_of = std::enable_if_t<polyfill::is_specialization_of_v<T, Primary>>;

            // enable_if for functions
            template<template<typename...> class Op, class... Args>
            using satisfies = std::enable_if_t<Op<Args...>::value, bool>;

            // enable_if for functions
            template<template<typename...> class Op, class... Args>
            using satisfies_not = std::enable_if_t<polyfill::negation<Op<Args...>>::value, bool>;

            // enable_if for functions
            template<class T, template<typename...> class Primary>
            using satisfies_is_specialization_of = std::enable_if_t<polyfill::is_specialization_of_v<T, Primary>, bool>;
        }

        // type name template aliases for syntactic sugar
        namespace internal {
            template<typename T>
            using type_t = typename T::type;

            template<typename T>
            using field_type_t = typename T::field_type;

            template<typename T>
            using constraints_type_t = typename T::constraints_type;

            template<typename T>
            using object_type_t = typename T::object_type;

            template<typename T>
            using elements_type_t = typename T::elements_type;

            template<typename T>
            using target_type_t = typename T::target_type;

            template<typename T>
            using on_type_t = typename T::on_type;
        }

#ifdef SQLITE_ORM_CPP20_CONCEPTS_SUPPORTED
        template<class T>
        concept orm_names_type = requires { typename T::type; };
#endif
    }
}
