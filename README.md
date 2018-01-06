Any type data switch statement for C/C++
========================================

There are many ways to implement that logic which you want to have by using
`switch`. For example map value:handler or use language switch with hash sum
values etc. But `switch` statement more readable and some times is more simple
to use.

The default switch implementation in this package is not quick. But it is
possible to enable quick map based implementation if you have new generation
C++11 or newer compiler. Little limitation exists in quick mode - the
`return` statement is not allowed.

There is no any dependency required to use this switch implementation.
Although the Qt project file exists here but it is only for tests.
You do not need Qt in your system for build and use this in project.

Features
--------

 * any type of data which support comparisions or checking equality
 * possibility to build cascading nested switch statemens.
 * possibility to break or fall through case statements
 * possibility to use non constatnt case expressions
 * possible to enable quick mode with tree searching


Comparison with language switch statement
-----------------------------------------

Logic differences:
  * linear search (tree search in quick mode, need C++11)
  * work with any type that support comparisions
  * allow nonconstant case expressions (quick mode does not support
    non constant expressions by default, but it is possible to enable)

Syntax differences:
  * uppercase keywords
  * need parentheses for `CASE` statement
  * semicolon ';' at end of statements is not allowed
  * colon ':' at `CASE` statement is not allowed
  * need one of `BREAK` or `FALL` keyword at end of `CASE` statement

Colon after `CASE` available, see in branch
[colon](https://github.com/oklas/switch/tree/colon).
Semicolon seems impossible for some impl, currently worked: `C` and `C++11`,
but not worked: `C++`. See in branch
[semicolon](https://github.com/oklas/switch/tree/semicolon).


Using
=====

Configure your build environment with adding path of this package `include`
dir to the list of directories to be searched for header files.
Or you can simple copy `include` folder files to your project tree.


Using with C++
--------------

Include switch in source file:

``` C++
#include <switch>
```

There is no colons or semicolons required (not allowed)
after any keywords of this switch.


Example:

``` C++
std::string val = "spring";

SWITCH(val)
  CASE("winter") return "cold"; BREAK
  CASE("summer") return "heat"; BREAK
  CASE("spring") FALL
  CASE("autumn") return "average"; BREAK
  DEFAULT return "not a season";
END

// the result will be: "average"
```


Cascaded nested switch example:

``` C++
std::string country = "Spain";
std::string city = "Granada";

SWITCH_STATIC( country )
  CASE( "Nicaragua" )
    SWITCH_STATIC( city )
      CASE("Granada") FALL
      CASE("Managua") return "-06:00"; BREAK
    END
    BREAK
  CASE( "Spain" )
    SWITCH_STATIC( city )
      CASE("Granada") FALL
      CASE("Madrid") return "+01:00"; BREAK
    END
END

// the result will be: "+01:00"
```


Complex object example:

``` C++
std::pair<char,int> val('a',1);

SWITCH(val)
  CASE( (std::make_pair('a',1)) ) return "first"; BREAK
  CASE( (std::make_pair('b',2)) ) return "second"; BREAK
END

// the result will be: "first"
```


Be carefull with commas. The implementation is macros based.
All expressins with commas in macroses must be in parentheses.
So where you need code like this:

``` C++
CASE( std::make_pair(first,second) )
```

write instead:

``` C++
CASE( ( std::make_pair(first,second) ) )
```


The quick C++ mode
------------------

It is possible to enable quick map based implementation with map tree search
alorithm if you have new generation c++11 or newer compiler. Little limitation
exists in quick mode - return statement is not allowed in case statement.

The quick mode does not support nonconstant expressions by default,
see `dynamic quick` below how to enable. Formally it is possible to
specify noncostant expressions and change them, but changed values will
be ignored and switch will work with values passed at first execution.

To enable quick mode define macro `SWITCH_QUICK` before include header:

``` C++
#define SWITCH_QUICK
#include <switch>
```

This macro will be ignored if you have not c++11 or newer compiler or that 
features is not enabled. The quick implementation will not be enabled for
that cases. The default (non quick) mode will be enabled instead.

The return statement is not allowed in quick mode.
Use helper variable instead:

``` C++
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

// the result will be: "average"
```


The dynamic quick C++ mode
--------------------------

The `dynamic quick` mode allow non constant `CASE` expressions.
It is not so quick as `quick` mode. To use `dynamic quick` mode 
simple use `SWITCH_DYNAMIC` instead of `SWITCH`. Another way is enable
`dynamic quick` by default. Non dynamic mode (`static quick`) mode
will be available by `SWITCH_STATIC` mode.
The `dynamic quick` mode build tree structure at every execution. The static
mode build tree structure once at first execution. 

To enable `dynamic quick` by default include `switch` header like this:


    #define SWITCH_QUICK_DYNAMIC
    #include <switch>


Using with C
------------

The C implementation support only C strings ( were type is `char*` )

Include switch in source file

``` C++
#include <switch.h>
```

One of your C source fil must define macro `SWITCH_IMPL` before
include `switch.h`  header file like this:

``` C++
#define SWITCH_IMPL
#include <switch.h>
```

The switch is enough simple to make library. So this is not library.
But the C implementation need to add instance of code. Implementation
must be included only once to avoid conflict of external symbols.


Example:

``` C++
const char[] val = "white";

SWITCH(val)
  CASE("black") return 0; BREAK
  CASE("white") return 1; BREAK
  DEFAULT exit(1);
END

// the result will be: 1
```


License
-------

Switch is available as open source under the terms of the *BSD License*

Copyright
---------

Copyright (c) 2006-present Serguei Okladnikov <oklaspec@gmail.com>
