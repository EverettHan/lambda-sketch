// COPYRIGHT Dassault Systemes 2002
//===================================================================
//
// CATVisBaseEnv.h
// Header definition of CATVisBaseEnv
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Sep 2002  Creation: JUT
//===================================================================
#ifndef CATVisBaseEnv_H
#define CATVisBaseEnv_H

#include "SGInfra.h"

//-----------------------------------------------------------------------

/**
* This class is used in order to initialize visualisation environment variables.
* If an environnement variable is to be valuated and used, you should
* make it accessible from here.
*/
class ExportedBySGInfra CATVisBaseEnv
{
public:

  static int IsCheckUpSurfacicRep();
  static int IsDebugLightSceneGraph();
  static int IsDebugLightSceneGraphStack();
  static int IsCheckUpCGRContainer();
  static int HasAssertInDestroyGP();
  static int HasLDHNoShow();
  static int	Is_Super_Sampling_FSAA(unsigned int &oNbSamples);
  static unsigned int Get_Nb_Samples_FSAA(void);

  static int AllowSgixOnHPUX();
  static int Is_FSAA_While_Moving();

  static bool IsNotAnODT();
  static bool IsAnODT();

  // fonction utilise a l'open de Part pour effectuer une phase
  // de pre-process utilisant SetVisuRep  (on ne pose plus les
  // attributs graphique par la voix habituelle)
  static int	IsFastOpenGA();
  // TUV 30 May 2008 IR 625611 
  // Retrieving value of Environment variable CAT_KERNING

  static int IsKerningEnabled();
  // TUV 4 May 2011 IR 053188 
  // Retrieving value of Environment variable CAT_DRAW_PIXELIMAGE_NEW_ALPHA
  static int IsDrawPixelImageWithOldAlpha();

  // Force number of transparency layers in Depth Peeling Algorithm
  static int NumTransparencyLayers();

  // Draw visualization versionning
  static int GetDrawVersion();

  // Active le record des draw différés
  static int IsDeferredDrawRecordable ();
  static int GetDeferredDrawVersion   ();

  static int IsNewVisu();
    
  // Prioritize sketcher rendering for SW performance issue with sketcher
  static int HasSketcherRenderingPrioritized();

  // Used to activate Unwrap Texture Mapping
  static int IsUnwrapSHM();
  // GF8: VBO in shared memory supported
  static int IsVBOInSharedAllowed();
  //H55++ gp toolbar in VID 
  static int IsVIDGPtoolbarAvailable();

  static int IsNewQualityMgtActive();
  static void SetNewQualityMgtActive(unsigned int iActivate);

  static short IsCATRepAddRefReleaseMode(); //D1A: June 2017: CATRep lifecycle

  static short IsCATVisNoGraphicalAPI(); //D1A: For non-visu mode (replacing the method IsSG_UseNonVisuMode): Sep 2019

  static short IsCATVisHeadlessAPI(); //OU4: For A2x mode 

  static short SGForceMonothreadedUnstreaming(); //TPG: sg force monothreaded unstreaming (April 2020)

  static short SG_MutexForCATSysDRMDocument(); //TPG: sg MutexForCATSysDRMDocument

  static short SGUseTBBCGRsMT(); //TPG: sg Use TBB for CGRsMT

  static short SGUseTBBAlloc(); //TPG: sg Use TBBAlloc

  static short SGStreamVis2DPrimitiveGroupRep(); //TPG: sg Stream Vis2DPrimitiveGroupRep

	static short SGAssertIfLifecycleIssue(); //E8C : sg Assert if CATRep lifecycle broken (April 2020)
  
	static short IsVisAreaLightClipQuad(); // For ClipQuad implemention of AreaLight(Rectangle)

	static short ONE_CONTAINER_CGR(); //E8C: new CGR structure
  
  // ambiance versionning
  struct Ambiance
  {
    enum EMode
    {
      eFastBoundingBox = 0,
      eGroundShadowClipping,
      eNeoPureWhite,
      eVisuPBRGasLook
    };
  };
  static int IsAmbianceActivated(Ambiance::EMode iMode);
  static int GetAmbianceVersion();
  
  // return false if the call is done after the initialization
  static bool DeactivateNewVisu();

  struct Tesselation
  {
      enum EMode
      {
          eSGITesselation = 0,
          eOldTesselation
      };
  };
  static short IsTessalationMode();

  struct Assertion
  {
    enum EMode
    {
      eDisabled = 0,
      eCATassert,
      eVassert,
    };
  };

  static bool IsPipeliningActivated();

  // Is Draw executed after the Cull phase ?
  // if false and the pipeline activated, then draw and cull are executed in parallel
  inline static bool IsPipeliningSequential()
  {
    return static_cast<bool> (_PIPELINING_SEQUENTIAL);
  }

  inline static void SetPipeliningSequential(bool isSequential)
  {
    _PIPELINING_SEQUENTIAL = isSequential;
  }

  // Do we assert when there is an error in the lifecycle of graphical elements ?
  inline static Assertion::EMode GetCheckLifecycle()
  {
    return static_cast<Assertion::EMode> (_CHECK_LIFECYCLE);
  }

  inline static void SetCheckLifecycle(Assertion::EMode assertMode)
  {
    _CHECK_LIFECYCLE = assertMode;
  }

  // set VisMaterialDebug=Traces,ConvertCGM,ConvertOnlyPhysical,StreamOriginalMat,RenderOriginalMat
  static bool GetVisMaterialDebugMode(const char* iModeName);
  static void SetVisMaterialDebugMode(const char* iModeName, bool iEnable);

  // HCSSE function available.
  static bool Is_HCSSE_Enabled();

  // HCSSE function activation forced.
  static bool Is_HCSSE_Activation_Forced();

  // HCSSE function forced threshold value.
  static double HCSSE_Forced_Threshold_Value();

  // Nodes deletion for 'VisSGOccurrenceObserver': immediate or delayed.
  // If 'NOT_FORCED' or not set, the default value is set in 'VisSGOccurrenceObserver'.
  // Environment variable: "VisSgForceNodesDeletionMode".
  enum class VisSgForceNodesDeletionMode { NOT_FORCED = 0, IMMEDIATE = 1, DELAYED = 2, last_value = DELAYED };
  static VisSgForceNodesDeletionMode VisSg_Force_Nodes_Deletion_Mode();

  static bool UseVisPoolAllocator();

  static bool IsAppearanceViewModeActivated();

  struct Highlight
  {
    enum EMode
    {
      eAdvancedPoliteEdgeAndMarker = 0,
    };
  };
  static bool IsHighlightActivated(Highlight::EMode iMode);
  static int GetHighlightVersion();

  static bool IsForcedHQAOPrepass();
  static bool IsForcedHQAOAreaShadows();

  static bool IsActivateNewRefPlaneVisu();

private:
  template <typename EnumType>
  static EnumType ReadEnumValue(const char* variableName, EnumType minValue, EnumType maxValue, EnumType defaultValue);

  static void _InitPipeliningMode();
  static int  _InitPipeliningSequential();
  static int  _InitCheckLifecycle();
  static void _InitAmbianceVersioning();
  static void _InitHighlightVersioning();
  static void _InitDraw();
  static void _InitDeferredDraw();
  static void _InitVisMaterialDebugMode();
  static void _InitEnv();

  static short _IS_INIT_DONE;
  static short _CATVISCHECKUP_SURFACICREP;
  static short _CATVISCHECKUP_CGRCONTAINER;
  static short _DEBUGLIGHTSCENEGRAPH;
  static short _DEBUGLIGHTSCENEGRAPHSTACK;
  static short _HAS_ASSERT_IN_DESTROY_GP;
  static short _CATVIS_LDH_NOSHOW;
  static short _IS_FAST_OPEN_GA;
  static short _NUM_TRANSPARENCY_LAYERS;
  static int _CATVIS_NB_SAMPLES_FSAA;
  static short _ALLOW_SGIX_ON_HPUX;
  static int _CATVIS_FSAA_WHILE_MOVING;
  static int _CAT_KERNING;// TUV 30 May 2008 IR 625611
  static int _CAT_DRAW_PIXELIMAGE_OLD_ALPHA;// TUV 4 May 2011 IR 053188
  static int _CATVIS_DRAW_VERSION;
  static int _CATVIS_DEFEREDDRAW_VERSION;
  static int _CAT_PRIORITIZE_SKETCHER_RENDERING;
  static int _CATUNWRAPSHM;
  static int _CATVBOInShared; // GF8: VBO In Shared memory?
  static int _CAT_VID_GP_TOOLBAR; //++H55
  static bool _PIPELINING;
  static int _PIPELINING_SEQUENTIAL; // draw executed after the cull and not in parallel
  static int _CHECK_LIFECYCLE;
  static int _NEW_QUALITY_MGT_ACTIVE;
  static int _CATVIS_AMBIANCE_VERSION;
  static int _CATVIS_HIGHLIGHT_VERSION;
  static int _VIS_MATERIAL_DEBUG_MODE;
  static short _TESSELATION_MODE;
  static short _CATREP_ADDREF_RELEASE_MODE; //D1A: Rep Lifecycle (June 2017)
  static short _CATVisNoGraphicalAPI; //E8C: CATVisNoGraphicalAPI mode
  static short _CATVisHeadlessAPI; //OU4: A2X mode
  static short _SGForceMonothreadedUnstreaming; //TPG: sg force monothreaded unstreaming (April 2020)
  static short _SG_MutexForCATSysDRMDocument; //TPG: sg MutexForCATSysDRMDocument
  static short _SGUseTBBCGRsMT; //TPG: sg Use TBB for CGRsMT
  static short _SGUseTBBAlloc; //TPG: sg Use TBBAlloc
  static short _SGStreamVis2DPrimitiveGroupRep; //TPG: sg Stream Vis2DPrimitiveGroupRep
	static short _SGAssertIfLifecycleIssue; //E8C: sg Assert if CATRep lifecycle broken (April 2020)
  static short _VIS_AREA_LIGHT_CLIP_QUAD; //KML4: For ClipQuad implemention of AreaLight(Rectangle) 
	static short _ONE_CONTAINER_CGR; //E8C: new CGR structure
  
  static bool _HCSSE_Enabled;
  static bool _HCSSE_Activation_Forced;
  static double _HCSSE_Forced_Threshold_Value;
  static VisSgForceNodesDeletionMode _VisSg_Force_Nodes_Deletion_Mode;

  static bool _UseVisPoolAllocator;
  static bool _ActivateNewRefPlaneVisu;
};

//-----------------------------------------------------------------------

#endif
