// COPYRIGHT Dassault Systemes 2004
//===================================================================
//
// Update convention for a virtual object.
//
//=============================================================================
// Oct. 04   Creation                                                  O.PERIOU
//=============================================================================

#ifndef CATOmbVOUpdateFlavour_H
#define CATOmbVOUpdateFlavour_H

/**
 * @level Private
 * @usage U1
 */

#include "CATOmbLnkVO.h"
#include "IUnknown.h" // for HRESULT

class CATOmbRelationMetaData;

/**
 * <p>
 * Class that embeds the update behavior of a Virtual Object.
 * <b>Role:</b>This class enables to set or get the update behavior that characterizes a VO. 
 * It is made of an update flavour and a sensitivity level.
 * <br>The update behavior tells how a VO is sensible to an update.
 * <br>An update flavour can take 3 values:
 * <ul> 
 * <li><tt>None</tt>: the VO is not sensible.
 * <li><tt>ContextOnly</tt>: the VO is sensible to the path elements.
 * <br>In this case the sensitivity level parameter gives the number of instances to consider for update 
 * in the path, from the targeted instance. Thus, if it is equal to 1, the VO will only be sensible to 
 * an update of information related to the targeted instance (e.g. in a product structure, when the position matrix 
 * of the targeted instance changes).</li>  
 * <li><tt>TargetOnly</tt>: the VO will only be sensible to an update of the targeted instance itself.</li> 
 * <li><tt>TargetInContext</tt>: the VO will be sensible to both previous updates.</li>
 * </ul>
 * See @href CATIOmbVOFactory for use.
 */

class ExportedByCATOmbLnkVO CATOmbVOUpdateFlavour
{

public:

/**
 * Update flavour of a VO.
 * @param ContextOnly
 *   The VO will be sensible to each update of the context of the targeted instance.
 * @param TargetOnly
 *   The VO will be sensible to each update of the targeted instance.
 * @param TargetInContext
 *   The VO will be sensible to both updates
 * @param Neutral
 *   The VO will be not sensible
 * @param NA
 *   The default value when an instance of <tt>CATOmbVOUpdateFlavour</tt> is created.
 *   <br>This value is not interpreted. <tt>SetUpdateFlavour</tt> must be called to set another value.
 */

  enum UpdateFlavour {ContextOnly=0, TargetOnly=1, TargetInContext=2, Neutral=4, NA=3};
	
/** 
 * Constructs an instance of CATOmbVOUpdateFlavour with a given update flavour. 
 * @param UpdateFlavour
 *   The update flavour  
 */

  CATOmbVOUpdateFlavour (UpdateFlavour);

  CATOmbVOUpdateFlavour (const CATOmbRelationMetaData & iLMD);

/** Constructs an instance of CATOmbVOUpdateFlavour with the <tt>NA</tt> update flavour. */

  CATOmbVOUpdateFlavour();

/** @nodoc */

  ~CATOmbVOUpdateFlavour();
	
/**
  * Sets the update flavour.
  * @param iFlavour
  *    The update flavour.
  * @return
  *    S_OK 
	* @see #UpdateFlavour
  */

  HRESULT SetUpdateFlavour (UpdateFlavour iFlavour);

/**
  * Gets the update flavour.
  * @param oFlavour
  *    The update flavour.
  * @return
  *    S_OK 
	* @see #UpdateFlavour
  */

  HRESULT GetUpdateFlavour (UpdateFlavour &oFlavour) const;
  
/**
  * Sets the sensitivity level.
  * @param iLevelSensitivity
  *    The sensitivity level.
  * @return
  *    S_OK 
  */

  HRESULT SetLevelSensitivity (unsigned short iLevelSensitivity);

/**
  * Gets the sensitivity level.
  * @param oLevelSensitivity
  *    The sensitivity level.
	*    <br><b>Legal values</b>: must be lesser (or equal) than the number of instances of which the VO is made.
  * @return
  *    S_OK 
  */

  HRESULT GetLevelSensitivity (unsigned short &oLevelSensitivity) const;	
	
  /** @nodoc */
  CATOmbVOUpdateFlavour& operator = (const CATOmbVOUpdateFlavour&);

  /** @nodoc */
  CATOmbVOUpdateFlavour(const CATOmbVOUpdateFlavour&);

private:

  UpdateFlavour _Flavour;
  unsigned short _Level;
};

#endif


