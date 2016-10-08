//! @file
//! @author Serguei Okladnikov oklaspec@gmail.com
//! @date 2016.09.28

#include <stdio.h>

#include "switch.h"

char g_result[512];

const char* check_multiple_external_link( const char* top, const char* sub, const char* val ) {
  SWITCH(top)
    CASE("SAMEFALL") FALL
    CASE("SAME") return val;
  END
  return "default";
}

