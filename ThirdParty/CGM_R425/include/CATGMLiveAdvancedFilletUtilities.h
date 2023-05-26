#ifndef CATGMLiveAdvancedFilletUtilities_H
#define CATGMLiveAdvancedFilletUtilities_H

#include "CATGMLiveFilletUtilities.h"
#include "AdvOpeInfra.h"
#include "CATCGMNewArray.h"
#include "CATMathDef.h"

class CATSoftwareConfiguration;
class CATBoneFillet;
class CATDynLiveFilletRadius;
class CATManifoldLocalRadius;
class CATGMLiveInputDataFilletManager;

class ExportedByAdvOpeInfra CATGMLiveAdvancedFilletUtilities : public CATGMLiveFilletUtilities
{
public:
  CATCGMNewClassArrayDeclare;      // Pool allocation

  CATGMLiveAdvancedFilletUtilities(CATSoftwareConfiguration * iConfig);
  virtual ~CATGMLiveAdvancedFilletUtilities();

  // --------------------------------------------------------------------------
  // Evaluate dimensions of a BoneFillet
  // --------------------------------------------------------------------------
  HRESULT EvaluateDimensions(CATLiveBody& iLiveBody, CATBoneFillet& iBoneFillet, CATPositiveLength* ioMinRadius, CATPositiveLength* ioMaxRadius, CATPositiveLength* ioLength, CATAngle* ioMinAngle, CATAngle* ioMaxAngle);// Angle between 0. & CATPI

  // --------------------------------------------------------------------------
  // Evaluate dimensions of a BoneManifold
  // --------------------------------------------------------------------------
  HRESULT EvaluateDimensions(CATLiveBody& iLiveBody, CATBoneManifold& iBone, CATAngle oMinMaxAngle[2], CATPositiveLength oMinMaxChord[2]);

  // --------------------------------------------------------------------------
  // Manage interactions between CATDynLiveFilletRadius & CATManifoldLocalRadius
  // --------------------------------------------------------------------------
  static void SetLocalRadius(CATBoneFillet& iBoneFillet, const CATDynLiveFilletRadius& iRadius);
  static CATDynLiveFilletRadius* CreateDynLiveFilletRadius(const CATManifoldLocalRadius& iManifoldLocalRadius, CATCell& iLocation, double iRatio, CATGMLiveInputDataFilletManager & iInputDataFilletManager, CATHVertex* iHVertex = NULL); // NULL HVertex: the one in iManifoldLocalRadius is used
  static CATDynLiveFilletRadius* CreateDynLiveFilletRadius(const double iRadius, CATAngle* iAngle, CATCell& iLocation, double iRatio, CATGMLiveInputDataFilletManager & iInputDataFilletManager, CATHVertex* iHVertex = NULL); 

  // --------------------------------------------------------------------------
  // Private section
  // --------------------------------------------------------------------------
private:
  HRESULT EvaluateAngles(CATLiveBody& iLiveBody, CATBoneManifold& iBone, CATAngle& oMinAngle, CATAngle& oMaxAngle);

};

#endif 

