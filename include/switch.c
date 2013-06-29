// this file need only for C using
// it NOT needed for C++ using object switch

#include "switch.h"

  int SWITCH__D_A_T_A_cmp(SWITCH__D_A_T_A* data, const char*cnst, int ndeflt)
    {
      if(ndeflt)
        {
          data->bEnterFall=!strcmp(data->strPtrThrSw,cnst);
          if(data->bEnterFall) data->bEnterDefault=0;
        }
      return ndeflt ?
			data->bEnterFall :
			data->bEnterDefault;
    }
  int SWITCH__D_A_T_A_fall(SWITCH__D_A_T_A* data, const char* cnst, int ndeflt)
    {
      if(data->bEnterFall)
        {
          return 1;
        }
      else
        {
          if(ndeflt)
            {
	          data->bEnterFall=!strcmp(data->strPtrThrSw,cnst);
              if(data->bEnterFall) data->bEnterDefault=0;
              return data->bEnterFall;
            }
          else
            return data->bEnterDefault;
        }
    }