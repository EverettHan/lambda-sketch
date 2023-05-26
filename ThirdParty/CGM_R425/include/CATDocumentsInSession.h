//
#ifndef CATDocumentsInSession_h
#define CATDocumentsInSession_h

// COPYRIGHT DASSAULT SYSTEMES 1999

/**
  * @level Protected
  * @usage U1
  */

/**
 * @collection CATLISTP(CATDocument)
 * Collection class for pointers to CATDocument.
 * Only the following methods of pointer collection classes are available:
 * <ul>
 * <li><tt>ReSize</tt></li>
 * <li><tt>Append</tt></li>
 * <li><tt>InsertAt</tt></li>
 * <li><tt>Locate</tt></li>
 * <li><tt>RemovePosition</tt></li>
 * <li><tt>RemoveAll</tt></li>
 * <li><tt>RemoveValue</tt></li>
 * </ul>
 * Refer to the articles dealing with collections in the encyclopedia.
 */

class CATDocument ;


#include "CATLISTP_Clean.h"

#define CATLISTP_ReSize
#define CATLISTP_Append
#define CATLISTP_AppendList
#define CATLISTP_InsertAt
#define CATLISTP_Locate
#define CATLISTP_RemovePosition
#define CATLISTP_RemoveAll
#define CATLISTP_RemoveValue
#define CATLISTP_RemoveDuplicates

#include  "AC0XXLNK.h"

#include "CATLISTP_Declare.h"

#undef  CATCOLLEC_ExportedBy
#define CATCOLLEC_ExportedBy    ExportedByAC0XXLNK

CATLISTP_DECLARE(CATDocument)

// MZC

#include  <CATHTAB_Clean.h>

// require needed functions
//#include  <CATHTAB_AllFunct.h>
#define  CATHTAB_KeyLocate
#define  CATHTAB_KeyLocatePosition
#define  CATHTAB_Insert
#define  CATHTAB_Locate
#define  CATHTAB_Remove
#define  CATHTAB_Dimension
#define  CATHTAB_Collisions
#define  CATHTAB_Unused
#define  CATHTAB_Next //returns the next to the one having a key <->item iFrom
                               /********/                          /**********/
#define  CATHTAB_NextPosition // to use the Next function with 2 parameters 
// get macros
#include  <CATHTAB_Declare.h>


#undef	CATCOLLEC_ExportedBy
#define	CATCOLLEC_ExportedBy	ExportedByAC0XXLNK

class CATDocument ;
class CATUuid;

CATHTAB_DECLARE( CATDocument )

class ExportedByAC0XXLNK CATDocumentsInSession: public CATHTAB(CATDocument)
{
public:
	CATDocumentsInSession(int);
	CATDocument *Locate(const CATUnicodeString &) const;
	CATDocument *Locate(const CATUnicodeString &, const CATUuid &) const;
  int Insert(CATDocument* );
  
	static unsigned int CalcHKey(const CATUnicodeString &);
};


#endif
