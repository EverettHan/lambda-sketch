#ifndef CATCXEventImplicitFactoryLife_H
#define CATCXEventImplicitFactoryLife_H
//=============================================================================
// Jul. 04   Argument CATCGMStream* pour Un/Streaming(...)                HCN
//=============================================================================

#include "CATCGMEvents.h"
#include "CATBoolean.h"
#include "CGMV5Interop.h"

class CATICGMSession;
/** @c++ansi fbq 2004-08-05.10:18:26 [Replace forward declaration by #include <iosfwd.h>] **/
#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
class ostream;
#endif
class CATGeoFactory;
class CATCXStreamSizeObject;
class CATDlgEditor;

class ExportedByCGMV5Interop CATCXEventImplicitFactoryLife  : public CATCGMEventImplicitFactoryLife 
{
public:
  //      kindofStreamSizeObject : champ de bits
  //             1 : taille de Stream par Type d'Objet 
  //             2 : taille de Stream pour chaque Object
  CATCXEventImplicitFactoryLife(CATICGMSession   *iSession,
                                ostream          &outputText,
                                int              iSetAllSharpness = 0,
                                CATGeometricType iSharpnessTargetType = CATEdgeType,
                                short             kindofStreamSizeObject = 1,
                                CATBoolean        withTrace = TRUE,
                                CATDlgEditor     *iEditor = NULL); 

  ~CATCXEventImplicitFactoryLife(); 
  CATCGMNewClassArrayDeclare;
  
  void Creating(CATGeoFactory *iFactory);
  void Closing(CATGeoFactory *iFactory, short iContext);
  void UnStreaming(CATGeoFactory *iFactory, CATCGMStream* ipStr, short iContext);
  void Streaming(CATGeoFactory *iFactory, CATCGMStream* ipStr, short iContext);
  void CommonDump(CATGeoFactory *iFactory, short iContext);

  CATCXStreamSizeObject *_ForDump;

private :

  ostream & _outputText;
  int              _SetAllSharpness;
  CATGeometricType _SharpnessTargetType;
  short            _kindofStreamSizeObject;
  CATBoolean       _withTrace;
  CATDlgEditor    *_Editor;
};

#endif
