#ifndef SWXUtGeomConversionUtils_H
#define SWXUtGeomConversionUtils_H

#include "SWXMathematics.h"

//-----------------------------------------------------------------------

class CATMathPoint;
class CATMathPointf;
class CATMathDirection;
class CATMathDirectionf;
class CATMathVector;
class CATMathVectorf;

extern ExportedBySWXMathematics CATMathPoint SWXUtMathPointFtoMathPoint(const CATMathPointf& iMpf);
extern ExportedBySWXMathematics CATMathVector SWXUtMathVectorFtoMathVector(const CATMathVectorf& iMvf);
extern ExportedBySWXMathematics CATMathDirection SWXUtDirectionFtoDirection(const CATMathDirectionf& iDf);
extern ExportedBySWXMathematics CATMathVector SWXUtPointToVector(const CATMathPoint& iPoint);
extern ExportedBySWXMathematics CATMathPoint SWXUtVectorToPoint(const CATMathVector& iVector);

extern ExportedBySWXMathematics CATMathVectorf SWXUtPointfToVectorf(const CATMathPointf& iPoint);
extern ExportedBySWXMathematics CATMathPointf SWXUtVectorfToPointf(const CATMathVectorf& iVec);

//-----------------------------------------------------------------------

#endif
