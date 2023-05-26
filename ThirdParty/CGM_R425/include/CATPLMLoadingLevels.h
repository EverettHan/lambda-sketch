/* -*-c++-*- */
#ifndef CATPLMLoadingLevels_H
#define CATPLMLoadingLevels_H
//
// CATIA Version 6 Release 208
// Copyright   : Dassault Systemes 2009
//-----------------------------------------------------------------------------
// Description :
// C++ class header file for the class named "CATPLMLoadingLevels"
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
// Inheritance : CATPLMLoadingLevels
//-----------------------------------------------------------------------------
//-----------------------------------------------------------------------------
//

/**
* @level Protected
* @usage U1
*/

#include "CATPLMModelBuilder.h"
#include "CATBaseUnknown.h"
#include "CATOmxDefaultCollecManager.h"
#include "CATOmxCollecManager.h"
#include "CATOmxOHMap.h"
#include "CATOmxClassManager.h"
#include "CATOmxPair.h"
#include "CATPLMQEDef.h"
#include "CATIPLMBoundingBoxForLDH.h"
#include "CATOmxCxxPortability.h"
#include "CATPLMQEConstants.h"
#include "CATIAV5Level.h"
#include "CATPLMTypeHSet.h"
#include "CATOmxKeyString.h"

using namespace CATPLMQEConstants;

#ifndef CATIAR424
/*
 * DO NOT USE: will be removed once migration done by the applications
 */
#define CATPLMLoadingLevel_None      ((int)-3)
#define CATPLMLoadingLevel_Inherited ((int)-2)
#define CATPLMLoadingLevel_Self      ((int)0)
#define CATPLMLoadingLevel_All       ((int)-1)

#endif

template <> CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMLoadingState>::manager();
template <> CATOmxCollecManager& CATOmxDefaultCollecManager<CATPLMLoadingLevel>::manager();
typedef CATOmxOHMap< CATPLMLoadingState, CATPLMLoadingLevel > CATPLMLoadingLevelMap;

class ExportedByCATPLMModelBuilder CATPLMLoadingLevels : public CATBaseUnknown
{
  CATDeclareClass;
public:

  // ctor / dtor
  CATPLMLoadingLevels();
  CATPLMLoadingLevels(const char* iName,
    CATPLMLoadingLevel iDefault = Level_None,
    TypingSystem iTypingSystem = TypingSystem::NewTyping);
  CATPLMLoadingLevels(const CATPLMLoadingLevels&);
  virtual ~CATPLMLoadingLevels();

  // AddRef/Release
  virtual ULONG __stdcall AddRef() override final;
  virtual ULONG __stdcall Release() override final;

  // Hash function
  CATHashKey Hash() const;

  // Full comparison of all elements
  int operator==(const CATPLMLoadingLevels&) const;
  int operator!=(const CATPLMLoadingLevels&) const;

  // assignment operator
  CATPLMLoadingLevels& operator=(const CATPLMLoadingLevels&);

  // LEVELS MANAGEMENT

#ifndef CATIAR424
  /**
   * DO NOT USE - deprecated
   * Sets all the different levels (Light, Navigation and Full).
   * @param  iLightLevel
   *    The desired Light level
   * @param  iNavLevel
   *    The desired Navigation level
   * @param  iFullLevel
   *    The desired Full level
   **/
  HRESULT SetLevels(int iLightLevel, int iNavLevel, int iFullLevel);
#endif

  /**
   * Sets all the different levels (Light, Navigation and Full).
   * @param  iLightLevel
   *    The desired Light level
   * @param  iNavLevel
   *    The desired Navigation level
   * @param  iFullLevel
   *    The desired Full level
   **/
  void SetLevels(CATPLMLoadingLevel iLightLevel, CATPLMLoadingLevel iNavLevel, CATPLMLoadingLevel iFullLevel);

#ifndef CATIAR424
  /**
   * DO NOT USE - deprecated
   * Sets one level (Light, Navigation or Full).
   * @param  iState
   *    The loading state to modify
   * @param  iLevel
   *    The desired level corresponding to the above loading state
   **/
  HRESULT SetLevel(CATPLMQEState iState, int iLevel);
#endif

  /**
   * Sets one level (Light, Navigation or Full).
   * @param  iState
   *    The loading state to modify
   * @param  iLevel
   *    The desired level corresponding to the above loading state
   **/
  void SetLevel(CATPLMLoadingState iState, CATPLMLoadingLevel iLevel);

  /**
   * Returns all the different levels (Light, Navigation and Full).
   * @param  oLightLevel
   *    The current Light level
   * @param  oNavLevel
   *    The current Navigation level
   * @param  oFullLevel
   *    The current Full level
   **/
  void GetLevels(CATPLMLoadingLevel& oLightLevel, CATPLMLoadingLevel& oNavLevel, CATPLMLoadingLevel& oFullLevel) const;

  /**
   * Returns the requested loading level (Light, Navigation or Full).
   * @param  iState
   *    The loading state which loading level is requested
   * @return
   *    The current loading level corresponding to the requested loading state.
   **/
  CATPLMLoadingLevel GetLevel(CATPLMLoadingState iLoadingState) const;

  /**
   * Returns the highest loading state of the corresponding query
   * @return
   *    The current highest loading state
   **/
  CATPLMLoadingState GetQueryState() const;

  /**
   * Merges the provided loading level with this one
   *  All the Level_Inherited values will be valued from the provided loading level
   * @param iLevels
   *    The loading level to be merged with this one
   **/
  void Merge(const CATPLMLoadingLevels& iLevels);

  /**
   * Specifies whether the current loading level can be expressed as an open query
   * @return
   *    TRUE if the loading level can be expressed an open query
   *    FALSE in other cases
   **/
  CATBoolean IsValidForOpenQuery();

  // Specifies the name of the profile
  CATOmxKeyString GetName() const;
  void SetName(const CATOmxKeyString& iName);

  // Specifies whether the caller wishes an old typing or new typing query
  TypingSystem GetTypingSystem() const;
  void SetTypingSystem(TypingSystem iTypingSystem);

  /*
   * Restores all the parameters of this loading level.
   *   like it was a brand loading level created through the default constructor.
   */
  void RestoreDefaultValues();

private:
  CATPLMLoadingLevelMap              m_levels;
  CATOmxKeyString                    m_name;
  TypingSystem                       m_typingSystem;

};
#endif
