// COPYRIGHT DASSAULT SYSTEMES 2012, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyBodyDecimatorCaptureObserver.h
//
//===================================================================
// January 2012  Creation: NDO
//===================================================================
#ifndef CATPolyBodyDecimatorCaptureObserver_H
#define CATPolyBodyDecimatorCaptureObserver_H

#include "PolyBodyDecimate.h"
#include "CATPolyBodyDecimatorObserver.h"
#include "CATErrorDef.h"
#include "CATBoolean.h"

class CATSoftwareConfiguration;

class CATechExt;
class CATString;


/**
 * Observer class to capture the data and events of the CATPolyBodyDecimator operator (Phoenix).
 */
class ExportedByPolyBodyDecimate CATPolyBodyDecimatorCaptureObserver : public CATPolyBodyDecimatorObserver
{

public:

  CATPolyBodyDecimatorCaptureObserver (CATPolyBodyDecimatorObserver* iOtherObserver = 0);

  ~CATPolyBodyDecimatorCaptureObserver ();

  inline void Suspend () {_Suspended = TRUE;}

public:

  //
  // Notifications.
  // 

  // Settings events.

  void ReactToSetChordalDeviation (const double iChordalDeviation, const double iChordalDeviationEdge);

  void ReactToDoFreezeBoundaryBars (CATBoolean iDoFreeze);

  void ReactToDoInterpolateNormals (CATBoolean iUseNormalLayer);

  void ReactToDoInterpolateTextureCoordinates (CATBoolean iUseTextureLayer);

  void ReactToProcessTextureCoordinatesConstraints(const unsigned int iDim, const double iWeight[]);

  void ReactToDoStitching (CATBoolean iDoStitching);

  void ReactToDoCreateBoundaryEdges (CATBoolean iDoCreateBoundaryEdges);

  // Decimation events.

  void PrepareToInitialize (const CATPolyBody& iPolyBody, const CATIPolyBodyFrameLayers* iFrameLayers, const CATMathTransformation* iMatrix);

  void ReactToInitialize (const CATPolyBodyBarGraph& iBodyGraph);

  void PrepareToStep ();

  void ReactToStep ();

  void ReactToFinalize (const CATPolyBody& oPolyBody, CATIPolyBodyFrameLayers* oFrameLayers);

public:

  // Access to parameters and data.

  const CATSoftwareConfiguration* GetSoftwareConfiguration () const {return _SoftwareConfiguration;}

  double GetChordalDeviation () const {return _ChordalDeviation;}
  double GetChordalDeviationEdge () const {return _ChordalDeviationEdge;}

  CATBoolean GetDoProcessNormals () const {return _DoInterpolateNormals;}
  CATBoolean GetDoProcessTextureCoordinates () const {return _DoInterpolateTextureCoordinates;}
  CATBoolean GetDoFreezeBoundaryBars () const {return _DoFreezeBoundaryBars;}
  CATBoolean GetDoCreateBoundaryEdges () const {return _DoCreateBoundaryEdges;}
  CATBoolean GetDoStitching () const {return _DoStitching;}

  const CATPolyBody* GetInputPolyBody () const {return _InputPolyBody;}
  const CATMathTransformation* GetInputMatrix () const {return _InputMatrix;}
  const CATPolyBody* GetOutputPolyBody () const {return _OutputPolyBody;}

public:

  /**
   * Returns the name of the Phoenix.
   */
  static const CATString& GetName ();

  /**
   * Returns <tt>TRUE</tt> if the capture of the data has been enabled.
   */
  static CATBoolean IsCaptureEnabled ();

  // Phoenix extension.
  void SetPhoenixExtension (CATechExt* iExtension);

private:

  // Phoenix data members.
  CATechExt* _Phoenix;
  CATBoolean _Suspended;

  // Software configuration.
  CATSoftwareConfiguration* _SoftwareConfiguration;  // Open configuration.

  // Captured parameters.
  double _ChordalDeviation;
  double _ChordalDeviationEdge;
  double *_TextureWeight;
  
  unsigned int _DoProcessTextureCoordinatesConstraints;

  CATBoolean _DoInterpolateNormals;
  CATBoolean _DoInterpolateTextureCoordinates;
  CATBoolean _DoFreezeBoundaryBars;
  CATBoolean _DoStitching;
  CATBoolean _DoCreateBoundaryEdges;

  // Captured input data.
  const CATPolyBody* _InputPolyBody;
  const CATMathTransformation* _InputMatrix;

  // Captured output data.
  const CATPolyBody* _OutputPolyBody;

  // Other observer called after the capture of the data.
  CATPolyBodyDecimatorObserver* _OtherObserver;

};

#endif
