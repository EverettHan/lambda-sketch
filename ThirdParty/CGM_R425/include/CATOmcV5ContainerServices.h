/* -*-c++-*- */
//-----------------------------------------------------------------------------
// COPYRIGHT DASSAULT SYSTEMES 2007  
//-----------------------------------------------------------------------------
// services for V5 containers :
//-----------------------------------------------------------------------------
/**
* @level Private 
* @usage U1
*/
#ifndef CATOmcV5ContainerServices_H
#define CATOmcV5ContainerServices_H

// COPYRIGHT DASSAULT SYSTEMES 2005
#include "CATOmcBase.h"

//#include "AC0CATPL.h"
#include "CATBaseUnknown.h"
#include "CATIContainer.h"

//class CATIAModel ;
class CATOmcContainer ;
//class CATIContainer ;
class CATUuid ;
class CATDocument;
/**
 * Service to find the Super Type of the container to be created.
 * <br><b>Role</b>: This method allows to define the type of container which 
 *									is going to be built.
 * @param iDefaultSuperType
 *	The default Super Type  of the container to be created.
 * @param iSuperType
 *	The Type of Container which is going to be built.
 * @param ioType
 *	The Document in which the container is built.
 * @param oSuperType
 *	The Type of Container which is going to be built.
 *  <b>Legal values</b>:
 *	<br><tt>CATV4Container :</tt>   in case of a V4 Document - if the environment variable is ON
 * 	<br><tt>CATV5Container:</tt>  in case of a V5 Document - if the environment variable is ON
 * 	<br><tt>CATContainer:</tt>  if the environment variable is OFF 
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
HRESULT ExportedByCATOmcBase GetSuperType(  char* iDefaultSuperType, char* iSuperType, char *&ioType, char*& oSuperType );
/**
 * Service to check if the V5 Containers tree contains a V4AnndCont
 * <br><b>Role</b>: This reccursive method allows to check if a V4Anndcont is 
 *									associated to the document.
 * @param iContainer
 *	The Root Container.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
int CheckContainersForAnnotations( CATOmcContainer*& iContainer) ;


HRESULT ExportedByCATOmcBase CATChangeContainerUUID( CATIContainer* iCont,
                                                             CATUuid*       iNewUuid ) ;

HRESULT ExportedByCATOmcBase CATResetContainer(const CATIContainer_var& iContainer);

/**
 * Service to check the type  of document in which the container is created.
 * Temporarily, it also checks an environment variable.
 * <br><b>Role</b>: This method allows to define the type of container which 
 *									is going to be built.
 * @param iFatherDocument
 *	The Document in which the container is built.
 * @param oTypeForContainer
 *	The Type of Container which is going to be built.
 *  <b>Legal values</b>:
 *	<br><tt>CATV4Container :</tt>   in case of a V4 Document - if the environment variable is ON
 * 	<br><tt>CATV5Container:</tt>  in case of a V5 Document - if the environment variable is ON
 * 	<br><tt>CATContainer:</tt>  if the environment variable is OFF 
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>S_OK :</tt>   on Success
 * 	<br><tt>E_FAIL:</tt>  on failure
*/
ExportedByCATOmcBase HRESULT CheckTypeForContainer(CATDocument* iFatherDocument, char*& oTypeForContainer);
/**
 * Service to check the status of the NEW_V5_CONTAINERS_PROJECT environment variable.
 * <br><b>Role</b>: This service allows to check if code associated to the new V5 
 *									containers structure has to be activated.
 * @return
 *	<b>Legal values</b>:
 *	<br><tt>TRUE:</tt> if the variable is switched ON.
 * 	<br><tt>FALSE:</tt> if the variable is switched OFF.
*/
/*ExportedByCATOmcBase int UseNewV5OmcContainer();
ExportedByCATOmcBase int UseOmc3DLive();*/
#endif
