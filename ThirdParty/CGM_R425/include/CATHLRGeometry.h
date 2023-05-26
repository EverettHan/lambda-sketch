/* -*-C++-*-*/
#ifndef CATHLRGeometry_H
#define CATHLRGeometry_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1998
//
// CATHLRGeometry 
//
// DESCRIPTION :
/**
 * Geometrical object for the HLR, that includes a pointer on a transformation
 * for multiple instanciation of objects.
 * <BR> If the pointer on a transformation is NULL, it means that no
 * transformation will be applied to the object from its own axis to the
 * instance axis.
 */
//
//=============================================================================
// Abstract Class     : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Jan. 98   Jose CHILLAN (jch)    Creation            
//
//=============================================================================

// For Windows NT
#include "HLRGeometry.h"

// For inheritance
#include "CATHLRObject.h"

class CATBaseUnknown;
class CATUnicodeString;
class CATGeometry;
class CATHLRContainer;
class CATHLRTransformation;

class ExportedByHLRGeometry CATHLRGeometry : public CATHLRObject
{
public:
//=============================================================================
// CONSTRUCTORS AND DESTRUCTOR
//=============================================================================
/**
 * Constructor from a Jele, and a container in which it will be included
 */
  CATHLRGeometry(int               iJele,
		 CATHLRContainer * iContainer,
		 const CATHLRTransformation * iTransformation);

/** Constructor from a pointer on an object being geometry.
 */
  CATHLRGeometry(void            * iGeometry,
		 CATHLRContainer * iContainer,
		 const CATHLRTransformation * iTransformation);

/**
 * Destructor is inherited
 */
//  virtual ~CATHLRGeometry();

//=============================================================================
// METHODS
//=============================================================================

/** Gets the transformation associated to a object
 */
  const CATHLRTransformation * GetTransformation() const;

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Pointer on the trasnformation (can be NULL)
  const CATHLRTransformation * _Transformation;

};


//=============================================================================
// DEBUG
//=============================================================================

typedef void (*HLRDBGPoint) (CATMathPoint & iPt, int Tag, int SymbolType, int Color);
typedef void (*HLRDBGLine) (float *P1, float *P2, int Tag, int SymbolType, int Color);
typedef void (*HLRDBGLineMP) (const CATMathPoint &iP1, const CATMathPoint & iP2, int Color);
typedef void (*HLRDBGText) (const CATMathPoint & iPt, CATUnicodeString &iText, int Color);
ExportedByHLRGeometry extern HLRDBGPoint TheHLRDBGPoint;
ExportedByHLRGeometry extern HLRDBGLine TheHLRDBGLine;
ExportedByHLRGeometry extern HLRDBGLineMP TheHLRDBGLineMP;
ExportedByHLRGeometry extern HLRDBGText TheHLRDBGText;
//#define VISUAL_DEBUG_CURVE
//#define VISUAL_DEBUG_SURFACE


//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================



#endif
