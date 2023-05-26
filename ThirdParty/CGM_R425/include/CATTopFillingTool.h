/* -*-C++-*- */
#ifndef CATTopFillingTool_H
#define CATTopFillingTool_H

// COPYRIGHT DASSAULT SYSTEMES 2000

#include "Ribbon.h"
#include "CATMathDef.h"
#include "CATCGMNewArray.h"

#define ActivateAutoLoft

class ExportedByRibbon CATTopFillingTool

{

public:

        enum CATFillType {automatic,analytic,powerfill,powerplane};

/**  constructor 
*/
	CATTopFillingTool();
  CATCGMNewClassArrayDeclare;        // Pool allocation
   
/**  destructor 
*/
	~CATTopFillingTool();
     

/** Set  the type (automatic analytic or powerfill) of the fill computation 
*/
  void  SetFillType (const CATTopFillingTool::CATFillType iFillType);


/** Get the type (automatic analytic or powerfill) of the fill computation
*/
  CATFillType GetFillType ();
 
/** Set the Canonical Detection option (Default value is FALSE)
*/
  void SetCanonicalDetection();

/** Read the Canonical Detection option
*/
  CATBoolean GetCanonicalDetection() const;

/** Set the Canonical Detection option (Default value is FALSE)
*/
  void SetJournalFix();

/** Read the Canonical Detection option
*/
  CATBoolean GetJournalFix() const;

  /** Set the Discretization by Length option
  */
  void SetDiscretizationByLength();

  /** Read the Discretization by Length option
  */
  CATBoolean GetDiscretizationByLength() const;

private: 

	CATFillType _FillType;
  CATBoolean  _CanonicalDetection;
  CATBoolean  _JournalFix, _DiscrLength;
};
#endif
