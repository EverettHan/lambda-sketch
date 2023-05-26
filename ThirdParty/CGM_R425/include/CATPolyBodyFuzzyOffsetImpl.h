//===================================================================
// COPYRIGHT Dassault Systemes 2017/01/13
//===================================================================

#ifndef CATPolyBodyFuzzyOffsetImpl_H
#define CATPolyBodyFuzzyOffsetImpl_H

#include "CATPolyBodyFuzzyOffset.h"
#include "CATFuzzyPolyOper.h"

#include "CATTolerance.h"

class CATPolyBody;
class CATIPolyMesh;
class CATPolyMeshOffset;


/**
*	Performs a fuzzy offset on polybodies
*/
class ExportedByCATFuzzyPolyOper CATPolyBodyFuzzyOffsetImpl : public CATPolyBodyFuzzyOffset
{
public:

    CATPolyBodyFuzzyOffsetImpl( const CATTolerance & iTol = CATGetDefaultTolerance() );

    virtual ~CATPolyBodyFuzzyOffsetImpl();

    /**
     * @brief Initialize will parse each PolyBody and aggregate all the geometry into a PolyMesh to performs the fuzzy offset
     * Match CATPolyMeshOffset interfaces
     *
     * @param iPolyBodies             pointers over polybodies to process
     * @param iTransfos               pointers to possible positions (may be null)
     * @param iNPolyBodies            
     * @param iOffsetValue            offset value
     * @param iClientMaxDeviation     deviation to compute the offset
     * @param oDepth                  expected depth of the octree, high values could lead to serious computation overhead
     * @param iBothSide
     * @param iRoundedBorder
     * @param iTol
     *
     */
    HRESULT Initialize( CATPolyBody** iPolyBodies, const CATMathTransformation ** iTransfos, unsigned iNPolyBodies, double iOffsetValue, double iClientMaxDeviation, int& oDepth, int iBothSide = 0, int iRoundedBorder = 0 );

    /**
     * @brief Run
     *
     * @param oPolyBody
     *
     */
    HRESULT Run( CATPolyBody*& oPolyBody );

private:

    CATPolyBodyFuzzyOffsetImpl( CATPolyBodyFuzzyOffsetImpl & );

    CATPolyBodyFuzzyOffsetImpl& operator=( CATPolyBodyFuzzyOffsetImpl& );

    HRESULT AggregatePolyMesh( const CATPolyBody& iPolyBody , const CATMathTransformation * pPos);

    CATIPolyMesh*       m_InputMesh;
    CATIPolyMesh*       m_OutputMesh;
    CATPolyMeshOffset*  m_Offset;
    const CATTolerance& m_Tol;
};

#endif
