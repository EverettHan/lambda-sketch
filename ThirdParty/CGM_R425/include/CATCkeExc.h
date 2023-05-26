/**  	   	   	 
* @level Protected 	  	  	 
* @usage U1 	  	  	 
*/

// Copyright Dassault Systemes 2000
#ifndef CATCkeExc_h
#define CATCkeExc_h
//////////////////////////////////////////////////////////////////////////
//
//
//	Cke Adapter Implementations
// 	declaration of cke exceptions
//
//
//////////////////////////////////////////////////////////////////////////

#include "CATLifDictionary.h"
#include "CATError.h"
#include "CATErrorDefs.h"
#include "CATCke.h"

class ExportedByCATLifDictionary CATCkeException : public CATError
{
public :

  /**
  * Constructor with strings
  */
  CATCkeException (const CATUnicodeString &s = "");
  void SetMsg (const CATUnicodeString *ps);
  void SetMsg ();
  virtual ~CATCkeException ();
  void Locate (const CATUnicodeString &, int);
  CATDeclareErrorClass(CATCkeException, CATError);
  // message
  CATUnicodeString  _msg;

protected:

  CATCkeException (const CATCkeException&);

  CATUnicodeString  _file;
  int _line;
};

class ExportedByCATLifDictionary CATCkeInvalidType : public CATCkeException
{
public:
  CATCkeInvalidType();
  CATDeclareErrorClass(CATCkeInvalidType,CATCkeException)
};

class ExportedByCATLifDictionary CATCkeConstObject : public CATCkeException
{
public:
  CATCkeConstObject(); 
  CATDeclareErrorClass(CATCkeConstObject,CATCkeException)
};
class ExportedByCATLifDictionary CATCkeParseStop : public CATCkeException
{
public:
  CATCkeParseStop(); 
  CATDeclareErrorClass(CATCkeParseStop,CATCkeException)
};



// technique EVN
class ExportedByCATLifDictionary CATCkeRaiseExc : public CATCke
{
public:

  // exceptions adapter
  static void RaiseNullPtrAccess ();
  static void RaiseAssertFailed ();
  static void RaiseNotYetImplemented ();
  static void RaiseBoundError(CATCke::Integer low, CATCke::Integer up, CATCke::Integer i);
  static void RaiseInvalidType ();
  static void RaiseConstObject ();
  static void RaiseUnderlyingError ();

  // exceptions term
  static void RaiseInvalidArg(const CATUnicodeString &s);
  static void RaiseUnsetParameter(const CATUnicodeString &s);

  // exceptions de parse
  // exceptions expressions
  static void RaiseNotEvaluable (const CATUnicodeString &s);
  static void RaiseNotApplyable (const CATUnicodeString &s);
  static void RaiseNotYetEvaluated ();
  static void RaiseUnrecognisedUnit (const CATUnicodeString &s);
  static void RaiseBadUnit (const CATUnicodeString &s);
  static void RaiseWrongNumberArg ();
  static void RaiseWrongTypesArg ();
  static void RaiseNoCurrentParmFactory ();
  static void RaiseValueOutOfRange (const double d1,const double d2,const CATCke::Boolean gt);

  static void RaiseParseStop ();
  static void Locate (const CATUnicodeString &, CATCke::Integer);

private :

  static void VasY (CATCkeException *);
  static CATUnicodeString  filename_;
  static int entier_;

};


#endif
