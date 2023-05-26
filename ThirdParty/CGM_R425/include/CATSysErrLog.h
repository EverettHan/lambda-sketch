#ifndef  CATSysErrLog_H
#define  CATSysErrLog_H
#include "CATSysErrorLog.h"
#include "CATIStatsThematics.h"
 
enum CATSysErrorLogSeverityEx { CATSysErrorLogSeverityExAbend=0,
                                CATSysErrorLogSeverityExError=1,
                                CATSysErrorLogSeverityExWarning=2,
                                CATSysErrorLogSeverityExUserInfo=3
                              };
enum CATSysErrLogPopUpKind     { CATSysErrLogPopUpError  = 0, 
                                    CATSysErrLogPopUpWarning = 1,  
                                    CATSysErrLogPopUpInfo  = 2,  
                                    CATSysErrLogPopUpNone  = 3  
                                   };

ExportedByJS0ERROR HRESULT CATSysErrLogSetCurrentWbk( CATUnicodeString *iWkbName, CATUnicodeString *iWkbNLS , int iBegin=-1);

ExportedByJS0ERROR HRESULT CATSysErrLogSetCurrentCmd( const char *iCmdName, CATUnicodeString * iCmdNLS ,int iBegin=-1);

ExportedByJS0ERROR HRESULT CATSysErrLogExBegin( const char *iErrName, 
CATSysErrorLogSeverityEx iSeverity, CATUnicodeString *iParameterNLSMsg, CATUnicodeString *iNonNLSMsg ,CATStatsEventId *oEventId , int iMsgFromTheUser=0);
ExportedByJS0ERROR HRESULT CATSysErrLogExAddField( CATStatsEventId iId,const char *iEventName,  const char *iValue);
ExportedByJS0ERROR HRESULT CATSysErrLogExEnd(CATStatsEventId iId);
ExportedByJS0ERROR HRESULT CATSysErrLogExPopUpWarning(  CATUnicodeString *iDialogMsg, enum CATSysErrLogPopUpKind iKind);

#endif
