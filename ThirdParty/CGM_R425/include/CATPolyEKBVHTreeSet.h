// COPYRIGHT DASSAULT SYSTEMES 2013, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyEKBVHTreeSet.h
// Header definition of CATPolyEKBVHTreeSet
//
//===================================================================
//
// Usage notes: 
//
//===================================================================
//
// November 2013 Creation JXO
//===================================================================
#ifndef CATPolyEKBVHTreeSet_H
#define CATPolyEKBVHTreeSet_H

// ExportedBy
#include "PolyEKNodes.h"

// Poly 
#include "CATBVHTreeRepBuilder.h"
#include "CATMapOfIntToPtr.h"
#include "CATPolyVisuBVHTreeSet.h"
#include "CATPolyVisuOptimizedBVHTreeSet.h"
#include "CATPolyBVHTreeFilterHidden.h"
class CATPolyVisuClashContactOper;
#include "CATIPolyInterference.h"
class CATPolyCurveListIterator;
class CATPolyClashInterf;
class CATPolyContactInterf;
class CATPolyInterferenceList;


// Visu
#include "CAT3DRep.h"

// Math
class CATMathTransformation;

// Experience Kernel
#include "EKNode.h"
#include "EKNodeId.h"
#include "EKBinary.h"
namespace EK
{
  class BinaryWriter;
};
// using namespace EK;

// System
#include "CATMutex.h"
#include "CATErrorDef.h"
#include "CATUnicodeString.h"



// For traces in the nodes
#define CATPolyhedralClashNodeTraces



class ExportedByPolyEKNodes CATPolyEKBVHTreeSet : public EK::Node
{
public:
  /** Basic constructor */
  CATPolyEKBVHTreeSet(const CATUnicodeString& nodename = CATUnicodeString(""));
  /** Destructor */
  ~CATPolyEKBVHTreeSet();
  // Implementation of EK:Node
  // Treats messages sent to the BVHtrees and stores data into m_TreeSets
  HRESULT OnBinary(const EK::Binary & input, EK::Channel& origin);
  // Implementation of EK:Node. Does nothing appart from storing text into m_DebugText
  HRESULT OnText  (const CATUnicodeString& input, EK::Channel& origin);

protected:
  void FullReset();

  // Compression/Uncompression?
  EK::Binary Compress(const EK::Binary & iBin);
  EK::Binary Uncompress(const EK::Binary & iBin);


protected:
  int m_nodeid;

  // BVHTreeSets 
  CATMapOfIntToPtr m_TreeSets;

public:
  CATUnicodeString m_DebugText;
};


class CATPolyEKBVHTreeSetAndBag
{
public:
  CATPolyEKBVHTreeSetAndBag()
  {
    m_tree = new CATPolyVisuOptimizedBVHTreeSet;
    m_HiddenFilter = new CATPolyBVHTreeFilterHidden;
    m_tree->SetFilter(m_HiddenFilter);
  }
  ~CATPolyEKBVHTreeSetAndBag()
  {
    delete m_tree;
    m_tree = 0;
    m_HiddenFilter->Release();
    m_HiddenFilter = 0;
    CATMapOfIntToPtr::Iterator it(m_reps);
    for(it.Begin(); !it.End(); ++it)
    {
      CAT3DRep * pRep = (CAT3DRep*)it.GetData();
      if(pRep)
        pRep->Destroy();
      pRep = 0;
    }
  }
  CATMapOfIntToPtr m_reps;
  CATPolyVisuBVHTreeSet * m_tree;
  CATPolyBVHTreeFilterHidden * m_HiddenFilter;
};


#endif

