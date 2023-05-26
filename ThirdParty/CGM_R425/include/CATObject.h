/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2000

#ifndef CATObject_h
#define CATObject_h

/**
* @level Protected
* @usage U1
*/

#include <stdlib.h>
#include "CATImplementationAdapter.h"
#include "CATOMY.h"


class CATObjectMetaType ;
class CATMetaClass ;
class CATObject ;

//================================================================
// List Declaration
//================================================================
#include "CATLISTP_Clean.h"
/** @nodoc */
#define CATLISTP_ReSize
/** @nodoc */
#define CATLISTP_Append
/** @nodoc */
#define CATLISTP_Locate
/** @nodoc */
#define CATLISTP_RemoveValue
/** @nodoc */
#define CATLISTP_RemovePosition
#include "CATLISTP_Declare.h"
#undef  CATCOLLEC_ExportedBy
/** @nodoc */
#define CATCOLLEC_ExportedBy    ExportedByCATOMY
/** @nodoc */
CATLISTP_DECLARE(CATObject)
//================================================================

class CATObjectMetaType;

/**
 * Late type class.
 * <br> This class can't be instanciated
*/

class ExportedByCATOMY CATObject : public CATImplementationAdapter
{
public:
  //  Constructors / Destructors
  //----------------------------------------------
/** @nodoc */
  CATObject (CATClassId type, CATClassId superType=0) ;
  virtual ~CATObject () ;

/** @nodoc */
  static const CATLISTP(CATObject)&    Extent (CATClassId type) ;
/** @nodoc */
  static void DefType (CATClassId type, CATClassId superType) ;

/** @nodoc */
  friend class   CATObjectMetaType;
  
protected:
  CATObject (const CATObject& from) ;
  CATObject& operator= (const CATObject& from) ;

  //   Data
  //----------------------------------------------
private:
  CATObjectMetaType*	               dynamic_type_ ;
  
  CATDeclareLateTyping ;

public :
  // Differences between CATDeclareLateTyping and CATDeclareKindOf
  //----------------------------------------------
/** @nodoc */
  virtual CATMetaClass * __stdcall GetMetaObject() const;
/** @nodoc */
  virtual CATClassId    IsA() const;			
/** @nodoc */
  virtual int           IsAKindOf(CATClassId) const;		
};

#endif






