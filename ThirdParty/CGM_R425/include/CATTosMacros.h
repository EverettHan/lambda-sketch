#ifndef CATTosMacros_H
#define CATTosMacros_H
/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2005

/**
 * @level Private
 * @usage U3
 */
#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include "ExportedByCATPLMTos.h"

#include "CATPLMIdentificationAccessMacros.h"

#include "CATIAV5Level.h"
#include "IUnknown.h"
#include "CATErrorDef.h"
#include "CATDataType.h"
#include "CATSysMacros.h"
#include "CATUnicodeString.h"
#include "CATTrace.h"

class CATPLMRepositoryName;
class CATPLMTypeId;
class CATPLMDocumentAdapter; 
class CATPLMTosPendingProviderImpl; 
class CATComponentId; 
class CATError;
class PlmIDSimple; 

class CATProxySpace; 

class CATOxSingleton; 
class CATOxSpace; 
class CATOxJanus; 
class CATOxPath;
class CATOxEntity;         
class CATOxProxy;         
class CATOxFolder;
class CATOxFolderPersistentUnit;
class CATOxTransaction; 


 /**
 * Definition of the possible kinds of filter for getting one handle.
 * <tt> Possible values:</tt>
 * <dl>
 * @param <tt>CatTosQuery_OnlyActivatedInSession</tt>           <dd>Only if associated Object alive/solved in session.
 * @param <tt>CatTosQuery_ActivatedOrGarbagedInSession</tt>     <dd>Only if associated Object alive or garbaged in session.
 * @param <tt>CatTosQuery_Nofilter</tt>                         <dd>Does not care if associated object is bind in session.
 * @param <tt>CatTosQuery_OnlyWithValidPersistencyIntents</tt>  <dd>Filter on persistent entities  ToCreate/ToModify/Loaded
 * </dl>
 */
enum CATTosQuery_Filter 
{
  CatTosQuery_OnlyActivatedInSession,
  CatTosQuery_ActivatedOrGarbagedInSession,
  CatTosQuery_Nofilter,
  CatTosQuery_OnlyWithValidPersistencyIntents
};

/**
 * Definition of the basic in session status associated with handle.
 * <tt> Possible values:</tt>
 * <dl>
 * @param <tt>CatTosInSession_Activated</tt>  <dd>Only if associated Object alive/solved in session.
 * @param <tt>CatTosInSession_Garbaged</tt>   <dd>Only if associated Object garbaged in session.
 * @param <tt>CatTosInSession_Null</tt>       <dd>Does not care if associated object is bind in session.
 * </dl>
 */
enum CATComponentId_InSession
{
  CatTosInSession_Activated,
  CatTosInSession_Garbaged,
  CatTosInSession_Null
};

/** @nodoc */
extern const ExportedByCATPLMTos CATProxySpace CATProxySpace_Null; 

#endif



