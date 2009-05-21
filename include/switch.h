#include <string.h>

#ifdef __cplusplus

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

#define SWITCH(arg) if(1){SWITCH__D_A_T_A switch__d_a_t_a; \
 switch__d_a_t_a.strPtrThrSw=arg;switch__d_a_t_a.bEnterDefault=true;if(switch__d_a_t_a.cmp(

#define CASE(cnst)  cnst,true)){

#define BREAK       switch__d_a_t_a.bEnterFall=false;}else if(switch__d_a_t_a.cmp(

#define FALL        }if(switch__d_a_t_a.fall(

#define DEFAULT     NULL,false)){

#define END         }};

#else // not defined __cplusplus

typedef struct tagSWITCH__D_A_T_A
  {
  int bEnterFall;
  int bEnterDefault;
  const char* strPtrThrSw;
  } SWITCH__D_A_T_A;

  int SWITCH__D_A_T_A_cmp(SWITCH__D_A_T_A* data, const char*cnst, int ndeflt);
  int SWITCH__D_A_T_A_fall(SWITCH__D_A_T_A* data, const char* cnst, int ndeflt);

#define SWITCH(arg) if(1){SWITCH__D_A_T_A switch__d_a_t_a; \
 switch__d_a_t_a.strPtrThrSw=arg; \
 switch__d_a_t_a.bEnterDefault=1; \
 if(SWITCH__D_A_T_A_cmp(&switch__d_a_t_a,

#define CASE(cnst)  cnst,1)){

#define BREAK       switch__d_a_t_a.bEnterFall=0;}else if(SWITCH__D_A_T_A_cmp(&switch__d_a_t_a,

#define FALL        }if(SWITCH__D_A_T_A_fall(&switch__d_a_t_a,

#define DEFAULT     NULL,0)){

#define END         }};


#endif // defined __cplusplus / not defined __cplusplus
