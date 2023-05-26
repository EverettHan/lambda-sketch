// COPYRIGHT DASSAULT SYSTEMES 2022, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyTriangleSelector.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// January 2022 Creation: GH7
//===================================================================
#ifndef CATPolyTriangleSelector_h
#define CATPolyTriangleSelector_h

#include "CATPolyRegularizeOperators.h"
#include "CATMathPoint.h"

#include "CATListOfInt.h"
#include "CATPolyRefCounted.h"
#include "CATCGMSharedPtr.h"

class CATIPolyMesh;
class CATPolyTriangleSelector;

/**
 * @brief return the list of triangle index that match a selection criteria
 * */
CATListOfInt ExportedByCATPolyRegularizeOperators CATPolyTriangleSelectorRun(const CATIPolyMesh &iMesh, CATPolyTriangleSelector &iSelector);

/**
 * @brief CATPolyTriangleSelector that must be implemented by user to define which triangle must be select.
 * **/
class ExportedByCATPolyRegularizeOperators CATPolyTriangleSelector : public CATPolyRefCounted
{
public:
    /**
     * @brief must be implement to select triangle based on user criteria like area, lenght, shape factor
     * @param[in] iT index of the triangle to check
     * @param[in] iVertexID indexes of the vertex associate to the triangle
     * @param[in] iVertexCoord coordinates of the vertex associate tot the triangle
     * @return true if the triangle must be selected
     **/
    virtual bool Select(
        const int &iT,
        const int iVertexID[3],
        const CATMathPoint iVertexCoord[3],
        const CATIPolyMesh &iOriginalMesh) = 0;

    typedef CATCGMSharedPtr<CATPolyTriangleSelector> SPtr;
};


/////////////////////////////////////////////////////////////////////
//// Implementation of logical Selector OR,AND, NOT
/////////////////////////////////////////////////////////////////////


/**
 * Composition of CATPolyTriangleSelector via Or
 **/
class ExportedByCATPolyRegularizeOperators CATPolyTriangleSelectorLogicalOr : public CATPolyTriangleSelector
{
    public:
    typedef CATCGMSharedPtr<CATPolyTriangleSelectorLogicalOr> SPtr;
    CATPolyTriangleSelectorLogicalOr(CATPolyTriangleSelector::SPtr &iA, CATPolyTriangleSelector::SPtr &iB) : _A(iA), _B(iB){

                                                                                                              };
    virtual bool Select(
        const int &iT,
        const int iVertexID[3],
        const CATMathPoint iVertexCoord[3],
        const CATIPolyMesh &iOriginalMesh)
    {
        bool resu = (_A->Select(iT, iVertexID, iVertexCoord, iOriginalMesh) || _B->Select(iT, iVertexID, iVertexCoord, iOriginalMesh));
        return resu;
    };
    CATPolyTriangleSelector::SPtr _A;
    CATPolyTriangleSelector::SPtr _B;
};

/**
 * Composition of CATPolyTriangleSelector via And
 **/
class ExportedByCATPolyRegularizeOperators CATPolyTriangleSelectorLogicalAnd : public CATPolyTriangleSelector
{
    public:
    typedef CATCGMSharedPtr<CATPolyTriangleSelectorLogicalAnd> SPtr;
    CATPolyTriangleSelectorLogicalAnd(CATPolyTriangleSelector::SPtr &iA, CATPolyTriangleSelector::SPtr &iB) : _A(iA), _B(iB){

                                                                                                                      };
    virtual bool Select(
        const int &iT,
        const int iVertexID[3],
        const CATMathPoint iVertexCoord[3],
        const CATIPolyMesh &iOriginalMesh)
    {
        bool resu = (_A->Select(iT, iVertexID, iVertexCoord, iOriginalMesh) && _B->Select(iT, iVertexID, iVertexCoord, iOriginalMesh));
        return resu;
    };
    CATPolyTriangleSelector::SPtr _A;
    CATPolyTriangleSelector::SPtr _B;
};

/**
 * Composition of CATPolyTriangleSelector via Not
 **/
class ExportedByCATPolyRegularizeOperators CATPolyTriangleSelectorLogicalNot : public CATPolyTriangleSelector
{
    public:
    typedef CATCGMSharedPtr<CATPolyTriangleSelectorLogicalNot> SPtr;
    CATPolyTriangleSelectorLogicalNot(CATPolyTriangleSelector::SPtr &iA) : _A(iA){

                                                     };
    virtual bool Select(
        const int &iT,
        const int iVertexID[3],
        const CATMathPoint iVertexCoord[3],
        const CATIPolyMesh &iOriginalMesh)
    {
        bool resu = !(_A->Select(iT, iVertexID, iVertexCoord, iOriginalMesh));
        return resu;
    };
    CATPolyTriangleSelector::SPtr _A;
};


/////////////////////////////////////////////////////////////////////
//// Implementation of logical Selector based on geometry Area
/////////////////////////////////////////////////////////////////////

/**
 * Abstract selector that select a triangle based on a value if the value is inside an interval
 * */
class ExportedByCATPolyRegularizeOperators CATPolyTriangleSelectorIntervalValue : public CATPolyTriangleSelector
{
    
    public:
    typedef CATCGMSharedPtr<CATPolyTriangleSelectorIntervalValue> SPtr;

    void SetInterval(double iMin, bool iMinIncluded,
                     double iMax, bool iMaxIncluded)
                     {
                         _Min=iMin;
                         _Max=iMax;
                         _MinIncluded = iMinIncluded;
                         _MaxIncluded = iMaxIncluded;
                     }
    //must be overide by children class;
    virtual double ComputeValue(
        const int &iT,
        const int iVertexID[3],
        const CATMathPoint iVertexCoord[3],
        const CATIPolyMesh &iOriginalMesh) = 0;

    virtual bool Select(
        const int &iT,
        const int iVertexID[3],
        const CATMathPoint iVertexCoord[3],
        const CATIPolyMesh &iOriginalMesh)
    {
        double value = ComputeValue(iT, iVertexID, iVertexCoord, iOriginalMesh);
        bool biggerThanMin =  _MinIncluded? value>= _Min : value>_Min;
        bool lesserThanMax =  _MaxIncluded? value<= _Max : value<_Max;
        bool resu = biggerThanMin && lesserThanMax;
        return resu;
    };


    protected:
    double _Min=0;
    double _Max=0;
    double _MinIncluded = true;
    double _MaxIncluded = true;
};

/**
 * Select triangle based on area and interval
 * */
class ExportedByCATPolyRegularizeOperators CATPolyTriangleSelectorIntervalArea : public CATPolyTriangleSelectorIntervalValue
{
    public:
    virtual double ComputeValue(
        const int &iT,
        const int iVertexID[3],
        const CATMathPoint iVertexCoord[3],
        const CATIPolyMesh &iOriginalMesh);
};
/**
 * Select triangle based on shape factor and interval
 * */
class ExportedByCATPolyRegularizeOperators CATPolyTriangleSelectorIntervalShapeFactor : public CATPolyTriangleSelectorIntervalValue
{
    public:
    virtual double ComputeValue(
        const int &iT,
        const int iVertexID[3],
        const CATMathPoint iVertexCoord[3],
        const CATIPolyMesh &iOriginalMesh);
};

/**
 * Select triangle based on edge length  and interval
 * */
class ExportedByCATPolyRegularizeOperators CATPolyTriangleSelectorIntervalEdgeLength : public CATPolyTriangleSelectorIntervalValue
{
    public:
    /**
     * active a mode to use the bigest edge, by default selector look the smallest;
     * */
    void SetMode(bool iUseBigest=false);
    virtual double ComputeValue(
        const int &iT,
        const int iVertexID[3],
        const CATMathPoint iVertexCoord[3],
        const CATIPolyMesh &iOriginalMesh);
    protected:
        bool _useBigest=false;
};

/**
 * Select triangle based on height length  and interval
 * */
class ExportedByCATPolyRegularizeOperators CATPolyTriangleSelectorIntervalHeightLength : public CATPolyTriangleSelectorIntervalValue
{
    public:
    virtual double ComputeValue(
        const int &iT,
        const int iVertexID[3],
        const CATMathPoint iVertexCoord[3],
        const CATIPolyMesh &iOriginalMesh);

};

#endif
