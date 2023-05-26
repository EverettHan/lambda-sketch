// COPYRIGHT Dassault Systemes 2022
//===================================================================
//
// CATWBBlackBoxBase.h
// Header definition of CATWBBlackBoxBase
//
//===================================================================
//
// Usage notes: Black box base class to manage link with BBxOperator
//
//===================================================================
//
// 11/08/22 Q48 Creation
//===================================================================

#ifndef CATWBBlackBoxBase_h
#define CATWBBlackBoxBase_h

// ExportedBy
#include "WhiteBoxData.h"

// C++ 11
#include "CATCDSVirtual.h"

// CDS
#include "CATCDSArray.h"

// WBx
class CATWBBlackBoxOperator;

// ODT
class WBBlackBoxTests; // for private reset methods
class ODT_StreamJSON;  // for private reset methods

// Debug
#include "CATWBDebug.h"

// ----------------------------------------------------------------------------
// The define for the rearchitecture
//   - so WhiteBoxesInfra can prepare
// ----------------------------------------------------------------------------
#define WBx_BBx_Rearchitecture
// ----------------------------------------------------------------------------

/**
* @brief The CATWBBlackBoxBase class represents the structure of the BlackBox objects
*/
class ExportedByWhiteBoxData CATWBBlackBoxBase
{
public:

   CATWBBlackBoxBase();

   virtual ~CATWBBlackBoxBase();

   // ---------------------------------------------------------------
   // Data management
   // ---------------------------------------------------------------

#ifndef WBx_BBx_Rearchitecture
   const CATWBBlackBoxOperator * GetDefaultOperator() const;
#endif

private:
   
   friend class CATWBBlackBoxOperator;

   // BBx are created externally, outside the scope of the factory etc --> maintain
   // a list of operators in case the BBx is deleted 

   mutable CATCDSArray<CATWBBlackBoxOperator*> _ListOperators; // List of associated operators

   void RegisterOperator(CATWBBlackBoxOperator*) const;
   void UnregisterOperator(CATWBBlackBoxOperator*) const;

   CATCDSBoolean HasRegisteredOperators() const;

   // ---------------------------------------------------------------
   // Internal counters
   // ---------------------------------------------------------------

private:

   static int _BBxCounter;

protected:

   const int  _BBxID;

   // ---------------------------------------------------------------
   // For ODTs
   // ---------------------------------------------------------------

private:

   friend class WBBlackBoxTests;
   friend class ODT_StreamJSON;
   static void ResetGlobalCounter();

   // ---------------------------------------------------------------
   // Debug
   // ---------------------------------------------------------------

protected:

   WBX_DEBUG_DECLARE;
};
#endif // CATWBBlackBoxBase_h
