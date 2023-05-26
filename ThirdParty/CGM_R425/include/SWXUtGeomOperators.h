//===================================================================
// COPYRIGHT DS SolidWorks 2011/06/29
//===================================================================


#ifndef SWXUtGeomOperators_H
#define SWXUtGeomOperators_H

#include "SWXMathematics.h"

class CATMathPoint;
class CATMathVector;
class CATMathPlane;
class CATMathPoint2D;
class CATMathBox2D;
class CATMathAxis;
class CATMathDirectionf;
class CATMathVectorf;
class CATMathPointf;

// Works with CATMathDirection, too:
extern ExportedBySWXMathematics bool SWXUtGeomEqualsTol(const CATMathVector& iLhs, const CATMathVector& iRhs);
extern ExportedBySWXMathematics bool SWXUtGeomNotEqualsTol(const CATMathVector& iLhs, const CATMathVector& iRhs);

extern ExportedBySWXMathematics bool SWXUtGeomEqualsTol(const CATMathPoint& iLhs, const CATMathPoint& iRhs);
extern ExportedBySWXMathematics bool SWXUtGeomNotEqualsTol(const CATMathPoint& iLhs, const CATMathPoint& iRhs);

extern ExportedBySWXMathematics bool SWXUtGeomEqualsTol(const CATMathPlane& iLhs, const CATMathPlane& iRhs);
extern ExportedBySWXMathematics bool SWXUtGeomNotEqualsTol(const CATMathPlane& iLhs, const CATMathPlane& iRhs);

extern ExportedBySWXMathematics bool SWXUtGeomEqualsTol(const CATMathPoint2D& iLhs, const CATMathPoint2D& iRhs);
extern ExportedBySWXMathematics bool SWXUtGeomNotEqualsTol(const CATMathPoint2D& iLhs, const CATMathPoint2D& iRhs);

extern ExportedBySWXMathematics bool SWXUtGeomEqualsTol(const CATMathBox2D& iLhs, const CATMathBox2D& iRhs);
extern ExportedBySWXMathematics bool SWXUtGeomNotEqualsTol(const CATMathBox2D& iLhs, const CATMathBox2D& iRhs);

extern ExportedBySWXMathematics bool SWXUtGeomEqualsTol(const CATMathAxis& iLhs, const CATMathAxis& iRhs);
extern ExportedBySWXMathematics bool SWXUtGeomNotEqualsTol(const CATMathAxis& iLhs, const CATMathAxis& iRhs);

extern ExportedBySWXMathematics bool SWXUtGeomEqualsTol(const CATMathDirectionf& iLhs, const CATMathDirectionf& iRhs);
extern ExportedBySWXMathematics bool SWXUtGeomNotEqualsTol(const CATMathDirectionf& iLhs, const CATMathDirectionf& iRhs);

extern ExportedBySWXMathematics bool SWXUtGeomEqualsTol(const CATMathVectorf& iLhs, const CATMathVectorf& iRhs);
extern ExportedBySWXMathematics bool SWXUtGeomNotEqualsTol(const CATMathVectorf& iLhs, const CATMathVectorf& iRhs);

extern ExportedBySWXMathematics bool SWXUtGeomEqualsTol(const CATMathPointf& iLhs, const CATMathPointf& iRhs);
extern ExportedBySWXMathematics bool SWXUtGeomNotEqualsTol(const CATMathPointf& iLhs, const CATMathPointf& iRhs);

//-----------------------------------------------------------------------

#endif
 
