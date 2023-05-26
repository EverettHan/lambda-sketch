#ifndef CATInterp3DBox_H
#define CATInterp3DBox_H

// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2002-2005
/**
* @level Private
* @usage U1
*/

#include "MathAdvMarsh.h"

#include "CATLib.h"
#include "CATMathPoint.h"
#include "CATDataType.h"

//#define RSD_Trichotomie

class ExportedByMathAdvMarsh CATInterp3DBox
{
public:
	
	CATInterp3DBox(int* iBoxCoords, const short isCentered=0);
	~CATInterp3DBox();

	int ComputeOptimalPoint(double*& iBoxCorner, int iCuttingStep[3],  CATMathPoint& OptimalPoint);

  void AddNumberOfPnts();
	int GetNumberOfPnts() const;

	
	float _MinDistToMiddle;
	float _ErrMax;
	int _BoxCoords[3];
	int _IndexOfActivePoint;				//-1 si aucun point n'est actif (et donc idem pour la boîte), l'indice du point actif sinon
	int _IndexOfClosestPointToMiddle;
	int _NumberOfPntsInside;	
	short _State;	//1 si erreur, 0 sinon
  short _Centered; //0 : Non 7 :: All Direction
  //short _SymGeo; //-1 Non calcule, 0 pas de symetrie, 1:x 2:y 3:xy 4:z, 5:xz 6:yz, 7:xyz.

	//unsigned short _Key;
};

#endif


