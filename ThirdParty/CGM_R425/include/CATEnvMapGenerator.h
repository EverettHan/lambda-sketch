//===================================================================
// COPYRIGHT Dassault Systemes 2015/09/02
//===================================================================

#ifndef CATEnvMapGenerator_H
#define CATEnvMapGenerator_H

#include "CATVisItf.h"

//System
#include "CATSysErrorDef.h" //for HRESULT

class CATEnvMapGeneratorDesc;
class CATIEnvMapGenerator;
class CATVizCubicEnvMapWithMipMap;
class CATVizTextureWithMipMap;

/*
**
** About
** ==========================
** This is an API for generating NRE-specific environment maps from LDR or HDR images or cube maps.
** The maps obtained through this API are expected to be used in the sky lighting part of a NRE-specific ambiance.
** This API still needs improving, so please forward your bug reports, remarks or suggestions to T64.
**
** How to use
** ==========
** There are two ways to use this class:
**   1st way: One-shot
**      - You call Generate, and the map is generated and written to the disk according to the Desc parameter (see CATEnvMapGeneratorDesc.h)
**
**   2nd way: Progressive
**      - Call Begin with the Desc to obtain a valid session ID.
**      - Call Step with this ID to advance the computation. When the function returns, you can use the partially computed map.
**        When the map is fully computed, Step returns E_FAIL and will have no effect until you pass another valid ID.
**      - Call End when you are finished with the map.
*/

class ExportedByCATVisItf CATEnvMapGenerator
{
public:

  /*
  ** Fully computes an environment map suitable for a CATVisInfiniteEnvironment's sky lighting.
  ** WARNING: depending on the parameters, this can take a long time to finish
  **
  **  iDesc: environment map generation parameters. See CATEnvMapGeneratorDesc.h
  **
  ** Returns E_FAIL if the desc parameters aren't valid. S_OK otherwise.
  */
  static HRESULT Generate(const CATEnvMapGeneratorDesc& iDesc);

  /*
  **
  ** Create a new environment map compute session, which allows rendering a few samples at a time.
  ** WARNING: any progress made on other sessions will be lost!
  **
  **  iDesc: environment map generation parameters. See CATEnvMapGeneratorDesc.h
  **  iStepSize: number of samples that will be computed each step.
  **  oHandle: when the method succeeds, contains an integer > 0 uniquely identifying the created session.
  **
  ** Returns E_FAIL if the desc parameters or step size aren't valid.
  ** Returns S_OK otherwise.
  */
  static HRESULT Begin(const CATEnvMapGeneratorDesc& iDesc, const unsigned int iStepSize, int& oHandle);

  /*
  ** Computes one step of an environment map.
  **
  **  iHandle: a session ID previously returned by Begin.
  **  oMap: the map being rendered
  **
  ** Returns E_FAIL if an error has occured.
  ** Returns S_FALSE when the environment map is fully computed.
  ** Returns S_OK otherwise
  */
  static HRESULT Step(const int iHandle, CATVizCubicEnvMapWithMipMap*& oMap);

  /*
  ** Same as Step() but the output is generated not as a cubemap but as a latlong image.
  */
  static HRESULT StepLatLong(const int iHandle, CATVizTextureWithMipMap*& oMap);

  /*
  ** Call this when the environment map is fully computed.
  **
  **  iHandle: a session ID previously returned by Begin.
  */
  static void End(const int iHandle);

private:
  CATEnvMapGenerator();
  ~CATEnvMapGenerator();

  static bool _new_impl;
  static CATIEnvMapGenerator* _GetGeneratorImplementation();
};

#endif // CATEnvMapGenerator_H
