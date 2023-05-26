#ifndef SGUseCanonicalReps_h_
#define SGUseCanonicalReps_h_

// SGInfra (PublicInterfaces)
#include "SGInfra.h"

class SGUseCanonicalReps;

/**
*   Correct usage:
*
*   { // <- begin scope
*
*       CAT3DCanonicalRepSettings canonicalRepSettings; // <- access current canonical settings
*       canonicalRepSettings.Settings.Set_VisBasicCreation(true); // <- override some setting
*
*       // <do some work>
*
*   } // <- end scope (which will automatically RESET canonical settings)
*/
class ExportedBySGInfra CAT3DCanonicalRepSettings
{
public:
    CAT3DCanonicalRepSettings();
    ~CAT3DCanonicalRepSettings();

private:
    CAT3DCanonicalRepSettings(const CAT3DCanonicalRepSettings&) = delete;
    CAT3DCanonicalRepSettings& operator=(const CAT3DCanonicalRepSettings&) = delete;

public:
    SGUseCanonicalReps& Settings;
};

//-----------------------------------------------------------------------------

/**
*   Correct WRITE usage:
*
*       cf. CAT3DCanonicalRepSettings above
*
*
*   Correct READ usage:
*
*       if (SGUseCanonicalReps::VisBasicCreation())
*       {
*           // <do some work>
*       }
*       else
*       {
*           // <do some other work>
*       }
*/
class ExportedBySGInfra SGUseCanonicalReps
{
    friend class CAT3DCanonicalRepSettings;

private:
    static SGUseCanonicalReps& NewOverride();
    static void ResetOverride(SGUseCanonicalReps& iOverride);

public:
    /** Instantiation CAT3DCanonicalReps in SGInfra\PublicInterfaces\VisBasicGeometryCreationServices.h */
    static const bool VisBasicCreation();

    /** Conversion from CAT3DCylinderRep/CAT3DCurvedPipeRep into CAT3DCanonicalRep in CGR streaming */
    static const bool Stream_ConvertToCanonical();
    /** Conversion from CAT3DCanonicalRep into CATSurfacicRep in CGR streaming
    * Possible return values:
    *     0: no conversion
    *     1: output is CATSurfacicRep with distinct faces and edges
    *     2: output is CATSurfacicRep with distinct faces
    *     3: output is CATSurfacicRep as a single face
    */
    static const int  Stream_ConvertToSurfacic();
    /** Conversion from CAT3DCylinderRep/CAT3DCurvedPipeRep into CAT3DCanonicalRep in CGR unstreaming */
    static const bool UnStream_ConvertToCanonical();
    /** Conversion from CAT3DCanonicalRep into CATSurfacicRep in CGR unstreaming
    * Possible return values:
    *     0: no conversion
    *     1: output is CATSurfacicRep with distinct faces and edges
    *     2: output is CATSurfacicRep with distinct faces
    *     3: output is CATSurfacicRep as a single face
    */
    static const int  UnStream_ConvertToSurfacic();

    /** Force CAT3DCanonical::Mesh generation in CGR unstreaming */
    static const bool ForceMeshInUnstream();
    /** Force CAT3DCanonical::Mesh generation in CAT3DCanonicalRep::GetSizeInBytes */
    static const bool ForceMeshInGetSize();

private:
    static const bool s_VisBasicCreation;
    static const bool s_Stream_ConvertToCanonical;
    static const int  s_Stream_ConvertToSurfacic;
    static const bool s_UnStream_ConvertToCanonical;
    static const int  s_UnStream_ConvertToSurfacic;
    static const bool s_ForceMeshInUnstream;
    static const bool s_ForceMeshInGetSize;

    static SGUseCanonicalReps s_override;

    //-------------------------------------------------------------------------

private:
    SGUseCanonicalReps();
public:
    ~SGUseCanonicalReps();

    void Set_VisBasicCreation(bool iVal);
    void Set_Stream_ConvertToCanonical(bool iVal);
    void Set_Stream_ConvertToSurfacic(int iVal);
    void Set_UnStream_ConvertToCanonical(bool iVal);
    void Set_UnStream_ConvertToSurfacic(int iVal);
    void Set_ForceMeshInUnstream(bool iVal);
    void Set_ForceMeshInGetSize(bool iVal);

private:
    bool _VisBasicCreation;
    bool _Stream_ConvertToCanonical;
    int  _Stream_ConvertToSurfacic;
    bool _UnStream_ConvertToCanonical;
    int  _UnStream_ConvertToSurfacic;
    bool _ForceMeshInUnstream;
    bool _ForceMeshInGetSize;
};

#endif // !SGUseCanonicalReps_h_
