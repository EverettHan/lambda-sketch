#ifndef CATCGRSetting_h
#define CATCGRSetting_h

#include "SGInfra.h"

// COPYRIGHT DASSAULT SYSTEMES 2000

/**
 * @CAA2Level L1
 * @CAA2Usage U1
 */

/**
 * @param EDGES
 *   To save edges in CGR file.
 * @param TEXTURE
 *   To save texture in CGR file.
 * @param AXIS
 *   To save axis in CGR file.
 * @param SHOW_AND_NOSHOW
 *   To save the graphical representations lying
 *   in the "show" and "no show" spaces. 
 * @param NO_3DCUSTOMREP
 *   Not to save CAT3DCustomRep.
 * @param LINEIC
 *	 To save lineic informations in CGR file.
 * @param NO_LODS
 *	 Not To save Levels of details in CGR file.
 * @param NO_ISOPARS
 *   To save isopars information in CGR file.
 * @param 2DLINEIC
 *   To save 2D Lineic information in CGR file.
 * @param SHOWFREEMODE
 *   To save hidden layer information in CGR file.
 * @param NO_MATERIAL
 *   Materials are not saved in CGR file.
 * @param NO_SGCOMP
 *   SG Composites are not saved in CGR file.
 * @param TEXT_MESH
 *   CAT2DGeometricTextGP tessellation is saved in CGR file.
 */

/** @nodoc */
#define EDGES             (1 << 0)
/** @nodoc */
#define TEXTURE           (1 << 1)
/** @nodoc */
#define AXIS              (1 << 2)
/** @nodoc */
#define SHOW_AND_NOSHOW   (1 << 3)
/** @nodoc */
#define NO_3DCUSTOMREP    (1 << 4)
/** @nodoc */
#define DEMO              (1 << 5)
/** @nodoc */
#define LINEIC            (1 << 6)
/** @nodoc */
#define NO_LODS           (1 << 7)
/** @nodoc */
#define NO_ISOPARS        (1 << 8)
/** @nodoc */
#define LINEIC2D          (1 << 9)
/** @nodoc */
#define SHOWFREEMODE      (1 << 10)
/** @nodoc */
#define NO_MATERIAL       (1 << 11)
/** @nodoc */
#define NO_SGCOMP         (1 << 12)
/** @nodoc */
#define TEXT_MESH         (1 << 13)

/**
 * class to specify what kind of data belonging
 * to a graphical representation we want to store
 * in a CGR file.
 */
class ExportedBySGInfra CATCGRSetting
{
public :
  
  /**
   * Constructs a setting to specify the graphical data type
   * we want to store in a CGR file.
   * @param iSetting
   *   The setting we want. This integer is obtained by
   *   combining the flags defined above.
   *   For example, if you need to save your graphical representation
   *   in a CGR file, with its edges, its texture, the axis, but without
   *   the CAT3DCustomRep that could be in the scene, you have to specify the following
   *   setting : <pre> EDGES | TEXTURE | AXIS | NO_3DCUSTOMREP </pre>.
   *   The default value is <pre> EDGES | TEXTURE </pre>.
   */
  CATCGRSetting(int iSetting = EDGES | TEXTURE);

  /**
   * Copy constructor.
   */
  CATCGRSetting(CATCGRSetting *ipBrother);
  
  virtual ~CATCGRSetting();
  
  /**
   * Sets the setting.
   * @param iSetting
   *    the wanted setting.
   */
  void SetSetting(int iSetting);

  /**
   * Gets the setting.
   */
  int GetSetting() const;
  
  /**
   * Sets the edges flag to "on" or "off".
   * @param iOnOff
   *   1 to save edges in the CGR file, 0 otherwise.
   */
  void SetEdgesFlag(int iOnOff);

  /**
   * Gets the edges flag.
   * @return
   *   1 means that edges are to be stored in the CGR file.
   *   0 means the contrary.
   */
  int GetEdgesFlag() const;

  /**
   * Sets the texture flag to "on" or "off" .
   * @param iOnOff
   *   1 to save texture in the CGR file, 0 otherwise.
   */
  void SetTextureFlag(int iOnOff);

  /**
   * Gets the texture flag.
   * @return
   *   1 means that texture is to be stored in the CGR file.
   *   0 means the contrary.
   */
  int GetTextureFlag() const;

  /**
   * Sets the axis flag to "on" or "off" .
   * @param iOnOff
   *   1 to save axes in the CGR file, 0 otherwise.
   */
  void SetAxisFlag(int iOnOff);

  /**
   * Gets the axis flag.
   * @return
   *   1 means that axes are to be stored in the CGR file.
   *   0 means the contrary.
   */
  int GetAxisFlag() const;

  /**
   * Sets the "show and no show" flag to "on" or "off" .
   * @param iOnOff
   *   1 to save "show" and "no show" spaces in the CGR file, 0 otherwise.
   */
  void SetShowAndNoShowFlag(int iOnOff);

  /**
   * Gets the "show and no show" flag.
   * @return
   *   1 means that "show and no show" spaces are to be stored in the CGR file.
   *   0 means the contrary.
   */
  int GetShowAndNoShowFlag() const;
  
  /**
   * Sets the "show free mode" flag to "on" or "off" .
   * @param iOnOff
   *   1 to save hidden layer information in the CGR file, 0 otherwise.
   */
  void SetShowFreeModeFlag(int iOnOff);

  /**
   * Gets the "show and no show" flag.
   * @return
   *   1 means that hidden layer information have also to be stored in the CGR file.
   *   0 means the contrary.
   */
  int GetShowFreeModeFlag() const;

    /**
   * Sets the "no CAT3DCustomRep" flag to "on" or "off".
   * @param iOnOff
   *   1 not to save CAT3DCustomRep in the CGR file, 0 otherwise.
   */
  void SetNo3DCustomRepFlag(int iOnOff);

  /**
   * Gets the "No CAT3DCustomRep" flag.
   * @return
   *   1 means that CAT3DCustomRep must not be stored in the CGR file.
   *   0 means the contrary.
   */
  int GetNo3DCustomRepFlag() const;

  /**
   * Sets the demo flag to "on" or "off".
   * @param iOnOff
   *   1 to save the CGR file as a demo file, 0 otherwise.
   */
  void SetDemoFlag(int iOnOff);

  /**
   * Gets the demo flag.
   * @return
   *   1 means that the CGR file is a demo file.
   *   0 means the contrary.
   */
  int GetDemoFlag() const;

  /**
   * Sets the lineic flag to "on" or "off".
   * @param iOnOff
   *   1 to save the lineic informations (wiredege - linerep) in the CGR file, 
   *   0 otherwise.
   */
  void SetLineicFlag(int iOnOff);

  /**
   * Gets the lineic flag.
   * @return
   *   1 means that the lineic informations are stored int the CGR file,
   *   0 means the contrary.
   */
  int GetLineicFlag() const;
  
  /**
   * Sets the 2Dlineic flag to "on" or "off".
   * @param iOnOff
   *   1 to save the 2D lineic informations (CAT2D...GP) in the CGR file, 
   *   0 otherwise.
   */
  void Set2DLineicFlag(int iOnOff);

  /**
   * Gets the 2Dlineic flag.
   * @return
   *   1 means that the 2D lineic informations are stored int the CGR file.
   *   0 means the contrary.
   */
  int Get2DLineicFlag() const;

  /**
   * Sets the nolod flag to "on" or "off".
   * @param iOnOff
   *   1 Not to save the lods in the CGR file, 
   *   0 otherwise.
   */
  void SetNoLodsFlag(int iOnOff);

  /**
   * Gets the nolod flag.
   * @return
   *   1 means that the lods are not stored int the CGR file,
   *   0 means the contrary.
   */
  int GetNoLodsFlag() const;

  /**
   * Sets the target sags for the LOD containers.
   * @param iSags
   *   The target sags
   * @param iNbContainers
   *   The number of containers to store in the CGR.
   */
  void SetTargetLodsSags(const float * iSags, int iNbContainers);

  /**
   * Sets the target sags for the LOD containers.
   * @param oSags
   *   The target sags
   * @param oNbContainers
   *   The number of containers to store in the CGR.
   */
  void GetLodsSags(const float * & oTargetSags, float * & oRealSags, int & oNbContainers) const;

  /**
   * Sets the target sags for the LOD containers.
   * @param oSags
   *   The target sags
   * @param oNbContainers
   *   The number of containers to store in the CGR.
   */
  void GetRealLodsSags(float * & oSags, int & oNbContainers) const;

  /**
   * Sets the isopars flag to "on" or "off".
   * @param iOnOff
   *   1 Not to save the isopars in the CGR file, 
   *   0 otherwise.
   */
  void SetNoIsoparsFlag(int iOnOff);

  /**
   * Gets the isopars flag.
   * @return
   *   1 means that the isopars are not stored int the CGR file,
   *   0 means the contrary.
   */
  int GetNoIsoparsFlag() const;

  /**
   * Sets the material flag to "on" or "off".
   * @param iOnOff
   *   1 Materials are not saved in the CGR file, 
   *   0 Materials are saved.
   */
  void SetNoMaterialFlag(int iOnOff);

  /**
   * Gets the material flag.
   * @return
   *   1 means that the materials are not stored int the CGR file,
   *   0 means the contrary.
   */
  int GetNoMaterialFlag() const;

  /**
   * Sets the SG Composites flag to "on" or "off".
   * @param iOnOff
   *   1 SG Composites are not saved in the CGR file,
   *   0 SG Composites are saved.
   */
  void SetNoSGCompFlag(int iOnOff);

  /**
   * Gets the SG Composites flag.
   * @return
   *   1 means that the SG Composites are not stored int the CGR file,
   *   0 means the contrary.
   */
  int GetNoSGCompFlag() const;

  /**
   * Sets the text mesh flag to "on" or "off".
   * @param iOnOff
   *   1 : CAT2DGeometricTextGP tessellation is saved in CGR file.
   *   0 : CAT2DGeometricTextGP tessellation is not saved in CGR file.
   */
  void SetTextMeshFlag(int iOnOff);

  /**
   * Gets the text mesh flag
   * @return
   *   1 : CAT2DGeometricTextGP tessellation is saved in CGR file.
   *   0 : CAT2DGeometricTextGP tessellation is not saved in CGR file.
   */
  int GetTextMeshFlag() const;

private:
  
  int     _Setting;
  float * _TargetLODSags;
  float * _RealLODSags;
  int     _nbLODContainers;
};

#endif
