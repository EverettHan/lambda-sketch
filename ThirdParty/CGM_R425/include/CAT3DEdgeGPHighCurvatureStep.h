#ifndef CAT3DEdgeGPHighCurvatureStep_H
#define CAT3DEdgeGPHighCurvatureStep_H

 //******************************************************************************
 //  Abstract:
 //  ---------
 //	   Internal USE
 //    To be used only by NRE and SG teams. This class is designed to be used for 
 //	   high curvature step edges view mode which is based on a requirement by TMC.
 //
 //******************************************************************************
 //  Inheritance:
 //  ------------
 //				CAT3DEdgeGPHighCurvatureStep
 //                CAT3DEdgeGP
 //                  CATGraphicPrimitive
 //                    CATBaseUnknown (SYSTEM framework)
 //
 //******************************************************************************


#include "SGInfra.h"
#include "CAT3DEdgeGP.h"

class CATStreamer;

/**
 * Class to create the graphic primitive of a 3D edge with high curvature step.
 */
class ExportedBySGInfra CAT3DEdgeGPHighCurvatureStep final : public CAT3DEdgeGP
{
	CATDeclareClass;
	CATVizDeclareClass;

public:

	CAT3DEdgeGPHighCurvatureStep(void);

	/**
	 * Constructs a 3D edge graphic primitive with high curvature step from the two faces it belongs to,
	 * its vertices indices and their number.
	 * @param iFace1
	 *    The first face the edge belongs to. This face shares vertices
	 *    informations with the edge.
	 * @param iFace2
	 *    The second face the edge belongs to. This face can be set to NULL if
	 *    doesn't exist.
	 * @param iVerticesIndices
	 *    Edge vertices indices array, taken from the first face. This means that these
	 *    indices allow to access vertices coordinates only through first face data.
	 * @param iNbVertices
	 *    The number of vertices in the edge.
	 */
	CAT3DEdgeGPHighCurvatureStep(CAT3DBoundingGP *iFace1, CAT3DBoundingGP *iFace2,
		int const *iVerticesIndices, int iNbVertices);

	/**
	 * @nodoc
	 * Streaming
	 */
	virtual void Stream(CATStreamer& oStr, int iSaveType = 0);

	/**
	 * @nodoc
	 * Streaming
	 */
	virtual void UnStream(CATStreamer& iStr);

protected:

	virtual ~CAT3DEdgeGPHighCurvatureStep(void);
};


#endif
