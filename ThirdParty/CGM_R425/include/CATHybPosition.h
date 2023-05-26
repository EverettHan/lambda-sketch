/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1997
//------------------------------------------------------------------------------
// CATHybPosition: Defines position of CATHybPart Object
//      
//------------------------------------------------------------------------------
// Usage Notes: To be used with CATHybPart
//------------------------------------------------------------------------------
// Inheritance: CATHybVicinity
//------------------------------------------------------------------------------
//
#ifndef CATHybPosition_h
#define CATHybPosition_h

//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
//------------------------------------------------------------------------------
// la classe CATHybPosition permet d indiquer :
// 	- la position d un carre dans son pere
//      	0 ou 1 suivant x
//		0 ou 1 suivant y
//		0 ou 1 suivant z
//                 
//------------------------------------------------------------------------------
# include "CATHybVicinity.h"

class ExportedByPBELight CATHybPosition : public CATHybVicinity
{
public:
  virtual ~CATHybPosition();

  CATHybPosition();
  CATHybPosition(int number);
  CATHybPosition(const CATHybPosition* direction);

  int  GetCoord(int iaxe)const;
  void SetCoord(int* coord);
  void SetCoord(int iaxe,int coord);
  int  DirectionToNumber()const;

  //void Invert ();
  //void OppositePosition(const CATHybPosition* way);
  //int  IsMatchingDirection(const CATHybPosition*)const;
  //virtual int  SuitsToPosition(const CATHybPosition*)const;

protected:
  int* _coord;

#ifdef CATHybDebugPart
  void Dump()const;
#endif

};
#endif




