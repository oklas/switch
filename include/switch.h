#include <string.h>

#ifdef _______cplusplus


#else // __cplusplus

struct SWITCH__D_A_T_A
  {
  bool bEnterFall;
  bool bEnterDefault;
  const char* strPtrThrSw;
  inline bool cmp(const char*cnst, bool ndeflt)
    {
      if(ndeflt)
        {
          bEnterFall=!strcmp(strPtrThrSw,cnst);
          if(bEnterFall) bEnterDefault=false;
        }
      return ndeflt ? bEnterFall:
             bEnterDefault;
    }
  inline bool fall(const char* cnst, bool ndeflt)
    {
      if(bEnterFall)
        {
          return true;
        }
      else
        {
          if(ndeflt)
            {
	          bEnterFall=!strcmp(strPtrThrSw,cnst);
              if(bEnterFall) bEnterDefault=false;
              return bEnterFall;
            }
          else
            return bEnterDefault;
        }
	}
  };


#define SWITCH(arg) do{SWITCH__D_A_T_A switch__d_a_t_a; \
 switch__d_a_t_a.strPtrThrSw=arg;switch__d_a_t_a.bEnterDefault=true;if(switch__d_a_t_a.cmp(

#define CASE(cnst)  cnst,true)){

#define BREAK       switch__d_a_t_a.bEnterFall=false;}else if(switch__d_a_t_a.cmp(

#define FALL        }if(switch__d_a_t_a.fall(

#define DEFAULT     NULL,false)){

#define END         }}while(0);


#endif // __cplusplus
