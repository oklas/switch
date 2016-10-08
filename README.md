Any type data switch statement for C/C++
========================================

There are many ways to implement that logic which you want to have by using
`switch`. For example map value:handler or use language switch with hash sum
values etc. But `switch` statement more readable and some times is more simple
to use.

The default switch implementation in this package is not quick. But it is
possible to enable quick map based implementation if you have new generation
C++11 or newer compiler. Little limitation exists in quick mode - the
`return` statement is not allowed. The static implementation available for
more quickness.

There is no any dependency required to use this switch implementation.
Although the Qt project file exists here but it is only for tests.
You do not need Qt in your system for build and use this in project.


Comparision with language switch statement
------------------------------------------

Logic differences:
  * linear search (tree search in quick mode, need C++11)
  * work with any type that support comparisions
  * allow nonconstant case expressions (except static mode)

Syntax differences:
  * uppercase keywords
  * need parentheses for `CASE` statement
  * semicolon ';' at end of statements is not allowed
  * colon ':' at `CASE` statement is not allowed
  * need one of `BREAK` or `FALL` keyword at end of `CASE` statement


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

It is possible to enable quick map based implementation with map tree search
alorithm if you have new generation c++11 or newer compiler. Little limitation
exists in quick mode - return statement is not allowed in case statement.

To enable quick mode define macro SWITCH_QUICK before include header:

    #define SWITCH_QUICK
    #include <switch>

This macro will be ignored if you have not c++11 or newer compiler or that 
fatures is not enabled. The quick implementation will not be enabled for
that cases. The default mode will be enabled instead.

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


The staic quick C++ mode
--------------------

The `static` mode is most quick and at the same time most limited and
difficult to use. The `static` implementation is defined only at
quick mode. To use static mode simple use SWITCH_STATIC instead of
SWITCH.

The quick mode build tree structure at every execution. The static mode
build tree structure once at first execution. The body of case statements
is lambda functions which created and capture variables only at first
execution. Non static local variables captured at first execution likely
will be garbage or will be at inaccessible memory at next executions.
So reading or writing at any visible local variables is forbidden at general.
But it is possible to use if you understand what you do, for example it is
possible to use smart pointers or suchlike.
Static variables simple cases helpfull, at code where threads does not used,
otherwise need to use synchronization.

On the whole limitations:

  * using all visible nonstatic local variables generally forbidden
  * unchangable case expressions
  * return statements not allowed

Using quick static switch implementation:

    std::string time_zone( std::string country, std::string arg_city ) {

      // non static variables forbidden for persistent capture
      static std::string city = arg_city;
      static std::string result;

      SWITCH_STATIC( country )
        CASE( "Nicaragua" )
          SWITCH_STATIC( city )
            CASE("Granada") FALL
            CASE("Managua") result = "-06:00"; BREAK
          END
          BREAK
        CASE( "Spain" )
          SWITCH_STATIC( city )
            CASE("Granada") FALL
            CASE("Madrid") result = "+01:00"; BREAK
          END
      END

      return result;

    }


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


License
-------

Switch is available as open source under the terms of the *BSD License*

Copyright
---------

Copyright (c) 2006-present Serguei Okladnikov <oklaspec@gmail.com>
