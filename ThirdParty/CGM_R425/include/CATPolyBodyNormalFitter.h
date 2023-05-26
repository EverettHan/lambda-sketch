
//===================================================================
// COPYRIGHT Dassault Systemes 2016
//===================================================================

#ifndef CATPolyMeshNormalFitter_H
#define CATPolyMeshNormalFitter_H

#include "CATPolyCanonicOperators.h"

#if defined(_WINDOWS_SOURCE) || defined(_LINUX_SOURCE)

class CATPolyBody;

/**
 *	Segment each face of a Polybody to compute new faces fitted on a plane.
 *  Plane normal will be assigned to the new faces
 *  @warning not defined for AIX
 *  
 */
class ExportedByCATPolyCanonicOperators CATPolyBodyNormalFitter 
{
public:
    CATPolyBodyNormalFitter();

    virtual ~CATPolyBodyNormalFitter();

    /**
     * @brief Run
     *
     * @param iPolyBody input
     * @param oPolyBody output owned by the caller
     *
     */
    void Run( CATPolyBody& iPolyBody, CATPolyBody*& oPolyBody );

    /**
     * @brief Provide a tolerance to fit planes in degrees
     *
     * @param iV tolerance 
     *
     */
    inline void SetFittingTolerance( double iV )
    {
        m_Tolerance = iV;
    }

    /**
     * @brief Minimum triangle on a face to process
     * Using this threshold avoid faces of one or two triangles
     * All planes fitted less than iV triangles will be put in a unique face
     *
     * @param iV 
     *
     */
    inline void SetMinimumTriangles( unsigned iV )
    {
        m_MinTriangles = iV;
    }

private :

    double m_Tolerance;
    unsigned m_MinTriangles;

};

#endif

#endif
