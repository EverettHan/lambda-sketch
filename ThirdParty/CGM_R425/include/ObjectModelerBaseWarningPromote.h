#pragma once

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "CATWarningPromote.h"

#pragma warning(error: 4002) // too many actual parameters for macro 'identifier'
#pragma warning(error: 4018) // 'expression' : signed/unsigned mismatch
#pragma warning(error: 4020) // 'function' : too many actual parameters
#pragma warning(error: 4067) // unexpected tokens following preprocessor directive - expected a newline
#pragma warning(error: 4099) // 'identifier' : type name first seen using 'objecttype1' now seen using 'objecttype2'
#pragma warning(error: 4102) // 'label' : unreferenced label
#pragma warning(error: 4129) // '?': unrecognized character escape sequence
#pragma warning(error: 4154) // deletion of an array expression; conversion to pointer supplied
#pragma warning(error: 4172) // returning address of local variable or temporary
#pragma warning(error: 4227) // anachronism used : qualifiers on reference are ignored
#pragma warning(error: 4238) // nonstandard extension used : class rvalue used as lvalue
#pragma warning(error: 4239) // nonstandard extension used : 'token' : conversion from 'type' to 'type' (temporary for non const arg &)
#pragma warning(error: 4244) // 'argument' : conversion from 'XX' to 'YY', possible loss of data
#pragma warning(error: 4267) // possible loss of data
#pragma warning(error: 4311) // 'variable' : pointer truncation from 'type' to 'type'
#pragma warning(error: 4313) // 'function' : 'format specifier' in format string conflicts with argument number of type 'type'
#pragma warning(error: 4334) // 'operator' : result of 32-bit shift implicitly converted to 64 bits (was 64-bit shift intended?)
#pragma warning(error: 4353) // nonstandard extension used : constant 0 as function expression.Use '__noop' function intrinsic instead
#pragma warning(error: 4390) // ';' : empty controlled statement found; is this the intent?
#pragma warning(error: 4473) // 'function' : not enough arguments passed for format string placeholders and their parameters expect number variadic arguments...
#pragma warning(error: 4474) // 'function' : too many arguments passed for format string
#pragma warning(error: 4475) // 'function' : length modifier 'modifier' cannot be used with type field character 'character' in format specifier
#pragma warning(error: 4476) // 'function' : unknown type field character 'character' in format specifier
#pragma warning(error: 4477) // 'function' : format string 'string' requires an argument of type 'type', but variadic argument number has type 'type'
#pragma warning(error: 4516) // 'class::symbol' : access-declarations are deprecated; member using-declarations provide a better alternative
#pragma warning(error: 4521) // 'class' : multiple copy constructors [of a single/same type] specified
#pragma warning(error: 4522) // 'class' : multiple assignment operators [of a single/same type] specified
#pragma warning(error: 4552) // 'operator' : operator has no effect; expected operator with side-effect
#pragma warning(error: 4553) // 'operator' : operator has no effect; did you intend 'operator'?
#pragma warning(error: 4554) // 'operator' : check operator precedence for possible error; use parentheses to clarify precedence
#pragma warning(error: 4645) // function declared with 'noreturn' has a return statement
#pragma warning(error: 4646) // function declared with 'noreturn' has non-void return type
#pragma warning(error: 4700) // uninitialized local variable 'name' used
#pragma warning(error: 4701) // local variable 'name' may be used without having been initialized
#pragma warning(error: 4702) // unreachable code
#pragma warning(error: 4715) // 'function' : not all control paths return a value
#pragma warning(error: 4723) // potential divide by 0
#pragma warning(error: 4789) // destination of memory copy is too small
#pragma warning(error: 4804) // 'operation' : unsafe use of type 'bool' in operation
#pragma warning(error: 4805) // 'operation': unsafe mix of type 'type1' and type 'type2' in operation
#pragma warning(error: 4806) // 'operation' : unsafe operation: no value of type 'type' promoted to type 'type' can equal the given constant
#pragma warning(error: 4838) // conversion from 'type_1' to 'type_2' requires a narrowing conversion
#pragma warning(error: 4927) // illegal conversion; more than one user-defined conversion has been implicitly applied
#pragma warning(error: 4930) // 'prototype': prototyped function not called (was a variable definition intended?)

#pragma warning(disable: 4351) // new behavior: elements of array '...' will be default initialized (VC at least compliant to C++03) 

