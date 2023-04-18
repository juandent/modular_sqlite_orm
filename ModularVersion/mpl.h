#pragma once

/*
 *  Symbols for 'template metaprogramming' (compile-time template programming),
 *  inspired by the MPL of Aleksey Gurtovoy and David Abrahams.
 *
 *  Currently, the focus is on facilitating advanced type filtering,
 *  such as filtering columns by constraints having various traits.
 *  Hence it contains only a very small subset of a full MPL.
 *
 *  Two key concepts are critical to understanding:
 *  1. A 'metafunction' is a class template that represents a function invocable at compile-time.
 *  2. A 'metafunction class' is a certain form of metafunction representation that enables higher-order metaprogramming.
 *     More precisely, it's a class with a nested metafunction called "fn"
 *     Correspondingly, a metafunction class invocation is defined as invocation of its nested "fn" metafunction.
 *  3. A 'metafunction operation' is an alias template that represents a function whose instantiation already yields a type.
 *
 *  Conventions:
 *  - "Fn" is the name for a metafunction template template parameter.
 *  - "FnCls" is the name for a metafunction class template parameter.
 *  - "_fn" is a suffix for a type that accepts metafunctions and turns them into metafunction classes.
 *  - "higher order" denotes a metafunction that operates on another metafunction (i.e. takes it as an argument).
 */

#include <type_traits>  //  std::false_type, std::true_type

#include "cxx_universal.h"
#include "cxx_type_traits_polyfill.h"

