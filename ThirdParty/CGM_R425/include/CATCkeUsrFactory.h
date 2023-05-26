/**
 * @level Protected
 * @usage U1
 */

// Copyright Dassault Systemes 2000
#ifndef CATCkeUsrFactory_h
#define CATCkeUsrFactory_h
//////////////////////////////////////////////////////////////////////////
//
// used to create instance from simple c++ types
//
//   ex : CATCKEUsrFactory->Bind (3) : creates an integer instance
//   note that define with uppercase CATCKE is used to access 
//   the current factory
//
//////////////////////////////////////////////////////////////////////////

// module
#include "CATLifDictionary.h"
#include "CATIAV5Level.h"
#include "CATIVisitor.h"

#include "CATEventSubscriber.h"

#include "CATICkeRelationForwards.h"
#include "CATICkeInst.h"
#include "CATICkeType.h"
#include "CATICkeMKSUnit.h"
#include "CATIParmPublisher.h"
#include "CATIList.h"
#include "CATIType.h"
#include "CATICkeFunction.h"


class CATPathElement;
class CATTime;

// current factory
#define CATCKEUsrFactory (CATCkeUsrFactory::Current())

class ExportedByCATLifDictionary CATCkeUsrFactory : public CATEventSubscriber
{

public :

  // from its type
  CATICkeInst_var Bind(const CATICkeType_var &t) const;   // default

  // basic types
  CATICkeInst_var Bind(const int) const;         // entier
  CATICkeInst_var Bind(const double)    const;   // penser a caster en double
  CATICkeInst_var Bind(const CATUnicodeString &)  const;  // string
  CATICkeInst_var Bind(const CATCke::Boolean &b) const;   // booleen
  CATICkeInst_var Bind(const CATTime& t) const;

  // Dimensions
  CATICkeInst_var Bind (const CATICkeType_var &,const double)    const; // penser a caster en double 

  // creation of an enumere
  CATICkeInst_var Bind (const CATICkeType_var &,const CATUnicodeString &)    const;
  CATICkeInst_var Bind (const CATICkeType_var&,const int)    const;

  // current factory
  static CATCkeUsrFactory *Current();

  // creation of a volatile parameter
  CATICkeParm_var CreateVolatileParm (const CATUnicodeString &name,const CATICkeInst_var  &i,const CATCke::Boolean  fixed = 0);
  // copy an instance
  CATICkeInst_var CopyValue   (const CATICkeInst_var &i) const;

  // creation of a Unknown
  CATICkeInst_var Bind (const CATBaseUnknown_var&)    const;

#ifdef _WINDOWS_SOURCE
#define CATCkeUsrFactory_deprecated __declspec(deprecated("error, Use CATICkeParmFactory instead of CATCkeUsrFactory"))
#else
#define CATCkeUsrFactory_deprecated
#endif
  CATCkeUsrFactory_deprecated CATICkeParm_var CreateObjectReference(const CATBaseUnknown_var &f);

  CATCkeUsrFactory_deprecated CATICkeParm_var CreateDimension(const CATICkeMagnitude_var &type,const CATUnicodeString &name,const double value);

  CATCkeUsrFactory_deprecated CATIParmManipulator_var  CreateParmManipulator();

  CATCkeUsrFactory_deprecated CATICkeParm_var CreateLength(const CATUnicodeString &name,const double value);

  // constructeur 
  CATCkeUsrFactory ();
  ~CATCkeUsrFactory();

private :  
  CATDeclareClass;
};


#endif


