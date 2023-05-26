/**
 * @COPYRIGHT DASSAULT SYSTEMES 2009
 */
/* -*-c++-*- */
//===========================================================================
//
// Nov. 2009   Creation                            JJ3
//
// Dec. 2013   Changed enum values for bitwise
//             operations; 0,1,2,3,4 -> 0,1,2,4,8  UVC
//===========================================================================

#ifndef  CATPartitionManager_h
#define  CATPartitionManager_h

//#include "ExportedByCATTopologicalObjects.h"
#include "CATHashTableWithIntAssoc.h"


class CATTopology;
class CATTopologiesSetForFastRun;
class CATContextForFastRunExt;
class CATContextForFastRunBoxSolutionExt;
class CATPAD;

// A renommer en CATPartionManager

typedef enum
{
  CATUndefinedPartition = 0,
  CATPartitionN  = 1,  // Identifie les objets neutres, c'est a dire inchanges par l'ancien run (f) ou par la modification (g). // CATPNeutral
  CATPartitionF  = 2,  // Identifie les objets changes par l'ancien run (f) et inchanges par la modification (g). // CATRelatedToF
  CATPartitionG  = 4,  // Identifie les objets changes par la modification (g) et inchanges par l'ancien run (f). // CATRelatdToG
  CATPartitionFG = 8   // Identifie les objets changes par l'ancien run (f) et par la modification (g).
}

CATPartitionForFastRun;


//class ExportedByCATTopologicalObjects CATPartitionManager
class CATPartitionManager
{

  public:

    CATPartitionManager();
    CATPartitionManager(int iEstimatedSize, CATPAD * iPADg);
    ~CATPartitionManager();

    int ComputePartitionment(CATTopology *iTopo, int iLevel, CATContextForFastRunBoxSolutionExt * iCtxExt);

    int FindCurrentPartition(CATTopology *iTopo, CATTopologiesSetForFastRun * iElements, CATPartitionForFastRun & oPartition);

    int GetPartition(CATTopology *iTopo);
    void SetPartition(CATTopology *iTopo, int iPartition);
    void Insert(CATTopology *iTopo, int iPartition);
    void SetPADg(CATPAD *iPADg);
    CATBoolean Contains(CATTopology *iTopo);
    int LocateItem(CATTopology *iTopo, CATINT32* iPartition);


  private :

    CATHashTableWithIntAssoc * _Partitionment;
    CATPAD                   * _PADg;


};

#endif
