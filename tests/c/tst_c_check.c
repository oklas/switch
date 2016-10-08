//! @file
//! @author Serguei Okladnikov oklaspec@gmail.com
//! @date 2016.09.28

#include <stdio.h>

#define SWITCH_IMPL
#include "switch.h"

char g_result[512];

const char* check( const char* top, const char* sub, const char* val ) {
  SWITCH(top)
    CASE("SAMEFALL")
      FALL
    CASE("SAME")
      return val;
      BREAK
    CASE("SUBFALL")
      FALL
    CASE("SUB")
      SWITCH(sub)
      CASE("SAMEFALL")
        FALL
      CASE("SAME")
        sprintf(g_result,"SUB%s",val);
        return g_result;
        BREAK
      CASE("DOUBLE")
        sprintf(g_result,"SUB%s%s",val,val);
        return g_result;
        BREAK
      CASE("DEFAULTFALL")
        FALL
      DEFAULT
        sprintf(g_result,"SUBdefault");
        return g_result;
      END
    BREAK
    CASE("DOUBLE")
      sprintf(g_result,"%s%s",val,val);
      return g_result;
      BREAK
    CASE("DEFAULTFALL")
      FALL
    DEFAULT
      return "default";
  END
  return "UNREACHEABLE";
}

