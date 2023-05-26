/* -*-C++-*- */
#ifndef CATPrContext_H
#define CATPrContext_H
// COPYRIGHT DASSAULT SYSTEMES 2011

//===================================================================
//===================================================================
//
// CATPrContext
// Algorithm Context dedicated to Pattern Recognition
//
//===================================================================
//===================================================================
// May 2011    Creation                         R. Rorato
//===================================================================

#include "CATCGMVirtual.h"
#include "CATCGMNewArray.h"
#include "CATPrRep.h"
#include "CATPrSet.h"
#include "CATListOfCATGeometries.h"
#include "CATMathInline.h"
#include "AdvOpeInfra.h"
#include "CATTrdOptions.h"

class CATSoftwareConfiguration;
class CATGeoFactory;
class CATLine;
class CATSurface;
class CATSphere;
class CATPoint;
class CATSurLimits;
class CATCGMProgressBar;
class CATMathTransformation;
class CATTextStampCGM;

//------------------------------------------------------------------------------
// Debug
//------------------------------------------------------------------------------
// SetCheck: auto-controle.
// SetTracedRep : active les traces pour une ou plusieurs Rep données. Utile pour analyser la comparaison géométrique de Reps. Editer CATPatternAdvancedRecognizer::RecognizeAllPatterns.
// SetTrace: active les traces pour une ou plusieurs composantes de l’algorithme. En plus des cgmout, on retrouve dans le e:\tmp les NCGM représentants les Sets et Patterns dans tous leurs états succéssifs.
// Activate CATCX_NCGM
//------------------------------------------------------------------------------
class ExportedByAdvOpeInfra CATPrContext : public CATCGMVirtual
{
  public:
  //------------------------------------------------------------------------------
  // Constructor
  //------------------------------------------------------------------------------
  CATPrContext(CATGeoFactory* iFactory, CATSoftwareConfiguration* iConfig, CATBody* iBody = NULL, CATCGMProgressBar* iProgressBar = NULL);
  CATPrContext();

  CATCGMNewClassArrayDeclare;        // Pool allocation

  //------------------------------------------------------------------------------
  // Destructor
  //------------------------------------------------------------------------------
  ~CATPrContext();

  //------------------------------------------------------------------------------
  // Customization
  //------------------------------------------------------------------------------
  enum Custom { Standard, LocalSymmetry, Similar };
  void Set(CATGeoFactory* iFactory, CATSoftwareConfiguration* iConfig, CATBody* iBody = NULL, CATCGMProgressBar* iProgressBar = NULL);
  void SetTolForLengthTest(const CATPositiveLength iTol);
  void SetTolForAngleTest(const CATAngle iTol);
  void AdaptTolToBodyGaps(ListPOfCATFace& iFaces);
  void ForbidAdjacentInstances(const CATBoolean iForbid); // Default is FALSE
  //void IgnoreInternalLoop(const CATBoolean iIgnore); // Default is FALSE
  void SetCustom(const Custom iCustom); // Default is Standard
  void SetTrdOptions(const CATTrdOptions &iOptions);

  //------------------------------------------------------------------------------
  // Debug
  //------------------------------------------------------------------------------
  static const int TraceCount = 9;
  enum TraceLevel { Any=0, Memory=1, Trihedron=2, IsIsometric=3, Catalyze=4, GrowNetwork=5, GrowShape=6, CreateSet=7, Recognize=8 };
  void SetTrace(const TraceLevel iLevel, const CATBoolean iOn=TRUE);
  INLINE CATBoolean GetTrace(const TraceLevel iLevel) const { return _TraceLevel[iLevel]; };

  INLINE CATBoolean Check() const { return _Check; };
  void SetCheck(const CATBoolean iOn=TRUE);

  void SetTracedRep(const int iTag);
  void SetTracedSet(const int iTag);
  INLINE CATBoolean GetTrace(CATPrRep& iRep) const { if ( _TracedRepTag.Size()==0 ) return FALSE; return _TracedRepTag.Locate(iRep.GetTag()); };
  INLINE CATBoolean GetTrace(CATPrSet& iSet) const { if ( _TracedSetTag.Size()==0 ) return FALSE; return _TracedSetTag.Locate(iSet.GetTag()); };

  //------------------------------------------------------------------------------
  // Errror, Warning, ProgressBar
  //------------------------------------------------------------------------------
  void Assert(const CATBoolean iAssertion = FALSE);
  void Warn(const CATUnicodeString& iText);
  CATBoolean SetProgress(const double iValue = 0., const CATBoolean iThrowIfInterrupted = TRUE);
  CATBoolean IsInterrupted(const CATBoolean iThrowIfInterrupted = TRUE);

  //------------------------------------------------------------------------------
  // Context access
  //------------------------------------------------------------------------------
  CATBoolean IsExact() const;
  INLINE CATSoftwareConfiguration* GetConfig() const { return _Config; };
  INLINE CATBody* GetBody()                    const { return _Body; };
  INLINE CATGeoFactory* GetFactory()           const { return _Factory; }
  INLINE CATBoolean ForbidAdjacentInstances()  const { return _ForbidAdjacentInstances;};
  INLINE CATBoolean IgnoreInternalLoop()       const { return _IgnoreInternalLoop;};
  INLINE double TolForLengthTest()             const { return _TolForLengthTest; };
  INLINE double TolForSquareLengthTest()       const { return _TolForSquareLengthTest; };
  INLINE double TolForAngleTest()              const { return _TolForAngleTest; };
  INLINE double TolForSquareAngleTest()        const { return _TolForSquareAngleTest; };
  INLINE double TolForRelativeTest()           const { return _TolForRelativeTest; };
  INLINE double TolForOBBRelativeTest()        const { return .2; };
  INLINE double MaxPatternAngle()              const { return CAT3PIBY4; }; //  PI/2 * (1+1/(NbMinInstances-1)) 
  INLINE double ModelInfinite()                const { return _ModelInfinite; };
  INLINE double Scale()                        const { return _Scale; }
  INLINE Custom GetCustom()                    const { return _Custom; }
  INLINE const CATTrdOptions GetTrdOptions()   const { return _TrdOptions; }

  //==============================================================================
  // Utilities
  //==============================================================================
  //------------------------------------------------------------------------------
  // Compare 2 Isometries
  //------------------------------------------------------------------------------
  CATBoolean AreEqual(const CATMathTransformation& iT1, const CATMathTransformation& iT2);

  //------------------------------------------------------------------------------
  // Compare 2 Rotations
  //------------------------------------------------------------------------------
  CATBoolean SameRotation(const CATMathTransformation& iTr1, const CATMathTransformation& iTr2);

  //------------------------------------------------------------------------------
  // Check a CATMathTransformation versus SimilarityType
  //------------------------------------------------------------------------------
  CATBoolean CheckTransformationType(const CATMathTransformation& iTransfo, const CATTrd::SimilarityType iType, const CATBoolean iOnlyWithInvariant);
  CATBoolean CheckTransformationType(CATLISTV(CATMathTransformation)& ioTransfo, const CATTrd::SimilarityType iType, const CATBoolean iOnlyWithInvariant);

  //------------------------------------------------------------------------------
  // Check whether a CATMathTransformation is a Translation
  //------------------------------------------------------------------------------
  CATBoolean IsTranslation(const CATMathTransformation& iTransfo) const;

  //------------------------------------------------------------------------------
  // Check whether a CATMathTransformation is a Rotation (Angle is positive)
  //------------------------------------------------------------------------------
  CATBoolean IsRotation(const CATMathTransformation& iTransfo, CATAngle& oAngle, CATMathLine &oAxis) const;

  //------------------------------------------------------------------------------
  // Check whether a CATMathTransformation is positive
  //------------------------------------------------------------------------------
  CATBoolean IsPositive(const CATMathTransformation& iTransfo, CATBoolean& oIsIsometric) const;

  //------------------------------------------------------------------------------
  // Compute Rotation
  //------------------------------------------------------------------------------
  CATBoolean ComputeRotationFromTwoTranslations(const CATMathTransformation& iTr1, const CATMathTransformation& iTr2, CATMathTransformation& oRotation);

  //------------------------------------------------------------------------------
  // Compute Rotations 
  //------------------------------------------------------------------------------
  void ComputeRotationAround(const CATMathVector& iV, const CATAngle iAngle, CATMathTransformation& oRotation); 
  void ComputeRotationAround(const CATMathLine&   iV, const CATAngle iAngle, CATMathTransformation& oRotation); 

  //------------------------------------------------------------------------------
  // Small angle rotation is snapped onto a translation
  //------------------------------------------------------------------------------
  //void MakeRegular(CATMathTransformation& ioTransfo); 

  //------------------------------------------------------------------------------
  // Are 2 vectors parallel ?
  //------------------------------------------------------------------------------
  CATBoolean AreParallel(const CATMathVector& iV1, const CATMathVector& iV2);

  //------------------------------------------------------------------------------
  // Compare 2 Surfaces (logically)
  //------------------------------------------------------------------------------
  CATBoolean Compare2Surfaces(CATSurface& iS1, const CATSurLimits& iUVBox1, const CATMathTransformation& iTransfo, CATSurface& iS2, const CATSurLimits& iUVBox2);

  //------------------------------------------------------------------------------
  // Dedicated to fast filtering out
  //------------------------------------------------------------------------------
  static unsigned char GetTypeUniqueId(const CATSurface& iSurface);

  //------------------------------------------------------------------------------
  // Check 2 Reps
  //------------------------------------------------------------------------------
  void Check2Reps(CATPrSet& iSet, CATMathTransformation & iTransfo, const int iRep1, const int iRep2);

  //------------------------------------------------------------------------------
  // Create object for Debug purpose
  //------------------------------------------------------------------------------
  CATGeometry*   CreateCylinder(const CATMathPoint& iP1, const CATMathPoint& iP2, const CATPositiveLength iRadius, const int iR, const int iG, const int iB, CATTextStampCGM* iTextStamp=NULL); 
  CATGeometry*   CreateSphere  (const CATMathPoint& iC, const CATPositiveLength iRadius, const int iR, const int iG, const int iB, CATTextStampCGM* iTextStamp=NULL); 
  CATGeometry*   CreatePoint   (const CATMathPoint& iC, const int iR, const int iG, const int iB, CATTextStampCGM* iTextStamp=NULL);
  CATGeometry*   CreateCone    (const CATMathPoint& iP1, const CATMathPoint& iP2, const int iR, const int iG, const int iB, CATTextStampCGM* iTextStamp=NULL);
  void           Remove(CATLISTP(CATGeometry)& ioObjects);

  //------------------------------------------------------------------------------
  void Dump(const CATMathTransformation& iTransfo, CATCGMOutput& ioOS);

  //==============================================================================
  // Private section
  //==============================================================================
  private:

  //------------------------------------------------------------------------------
  // Data
  //------------------------------------------------------------------------------

  CATListOfInt              _TracedRepTag;
  CATListOfInt              _TracedSetTag;
  int                       _TraceLevel[TraceCount];
  CATBoolean                _Check;
  CATBoolean                _ForbidAdjacentInstances;
  CATBoolean                _IgnoreInternalLoop;
  Custom                    _Custom;
  CATTrdOptions             _TrdOptions;

  CATSoftwareConfiguration* _Config;
  CATGeoFactory*            _Factory;
  CATBody*                  _Body;
  CATCGMProgressBar*        _ProgressBar;

  double     _TolForLengthTest;
  double     _TolForSquareLengthTest;
  double     _TolForAngleTest;
  double     _TolForSquareAngleTest;
  double     _TolForRelativeTest;
  double     _ModelInfinite;
  double     _Scale;
};


#endif
