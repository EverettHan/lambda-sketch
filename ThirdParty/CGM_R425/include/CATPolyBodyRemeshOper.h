// COPYRIGHT Dassault Systemes 2009
//==============================================================================
//
// CATPolyBodyRemeshOper.h
// Header definition of CATPolyBodyRemeshOper
//
//==============================================================================
//
// Usage notes: 
//       Use to apply an Remesh to a CATIPolyMesh CGM Model. A new 
//       representation will be created.
//
//==============================================================================
//
//  Jul 2009  Creation: TG2
//==============================================================================
#ifndef CATPolyBodyRemeshOper_H
#define CATPolyBodyRemeshOper_H


#include "PolyBodyRemeshing.h"
#include "CATMapOfPtrPtrToPtr.h"
#include "CATPolyBodyVOCOper.h"
#include "CATPolyBuildMeshOper.h"
#include "CATMapOfPtrToPtr.h" 
class CATPolyMeshBoundaryOper;
class CATPolyBody;
class CATPolyFace;
class CATIPolyMesh;

/**
 * Operator that do the remeshing of a  CATPolyBody.
 * It generates a CATIPolyMesh.
 * 
 * Initial CATIPolyBody is first converted in a CATIPloyMesh using  CATPolyBodyToPolyMeshConverter operator
 *
 * 
 *
 */
#include <vector>
struct QuadriVector

{



	int T;
	double Alpha;
	double Beta;
	double Gamma;


};
class ExportedByPolyBodyRemeshing CATPolyBodyRemeshOper  
{
  

    public:

        //======================================================================
        // Constructor
        //======================================================================
        CATPolyBodyRemeshOper( CATPolyBody* iPolyBody );

        //======================================================================
        // Destructor
        //======================================================================
        virtual ~CATPolyBodyRemeshOper();

public :    
	/** @name Settings
	@{ */

	/**
	* Sets a flag to allow the decimation only (if true)  or to allow a complete remeshing (if false).
	* @param iOnlyDecimate
	*   The input flag .
	*  
	*/
	void SetOnlyDecimate(bool iOnlyDecimate);

	/**
	* Set a flag to allow the sharpness detection af Vertices .
	* @param iVertexSharpnessDetection 
	*   The input flag .
	*  (by default a vertex is said sharp if its first ring neighborhood has a bar which makes an angle with the normal at the vertex greater than PI/4. )
	* A sharp Vertex will be kept.
	*/
   void ActivateVertexSharpnessDetection(bool iVertexSharpnessDetection);
		
  /**
   * Set the vertex sharpness threshold. It can take values between  0 and  PI/2 .
   * If the first ring neighborhood of a vertex has a bar which makes an angle with the normal at the vertex greater than iMaxVertexSharpnessThreshold , the vertex is said sharp and will be kept. 
   * @param iMaxVertexSharpnessThreshold
   *   The input threshold .
   */
	void SetMaxVertexSharpnessThreshold(const double &iMaxVertexSharpnessThreshold);

   /**
   * Set the differential vertex sharpness threshold. It can take values between  0 and  PI/2.
   * If the difference of angle  , between the max angle between the bars and the normal , and ,  between the min angle between the bars and the normal,  is greater than iMaxMinVertexSharpnessThreshold , the vertex is said sharp and will be kept. 
   * @param iMaxMin VertexSharpnessThreshold
   *   The input threshold .
   */
   
	void SetMaxMinVertexSharpnessThreshold(const double &iMaxMinVertexSharpnessThreshold);

 

    /**
   * Set the level of Loop subdivision of the mesh after its previous decimation.
   * @param iLevelOfSubdivision
   */
        void SetLevelOfSubdivision(int ilevelOfSubdivision);

	/**
	* Sets a flag to allow the Laplacian smoothing of the resulting mesh (with a following projection of the result onto the original mes).
	* @param iLaplacianSmoothing .
	* Only non sharp vertex are "smoothed" 
	*   The input flag .
	*/              
        void ActivateLaplacianSmoothing(bool iLaplacianSmoothing);
/**
	* Sets a flag to allow the Laplacian smoothing of the resulting mesh (with a following projection of the result onto the original mes).
	* @param iLaplacianSmoothing .
	* Only non sharp vertex are "smoothed" 
	*   The input flag .
	*/      
        void  ActivateEdgeSharpnessDetection(bool iEdgeSharpnessDetection);

		void  ActivateGetTheReferenceMesh(bool iGetTheReferenceMesh );

		void ActivateTheFlip(bool iActivateTheFlip); 

		void SetBoundaryMapping(CATMapOfPtrPtrToPtr **iMap);
	/**
	* Run the Operator .
	*/         
        HRESULT Run();
    /**
	* Get the remeshed polymesh .
	*/        
		void GetResult(CATIPolyMesh *& ioPolyMesh);
   /**
	* Get the operator name
	*/  
         const char *  GetOperatorName();

//void  GetBodyResult(CATPolyBody * ioPolyBody);
void  GetBodyResult(CATPolyBody * ioPolyBody);
void GetBodyResult(CATPolyBody *& ioPolyBody,CATMapOfPtrToPtr *& ionversemap);
    private:

        bool  _VertexSharpnessDetection;

		bool  _LaplacianSmoothing;

		int    _SubdivisionLevel;

		bool _OnlyDecimate;

		CATIPolyMesh* _FinalMesh;

		CATIPolyMesh * _PolyMesh;

		CATPolyBody * _PolyBody;

        double _MaxVertexSharpnessThreshold;

		double _MaxMinVertexSharpnessThreshold;

		bool  _EdgeSharpnessDetection;

		HRESULT RunPolyMeshMode(); 

		HRESULT RunKeepEdgeMode();

		bool _GetTheReferenceMesh ;
		bool _ActivateTheFlip ;
		int _NbFaces ;
		CATIPolyMesh ** _TheMesh;
		CATMapOfPtrPtrToPtr **_BoundaryMapping;
		CATMapOfPtrToPtr _InverseMap;
		CATPolyFace **_TheFace;
		CATPolyBody * _ThePolyBody;
		void GetVertexLineFromBoundary(CATIPolyMesh* iMesh,CATPolyMeshBoundaryOper *BoundaryOper,int &Vdeb,int &Vfin,CATListOfInt &LesVertexLine);
int   CheckInvertion(int& Old_Vdeb,int &Old_Vfin, CATIPolyMesh *iMesh);
};

//-----------------------------------------------------------------------

#endif
