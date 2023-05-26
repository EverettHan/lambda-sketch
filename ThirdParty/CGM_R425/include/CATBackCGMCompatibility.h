#ifndef CATBackCGMCompatibility_H
#define CATBackCGMCompatibility_H

// COPYRIGHT DASSAULT SYSTEMES 2021

#include "CGMV5Interop.h"
#include "CATBoolean.h"
#include "CATUnicodeString.h"

class CATICGMObject;
class CATICGMContainer;
class CATBody;

/**
 * @brief     Tool class to check compatibilty of CGM objects or CGM factory inside the CATBack process.
 * @date      W17-Y2021
 * @author    YL3 and LAP
 */
class ExportedByCGMV5Interop CATBackCGMCompatibility
{
public:
   /**
   * @brief   Check designed for CATBack as Result with the level from VersionManagement.<br>
   *          CATBack as Result : From level to lower level. The body will be associated with datum feature only.<br>
   *          It's used by CDM and inside the CATBodyDatumiser.
   * @param   iObject
   *          Object to check. It is often a CATBody, but it could be an other type.
   * @return
   *          TRUE  : If the object is compatible for a CATBack.<br>
   *          FALSE : Otherwise. For example if the CATBody is a Polyhedral, it is not allowed to be streamed in V5.
   */
  static CATBoolean IsCompatible(CATICGMObject* iObject);

  /**
   * @brief   Check designed for CATBack as Spec with the level from VersionManagement.<br>
   *          CATBack as Spec : From 3DEXPERIENCE to synchronized V5.<br>
   *          Only use for fast detection of only compatible objects.<br>
   *          Warning : Some incompatible objects could be not pointed by feature, for example temporary bodies not involed in the stream process.<br>
   *          So if it return FALSE, you have to check all features of the tree to check only objects involed in the stream process.
   * @param   iCGMContainer
   *          The container to check. It should be the explicit factory.
   * @return
   *          TRUE : If we are sure that all CATBody are compatible.<br>
   *          FALSE : Otherwise. For example if there is an Polyhedral CATBody in the container, it returns FALSE because it is not allowed in V5.<br>
   *          An other example, if there is a CATGeoPolyBody in the container, it returns FALSE.
   */
  static CATBoolean IsCompatible(CATICGMContainer* iCGMContainer, CATBoolean iCreateWarningInsideIncidentCollector=FALSE);


  	// @nocgmitf
  /**
   * @brief Do not call this method. It is for internal coverage of functionality.
   */
  static CATBoolean CheckVersionWithMinVersion(int iIsCatback, const CATUnicodeString & iTargetVersion, int iMinVersion);
	// @nocgmitf
  /**
   * @brief Do not call this method. It is for internal coverage of functionality.
   */
	static CATBoolean CheckVersionPolyhedral(int iIsCatback, const CATUnicodeString & iTargetVersion);

  // @nocgmitf
  /**
   * @brief Do not call this method. It is for internal coverage of functionality.
   */
	static CATBoolean CheckVersionImplicitSurface(int iIsCatback, const CATUnicodeString & iTargetVersion);
private:
	// @nocgmitf
	static CATBoolean IsCompatiblePolyhedral(CATICGMObject* iObject, int iIsCatback, const CATUnicodeString & iTargetVersion);
  // @nocgmitf
  static CATBoolean IsCompatibleImplicitSurface(CATICGMObject* iObject, int iIsCatback, const CATUnicodeString & iTargetVersion);
  // @nocgmitf
  static CATBoolean ContainsGMImplicitSurfaceObject(CATBody *piBody);

  static void CreateTheWarningInsideIncidentCollector();
};

#endif
