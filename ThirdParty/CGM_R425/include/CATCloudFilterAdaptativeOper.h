/**
 *  Large Range compatibility certified by DNR (2014-05-21)
 */
//==============================================================================================================
// COPYRIGHT DASSAULT SYSTEMES 19??
//==============================================================================================================
// Class CATCloudFilterAdaptativeOper
//==============================================================================================================
// Usage Notes:
//==============================================================================================================
// 20-Mar-2003 - JLH - 'Prise en compte' des points "graines".
//                     Possibilite d'une distance maximale : application d'un filtrage homogene apres le filtra-
//                     ge adaptatif.
// 12-Nov-2002 - JLH - Derivation de CATCloudFilterOperator.
// ??-???-???? - ??? - Creation
//==============================================================================================================

#ifndef CATCloudFilterAdaptativeOper_H
#define CATCloudFilterAdaptativeOper_H

#include "ExportedByCATCloudBasicResources.h"
#include "CATCloudFilterOperator.h"
#include "CATCldToleranceBase.h"

class ExportedByCATCloudBasicResources CATCloudFilterAdaptativeOper : public CATCloudFilterOperator
{
public:

  CATCloudFilterAdaptativeOper (const int    iNbPoints,
                                const float* iCoords,
                                const double iMin[3],
                                const double iMax[3]) ;
  virtual ~CATCloudFilterAdaptativeOper () ;

  // La tol�rance est l'erreur de corde locale.
  // Ce n'est que si un point est � une distance du plan des moindre carr�s sup�rieure � elle, que le voxel
  // sera recursivement red�coup� selon la plus grande dimension de sa boite d'encombrement.
  // Sinon, on conserve le point le plus proche du barycentre. Tout est dit.
  inline void SetChordalError (const double iError) ;

  // On garde des points dans les zones planes afin de respecter une distance maximale entre eux.
  inline void SetMaxDistance  (const double iMaxDistance = CATCldToleranceBase::Infinite()) ;

  void Run () ;

  // Les deux classes ci-apres sont public, car SUN/solaris n'accepte pas de les voir en prive.
  // En effet, si tel est le cas Voxel ne connait pas Index, d'ou probleme a la compilation.

  // Structure chainee des indices des points contenus dans un voxels.
  class Index {
  public:
    Index () {
      _Idx = -1 ;
      _Nxt = NULL ;
    }
    ~Index () {
      _Idx = -1 ;
      _Nxt = NULL ;
    }
    friend class CATCloudFilterAdaptativeOper ;
    friend class Voxel ;
  private:
    int  _Idx ;
    Index* _Nxt ;
  } ;

  // Structure chain�e de voxels. Un voxel est une partition du nuage.
  // Ces donn�es sont donc les indices des points contenus. Une des donn�es du voxel
  // est donc un pointeur sur une liste chain�e de type "CATCloudFilterAdaptativeOper::Index"
  // D�finie ci dessus.
  // Autres donn�es:
  // _RightSon : le fils r�sultant de la d�coupe droite et _LeftSon son compl�mentaire. Cette
  // d�coupe est �ventuelle, ele d�pend de plan�rit� du voxel.
  // _Planar, le voxel est-il plan selon le crit�re de tol�rance ? Si tous les points contenus
  // sont � une distance du plan des moindre carr�s inf�rieure � la tol�rance, il est plan.
  // On arr�te alors la d�coupe et on assigne � _Idx, l'index du point du voxel le plus proche
  // du barycentre.
  class Voxel {
  public:
    Voxel () {
      _RightSon = NULL ;
      _LeftSon  = NULL ;
      _Planar   = 0 ;
      _Indexes  = NULL ;
      _Idx = -1 ;
    }
    ~Voxel () {
      if (_RightSon) {
        delete _RightSon ;
        _RightSon = NULL ;
      }
      if (_LeftSon) {
        delete _LeftSon ;
        _LeftSon = NULL ;
      }
      _Planar  = 0 ;
      _Indexes = NULL ;
      _Idx = -1 ;
    }
    friend class CATCloudFilterAdaptativeOper ;
    friend class Index ;
  private:
    Index* _Indexes ;
    Voxel* _LeftSon ;
    Voxel* _RightSon ;
    unsigned int _Planar ;
    int _Idx ;
  } ;

private:

  void ImpossibleAllocation () ;

  // M�thode r�cursive de d�coupage du nuage en voxels.
  void Voxelize (Voxel *) ;
  // Une fois cette partition faite, les points finaux sont rendus actifs.
  void EnablePlanar (Voxel *) ;

  double _ChordalError ;
  double _MaxDistance ;

  Voxel* _RootVoxel ;
  Index* _Indexes ;
} ;

//--------------------------------------------------------------------------------------------------------------
// Function : SetChordalError
// Purpose  :
//--------------------------------------------------------------------------------------------------------------

inline void CATCloudFilterAdaptativeOper::SetChordalError (const double iError)
{
  _ChordalError = iError ;
}

//--------------------------------------------------------------------------------------------------------------
// Function : SetMaxDistance
// Purpose  :
//--------------------------------------------------------------------------------------------------------------

inline void CATCloudFilterAdaptativeOper::SetMaxDistance  (const double iMaxDistance)
{
  _MaxDistance = iMaxDistance ;
}

#endif
