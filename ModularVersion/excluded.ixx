module;

#include <utility>  //  std::move

export module excluded;

export
{
    namespace sqlite_orm {
        namespace internal {

            template<class T>
            struct excluded_t {
                using expression_type = T;

                expression_type expression;
            };
        }

        template<class T>
        internal::excluded_t<T> excluded(T expression) {
            return { std::move(expression) };
        }
    }
}
