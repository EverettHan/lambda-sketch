#ifndef CATVisClippingVolume_H
#define CATVisClippingVolume_H

//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2016
//-----------------------------------------------------------------------------
// Class  :  	CATVisClippingVolume
// Date   :  	18/01/16
//-----------------------------------------------------------------------------
//  Inheritance : CATVisClippingVolumesFilter
//					CATVisFilter
//-----------------------------------------------------------------------------
//  Abstract : EXPERIMENTAL, NO SUPPORT!
//             DO NOT USE WITHOUT ASKING TO RENDER ENGINE TEAM!
//-----------------------------------------------------------------------------
//  Main Methods : N/A
//-----------------------------------------------------------------------------

// Local Framework
#include "SGInfra.h"

#include "CATDataType.h"
#include "CATSysErrorDef.h"
#include "CATMathPoint.h"
#include "CATMathVector.h"
class l_CATVisClippingVolume;


class ExportedBySGInfra CATVisClippingVolume
{
public:
  struct TriangleIndices
  {
    // Given indices must be counter clock wise for triangle orientation.
    unsigned int ccwIndices[3];
  };
  static CATVisClippingVolume* Create(const CATMathPoint* iVertices, unsigned int iVertCount, const TriangleIndices* iTriangles, unsigned int iTriCount);

  void AddRef();
  void Release();

	unsigned int GetVerticesCount() const;
	const CATMathPoint* GetVertices() const;
	HRESULT GetVertex(unsigned int iVertInd, CATMathPoint& oPoint) const;
  
  class Triangle
  {
  public:
    Triangle() : padding(0) { indices[0] = 0; indices[1] = 0; indices[2] = 0; }
    Triangle& operator=(const Triangle& iSrc)
    {
      normal = iSrc.normal;
      indices[0] = iSrc.indices[0];
      indices[1] = iSrc.indices[1];
      indices[2] = iSrc.indices[2];
      return *this;
    }
  
    CATMathVector normal;
    unsigned int indices[3];

  private:
    const unsigned int padding;
  };
  unsigned int GetTrianglesCount() const;
  const Triangle* GetTriangles() const;
  HRESULT GetTriangle(unsigned int iTriInd, Triangle& oTriangle) const;

  CATULONG32 ComputeCheckValue(unsigned int iCheckValVersion = 0) const;

protected:
	CATVisClippingVolume();
	virtual ~CATVisClippingVolume();

  inline l_CATVisClippingVolume& GetLetter() const { return *_pLetter; };

private:
	l_CATVisClippingVolume* _pLetter;
	unsigned int _nRef;
};

#endif
