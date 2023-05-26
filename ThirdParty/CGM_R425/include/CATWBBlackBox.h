// COPYRIGHT Dassault Systemes 2007
//===================================================================
//
// CATWBBlackBox.h
// Header definition of CATWBBlackBox
//
//===================================================================
//
// Usage notes: A class for White Boxes equations support in CDS.
//
//===================================================================
//
//   /01/07      Creation (Sergey Lipski)
// 12/03/18 Q48  Add _IsInternal for memory management
// 24/07/18 Q48  Make GetName const and storage mutable (for printer)
// 05/08/19 Q48  Make SetOperator private (friend class CATWBBlackBoxOperator)
// 25/01/23 Q48  Migrate to new BBx architecture
//===================================================================

#ifndef CATWBBlackBox_h
#define CATWBBlackBox_h

// Base class
#include "CATWBBlackBoxBase.h"

// ExportedBy
#include "WhiteBoxData.h"

// C++ 11
#include "CATCDSVirtual.h"

// CDS
#include "CATCDSString.h"
#include "CATCDSArray.h"

class CATWBBlackBoxOperator;
class CATWBVariable;
class CATWBValue;

// Streaming (deprecated)
class CATWBParser;

 /**
  * @brief The CATWBBlackBox class represents the structure of the BlackBox objects
  */
class ExportedByWhiteBoxData CATWBBlackBox : public CATWBBlackBoxBase
{
protected:

   CATWBBlackBox(); // for most derived classes
   CATWBBlackBox(const CATCDSBoolean iIsInternal); // for CATWBBlackBoxCke (WBx converter)

public:

   virtual ~CATWBBlackBox();

   // ---------------------------------------------------------------
   // Naming
   // ---------------------------------------------------------------

   CATCDSString GetName() const;
   CATCDSString GetName(CATCDSBoolean & oIsSet) const;

   void SetName(const CATCDSString & iName) const;

   // ---------------------------------------------------------------
   // Black-box <-> Black-box operator link
   // ---------------------------------------------------------------

private:

   friend class CATWBBlackBoxOperator;
   friend class CATWBBlackBoxDerivOperator;

   void SetOperator(const CATWBBlackBoxOperator * iBBxOp) const;

protected:

#ifdef WBx_BBx_Rearchitecture
   const CATWBBlackBoxOperator * GetOperator() const;
#else
   CATWBBlackBoxOperator * GetOperator() const;
#endif
     
   // ---------------------------------------------------------------
   // Eval (to be derived)
   // ---------------------------------------------------------------

private:

   // Q48 (17/05/22): Made private so eval is only through the associated BBx operator
   //virtual double Eval() const = 0;
   //virtual double Eval() const CATCDSFinal;

   // Deprecated but...
   //   - is required for CATWBBlackBoxCke (in WhiteBoxesInfra) until code changes reach BSF to remove override
   //   - may be required for CATCkeWBBlackBox (in KnowEquCDSPlug)
   virtual double Eval();

   // The method to use!
   virtual void   Eval(CATWBValue & oValue) = 0; // The actual eval method to be implemented

   // ---------------------------------------------------------------
   // Eval (internal)
   // ---------------------------------------------------------------

private:

   friend class CATWBBlackBoxOperator;
   friend class CATWBBlackBoxDerivOperator;
   
   // To be called from the BBx operator
   virtual double Eval(const CATWBBlackBoxOperator * iBBxOp) /* const*/ CATCDSFinal;

   // To be called from the BBx operator
   virtual void Eval(const CATWBBlackBoxOperator * iBBxOp,
                           CATWBValue            & oValue) /* const*/ CATCDSFinal;

   // Over-ride this to implement exact derivatives!
   virtual void EvalDeriv(const CATWBBlackBoxOperator * iBBxOp,
                                CATWBVariable         * iDerivVar,
                                CATWBValue            & oValue) const;

public:

   CATCDSBoolean IsInternal() const;

#ifndef WBx_BBx_Rearchitecture
   void SetInternal() const;
#endif

private:

   friend class CATWBParser; // deprecated stream / unstream class - needs access to set BBx as internal
   
   // Only set by the BBx operator
#ifdef WBx_BBx_Rearchitecture
   void SetInternal() const;
#endif

   void SetExternal() const;

   static CATCDSString GetDefaultBlackBoxName(const int iBBxID);

#ifdef WBx_BBx_Rearchitecture
private:
   mutable const CATWBBlackBoxOperator* _CurrentOperator; // cached only for duration of Eval...
#else
protected: // make available in CATWBBlackBoxCke::Eval (awaiting migration to reach BSF)
   mutable const CATWBBlackBoxOperator* _pOperator; // cached only for duration of Eval...
#endif

private:

   mutable CATCDSBoolean _NameIsSet;
   mutable CATCDSString  _Name;

   mutable CATCDSBoolean _IsInternal;

   // Streaming
   // ---------

private:

   friend class CATWBxBlackBoxOperatorUnStr;
   void ClearName();
};

//-----------------------------------------------------------------------
CATCDSLISTP_DECLARE_EXPORTED(CATWBBlackBox, ExportedByWhiteBoxData);

#endif
