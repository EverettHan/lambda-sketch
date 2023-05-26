/* -*-c++-*- */
/**
* @COPYRIGHT DASSAULT SYSTEMES 2009
*/
#ifndef CATCGMDefType_H 
#define CATCGMDefType_H 
//=============================================================================
// DESCRIPTION : Symbolic Name On demand  
//=============================================================================
// Feb. 09	Symbolic Name On demand , 
//             (volatile structure Helpers for  Journal/CellTracking)
//          Associativity/equivalency management through operation
//=============================================================================
#include "CGMV5Interop.h"
#include "CATCGMHashTable.h"
#include "CATCGMAttributeDef.h"
#include "CATUnicodeString.h"
#include "CATThrowForNullPointer.h"
#include "CATBoolean.h"
 

class ExportedByCGMV5Interop CATCGMDefType
{
public :

  CATCGMDefType(CATCGMAttributeDef *  iDefinition, short itp, CATBoolean iCore = FALSE);


  /** LifeCycle protection  */
  INLINE unsigned short IncreaseCounter();

  /** LifeCycle protection */
  INLINE unsigned short DecreaseCounter();


  /** HashKey */
  INLINE unsigned int  HashKey();

 /** CompareData   0:equal 1:distinct */
  INLINE int  Compare(CATCGMDefType* ipNickName);

  CATCGMNewClassArrayDeclare;


  const char *GetValue();



  /**
  * For Stack variable
  */
  ~CATCGMDefType();


protected  :


  unsigned int                 _Hashkey;
  unsigned int                 _Counter;

  CATCGMAttributeDef        *  _Definition;
  short                        _itp;
  CATBoolean                   _Core;

  CATUnicodeString  _AttrType; 
  char             *_AttrTypeComputed; 

private :
  //------------------------------------------------------------------------
  // Forbidden (Declared, Not Defined) : Constructor by copy  et   operator =
  //------------------------------------------------------------------------
  CATCGMDefType(const CATCGMDefType &iCopy);
  CATCGMDefType& operator=(const CATCGMDefType &iCopy);
};


unsigned short CATCGMDefType::IncreaseCounter()
{ return ++_Counter; }

unsigned short CATCGMDefType::DecreaseCounter()
{ unsigned short rc = --_Counter; if ( 0 == rc ) delete this; return rc; }

INLINE unsigned int  CATCGMDefType::HashKey()
{ return _Hashkey; }


/** CompareData   0:equal 1:distinct */
INLINE int  CATCGMDefType::Compare(CATCGMDefType* ipNickName) 
{
  if ( ! ipNickName ) CATThrowForNullPointer();  

  if ( this        == ipNickName              ) return 0;
  if ( _Hashkey    != ipNickName->_Hashkey    ) return +1;
  if ( _Definition != ipNickName->_Definition ) return +1;
  if ( _itp        != ipNickName->_itp        ) return +1;
  if ( _Core       != ipNickName->_Core       ) return +1;
  return 0;
}



/**
*  Dictionnary of CATCGMDefType.
*/

class   ExportedByCGMV5Interop  CATCGMDefTypes  : protected  CATCGMHashTable
{
public:
  CATCGMDefTypes (int iEstimatedSize = 0);
  ~CATCGMDefTypes();
  CATCGMNewClassArrayDeclare;

  int             Insert(CATCGMDefType* ipCGMObject);
  CATCGMDefType* Locate(CATCGMDefType* ipCGMObject) const;

  int             Remove(CATCGMDefType* ipCGMObject);
  CATCGMDefType* Next(int& ioNumBucket, int& ioPos) const;

  int             Size() const;
  CATCGMDefType* Get(int iPos) const;
};

#endif
