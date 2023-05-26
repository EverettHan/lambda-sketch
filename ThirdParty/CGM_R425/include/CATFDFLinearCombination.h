// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2016
//
#ifndef CATFDFLinearCombination_h
#define CATFDFLinearCombination_h

#include "InfraMorph.h"

#include "CATMathMarshFunction.h" // Pour la definition de cat_fpoint
#include "CATMathStream.h"
#include "CATStreamMapFunctionXYZ.h"
#include "CATMathVector.h"


class CATSoftwareConfiguration;
class CATMapFunctionXYZ;




class ExportedByInfraMorph CATFDFLinearCombination : public CATStreamMapFunctionXYZ
{


public:
	CATFDFLinearCombination(int iNbOfMap, CATMapFunctionXYZ   **  iMapArray,const double* iCfArray, CATSoftwareConfiguration* iConfig=NULL);
	~CATFDFLinearCombination();

  int Init(  CATMapFunctionXYZ   ** iMapArray, const double* iCfArray);

  void RAZ();

	CATBoolean IsAKindOf(const char*) const;

	CATBoolean IsALinearMap() const;

	
 // CATBoolean IsModelDependant() const;
  //int GetDeformationAlongNormal() const;
  //void SetDeformationAlongNormal(const int iOrientation);

//	CATLONG32 SetPreTransfo(const CATMathTransformation& iTrsf,  const CATMathTransformation* inverseTrsf=NULL);
//  int SetCorrection(const CATMathVector& iTranslation);


	CATLONG32 GetMathTransformation(CATMathTransformation & oTransformation) const;

	CATLONG32 Eval(const CATMathPoint& iPInitial,
			            CATMathPoint & oPModified) const;

	CATLONG32 EvalFirstDeriv(const CATMathPoint& iPInitial, 
						CATMathVector& oDu, 
						CATMathVector& oDv,
						CATMathVector& oDw) const;
	CATLONG32 EvalSecondDeriv(const CATMathPoint& iPInitial, 
						 CATMathVector& oD2u,
						 CATMathVector& oD2v,
						 CATMathVector& oD2w,
						 CATMathVector& oDuv,
						 CATMathVector& oDuw,
						 CATMathVector& oDvw) const;


	//// ALA 3
	//void EvalMesh(int ID,
	//		int iNumberOfFaces,
	//		int *iNumberOfVerticies,
	//		cat_fpoint **iVerticies,
	//		cat_fpoint **iNormals,
	//		cat_fpoint **oVerticies,
	//		cat_fpoint **oNormals);


	//	// Pour le MultiThreading
	//CATBoolean IsThreadSafe() const { return TRUE; }  
	//// Clone pour MultiThreading 
	//// return 1 : copy impossible
	//CATLONG32 Clone(CATMapFunctionXYZ * & oCopyMapFunctionXYZ, CATGeoFactory * ifactory) const;

	///** 
	//* Returns the number of sources in  the final resolution.		
	//*/
	//int GetNumberOfSources() const;

 // double GetSmoothFactor() const { return _SmoothFactor;}


	//  prevoir de le mettre en private  et de definir le Mproc en friend
	CATBoolean IsStreamable(const CATCGMStreamVersion iTargetVersion, CATBoolean & ioReversible )const;
	//CATFDFLinearCombination(CATGeoFactory* iFactory, CATSoftwareConfiguration * ipConfig, CATMathStream& ioRedaStream );
	void Stream( CATMathStream& ioWriteStream )const;
	
	//// master
	void GetPrerequisiteObjects( CATLISTP(CATICGMObject)& olObjects)const;

  int SetXScalingTransfert(double iScaleRatio);


private:


  //void Init(CATMathMarshFunction *f, CATSoftwareConfiguration* iConfig );

  //short GetLevelOfStream(const CATCGMStreamVersion iTargetVersion) const;

  int _NbOfMap;
  CATMapFunctionXYZ     **  _MapArray;  //MBP
  double *                   _CfArray;  //MBP (Must be Persistent)


};

#endif
