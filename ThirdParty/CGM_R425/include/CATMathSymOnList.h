/// COPYRIGHT DASSAULT SYSTEMES 2003
//=============================================================================
//
// CATMathSymOnList :
// Class to Find and Check symmetry on a list of values
//=============================================================================


#ifndef _CATMathSymOnList_HeaderFile
#define _CATMathSymOnList_HeaderFile

#include "MathApprox.h"


class CATMathSymOnList
{

public:

virtual ~CATMathSymOnList();

virtual int Run() =0;

virtual int IsSymmetric() const=0;

virtual double GetSymmetryError() const=0;

virtual int GetOrigin(int& oIndex, short& oIsOnVertex) const =0;

virtual int Dump() const =0;
};


// Attention le pointeur "iValues" doit rester valide le temp de l'operation
ExportedByMathApprox CATMathSymOnList * CATCreateCATMathSymOnList(const double * iValues, const int iNbValues, const short isClosed);

#endif
