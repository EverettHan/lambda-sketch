//=============================================================================
// COPYRIGHT Dassault Systemes 2007
//=============================================================================
//
// Tessellate a CGM BRep into a polyhedral body
//
//=============================================================================
//  2007-10-23  BPG: New.
//=============================================================================
#ifndef CATTessPolyBodyTessellator_H
#define CATTessPolyBodyTessellator_H

#include "TessPolygon.h"

#include "CATDataType.h"
#include "CATTessDiagnostic.h"

//
class CATTessSettings;
class CATTessellate;
class CATTessPolyBodyTessellatorSettings;

class CATBody;
class CATPolyBody;
class CATMapOfPtrToPtr;

class CATSoftwareConfiguration;
 
#ifndef CATTessFrameworkCaller
#define CATTessFrameworkCallerExpansed(x) #x
#define CATTessFrameworkCaller(x)  CATTessFrameworkCallerExpansed(x)
#endif

//
class ExportedByTessPolygon CATTessPolyBodyTessellator
{
public:
  CATTessPolyBodyTessellator();
  ~CATTessPolyBodyTessellator();

public:
  /** Tesselate a CATBody into a CATPolyBody
   */
  CATTessDiagnostic Compute(CATBody *iBody, const CATTessSettings &iTessSettings,
                            const CATTessPolyBodyTessellatorSettings &iSettings,
                            CATPolyBody *&ioPolyBody,
                            CATSoftwareConfiguration *iConfig = 0,
                            const char *iFwCaller = CATTessFrameworkCaller(_MK_FWNAME_) ) const;

  /** Tesselate a CATBody into a CATPolyBody
   *  Construct a map of the CATPolyBody's cells to the CATBody's cells.
   */
  CATTessDiagnostic Compute(CATBody *iBody, const CATTessSettings &iTessSettings,
                            const CATTessPolyBodyTessellatorSettings &iSettings,
                            CATPolyBody *&ioPolyBody,
                            CATMapOfPtrToPtr*& ioMapCATPolyCellToCATCell,
                            CATSoftwareConfiguration *iConfig = 0,
                            const char *iFwCaller = CATTessFrameworkCaller(_MK_FWNAME_) ) const;

  /** Invoke a tessellator to fill a CATPolyBody
   */
  CATTessDiagnostic Compute(CATTessellate &ioTessellator,
                            const CATTessPolyBodyTessellatorSettings &iSettings,
                            CATPolyBody *&ioPolyBody) const;
};

#endif // !CATTessPolyBodyTessellator_H
