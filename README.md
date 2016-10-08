Any type data switch statement for C/C++
========================================

There are many ways to implement that logic which you want to have by using
`switch`. For example map value:handler or use laguage switch with hash sum
values etc. But `switch` statement some times is more simple to implement
and more readable.

The default switch implementation in this package is not quick. But it is
possible to enable quick map based implementaion if you have new generation
c++11 or newer compiler. Little limitation exists in quick mode - the
`return` statement is not allowed.

There is no any dependency required to use this switch implementation.
Although the Qt project file exists here but it is only for tests.
You do not need Qt in your system for build and use this in project.


Using
-----

Configure your build environment with adding path of this package `include`
dir to the list of directories to be searched for header files.
Or you can simple copy `include` folder files to your project tree.


Using with C++
--------------

Include switch in source file:

    #include <switch>

There is no colons or semicolons required (not allowed)
after any keywords of this switch.

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


Quick C++ mode
--------------

It is possible to enable quick map based implementaion with map
tree search alorithm if you have new generation c++11 or newer
compiler. Little limitation exists in quick mode - return statement
is not allowed in case statement.

To enable quick mode define macro SWITCH_QUICK before include header:

    #define SWITCH_QUICK
    #include <switch>

This macro will be ignored if you have not c++11 or newer compiler
or that fatures is not enabled. The quick implementation will
not be enabled for that cases. The default mode will be enabled instead.

The return statement is not allowed in quick mode.
Use helper variable instead:

    std::string val = "spring";
    std::string result;

    SWITCH(val)
      CASE("winter") result = "cold"; BREAK
      CASE("summer") result = "heat"; BREAK
      CASE("spring") FALL
      CASE("autumn") result = "average"; BREAK
      DEFAULT result = "not a season";
    END

    return result;



Using with C
------------

The C implementation support only C strings ( were type is `char*` )

Include switch in source file

    #include <switch.h>

One of your C source fil must define macro `SWITCH_IMPL` before
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
  * linear search (tree search in quick mode)
  * work with any type that support comparisions
  * allow nonconstant case expressions

Syntax differences:
  * uppercase keywords
  * need parentheses for `CASE` statement
  * semicolon ';' at end of statements is not allowed
  * colon ':' at `CASE` statement is not allowed
  * need one of `BREAK` or `FALL` keyword at end of `CASE` statement


License
-------

Switch is available as open source under the terms of the *BSD License*

Copyright
---------

Copyright (c) 2006-present Serguei Okladnikov <oklaspec@gmail.com>
