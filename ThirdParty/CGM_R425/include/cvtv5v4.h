/**
* @level Private 
* @usage U1
*/
/* cvtv5v4.h : COPYRIGHT DASSAULT SYSTEMES 1997 */
#ifndef cvtv5v4_h
#define cvtv5v4_h

//
// Includes
#include "CATAIXServices.h"
#include "CATV4CSTypes.h"


ExportedByCATAIXServices void cvtv5v4( const integer4   dest_Codepage, \
				       const integer4   dest_Real,     \
				       const integer4   dest_LBEndian, \
				       integer4       & actconv,       \
				       integer4       & ier );

#endif
