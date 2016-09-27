//! @file
//! @author Serguei Okladnikov
//! @date 2006.07.04


#ifndef __SWITCH__H__
#define __SWITCH__H__

#include <string.h>

#ifdef __cplusplus

template<class T>
struct SWITCH__D_A_T_A {
  bool bEnterFall;
  bool bEnterDefault;
  bool bDone;
  T strPtrThrSw;
  SWITCH__D_A_T_A( T arg ) : strPtrThrSw(arg) {}
  inline bool transition(bool fall, const T& cnst, bool ndeflt) {
    if(bDone)
       return false;

    if(fall && bEnterFall)
      return 1;

    if(!fall && bEnterFall) {
      bDone = 1;
      return 0;
    }

    if(ndeflt) {
      bEnterFall = strPtrThrSw == cnst;
      if(bEnterFall) bEnterDefault=false;
    }

    return ndeflt ?
      bEnterFall :
      bEnterDefault;
  }
};


#if __cpluplus > 199711
#define SWITCH(arg) if(1){SWITCH__D_A_T_A< typeof(arg) > switch__d_a_t_a(arg); \
 switch__d_a_t_a.bEnterDefault=true;switch__d_a_t_a.bEnterFall=false; \
 switch__d_a_t_a.bDone=false;if(switch__d_a_t_a.transition(false,
#else
#define SWITCH(arg) if(1){SWITCH__D_A_T_A< decltype(arg) > switch__d_a_t_a(arg); \
 switch__d_a_t_a.bEnterDefault=true;switch__d_a_t_a.bEnterFall=false; \
 switch__d_a_t_a.bDone=false;if(switch__d_a_t_a.transition(false,
#endif

#define CASE(cnst)  cnst,true)){

#define BREAK       switch__d_a_t_a.bDone=true; \
                    } if(switch__d_a_t_a.transition(false,

#define FALL        } if(switch__d_a_t_a.transition(true,

#define DEFAULT     switch__d_a_t_a.strPtrThrSw,false)){

#define END         }};


#else // not defined __cplusplus

typedef struct tagSWITCH__D_A_T_A
  {
  int bEnterFall : 1;
  int bEnterDefault : 1;
  int bDone : 1;
  const char* strPtrThrSw;
  } SWITCH__D_A_T_A;

  int SWITCH__D_A_T_A_transition(
    SWITCH__D_A_T_A* data, int fall, const char*cnst, int ndeflt);

#define SWITCH(arg) if(1){SWITCH__D_A_T_A switch__d_a_t_a; \
 switch__d_a_t_a.strPtrThrSw=arg; \
 switch__d_a_t_a.bEnterDefault=1; \
 switch__d_a_t_a.bEnterFall=0; \
 switch__d_a_t_a.bDone=0; \
 if(SWITCH__D_A_T_A_transition(&switch__d_a_t_a, 0,

#define CASE(cnst)  cnst,1)){

#define BREAK       switch__d_a_t_a.bDone=1; \
                    } if(SWITCH__D_A_T_A_transition(&switch__d_a_t_a, 0,

#define FALL        } if(SWITCH__D_A_T_A_transition(&switch__d_a_t_a, 1,

#define DEFAULT     switch__d_a_t_a.strPtrThrSw,0)){

#define END         }};


#endif // defined __cplusplus / not defined __cplusplus

#endif // __SWITCH__H__