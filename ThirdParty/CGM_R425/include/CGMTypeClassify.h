#ifndef CGMTypeClassify_H
#define CGMTypeClassify_H
//=============================================================================
// COPYRIGHT DASSAULT SYSTEMES  2002
//  Classification des Objets de la CATGeoFactory
//
#include "CGMV5Interop.h"
#include "CATDataType.h"
#include "CATListOfCATCGMObjects.h"
#include "CATCGMNewArray.h"
#include "CATListOfCGMTypeClassify.h"
#include "CATBoolean.h"
#include "CATRootContainerGEO.h"
#include "CATCGMHashNames.h"
#include "CATCGMDefType.h"

class CATHashTabCGMTypeClassify;
class CATRootContainerGEO;
class CATCGMAttributeDef;
 

class ExportedByCGMV5Interop CGMTypeClassify
{
public:
  CGMTypeClassify(const char *iCGMTypeName, const short iOldType);
  ~CGMTypeClassify();
  CATCGMNewClassArrayDeclare;  
  
  static const char * GetDefType(CATCGMAttributeDef *  iDefinition, short itp, CATBoolean iCore = FALSE);



  static void GetVision( CATRootContainerGEO       *   implctr,
                         CATHashTabCGMTypeClassify * & ioCGMTypes,
                         CATLISTP(CGMTypeClassify) * & ioListOfTypes,
                         CATBoolean                    iGetMemoryBytes = FALSE);

  inline int  GetNumberOfBlocs() const;


  inline const CATLISTP(CATCGMObject) & GetInstances() const;
  inline int  GetInstancesSize() const;
  inline int  GetLyingOnSize() const;
  inline int  GetSharpnessSize() const;
  inline int  GetAttributeSize() const;

  void AddInstance(CATCGMObject *iObject, CATCGMAttributeDef *  iDefinition);

  void AddLyingOn(int iNewLyingOn);
  void AddSharpness(int iNewSharpness);
  void AddAttributes(int iNewAttributes);
 
  size_t GetStaticMemoryBytes();
  size_t GetDynamicMemoryBytes();

  size_t GetKnotVectorStaticMemoryBytes();
  size_t GetKnotVectorDynamicMemoryBytes();


  const char * _CGMTypeName;

  CATULONG32 _Cumulated;
  CATULONG32 _CumulatedLyingOn;
  CATULONG32 _CumulatedSharpness;
  CATULONG32 _CumulatedAttribute;

  int _StaticMemoryBytes;
  int _DynamicMemoryBytes;

  int _KnotVectorStaticMemoryBytes;
  int _KnotVectorDynamicMemoryBytes;
  
  static void ManageAtExit();

  short _OldType;

private:


  static CATCGMHashNames * _CGMTypeNames; 
  static CATULONGPTR       _CGMTypeNamesIndex; 
  

  static CATCGMDefTypes  * _CGMDefTypes; 
 
  int                    _NumberOfBlocs;

  CATLISTP(CATCGMObject) _Instances;
  int                    _NbLyingOn;
  int                    _NbSharpness;
  int                    _NbAttr;

};



inline int   CGMTypeClassify::GetNumberOfBlocs() const
{
  return _NumberOfBlocs;
}


inline int  CGMTypeClassify::GetInstancesSize() const
{
  return _Instances.Size();
}

inline int   CGMTypeClassify::GetLyingOnSize() const
{
  return _NbLyingOn;
}

inline int   CGMTypeClassify::GetSharpnessSize() const
{
  return _NbSharpness;  
}
inline int   CGMTypeClassify::GetAttributeSize() const
{
  return _NbAttr;
}
//-----------------------------------------------------------------------------
// GetInstances
//-----------------------------------------------------------------------------
inline const CATLISTP(CATCGMObject) & CGMTypeClassify::GetInstances() const
{
  return _Instances;
}



#endif
