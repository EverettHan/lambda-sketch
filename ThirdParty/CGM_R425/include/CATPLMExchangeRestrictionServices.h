//=======================================================================================
// WARNING: YWE 18:09:24 SINGLE-CODE 2015x => NO LOCAL CHANGE EXPECTED - USE IMPORT  
//=======================================================================================
//===================================================================
// COPYRIGHT Dassault Systemes 2014/12/25
//===================================================================
// CATPLMExchangeRestrictionServices.cpp
// Header definition of class CATPLMExchangeRestrictionServices
//===================================================================
//
// Usage notes:
//    This class is used to create a list of objects which are not to be expanded.
//    The modelers for these type of objects are considered as restricted modelers.
//===================================================================

#ifndef CATPLMExchangeRestrictionServices_H
#define CATPLMExchangeRestrictionServices_H

#include "PLMExchangeGlobalServices.h"
#include "CATListOfCATUnicodeString.h"
#include "CATBoolean.h"
//-----------------------------------------------------------------------
class CATPLMTypeH;


class ExportedByPLMExchangeGlobalServices CATPLMExchangeRestrictionServices
{
public:

   static void IsInList(CATPLMTypeH & iCompTypeH, CATBoolean & obIsInList, CATListOfCATUnicodeString & iRestrictionList);
   static void BuildWholeStructOptRestrictionList( CATListOfCATUnicodeString & oRestrictionList);
   static void BuildRestrictionListForDetach( CATListOfCATUnicodeString & oRestrictionList ) ;
   static void BuildWholeStructRestrictionListForEditorServices(CATListOfCATUnicodeString & oRestrictionList);
   static void BuildRestrictionItemToShade(CATListOfCATUnicodeString & oRestrictionList); //IR-786952 SKN14
  
   //
   // TODO: Add your methods for this class here.
   //

private:
   // Standard constructors and destructors
   // -------------------------------------
   CATPLMExchangeRestrictionServices ();
   virtual ~CATPLMExchangeRestrictionServices ();
   // Copy constructor and equal operator
   // -----------------------------------
   CATPLMExchangeRestrictionServices (CATPLMExchangeRestrictionServices &);
   CATPLMExchangeRestrictionServices& operator=(CATPLMExchangeRestrictionServices&);

};

//-----------------------------------------------------------------------

#endif
 
