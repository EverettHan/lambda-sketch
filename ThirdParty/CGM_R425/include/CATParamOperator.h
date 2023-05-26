// COPYRIGHT Dassault Systemes 2003
//===================================================================
//
// CATParamOperator.h
// Header definition of CATParamOperator
//
// This class represents an operator that takes a 3d triangulation 
// and computes (u, v) parameters for each vertex of the mesh. It is 
// based on the article entitled "Surface Parameterization for Meshing 
// by Triangulation Flattening" by A. Sheffer and E. de Sturler, 9th 
// Intl. Meshing Roundtable, pp. 161-172, 2000. 
//
// Usage notes :
//
//	Two methods are provided to get the result:
//		* C0 evaluator (prefered): return 3d coordinates associated 
//		  to (u,v) parameters.
//		* Basic method : for each vertex of the triangulation, get
//		  the corresponding (u,v) parameters.
//		
//===================================================================
// 
//===================================================================
//
//  Jan 2003  Creation: LLR
//===================================================================
// Jun  2011   JSX : add SetWeights 
// Oct  2008   KTU : Add GetXYZForUV with tolerance and information about the result
// Oct  2004   KTU : Integration  of   LLR/SUH improvements
//                   Versionning  of modifications
// Sept 2003   KTU : - Progress Bar integration 

#ifndef CATParamOperator_H
#define CATParamOperator_H

#include "MathMeshParam.h"
#include "CATDataType.h"

#include "CATListOfInt.h"
#include "CATListOfDouble.h"

#include "CATIAV5Level.h"
#include "CATBoolean.h"

class CATParamImplementation;
class CATSoftwareConfiguration;
class CATTolerance;
class CATCGMProgressBar;

#if defined(CATIAV5R23) || defined(CATIAR216)
class CATPolyMeshMappingFunction;
#endif

class ExportedByMathMeshParam CATParamOperator
{
  public: 


  /*
   * Standard constructor
   * 
   * The <tt>i</tt>'th triangle is described by :<br><tt>
   * <ul>
   * <li>iTriangles[3*i+0]
   * <li>iTriangles[3*i+1]
   * <li>iTriangles[3*i+2]
   * </ul>
   * The neighbors of the <tt>i</tt>'th triangle are:<br><tt>
   * <ul>
   * <li>iNeighbors[3*i+0]
   * <li>iNeighbors[3*i+1]
   * <li>iNeighbors[3*i+2]
   * </ul> 
   * Neighbors' information is redundant but since almost all 
   * triangulation data storage provide a way to compute it, we 
   * prefer to take it as an input rather then computing it ourselves.
   * The <tt>i</tt>'th vertex's coordinates are:<br><tt>
   * <ul>
   * <li>iCoordinates[3*i+0]
   * <li>iCoordinates[3*i+1]
   * <li>iCoordinates[3*i+2]
   * </ul> 
   * <tt>ipConfig</tt> Software configuration.
   */

	CATParamOperator(
		  int * iTriangles, int * iNeighbors, double * iCoordinates,
		  const int iNbTriangles, const int iNbVertices,
		  CATSoftwareConfiguration * ipConfig
		  ,const int iLevel=3 );


	 // @ BEGINDEPRECATED CONSTRUCTORS
     CATParamOperator(int * iTriangles, int * iNeighbors, double * iCoordinates,
					  const int iNbTriangles, const int iNbVertices,
                  const  int  iLevel = 0 );

     // deprecated
     CATParamOperator(int * iTriangles, int * iNeighbors, float * iCoordinates,
					  const int iNbTriangles, const int iNbVertices,
                  const  int  iLevel = 0 );

	 // @END DEPRECATED CONSTRUCTORS

	 //@NoDoc
	 // For internal only ,  can be removed
	CATParamOperator(CATSoftwareConfiguration * ipConfig);
	void SetMesh(int * iTriangles, int * iNeighbors, double * iCoordinates,
		const int iNbTriangles, const int iNbVertices);


	 virtual ~CATParamOperator();

	 /*
	 * ConstrainBorderExtremities
	 * This method allows the user to constrain mesh borders extremities on their projected position
	 * Extremities are defined by vertices around which the angle is >= PI + deltaAngle or <= PI - deltaAngle
	 *
	 * Return value <br><tt>
	 * <ul>
	 * <li> 0     : success
	 * <li> other : failure
	 * </ul>
	 */
	 int ConstrainBorderExtremities(double iDeltaAngle);


  /*
   * SetConstrainedUV
   * This method allows the user to constrain some vertices to given uv coordinates
   * It's recommended to use this instead of the version below.
   * iConstrainedVertices : list of the indices of constrained vertices
   * iConstrainedUVs :		list of the uv values of constrained vertices (2 double per vertex)
   * 
   * Return value <br><tt>
   * <ul>
   * <li> 0 : iVertex >= nbVertices or iVertex < 0
   * <li> 1 : OK
   * </ul> 
   */
	 int SetConstrainedUV(CATListOfInt * iConstrainedVertices, 
						  CATListOfDouble * iConstrainedUVs);
	 /** 
	 * To Impose uv-coodinates at nodes.
	 * It's recommended to use this instead of the version above without angles devifinition.
	 *  The angles will be estimated from the position constraints
	 * @param iConstrainedVtxIdx [in]
	 *   list of vertices’s indices
	 * @param iConstrainedVtxUV [in]
	 *   list of vertices’s uv-values size = 2*iConstrainedVtxIdx.Size()
	 * @param iConstrainedVtxAngles [in]
	 *   list of 2d angles(radian) around vertices size = iConstrainedVtxIdx.Size()
	 *
	 * Return value <br><tt>
	 * <ul>
	 * <li> 0     : success
	 * <li> other : failure
	 * </ul> 
	 */
	 int SetConstrainedUV(CATListOfInt * iConstrainedVtxIdx
		                  ,CATListOfDouble * iConstrainedVtxUV 
						  ,CATListOfDouble * iConstrainedVtxAngles);

	 /** 
	 * To Impose 2d angles arouns nodes.
	 *
	 * @param ilVtxIdx [in]
	 *   list of vertices’s indices
	 * @param ilVtxAngleValues [in]
	 *   list of 2d angles(radian) around vertices size = ilVtxIdx.Size()
	 *
	 * Return value <br><tt>
	 * <ul>
	 * <li> 0     : success
	 * <li> other : failure
	 * </ul> 
	 */
	 int SetAngleAroundVtx(CATListOfInt & ilVtxIdx
		                   ,CATListOfDouble & ilVtxAngleValues);

	 
	 /**
	 * SetUVBoxLowerCorner
	 * To define the lower corner of the resulting UVBox.
	 * @param iLowerCornerUV
	 * the coordinates uv of the lower corner
	 */
	 int SetUVBoxLowerCorner(const double iLowerCornerUV[2]);

	 /**
	 *
	 * <br><b>Requests if the  UVBoxLowerCorner option is set . see @SetUVBoxLowerCorner</b>:
	 * @return
	 *  TRUE if it sets and FALSE if not
	 */
	 CATBoolean IsDefinedUVBoxLowerCorner()const;

	 /**
	 *
	 * <br><b>To Retrieve the low conner coordinate set by @SetUVBoxLowerCorner</b>:
	 * @param oLowerCornerUV
	 *  the set  low conner coordinate
	 * @return
	 * 0 if successful and non-zero  if not
	 */
	 int GetUVBoxLowerCorner(double oLowerCornerUV[2])const;

	 /**
	 * SetUVBoxMaxLength
	 * To define the length of the largest UV directions.
	 * Do not change anisotropy (lengthU/lengthV) of the result.
	 * @param iLenght
	 * the Max(Umax-Umin, Vmax-Vmin) will be equal to the given value of iLenght.
	 */
	 int SetUVBoxMaxLength(const double iLenght);

	 /**
	 *
	 * <br><b>Requests if the  UVBoxMaxLength option is set . see @SetUVBoxMaxLength</b>:
	 * @return
	 *  TRUE if it sets and FALSE if not
	 */
	 CATBoolean IsDefinedUVBoxMaxLength()const;

	 /**
	 *
	 * <br><b>To Retrieve the length  set by @SetUVBoxMaxLength</b>:
	 * @param &oLenght
	 *  the set length
	 * @return
	 * 0 if successful and non-zero  if not
	 */
	 int GetUVBoxMaxLength(double &oLenght)const;


	/**
	* SetUVToInertiaPlane
	* Called, the uv directions will be matched to the principal directions of the 3D model
	* By default, the those directions are matched to the directions of the plane which minimizes the area of UV Box.
	* Return value <br><tt>
	* <ul>
	* <li> 0     : success
	* <li> other : failure
	* </ul> 
	*/
	int SetUVToInertiaPlane();

	/**  
	* SetBoxCenterAs 
	* Centered the Center of UV box to (@Param iU, @Param iV).
	* Not compatible with @SetUVBoxLowerCorner
	* Return value <br><tt>
	* <ul>
	* <li> 0     : success
	* <li> other : failure
	* </ul> 
	*/
	int SetBoxCenterAs(const double iU=0., const double iV=0. );


  /*
   * Run
   * iUVLimits : bounding box for (u,v) parameters:<br><tt>
   * CAUTION: DO NOT USE  WITH iUVLimits.( Do not keep the anisotropy)
   *          Use #SetTheLargestUVDirectionsLength and  #SetResultLowerCorner instead.
   *          to constrain the uvbox if necessary.
   * <ul>
   * <li>iUVLimits[0] : minimum u parameter
   * <li>iUVLimits[1] : minimum v parameter
   * <li>iUVLimits[2] : maximum u parameter
   * <li>iUVLimits[3] : maximum v parameter
   * </ul> 
   * if iUVLimits is NULL, the parameters will be computed so that
   * the mesh and its parameterization have approximately the same scale
   * CAUTIONSetTheLargestUVDirectionsLength
   * Return value <br><tt>
   * <ul>
   * <li> 0 : success
   * <li> 1 : failure
   * </ul> 
   */
	virtual  int Run(double * iUVLimits = 0);

  /*
   * GetUVLimits
   * Get the (u,v) bounding box represented by oUVLimits:<br><tt>
   * <ul>
   * <li>oUVLimits[0] : minimum u parameter
   * <li>oUVLimits[1] : minimum v parameter
   * <li>oUVLimits[2] : maximum u parameter
   * <li>oUVLimits[3] : maximum v parameter
   * </ul> 
   * <b>CAUTION:</b> parameters (u,v) inside the bounding box don't necessarly
   * belong to a triangle
   */
	 void GetUVLimits(double oUVLimits[4]);

	/*
	* GetXYZforUV: 
	* Get the 3d coordinates for parameters (u,v) if and only if the corresponding 2d is on mesh.
	* Return value :<br><tt>
	* <ul>
	* <li>0:  The (u,v) parameter doesn't match any point of the triangulation
	* <li>1: OK
	*/
	int GetXYZforUV(const double u, const double v, double &x, double &y, double &z);


	/*
	* GetXYZforUV: 
	* Get the 3d coordinates for parameters (u,v) 
	* The 3d result point corresponds to the 2d point  (u'v') on the  mesh such as distance( (u,v), (u'v') ) < iTol
	* The  method gives also the Index of the Triangle and the barycentrics coord of the point ( P = T0 + os*T0T1 + otT0T2 )
	* This method is equivalent to "int GetXYZforUV(const double u, const double v, double &x, double &y, double &z)", if it 's called with iTol<0.
	* IMPORTANT : Before the first call with iTol>0., The method InflateUVLimits must be called.
	* Return value :<br><tt>
	* <ul>
	* <li>0: The (u,v) parameter doesn't match any point of the triangulation with this tolerance
	* <li>1: OK
	*/

	int GetXYZforUV(const double iu, const double iv, const double  iTol,double &ox, double &oy, double &oz, int & oNumTri, double &os, double&ot );

	/*
	* GetXYZforUV: 
	* Get the all  3d coordinates for parameters (u,v). Right call in non bijective case.
	* The 3d result point corresponds to the 2d point  (u'v') on the  mesh such as distance( (u,v), (u'v') ) < iTol
	* The  method gives the Index of the Triangle and the barycentrics coord of the point ( P = T0 + os*T0T1 + otT0T2 )
	* So sizeof(olCoordST) = 2 x sizeof(olTrianglesIdx)
	* This method is equivalent to "int GetXYZforUV(const double u, const double v, double &x, double &y, double &z)", if it 's called with iTol<0.
	* IMPORTANT : Before the first call with iTol>0., The method InflateUVLimits must be called. Note that this method is time consuming
	* Return value :<br><tt>
	* <ul>
	* <li>0: The (u,v) parameter doesn't match any point of the triangulation with this tolerance
	* <li>1: OK
	*/
	int GetXYZforUV(const double u, const double v, const double  iTol, CATListOfInt &olTrianglesIdx, CATListOfDouble& olCoordST);

	/*
   * GetUVforVertex
   * Get the (u,v) parameters for the <tt>iVertex</tt>'th vertex
   * Return value :<br><tt>
   * <ul>
   * <li>0: iVertex >= nbVertices or iVertex < 0
   * <li>1: OK
   */
	int GetUVforVertex(const int iVertex, double &u, double &v);

	// @BEGINDEPRECATED 
	// Use SetCallback instead of
   /**
    * Set Callback function to update Progress Bar
    * iNbTops : 0<iNbTops<=100 : number of times to call iFunc.
    * WARNING : iFunc will be called EXACTLY iNbTops times.
    */
   int SetProgressBarEvolFunction(  void (*iFunc)(), unsigned short iNbTops );
   // @END DEPRECATED 


   /**
    * Set Callback function to update Progress Bar
    */
   void SetCallback( CATCGMProgressBar *ipProgressBar );

  /*
   * ComputeDistortion: 
   * Compute the distortion and return the distortion limits
   * Distortion is computed as the quotient of 2d value by 3d value.
   * <ul>
   * <li> a value of 1 means no distortion
   * <li> a value lower than 1 means 2d lengths (or angles, or areas) are smaller in 2d than in 3d
   * <li> a value greater than 1 means 2d lengths (or angles, or areas) are greater in 2d than in 3d
   * iType <br><tt>
   * <ul>
   * <li>0: Length distortion
   * <li>1: Angle distortion
   * <li>2: Area distortion
   * Returns the min and max of distortion as well as the median value
   * Return value :<br><tt>
   * <ul>
   * <li>0: Non available type of distortion
   * <li>1: OK
   *
   */
   int ComputeDistortion(int iType, double & minDistortion, double & maxDistortion, double & medianDistortion);

  /*
   * GetDistortionforUV: 
   * Get the distortion value for parameters (u,v) 
   * The type of distortion is defined by the last call of the method ComputeDistortion
   * Return value :<br><tt>
   * <ul>
   * <li>0: (u,v) parameters don't correspond to a point on the triangulation or no distortion values available
   * <li>1: OK
   */
   int GetDistortionforUV(const double u, const double v, double &distortion);

  /*
   * GetDistortionforVertex: 
   * Get the distortion value for the <tt>iVertex</tt>'th vertex
   * The type of distortion is defined by the last call of the method ComputeDistortion
   * Return value :<br><tt>
   * <ul>
   * <li>0: iVertex >= nbVertices or iVertex < 0 or no distortion values available
   * <li>1: OK
   */
   int GetDistortionforVertex(const int iVertex, double &distortion);

  /*
   * ApplyCorrectionRatio: 
   * Apply a scaling ratio to the result in order to control the distribution of distortion
   * Returns the new min, max and median distortion values.
   * Type of distortion should be length or area. No correction ratio is provided for angular distortion.
   * Special values for <tt>iRatio</tt> 
   * <ul>
   * <li> 1./minDistortion:		Scale the mesh so that there is only positive distortion (distortion > 1.)
   * <li> 1./maxDistortion:		Scale the mesh so that there is only negative distortion (distortion < 1.)
   * <li> 1./medianDistortion:	Scale the mesh so that distortion is evenly distributed 
   * Return value :<br><tt>
   * <ul>
   * <li>0: no distortion values available or type of distortion = angle
   * <li>1: OK
   */
   int ApplyCorrectionRatio(double iRatio, double & minDistortion, double & maxDistortion, double & medianDistortion);

  /*
   * DistributeDistortion: 
   * Apply a scaling ratio to the result in order to control the distribution of distortion
   * Returns the new min, max and median distortion values.
   * Type of distortion should be length or area. No correction ratio is provided for angular distortion.
   * <tt>iRatio</tt> is a value in [0,1] that gives the percentage of distortion values greater than one.
   * Examples :
   * <ul>
   * <li> 0 : corresponds to only shrinking (i.e. the distortion at all points is < 1). 
   *          This means that the flattened body is smaller than the  input body.
   * <li> 1 : corresponds to only stretching (i.e. the distortion at all points is > 1). 
   *          This means that the flattened body is larger than the  input body.
   * <li> .5 : corresponds to even distortion (i.e. the distortion at all points is > 1). 
   *          This means that the flattened body is larger than the  input body.
   * An intermediate value, say 0.85 means 85% points have stretching distortion
   * Return value :<br><tt>
   * <ul>
   * <li>0: no distortion values available or type of distortion = angle
   * <li>1: OK
   */
   int DistributeDistortion(double iPercentage, double & minDistortion, double & maxDistortion, double & medianDistortion);

	 
	 /*
	 * InflateUVLimits: 
	 * Inflate the 2D box. the new bound is 
	 * [umin-0*5iInflateRatio*(umax-umin), umax+0*5iInflateRatio*(umax-umin)] x [vmin-0*5iInflateRatio*(vmax-vmin), vmax+0*5iInflateRatio*(vmax-vmin)]
	 * This method must be called before retrieval of x, y, z from u,v with tol>0..
	 * IMPORTANT : This Re-initialize of tools which are expensive. So must be called Once.
	 * Return value :<br><tt>
	 * <ul>
	 * <li>0: success
	 * <li>1: failure
	 */
   	 int InflateUVLimits( const double iInflateRatio ); 


	
	// Used if  you  assume  it .
	void AcceptInternalBoundarie( CATBoolean iAccept ) ;

	/**
	* @ DEPRECATED :  Use CheckOverlap instead
	* <br><b>Tell if the result is twisted or not. This has a sense if the method Run successed</b>: 
	* @param oIsTwisted [out]
	* @return
	* <ul>
	* <li>0: success
	* <li>1: failure
	*/
	int IsTwisted( CATBoolean & oIsTwisted );

	
	/**
	*
	* <br><b>Indicates where to seach the overlap. 
	*<br><b>Legal values</b>:
	* <dl>
	*     <dt>CheckInnerOverlap</dt>        <dd>the search is done in the interior.</dd>
	*     <dt>CheckBoundaryOverlap</dt>     <dd>the search is done on the boubdary.</dd>
	*     <dt>CheckBoth</dt>     <dd>the search is done on the boubdary and in the interior.</dd>
	* </dl>
	*/
	enum OverlapType{
		CheckInnerOverlap   = 0x01,
		CheckBoundaryOverlap  = 0x02,
		CheckBoth = 0x03
	};

	/**
	*
	* <br><b>Checks if the result overlaps </b>: 
	* @param iType
	* Indicates where to seach the overlap. Refer to the definition of <b>OverlapType</b> .
	* @param &oIsOverlapped
	* <b>TRUE</b> if there is overlaps and  <b>FALSE</b> if not
	* @param *iopBoundaryOvelapVertices
	* if it is not NULL and the  option <b>CheckBoundaryOverlap</b> is required, It'll contain the vertices 
	* representing the edges which overlap. Its size is a multiple of 4. Each a quadruple vertices represents
	* two intersecting edges and each couple of vertices represents an edge..
	* @param *iopInnerOverlapVertices
	* it is not NULL and the  option <b>CheckInnerOverlap</b> is required, It'll contain the vertices locating an overlaps area.
	* @return
	*   <dl>
	*     <dt>0</dt>        <dd>Succes.</dd>
	*     <dt>non-zero</dt> <dd>Failure.</dd>
	*   </dl>
	*/
	int CheckOverlap(OverlapType iType, CATBoolean &oIsOverlapped, CATListOfInt *iopBoundaryOvelapVertices, CATListOfInt *iopInnerOverlapVertices);

  /**
   * Set the Weights 
   * ! a vertex can be on different surfaces with different strains.
   *  so the strain is define for each angle of a triangle
   * When using this methode, the weight is directly used in the minimization
   * the internal (relative ponderation) is not apply.
   * The order is {Wa1g1, Wa2g1, Wa3g1, Wa1g2, Wa2g2, Wa3g2, Wa1g3,....,Wa3gn}
   *  Wa1g2 is the weigt for the angle 1 of triangle 2 
   */
  int SetWeights(double *iStrainForEachAngle,CATLONG32 iUseOfAreaWeight, CATLONG32 iScaleOneOnFlatArea);

#if defined(CATIAV5R23) || defined(CATIAR216)
  /** 
  * Call ResultAsFunction, if you want the result as a function @GetMappingFunction
  */
  void ResultAsFunction (); 	

  
	/** 
	* Return the mapping function between the  inpout mesh and the result mesh.
	* <br> Call AddRef on it to make it valid after calling the constructor of this. And  Release afetr use.
	* <br> <b> BE CARE that any modifications of the resultats by any "apply"Distortion are not take by the function: .
	* in this case you must create the onction by yourself
	* @return
	*   the  pointer on the  function.
	*/
  CATPolyMeshMappingFunction* GetMappingFunction (); 

	/** 
	* Call IsRegular, if you dont want the scaling the scaling done after the computation. In particulary, 
	* if the input mesh is regular and whithout holes .
	* <br> If  yo don't know,  call it  and make the correction by calling ComputeDistortion and ApplyCorrectionRatio
	*/
  void IsRegular (); 
#endif

  private:
	  // Copy forbidden
	  CATParamOperator(const CATParamOperator& iCopy);
	  CATParamImplementation * _paramImpl;
	 
	  
};

#endif
