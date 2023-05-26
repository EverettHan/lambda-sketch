
/**
* @level Private
* @usage U1
*/
// Copyright Dassault Systemes 2000
#ifndef CATCkeEquationExc_h
#define CATCkeEquationExc_h
//////////////////////////////////////////////////////////////////////////
//
//
//	Cke Engineering Equations Interfaces
// 	declaration of exceptions
//
//
//////////////////////////////////////////////////////////////////////////

#include "CATLifDictionary.h"
#include "CATCkeEquExc.h"

// ++IK8: Handle migration: CAT_DECLARE_ERROR_CLASS(thisClass) => CAT_DECLARE_ERR_CLASS(thisClass,baseClass)
#if defined(CAT_DECLARE_ERR_CLASS)
#define CKE_DECLARE_ERROR_CLASS(thisClass,baseClass)    CAT_DECLARE_ERR_CLASS(thisClass,baseClass)
#else
#define CKE_DECLARE_ERROR_CLASS(thisClass,baseClass)    CAT_DECLARE_ERROR_CLASS(thisClass)
#endif

#define CATCkeDeclareErrorClass(className,baseClass)                    \
  CATDeclareClass;                                                      \
  CKE_DECLARE_ERROR_CLASS(className,baseClass)                          \
  virtual void GetErrorTable (unsigned int *,const CATErrDsc**);        \
  static const unsigned int errorTableLength;                           \
  static const CATErrDsc errorTable[];

//---------------------------------------------------------------
// other classes
//---------------------------------------------------------------
class ExportedByCATLifDictionary CATCkeNotEvaluable : public CATCkeException
{
public:
  CATCkeNotEvaluable (const CATUnicodeString &);
  CATCkeDeclareErrorClass(CATCkeNotEvaluable,CATCkeException)
};

class ExportedByCATLifDictionary CATCkeNotApplyable : public CATCkeException
{
public:
  CATCkeNotApplyable (const CATUnicodeString &);
  CATCkeDeclareErrorClass(CATCkeNotApplyable,CATCkeException)
};

class ExportedByCATLifDictionary CATCkeNotYetEvaluated : public CATCkeException
{
public:
  CATCkeNotYetEvaluated ();
  CATCkeDeclareErrorClass(CATCkeNotYetEvaluated,CATCkeException)
};

class ExportedByCATLifDictionary CATCkeUnrecognisedUnit : public CATCkeException
{
public:
  CATCkeUnrecognisedUnit (const CATUnicodeString &);
  CATCkeDeclareErrorClass(CATCkeUnrecognisedUnit,CATCkeException)
};

class ExportedByCATLifDictionary CATCkeBadUnit : public CATCkeException
{
public:
  CATCkeBadUnit (const CATUnicodeString &);
  CATCkeDeclareErrorClass(CATCkeBadUnit,CATCkeException)
};


//---------------------------------------------------------------
// Exeptions for relations
//---------------------------------------------------------------


class ExportedByCATLifDictionary  CATCkeWrongNumberArg : public CATCkeException
{
public:
  CATCkeWrongNumberArg ();
  CATCkeDeclareErrorClass(CATCkeWrongNumberArg,CATCkeException)

};

class ExportedByCATLifDictionary CATCkeWrongTypesArg : public CATCkeException
{
public:
  CATCkeWrongTypesArg ();
  CATCkeDeclareErrorClass(CATCkeWrongTypesArg,CATCkeException)

};

class ExportedByCATLifDictionary CATCkeNoCurrentParmFactory : public CATCkeException
{
public:
  CATCkeNoCurrentParmFactory ();
  CATCkeDeclareErrorClass(CATCkeNoCurrentParmFactory,CATCkeException)
};

// Value out of range
class ExportedByCATLifDictionary CATCkeValueOutOfRange : public CATCkeException
{
public:
  CATCkeValueOutOfRange (const double d1,const double d2,const CATCke::Boolean gt);
  CATCkeDeclareErrorClass(CATCkeValueOutOfRange,CATCkeException)
};

#endif

