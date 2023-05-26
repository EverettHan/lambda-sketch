/* -*-C++-*-*/
// COPYRIGHT DASSAULT SYSTEMES 1997
//------------------------------------------------------------------------------
// CATHybPart: Elementary object for the recursive discretization of space.
//              Allows to seek geometrical neighbours of a point
//      
//------------------------------------------------------------------------------
// Usage Notes: Allows several identical points in a basic cell
//------------------------------------------------------------------------------
// Inheritance: CATHybVicinity
//------------------------------------------------------------------------------
//
#ifndef CATHybPart_h
#define CATHybPart_h

//#include "ExportedByCATTopImpl.h"
#include "ExportedByPBELight.h"
//------------------------------------------------------------------------------
# include "CATHybVicinity.h"
# include "CATPoints.h"

class CATHybBox;
class CATHybCloudBox;

class ExportedByPBELight CATHybPart : public CATHybVicinity
{
public:
  virtual ~CATHybPart();
  CATHybPart (CATHybBox* espacedef, CATHybNeighbour* oper);

  // Setup
  //static CATHybPart*	GetMainCube();
  void			AddPt (CATPoint* pt);
  int			IsBasic()const;
  void 			Finish();

  // Get results
  void 			SeekNeighbours(int degre, CATPoints* neighbours);
  void                  SeekRealNeighbours(CATPoint* iPt,
					   CATPoints* oNeighbours)const;

  short                 IsPossiblyAdjacentPart(CATHybPart*,short)const;
  CATHybPart*           GetAdjacentPart(short iDirection)const;
  CATHybPart*           GetSmallestAdjacentPart(short,CATHybPart*)const;

  // Infos
  CATPoints*		GetListOfPoints();
  CATHybPosition* 	GetPosition()const;
  
  // basics walker: next=current->NextBasic();
  CATHybPart* 		NextBasic()const;

  static CATHybPart* 	GetStoredPart(CATGeometry* pt,int key);
  CATHybPart* GetNearBorderPart(CATGeometry* pt);

#ifdef CATHybDebugPart
  void Dump(int=0);
#endif
  
protected:
  CATHybPart (CATHybBox* espacedef, CATHybPosition* my_position, 
	       CATHybPart* carrepere);
  // Setup
  void InitializeMyChildren();
  void AffectPointsToMyChildren();
  void Split();

  void GetBasics(int deep, CATHybPart* fils,CATPoints* neighbours);
  void ScanBasics(int level, CATPoints* neighbours);

  CATHybPart* GetFather(int& level);
  short IsFatherOf(CATHybPart* fils);

  void AppendMyCells(CATPoints* neighbours)const;
  CATHybPart* NextBasic(const CATHybPart* fils)const;

  int StorePartOn(CATGeometry* pt);
  int SetPointNearBorder(CATGeometry* pt);
  
#ifdef CATHybDebugPart
  void DumpBasicSquare();
  static CATHybPart*  	_main_carre;
#endif
#ifdef CATHybDumpPart
  void DumpInFactory();
#endif

protected:
  CATPoints*     	_listofpoints;
  CATHybPart** 		_children;
  CATHybCloudBox*  	_cloud;
  CATHybBox*       	_volume;
  static int		_borderkey;
  int                   GetBorderKey()const;
  
private:
  int 			_is_basic;
  CATHybPart*  		_father;
  CATHybPosition* 	_my_position;

};

#endif
