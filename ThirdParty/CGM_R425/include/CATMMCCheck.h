#ifndef CATMMCCHECK_H
#define CATMMCCHECK_H

#include "CATSYPCheck.h"
#include "CATMMCReturnCode.h"
//@MMNJNinf @QDesc: Macro for HRESULT and CATMmRC
//@MMNJNinf @FDesc: Macro for HRESULT and CATMmRC.

#define CHECK_HR_RETH(iHRESULT)               do { HRESULT hrRetVal=iHRESULT; if(FAILED(hrRetVal)) { Check_TRUE_Failed__(#iHRESULT, __FILE__, __LINE__, NULL); return hrRetVal; } } while(0)
#define CHECK_HR_RETC(iHRESULT)               do { HRESULT hrRetVal=iHRESULT; if(FAILED(hrRetVal)) { Check_TRUE_Failed__(#iHRESULT, __FILE__, __LINE__, NULL); return CATMmRC(hrRetVal); } } while(0)
#define CHECK_HR_RETV(iHRESULT,iVal)          do { HRESULT hrRetVal=iHRESULT; if(FAILED(hrRetVal)) { Check_TRUE_Failed__(#iHRESULT, __FILE__, __LINE__, NULL); return iVal; } } while(0)
#define CHECK_HR_RET(iHRESULT)                do { HRESULT hrRetVal=iHRESULT; if(FAILED(hrRetVal)) { Check_TRUE_Failed__(#iHRESULT, __FILE__, __LINE__, NULL); return; } } while(0)
#define CHECK_HR(iHRESULT)                    do { HRESULT hrRetVal=iHRESULT; if(FAILED(hrRetVal)) { Check_TRUE_Failed__(#iHRESULT, __FILE__, __LINE__, NULL); } } while(0)

#define CHECK_RC_RETC(iMmRC)                  do { CATMmRC rc(iMmRC); if(rc.IsError()) { Check_TRUE_Failed__(#iMmRC, __FILE__, __LINE__, NULL); return rc; } } while(0)
#define CHECK_RC_RETV(iMmRC,iVal)             do { CATMmRC rc(iMmRC); if(rc.IsError()) { Check_TRUE_Failed__(#iMmRC, __FILE__, __LINE__, NULL); return iVal; } } while(0)
#define CHECK_RC_RET(iMmRC)                   do { CATMmRC rc(iMmRC); if(rc.IsError()) { Check_TRUE_Failed__(#iMmRC, __FILE__, __LINE__, NULL); return; } } while(0)
#define CHECK_RC(iMmRC)                       do { CATMmRC rc(iMmRC); if(rc.IsError()) { Check_TRUE_Failed__(#iMmRC, __FILE__, __LINE__, NULL); } } while(0)

#endif
