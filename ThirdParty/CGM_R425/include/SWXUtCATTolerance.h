//===================================================================
// COPYRIGHT DS SolidWorks 2021/09/15
//===================================================================
// SWXUtCATTolerance.h
// Header definition of class SWXUtCATTolerance
//===================================================================
//
// Usage notes:
//
//===================================================================
//  2021/09/15 Creation: Code generated by the 3DS wizard
//===================================================================

#ifndef SWXUtCATTolerance_H
#define SWXUtCATTolerance_H

#include "CATCGMScaleCategoryDef.h"
#include "CATTolerance.h"
#include "SWXUtGeneral.h"

class ExportedBySWXUtGeneral SWXUtCATTolerance : public CATTolerance
{
public:
    SWXUtCATTolerance(CATCGMScaleCategory iScaleCategory = ScaleN);
    ~SWXUtCATTolerance();

    double ModelSize() const;
    double ModelResolution() const;
    double ModelResolutionSq() const;

    double LengthTol() const;
    double LengthTolSq() const;
    double AbsoluteTol() const;
    double AbsoluteTolSq() const;
    double TessellationTol() const;
    double TessellationTolSq() const;

    double AlmostZero() const;
    double Infinity() const;

private:
};
#endif