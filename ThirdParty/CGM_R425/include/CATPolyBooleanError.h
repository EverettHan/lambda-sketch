// COPYRIGHT DASSAULT SYSTEMES 2006, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBooleanError.h
// Header definition of CATPolyBooleanError
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// July 2006 Creation: ndo
//===================================================================
#ifndef CATPolyBooleanError_H
#define CATPolyBooleanError_H

#include "CATPolyBooleanOperators.h"
#include "CATPolyBoolean.h"
#include "CATUnicodeString.h"
#include "CATBaseUnknown.h"
//#include "CATError.h"
//#include "CATErrorDefs.h"


/*
* Error class for the boolean operators.
* The error IDs are defined in CATPolyBoolean::BooleanError.
* We may want to derive this class from CATError... TO DO!
*/ 
//class ExportedByCATPolyBooleanOperators CATPolyBooleanError : public CATError
class ExportedByCATPolyBooleanOperators CATPolyBooleanError : public CATBaseUnknown
{
  
  CATDeclareClass;

public:

  //CATDeclareError (CATPolyBooleanError, CATError)

  CATPolyBooleanError (const int iErrorID = CATPolyBoolean::eNoError);

  // Set and get error ID for first (iOperand = 0) or second (iOperand = 1) operands.
  void SetOperandErrorID (const int iOperand, const int iErrorID);
  int GetOperandErrorID (const int iOperand) const;

  // Set and get the error ID for the operator.
  void SetOperatorErrorID (const int iErrorID);
  int GetOperatorErrorID () const;

  // Returns the ID of the error encountered.  
  // This ID is calculated from the operand and operator error IDs.
  // See CATPolyBoolean::BooleanError for definition of the various error Ids.
  int GetID () const;

  // Returns the full error message as defined in the NLS catalog for the error.
  CATUnicodeString GetNLSMessage () const;

private:

  int _OperandErrorID[2]; // Error ID for the operands.
  int _OperatorErrorID;   // Error ID for the operator.

};

#endif

