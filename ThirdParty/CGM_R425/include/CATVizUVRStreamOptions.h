#ifndef CATVizUVRStreamOptions_H
#define CATVizUVRStreamOptions_H

#include "SGInfra.h"
#include "CATErrorDef.h"
#include "CATVizUVTools.h"
#include "CATVizGlobals.h"
#include "CATListOfCATUnicodeString.h"
#include "CATBoolean.h"
class CATStreamer;
class CATCGRSetting;
class CATBaseUnknown;

/*
 * Defines the different streaming format available for leaf representations
 * @param CATVizUVR_UV
 *    Unified Visualization
 * @param CATVizUVR_CGR
 *    CGR
 * @param CATVizUVR_V5XVL
 *    V5-XVL
 */
typedef enum _CATVizUVRFormat
{
   CATVizUVR_Unknown,
   CATVizUVR_UV,
   CATVizUVR_CGR,
   CATVizUVR_V5XVL,
} CATVizUVRFormat;

typedef enum _CATVizUVRMode
{
   CATVizUVRMode_Tessellated,
   CATVizUVRMode_Adaptative
} CATVizUVRMode;

class ExportedBySGInfra CATVizUVRStreamOptions
{
public:

   CATVizUVRStreamOptions();
   CATVizUVRStreamOptions(const CATVizUVRStreamOptions & options);
   CATVizUVRStreamOptions(const CATVizUVRFormat iFormat);
   ~CATVizUVRStreamOptions();

   // UV Options
   void  SetUVOptions(const CATUVOptions & options);
   const CATUVOptions & GetUVOptions() const;
   void  SetUVAccuracy(float accuracy);
   float GetUVAccuracy() const;

   void  SetStreamAccuracy(float accuracy);
   float GetStreamAccuracy() const;

   // CGR Options
   void SetCGRSettings(CATCGRSetting * settings);
   void SetCGRTargetVersion(const CATVizTargetCGR iTargetCGRVersion);

   CATCGRSetting * GetCGRSettings();

   	// versioning
	CATVizTargetCGR GetCGRTargetVersion() const;
	unsigned int GetUVRVersion() const;
	unsigned int GetUVVersion() const;
   void SetUVVersion(unsigned int version);

   // Returns the target streaming format
   const CATVizUVRFormat GetStreamingFormat() const;
   void SetStreamingFormat(const CATVizUVRFormat iFormat);
   
   // scene graph simplification
   void SetSkipUselessBags(CATBoolean iOnOff);
   CATBoolean GetSkipUselessBags() const;
   
   // scene graph simplification
   void SetNoMemoryShortTangents(CATBoolean iOnOff);
   CATBoolean GetNoMemoryShortTangents() const;

   // Container settings
   void SetAutoLoadContainerList(const CATListOfCATUnicodeString & iContainerList);
   void GetAutoLoadContainerList(CATListOfCATUnicodeString & oContainerList);

   // Model to attach when unstream applicative containers
   void SetUnstreamModelForContainers(CATBaseUnknown * iModel);
   CATBaseUnknown * GetUnstreamModelForContainers();

   // Model to attach when unstream applicative containers
   void SetStreamModelForContainers(CATBaseUnknown * iModel);
   CATBaseUnknown * GetStreamModelForContainers();

   // Unstream mode
   const CATVizUVRMode GetUnStreamMode() const;
   void SetUnStreamMode(const CATVizUVRMode iMode);

   HRESULT Stream   (CATStreamer & oStreamer);
   HRESULT UnStream (CATStreamer & iStreamer);

   HRESULT WriteUVBody      (CATStreamer & streamer, CATRep * iRep, CATBoolean refinable, unsigned int pntLevel);
   HRESULT FitAndWriteUVBody(CATStreamer & streamer, CATRep * iRep, CATBoolean &oFittingSucceeded);
   HRESULT ReadUVBody       (CATStreamer & streamer, CATRep * & oRep);
   HRESULT SetTargetVersion(unsigned int majorVersion, unsigned int minorVersion);
   unsigned int GetFittingLevel() const;

   // define CATVizCGRAccessMode to be used for CATWriteUVR
   // default value is CATVizCGRAccessModeDirect (a bit slow but no size limitations)
   void SetAccessMode(CATVizCGRAccessMode iMode);
   CATVizCGRAccessMode GetAccessMode() const;

private :

   HRESULT WriteUVHeader(CATStreamer & streamer);
   HRESULT ReadUVHeader (CATStreamer & streamer);
   HRESULT CleanupUV();

   CATVizUVRFormat   _format;
   CATVizUVRMode     _unStreamMode;
   CATUVOptions      _uvOptions;
   unsigned int      _uvrVersion;
   unsigned int      _uvVersion;
   float             _uvAccuracy;
   float             _streamAccuracy;
   CATCGRSetting *   _cgrSettings;
   CATVizTargetCGR   _cgrTargetVersion;
   CATListOfCATUnicodeString _autoLoad;
   CATBaseUnknown *  _modelForContainersUnStream;
   CATBaseUnknown *  _modelForContainersStream;
   CATBoolean _skipUselessBags;
   CATBoolean _noMemoryShortTangents;
   unsigned int _fittingLevel;
   CATVizCGRAccessMode _accessMode;
};

#endif
