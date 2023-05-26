#ifndef VISSPATIALMEDIASERVICE_H
#define VISSPATIALMEDIASERVICE_H

#include <string>

#include "VisSpatialMedia.h"

class VisMP4MpegContainer;
class VisMP4ReadStream;
class VisMP4WriteStream;
class VisMP4Box;

/** This class is used to inject the metadata for spherical video. */
class ExportedByVisSpatialMedia VisSpatialMediaService
{

public:

    VisSpatialMediaService();
    virtual ~VisSpatialMediaService();

    enum StereoMode
    {
        eNone,
        eTopBottom,
        eLeftRight
    };

    /** @struct This struct contains parameters injecting metadata. */
    struct ExportedByVisSpatialMedia InputParams
    {
        bool useStereo;
        StereoMode stereoMode;
        std::string stichingSoftware;
        std::string inputFileName;
        std::string outputFileName;        

        InputParams(): useStereo(false), stereoMode(eNone)
        {
            stichingSoftware = "Dassault Systemes: Stellar Engine";
        }
    };
          
  /** Use to inject metadata.
   *  @param iValues input parameters for metadata injection.
   */
    static void InjectMetadata(const InputParams& iValues);
    
protected:

    static bool CheckParams(const InputParams& iValues);
    static std::string GenerateMetadata(const InputParams& iValues);
    static bool Mpeg4AddSpherical(VisMP4MpegContainer* iMpeg4File, VisMP4ReadStream* iInputFileHandle, VisMP4Box* iUuidLeaf);

};

#endif //VISSPATIALMEDIASERVICE_H
