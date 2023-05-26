// COPYRIGHT DASSAULT SYSTEMES 2010 ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyFileSkinning.h
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
// Aug 2010 Creation: pmg
//===================================================================
#ifndef CATPolyFileSkinning_h
#define CATPolyFileSkinning_h

#include "CATPolyDeformOperators.h"

#include "CATBoolean.h"
#include "CATLISTV_CATMathPoint.h"
#include "CATListOfInt.h"
#include "CATListOfFloat.h"
#include "CATMathTransformation.h"
#include "CATMathPoint.h"
#include "CATUnicodeString.h"


class ExportedByCATPolyDeformOperators CATPolyFileSkinning
{

public:

  CATPolyFileSkinning ();

  ~CATPolyFileSkinning ();

  HRESULT ReadWeights (const CATUnicodeString & iWeightsFileName);

  HRESULT ReadSkeleton(const CATUnicodeString & iSkeletonFileName);

  HRESULT ReadAnimation(const CATUnicodeString & iAnimationFileName);

  HRESULT WriteWeights (const CATUnicodeString & iWeightsFileName) const;

  HRESULT WriteAnimation (const CATUnicodeString & iFileName) const ;

  HRESULT WriteSkeleton (const CATUnicodeString & iFileName) const;

  HRESULT PutWeightsInfo( const int iNbOfVerticies, const int iNbOfBone);

  HRESULT PutWeights(const int iNumVertex, const short iNbOfImpactingBone, 
                      const short* iNumBones, 
                      const float* iWeights);

  HRESULT PutSkeleton(const CATLISTV(CATMathPoint)& iJointPoints, const CATListOfInt& iPreviousNumJoint);

  HRESULT PutAnimationInfo(const int iNbFrames, const int iNbJoints);
  HRESULT PutJointAnimation(const int iNumFrame, const int iNumJoints, const float*);
  HRESULT PutTrsfJointAnimation(const int iNumFrame, const int iNumJoints, const CATMathTransformation& iTrsf);


  HRESULT GetWeightsInfo( int& oNbOfVerticies, int& oNbOfBone) const;

  HRESULT GetWeights(const int iNumVertex, short& oNbOfImpactingBone, 
                      const short*& oNumBones, 
                      const float*& oWeights) const;


  HRESULT GetAnimationInfo(int& oNbFrames, int& oNbJoints) const;
  HRESULT GetTrsfBoneAnimation(const int iNumFrame, const int iNumBone, CATMathTransformation& oTrsf) const;
  HRESULT GetTrsfJointAnimation(const int iNumFrame, const int iNumJoints, CATMathTransformation& oTrsf) const;

  CATBoolean HasSkeleton() const;
  HRESULT GetSkeleton(CATLISTV(CATMathPoint)& oJointPoints, CATListOfInt& oPreviousNumJoint) const;

  static HRESULT GetBoneTrsf(const CATMathPoint& iBeginPoint, 
                             const CATMathTransformation& iGlobalBeginTrsf, 
                             const CATMathPoint& iEndPoint, 
                             const CATMathTransformation& iGlobalEndTrsf, 
                              CATMathTransformation& oBoneTrsf);

private:
  int Read_Skeleton(const CATUnicodeString & iSkelfilename, CATLISTV(CATMathPoint)& oJointPoints, CATListOfInt& oPrevious) const;
  int Write_Skeleton(const CATUnicodeString& iSkeletonFileName) const;

  int Read_Weights(const CATUnicodeString & iWeightsfilename);
  int Write_Weights(const CATUnicodeString & iWeightsfilename) const;

  int Read_Animation(const CATUnicodeString & iAnimationfilename);
  int Write_Animation(const CATUnicodeString & iAnimationfilename) const;

  void CleanWeights();
  int AllocWeights();

  void CleanAnimation();

  //Skeleton
  CATLISTV(CATMathPoint) _RefJoin;
  CATListOfInt           _PreviousJoin;

  //Weights
  short* _NbOfImpactingBone;
  short** _NumBones;
  float** _BonesWeights;
  int _NbBonesForW;
  int _NbVerticiesForW;

  //Animation
  int _NbFrame;
  int _NbBonesToAnim;
  int _NbValuesByJoin;
  CATListOfFloat _DataAnimation;
  //CATBoolean _IsJoinAnimation;
  
};

#endif
