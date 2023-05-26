/**
 *  Large Range compatibility certified by DNR (2014-05-21)
 */
//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES 19??
//==============================================================================================================
// Class CATCloudFilterHomogenizeOper
//==============================================================================================================
// Usage Notes:
//==============================================================================================================
// 20-Mar-2003 - JLH - 'Prise en compte' des points "graines".
//                     CATCloudFilterAdaptativeOper devient friend pour eviter la duplication des tableaux lors
//                     d'un filtrage adaptatif avec distance maximum.
// 12-Nov-2002 - JLH - Derivation de CATCloudFilterOperator.
//                     Voxellisation dynamique.
// 26-Jul-2002 - JLH - Correction de relecture de code
// ??-???-???? - ??? - Creation
//==============================================================================================================

#ifndef CATCloudFilterHomogenizeOper_H
#define CATCloudFilterHomogenizeOper_H

#include "ExportedByCATCloudBasicResources.h"
#include "CATCloudFilterOperator.h"

#define _Power 1
// L'heuristique montre qu'avec une puissance de 2, nous avons un gain en CPU de 40 à 50%, mais une consomation
// memoire multipliee par 4 !!! Nous preferons perdre du temps plutot que de la memoire.

class ExportedByCATCloudBasicResources CATCloudFilterHomogenizeOper : public CATCloudFilterOperator
{
public:

  CATCloudFilterHomogenizeOper (const int    iNbPoints,
                                const float* iCoords,
                                const double iMin[3],
                                const double iMax[3]) ;
  virtual ~CATCloudFilterHomogenizeOper () ;

  inline void SetRadius (const double iRadius) ;

  void Run () ;

  friend class CATCloudFilterAdaptativeOper ;
  // Pour pouvoir partager certains champs, s'il y a filtrage adaptatif avec distance maximale.

private:

  class Voxel {
    friend class CATCloudFilterHomogenizeOper ;
  public:
    Voxel() ;
    ~Voxel() ;
    int _Idx ;
    Voxel *_Sons[1<<_Power][1<<_Power][1<<_Power] ;
  } ;

  void ImpossibleAllocation () ;

  Voxel* GetVoxel ( Voxel*       iVoxel,
                    unsigned int iAdr[3],
                    unsigned int iLevel) ;

  unsigned int ToInsert ( unsigned int iIdx,
                          unsigned int iNum[3]) ;

  void Insert (unsigned int iIdx,
               Voxel*       iVoxel,
               unsigned int iAdr[3],
               unsigned int iLevel) ;

  unsigned int InvertBitsField (const unsigned int iValue) ;
  
  inline unsigned int AreTooNear (const unsigned int  iIdx,
                             const unsigned int  iJdx) ;

  double _Rad1, _Rad2, _Ratio ;
  unsigned int _NbVoxels[3] ;
  unsigned int _MaxLevel ;
  Voxel* _RootVoxel ;
} ;

//--------------------------------------------------------------------------------------------------------------
// Function : SetRadius
// Purpose  :
//--------------------------------------------------------------------------------------------------------------

inline void CATCloudFilterHomogenizeOper::SetRadius (const double iRadius)
{
  _Rad1 = iRadius ;
  _Rad2 = _Rad1 * _Rad1 ;
}

//--------------------------------------------------------------------------------------------------------------
// Function : AreTooNear
// Purpose  :
//--------------------------------------------------------------------------------------------------------------

inline unsigned int CATCloudFilterHomogenizeOper::AreTooNear (const unsigned int iIdx,
                                                              const unsigned int iJdx)
{
  int Idx = 3 * iIdx ;
  int Jdx = 3 * iJdx ;
  float Dis, Delta ;
  Dis = 0. ;
  Delta = _Coords[Jdx+0] - _Coords[Idx+0] ; Dis += Delta*Delta ; if (Dis > _Rad2) return 0 ;
  Delta = _Coords[Jdx+1] - _Coords[Idx+1] ; Dis += Delta*Delta ; if (Dis > _Rad2) return 0 ;
  Delta = _Coords[Jdx+2] - _Coords[Idx+2] ; Dis += Delta*Delta ; if (Dis > _Rad2) return 0 ;
  return 1 ;
}

#endif
