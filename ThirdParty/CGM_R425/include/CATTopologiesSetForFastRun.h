/**
 * @COPYRIGHT DASSAULT SYSTEMES 2009
 */
/* -*-c++-*- */
//===========================================================================
//
// Ensemble de Topologies 
//
// Nov. 2009   Creation                            JJ3
//
//===========================================================================

#ifndef  CATTopologiesSetForFastRun_h
#define  CATTopologiesSetForFastRun_h

#include "CATHashTableWithIntAssoc.h"
#include "CATTopDefine.h"

class CATTopology;
class CATBody;
class CATTopData;
class CATPartitionManager;
class CATCGMHashTableWithAssoc;


class CATTopologiesSetForFastRun
{
  public:
    
    CATTopologiesSetForFastRun(CATTopology *iTopo, int iLevel, CATCGMHashTableWithAssoc * iVirtualEdgesHT1 = NULL, CATCGMHashTableWithAssoc * iVirtualEdgesHT2 = NULL);
    ~CATTopologiesSetForFastRun();

    CATTopologiesSetForFastRun * GetPartition(CATPartitionManager * iPartitionHT, int iPartitionToFind);
    CATTopologiesSetForFastRun * GetPartition(CATPartitionManager * iPartitionHT, int iPartitionToFind1, int iPartitionToFind2);
    int Size();
    CATTopologiesSetForFastRun(int iLevel, int estimatedSize = 0);
    CATTopology * GetItem(int iElem);
    int GetAssoc(int iElem);
    void Insert(CATTopology * iElem, int iAssoc);
    CATCGMHashTable * CreateObjectFromElements(CATBody * iBody, CATLocation iLocation, CATTopData  &iTopData);
    CATBoolean Contains(CATTopology * iElem);
    inline const int GetLevel() const { return _Level; }

    
  private :

    void ComputeElements(CATTopology *iTopo, int iLevel);


    CATHashTableWithIntAssoc * _Elements;
    int                        _Level;

};

#endif
