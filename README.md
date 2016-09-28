Any data type switch statement for C/C++
========================================

There are many more effective ways to implement that logic
which you want to have by using switch. For example map
value:handler or use laguage switch with hash sum values etc.
The purpose to use this switch statement is not performance
but code visibility. Do not use this switch implementation
if you can use more effective solution.

There is no any dependency required to use this switch implementation.
Although the Qt project file exists here but it is only for tests.
You do not need Qt in your system for build and use this in project.


Using with C++
--------------

Configure your build environment with adding path of this package `include`
dir to the list of directories to be searched for header files.

    #include <switch>

There is no semicolons required after any keywords of this switch.

Example:

    std::string val = "spring";

    SWITCH(val)
      CASE("winter") return "cold"; BREAK
      CASE("summer") return "heat"; BREAK
      CASE("spring") FALL
      CASE("autumn") return "average"; BREAK
      DEFAULT return "not a season";
    END

    // the result will be: "average"

Complex object example:

    std::pair<char,int> val('a',1);

    SWITCH(val)
      CASE( (std::make_pair('a',1)) ) return "first"; BREAK
      CASE( (std::make_pair('b',2)) ) return "second"; BREAK
    END

    // the result will be: "first"


Be carefull with commas. The implementation is macros based.
All expressins with commas in macroses must be in parentheses.
So where you need code like this:

    CASE( std::make_pair(first,second) )

write instead:

    CASE( ( std::make_pair(first,second) ) )


Using with C
------------

The C implementation support only C strings ( were type is char* )

Include switch in source file

    #include <switch.h>

One of your C source fil must define macro `SWITCH_IMPL` befire
include `switch.h`  header file like this:

    #define SWITCH_IMPL
    #include <switch.h>

The switch is enough simple to make library. So this is not library.
But the C implementation need to add instance of code. Implementation
must be included only once to avoid conflict of external symbols.


Example:

    const char[] val = "white";

    SWITCH(val)
      CASE("black") return 0; BREAK
      CASE("white") return 1; BREAK
      DEFAULT exit(1);
    END

    // the result will be: 1


Comparision with language switch statement
------------------------------------------

Logic differences:
  * linear search
  * work with any type that support comparisions
  * allow nonconstant case expressions
  * currently possible to use lang `break` for break upper including loop

Syntax differences:
  * uppercase keywords
  * need parentheses for `CASE` statement
  * semicolon at end statement is not allowed
  * colon ':' at `CASE` statement not allowed
  * need one of `BREAK` or `FALL` keyword at end of `CASE` statement


License
-------

Swtich is available as open source under the terms of the *BSD License*

Copyright
---------

Copyright (c) 2006-present Serguei Okladnikov <oklaspec@gmail.com>
