#ifndef  CATCmdDelayReceives_H
#define  CATCmdDelayReceives_H

#include "JS0FM.h"
#define CATSysFM_SYNC     1
#define CATSysFM_ASYNC    0
ExportedByJS0FM int CATCmdDelayReceives() ;
ExportedByJS0FM int CATCmdCeaseDelayingReceives() ;
ExportedByJS0FM int CATCmdGetSendSynchronicityStatus() ;
#endif
