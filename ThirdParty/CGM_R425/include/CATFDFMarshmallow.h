// COPYRIGHT DASSAULT SYSTEMES PROVENCE 2000
//
// Auteur  : Nicolas Lafont, le 9/05/2000
// Classe qui definit une deformation de R3 dans R3
//           version CATIA


#ifndef CATFDFMarshmallow_h
#define CATFDFMarshmallow_h

#include "InfraMorph.h"

#include "CATMathMarshFunction.h" // Pour la definition de cat_fpoint
#include "CATMathStream.h"
#include "CATStreamMapFunctionXYZ.h"
#include "CATMathVector.h"

class CATMathLine;
class CATSoftwareConfiguration;

//#define FDF_LineReference
//#define FDFMarsh_CheckDeriv


class ExportedByInfraMorph CATFDFMarshmallow : public CATStreamMapFunctionXYZ
{
private:
#ifdef FDFMarsh_CheckDeriv
  int CheckD1(const CATMathPoint& iPInitial, 
						CATMathVector& oDu, 
						CATMathVector& oDv,
						CATMathVector& oDw)const ;

  int CheckD2(const CATMathPoint& iPInitial, 
						CATMathVector& oD2u,
						 CATMathVector& oD2v,
						 CATMathVector& oD2w,
						 CATMathVector& oDuv,
						 CATMathVector& oDuw,
						 CATMathVector& oDvw) const;
#endif

   void Init(CATMathMarshFunction *f, CATSoftwareConfiguration* iConfig );

   short GetLevelOfStream(const CATCGMStreamVersion iTargetVersion) const;

	CATMathVector             _VAux[6];
  CATMathVector             _CenterTranslation; //for smoothing coorection //MBP
	CATMathMarshFunction *    _Function;  //MBP (Must be Persistent)
	CATMathTransformation*    _PreTransfo; //MBP 
	CATMathTransformation*    _InverseTransfo;
#ifdef FDF_LineReference
  CATMathLine *            _RefLine; //MBP (Must be Persistent) Necessite une nouvelle version du CGMStream!!
#endif
  #ifdef FDFMarsh_CheckDeriv
  CATBoolean _CheckD1;
#endif
  double _NativeMQCoeff; //MBP (Must be Persistent)
  double _SmoothFactor;  //MBP (Must be Persistent)
	short _IsOffset; //MBP (Must be Persistent)
  short _Level;    //MBP (Must be Persistent)

  
  //@KTU_Multithred_Begin
  //It is true only if the clone method is called
  //in this case 
  //CATBoolean _IsClone;
  //@KTU_Multithred_End
  

public:
	CATFDFMarshmallow(CATMathMarshFunction *f, CATSoftwareConfiguration* iConfig);
	~CATFDFMarshmallow();

	CATBoolean IsAKindOf(const char*) const;

	CATBoolean IsALinearMap() const;

	
  CATBoolean IsModelDependant() const;
  int GetDeformationAlongNormal() const;
  void SetDeformationAlongNormal(const int iOrientation);

	CATLONG32 SetPreTransfo(const CATMathTransformation& iTrsf,  const CATMathTransformation* inverseTrsf=NULL);
  int SetCorrection(const CATMathVector& iTranslation);

#ifdef FDF_LineReference
  int SetLineofReference(CATMathLine *  iRefLine);
#endif


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

#ifdef With_EvalThirdDeriv
	CATLONG32 EvalThirdDeriv(const CATMathPoint& iPInitial, 
						CATMathVector& oD3x, 
						CATMathVector& oD3y,
						CATMathVector& oD3z,
						CATMathVector& oD2xDy,
						CATMathVector& oD2xDz, 
						CATMathVector& oD2yDx,
						CATMathVector& oD2yDz,
						CATMathVector& oD2zDx, 
						CATMathVector& oD2zDy,
						CATMathVector& oD3xyz) const;
#endif


	// ALA 3
	void EvalMesh(int ID,
			int iNumberOfFaces,
			int *iNumberOfVerticies,
			cat_fpoint **iVerticies,
			cat_fpoint **iNormals,
			cat_fpoint **oVerticies,
			cat_fpoint **oNormals);


		// Pour le MultiThreading
	CATBoolean IsThreadSafe() const { return TRUE; }  
	// Clone pour MultiThreading 
	// return 1 : copy impossible
	CATLONG32 Clone(CATMapFunctionXYZ * & oCopyMapFunctionXYZ, CATGeoFactory * ifactory) const;

	/** 
	* Returns the number of sources in  the final resolution.		
	*/
	int GetNumberOfSources() const;

  double GetSmoothFactor() const { return _SmoothFactor;}


	//  prevoir de le mettre en private  et de definir le Mproc en friend
	CATBoolean IsStreamable(const CATCGMStreamVersion iTargetVersion, CATBoolean & ioReversible )const;
	CATFDFMarshmallow(CATGeoFactory* iFactory, CATSoftwareConfiguration * ipConfig, CATMathStream& ioRedaStream );
	void Stream( CATMathStream& ioWriteStream )const;
	//void UnStream( CATMathStream& ioStream );
	//// master
	void GetPrerequisiteObjects( CATLISTP(CATICGMObject)& olObjects)const;
	//void Finalize( CATGeoFactory * ipFactory, const CATSoftwareConfiguration* ipSoftwareConfiguration);

  int SetSmoothFactor(double iSmoothFactor);

  int SetXScalingTransfert(double iScaleRatio);
};

#endif
