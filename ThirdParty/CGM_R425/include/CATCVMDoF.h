// COPYRIGHT DASSAULT SYSTEMES 2006

#ifndef CATCVMDoF_H
#define CATCVMDoF_H

#include "CATCVMGeoOperators.h"
#include "CATBoolean.h"
#include "ListPOfCATCVMGeometry.h"

class CATMathVector;
class CATMathPoint;

enum CATCVMDoFType
{
    CATCVMDoF_Translation,
    CATCVMDoF_Rotation,
    CATCVMDoF_Screw
};

class ExportedByCATCVMGeoOperators CATCVMDoF
{
public:

virtual ~CATCVMDoF();


/**
 *  Return the number of Translations. 
 */
virtual int GetNbTranslations() = 0;

/**
 *  Return the number of Rotations. 
 */
virtual int GetNbRotations() = 0;

/**
 *  Return the number of Screws. 
 */
virtual int GetNbScrews() = 0;

/**
 *  Return the number of DoF. Equal to GetNbTranslations() + GetNbRotations() + GetNbScrews()
 */
virtual int GetNbDoF() = 0;

/**
 * Retrieves the elements that defines the DoF correspond to iIndex.
 *
 * @param iIndex
 * Index of a degree of freedom (0 < iIndex <= GetNbDoF() 
 *
 * @param oType
 * Type of the freedom: translation, rotation , screw. A screw is a combination of
 * a translation and a rotation such that the translation vector and the rotation axis are parallel.
 *
 * @param oPoint, oVector, oPitch
 * Geometric Data that define the DoF; their meaning is dependent on oType:
 *
 * if (oType == CATCVMDoF_Translation): 
 *   oVector is the vector of the translation.
 *   oPoint is the barycenter of the entities of which this is the DoF.
 *   oPitch is not used.
 *
 * if (oType == CATCVMDoF_Rotation):
 *   oVector is the vector of the axis of the rotation.
 *   oPoint is a point lying on the rotation axis; the set of possible locations for oPoint is a subset
 *   of the 3D space, and the actual location is chosen as the closest to the barycenter of the entities of which this is the DoF.
 *   oPitch is not used.
 *
 * if (oType == CATCVMDoF_Screw):
 *   oVector is the vector of the axis of the screw.
 *   oPoint is a point lying on the screw axis; the set of possible locations for oPoint is a subset
 *   of the 3D space, and the actual location is chosen as the closest to the barycenter of the entities of which this is the DoF.
 *   oPitch is defined as follows: for a given angle of rotation ALPHA, the screw is a combination of a rotation
 *   of angle ALPHA around the axis and of a translation of oPitch*(ALPHA)*oVector
 *   ALPHA is measured counterclockwise in radians.
 */
  virtual void GetDoF(int iIndex, CATCVMDoFType &oType, CATMathPoint & oPoint, CATMathVector & oVector, double & oPitch)= 0;


private:

CATCVMDoF(const CATCVMDoF &);
void operator = (const CATCVMDoF &);

protected:
CATCVMDoF();

};

#endif
