//==========================================================================
// COPYRIGHT DASSAULT SYSTEMES 1999
//==========================================================================
//
// CATAutoFillFaceAttr:
// Class for face private attributes for AutoFill 
//
//==========================================================================
// Usage Notes:
//
// Cette classe n'est active  qu'avec la variable POWERFILL_ATTRIBUTE=1
//==========================================================================
// MPS : Mars 2005 
//========================================================================== 

#ifndef CATAutoFillFaceAttr_H
#define CATAutoFillFaceAttr_H

#include "CATCGMAttribute.h"
#include "AutoFill.h"


class ExportedByAutoFill CATAutoFillFaceAttr : public CATCGMAttribute
{
	CATCGMDeclareAttribute(CATAutoFillFaceAttr, CATCGMAttribute);

	public:
		CATAutoFillFaceAttr();

		//destructor
		~CATAutoFillFaceAttr();

// donne l'angle entre le plan et les normales  
		int SetAngle(const double iAngle);
        double  GetAngle();

// donne la deviation relative entre les deux modes de calcul,c'est a dire la distance ramenee a la 
// taille du modele 
		int SetDeviation(const double iDeviation);
	    double  GetDeviation();

//indique  si la face  a ete calcule par la methode des elements finis geometriques 
		int SetGeometricOptimumInitialSurfaceMode(const CATBoolean iGeometricOptimumInitialSurface);
        CATBoolean GetGeometricOptimumInitialSurfaceMode();

   	protected:

		double _Angle;
		double _Deviation;
		CATBoolean _GeomFe;
		
};
#endif
