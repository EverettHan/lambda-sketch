#ifndef SWXUtTolerance_H
#define SWXUtTolerance_H

#include "SWXUtGeneral.h"

class CATTolerance;
class CATBaseUnknown_var;

class ExportedBySWXUtGeneral SWXUtTolerance
{
public:
	SWXUtTolerance();
	SWXUtTolerance(const CATBaseUnknown_var &ispObject);
	~SWXUtTolerance();

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

    double ZeroAngle() const;

private:
	const CATTolerance	*mpTolerance;
};
#endif
