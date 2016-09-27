//! @file
//! @author Serguei Okladnikov
//! @date 2009.04.29

// this file need only for C using
// it NOT needed for C++ using object switch

#include "switch.h"

int SWITCH__D_A_T_A_transition(
  SWITCH__D_A_T_A* data, int fall, const char*cnst, int ndeflt) {

  if(data->bDone)
    return 0;

  if(fall && data->bEnterFall)
    return 1;

  if(!fall && data->bEnterFall) {
    data->bDone = 1;
    return 0;
  }

  if(ndeflt) {
    data->bEnterFall=!strcmp(data->strPtrThrSw,cnst);
    if(data->bEnterFall) data->bEnterDefault=0;
  }

  return ndeflt ?
    data->bEnterFall :
    data->bEnterDefault;
}
