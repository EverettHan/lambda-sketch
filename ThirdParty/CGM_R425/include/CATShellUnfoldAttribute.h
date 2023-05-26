
/*
=============================================================================

 COPYRIGHT   : DASSAULT SYSTEMES 2016
 
 DESCRIPTION : CGM Attribute for Cloud Polygons (folded and unfolded)

=============================================================================
*/

// <ClassName>: CATShellUnfoldAttribute
//
//=============================================================================
//
// Usage Notes: The class used to create and store the mesh attributes (attached to flattened shell) 
//
//=============================================================================
// June 2016      Creation                   S9L
//=============================================================================

#ifndef CATShellUnfoldAttribute_H
#define CATShellUnfoldAttribute_H

#include "FrFTopologicalOpe.h"    // exported by

#include "CATCGMStreamAttribute.h"
#include "CATCGMStreamClonableAttribute.h"

#include "CATMathPoint.h"
#include "CATMathVector.h"
#include "CATPGMShellUnfoldAttribute.h"

class CATMathSetOfLongs;
class CATMathSetOfPointsND;

//-----------------------------------------------------------------------
// CATShellUnfoldAttribute
//-----------------------------------------------------------------------  
class ExportedByFrFTopologicalOpe CATShellUnfoldAttribute : public CATPGMShellUnfoldAttribute
{
public:
  CATCGMDeclareAttribute(CATShellUnfoldAttribute, CATCGMStreamClonableAttribute);

           CATShellUnfoldAttribute();
  virtual ~CATShellUnfoldAttribute();

  // Streaming/Unstreaming of mesh atttributes
  virtual void UnStream(CATCGMStream & ioStream);
  virtual void Stream  (CATCGMStream & ioStream) const;

  // Get & Set methods for mesh attributes
  void SetMeshAttributes(CATLONG32              iNbVertices, 
                         CATLONG32              iNbTriangles, 
                         CATMathSetOfLongs    & ipTriangleIndices,
                         CATMathSetOfPointsND & ipInputPoints,
                         CATMathSetOfPointsND & ipOutputPoints);

  void GetMeshAttributes(CATLONG32             & oNbVertices, 
                         CATLONG32             & oNbTriangles, 
                         CATMathSetOfLongs    *& iopTriangleIndices,
                         CATMathSetOfPointsND *& iopInputPoints,
                         CATMathSetOfPointsND *& iopOutputPoints) const;

  // Get & Set methods for Unfold type (0 : Free Form Unfold, 1: Shell Expansion)
  void SetUnfoldType(CATShellUnfoldType iUnfoldType);
  void GetUnfoldType(CATShellUnfoldType & ioUnfoldType) const;

  // Get & Set methods for the reference origin 
  void SetOrigin(const CATMathPoint & iReferenceOrigin);
  void GetOrigin(CATMathPoint & ioReferenceOrigin) const;

    // Get & Set methods for the first direction (Reference vector in Shell Expansion)
  void SetFirstDirection(const CATMathVector & iFirstDirection);
  void GetFirstDirection(CATMathVector & ioFirstDirection) const;

  // Get & Set methods for the second diection (Symmetry plane normal in Shell Expansion)
  void SetSecondDirection(const CATMathVector & iSecondDirection);
  void GetSecondDirection(CATMathVector & ioSecondDirection) const;

  // Report the clonable attributes from origin to destination
  virtual CATCGMAttribute * ReportClonableAttributes (CATExtClonableManager * ipClonableManager, 
                                                      CATICGMObject         * ipOrigin, 
                                                      CATICGMObject         * ipDestination);
  
protected:
  short                                 _Version;

  CATShellUnfoldType                    _UnfoldType;

  CATMathPoint                          _ReferenceOrigin;
  CATMathVector                         _FirstDirection;
  CATMathVector                         _SecondDirection;

  CATLONG32                             _nbVertices;
  CATLONG32                             _nbTriangles;

  CATMathSetOfLongs    *                _pTriangleIndices;

  CATMathSetOfPointsND *                _pInputPoints;
  CATMathSetOfPointsND *                _pOutputPoints;

  CATBoolean                            _Streamable;
};

ExportedByFrFTopologicalOpe CATShellUnfoldAttribute *CATCreateShellUnfoldAttribute();

#endif



