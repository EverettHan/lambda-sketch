/**
 * @level Private
 * @usage U1
 */
#ifndef CATListOfCATVVSUrl_H
#define CATListOfCATVVSUrl_H

class CATVVSUrl ;  



#include "CATLISTP_Clean.h"

#define CATLISTP_Append
#define CATLISTP_AppendList
#define CATLISTP_Locate
#define CATLISTP_RemoveValue
#define CATLISTP_RemoveAll

#include "CATLISTP_Declare.h"

#include "CATVVSNetBase.h"

// exportation du Block
#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByVVSNetBase


CATLISTP_DECLARE(CATVVSUrl)

typedef CATLISTP(CATVVSUrl) CATListOfCATVVSUrl; 

#undef CATCOLLEC_ExportedBy

#endif
