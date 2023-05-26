/**
* @level Protected 
* @usage U1
*/
/* cvtoolw.h : COPYRIGHT DASSAULT SYSTEMES 1997 */
#ifndef cvtoolw_h
#define cvtoolw_h

//
// Includes
#include "CATAIXServices.h"
#include "CATV4CSTypes.h"


ExportedByCATAIXServices void cvtoolw( const integer4   src_Codepage, \
				       const integer4   src_Real,     \
				       const integer4   src_Integer,  \
				       integer4       & actconv,      \
				       integer4       & ier );

#endif
