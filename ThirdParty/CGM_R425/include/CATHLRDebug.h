/* -*-C++-*-*/
#ifndef CATHLRDebug_H
#define CATHLRDebug_H

//=============================================================================
//
// COPYRIGHT : DASSAULT SYSTEMES 1997
/**
 * CATHLRDebug 
 */
// DESCRIPTION :  class to encapsule the debug information for the HLR
//
// NOTE  : the class includes some debug level for some features ( geometry,
// topology, etc). If the level is set to Off ( the default value), no debug
// information is displayed.
//
// NOTE2 : this class cannot be instancied
//
//=============================================================================
// Abstract Class     : No
// Template Code      : No
// Inline Functions   : No
//=============================================================================
//
// History
//
// Mar. 98   Jose CHILLAN (jch)    Creation            
// Oct. 2000 TPD Mise en place d'ecriture
// Nov. 2000 TPD Mise en place d'un test pour avoir les ecritures que pour une Edge
//
//=============================================================================

#include "CATDataType.h"
#include "HLRDebug.h"

/** @c++ansi fbq 2004-08-05.10:18:26 [Replace forward declaration by #include <iosfwd.h>] **/
#ifdef _CAT_ANSI_STREAMS
#include <iosfwd.h>
#else
class ostream;
#endif

//=============================================================================
// Definition of the debug Macro
// - Put the line "#define CATHLRDEBUG" here in comment if no debug information
// is needed in the whole framework.
// - Add the line "#define CATHLRNODEBUG" at the beginning of a source file
// when you don't want debug informations being activated in it, before the
// commands #include "CATHLRDebug.h" or #include "CATHLRTrace.h"
//=============================================================================
#ifndef CATHLRNODEBUG
// Pour activer les traces, il faut definir la variable "CATTESSDEBUG"
// (enlever le commentaire de la ligne suivante)
//#define CATHLRDEBUG
#endif

// Class include
#include "CATHLRDebugDomain.h"

class ExportedByHLRDebug CATHLRDebug
{
public:

  // Different levels of debug.
  enum DebugLevel { DebugOff, DebugOk1, DebugOk2, DebugOk3, DebugOk4, DebugOk5 };  

  enum Domain { General,
                Geometry,
		Topology,
		Model,
		Performance,
		Projection,
		Silhouette,
		SubModel,
		HiddenPoints,
		HiddenLines,
		Result,
		Cpu,
		CountDomains};

  // Niveau de Blanc pour les traces
  static int          _BlN;

  // Nombre de Blancs : Niveau d'incrémentation
   enum BlancNiv { BlN1  =  0, BlN2  =  2, BlN3  =  4, BlN4  =  6, BlN5  =  8
		 , BlN6  = 10, BlN7  = 12, BlN8  = 14, BlN9  = 16, BlN10 = 18};

//=============================================================================
// METHODS
//=============================================================================
/** Sets the level for a given domain of debug.
 */
  static void SetDomainLevel(CATHLRDebug::Domain     iWhichDomain,
			     CATHLRDebug::DebugLevel iLevel);

/** Gets the level for a domain of debug.
 */
  inline static CATHLRDebug::DebugLevel GetLevelForDomain(CATHLRDebug::Domain iWhichDomain);
  
/** Sets the stream for a given domain of debug.
 */
  static void SetDomainStream(CATHLRDebug::Domain   iWhichDomain,
			      ostream             * iStream);

/** Gets the stream for a domain of debug.
 */
  inline static ostream & GetStreamForDomain(CATHLRDebug::Domain iWhichDomain);
  
//------------------------------------------------------------
// Getting and setting the stream for the debug and the errors
//------------------------------------------------------------
/** Setting the stream of output (default value, when the parameter is NULL,  is cout)
 */
  static void SetDebugStream(ostream * iDebugStream = 0L);

/** Opens  and closes a file debug.out for the outputs.
 */
  static ostream * OpenDebugFile(const char * iName = "/tmp/debug.out");
  static void CloseDebugFile();

/** Getting the stream.
 */
   static inline ostream & GetDebugStream();

/** Stream for the errors. If the stream is NULL, cerr will be used.
 */
  static void SetErrorStream(ostream * iErrorStream = 0L);

/** Getting the stream for the errors.
 */
  inline static ostream & GetErrorStream();

//------------------------------------------------------------
// Methods for the dialog
//------------------------------------------------------------
/** Asks if the dialog is active ( returns 1 if true).
 */
  inline static CATLONG32 IsDialogActive();

/** Activates the dialog.
 */
  static void ActivateDialog();

/** Disactivates the dialog.
 */
  static void DisactivateDialog();

//------------------------------------------------------------
// Methods for the ODTs
//------------------------------------------------------------
/** To display all the traces in a null stream when it is an ODT.
 */
  static void SetODTMode();

/** Tests if the ODT mode is active.
 */
  inline static CATLONG32 IsODTMode();

//------------------------------------------------------------
// Space at the beginning of a line for the trace
//------------------------------------------------------------
  inline static const char * GetSpace(CATHLRDebug::DebugLevel iLevel);

// Special meethod for the dialog
  static void SetDebugAll(CATHLRDebug::DebugLevel iLevel = CATHLRDebug::DebugOk5);
  static void UnsetDebugAll();

//------------------------------------------------------------
// Space at the beginning of a line for the trace
//------------------------------------------------------------
  static inline const char * SetSpace(CATLONG32 iSize);

//------------------------------------------------------------
// Formatting numbers for display
//------------------------------------------------------------
  static const char * ShowDouble(double iValue);
  static const char * ShowInteger(int iValue);

//=============================================================================
// INTERNAL DATAS
//=============================================================================
protected:
// Size of the array for spaces.
  enum {SizeOfArraySpace = 100 };  

// Domains for the debug
  static CATHLRDebugDomain _Domains[];

// Default stream on which the debug informations are sent (default value is cout)
  static ostream * _DebugStream;

// True if a file debut.out as been created
  static int       _StreamIsFile;

// Stream on which the error informations are sent (default value is cerr)
  static ostream * _ErrorStream;

// For the ODT
  static int       _IsODTMode;

// Activate or disactivate the dialog
  static int       _DialogActive;

// Default level (DebugOff if not in development stage, debugOK else)
  static CATHLRDebug::DebugLevel _DefaultLevel;

// Array of chars ( use the tabulate the traces)
  static const char * _Space[8];
  static const char   _Space0[];
  static const char   _Space1[];
  static const char   _Space2[];
  static const char   _Space3[];
  static const char   _Space4[];
  static const char   _Space5[];

  static char         _BufferValues[];
  static const char   _BigSpace[];
  
//=============================================================================
// Avoids the instanciation of the class
//=============================================================================
private:
  CATHLRDebug();
  ~CATHLRDebug();
  static CATLONG32 _ForInitialization;
  // active les ecritures pour cette edge
  static CATLONG32 _LEdgeOK;
  static CATLONG32 _TagEdge;
  // Faces parentes a "_TagEdge"
  static CATLONG32 _TagFace1;
  static CATLONG32 _TagFace2;
  
public:
  static CATLONG32 Initialize();
  inline static CATLONG32 GetLEdgeOK();
  inline static void SetLEdgeOK( CATLONG32 iLEdgeOK );
  static void CalLEdgeOK( CATLONG32 iTagEdge );
  inline static CATLONG32 GetTagEdge();
  inline static void SetTagEdge( CATLONG32 iTagEdge );
  static void CalLFaceOK( CATLONG32 iTagFace );
  inline static CATLONG32 GetTagFace1();
  inline static void SetTagFace1( CATLONG32 iTagFace1 );
  inline static CATLONG32 GetTagFace2();
  inline static void SetTagFace2( CATLONG32 iTagFace2 );
};

//------------------------------------------------------------
// Constant
//------------------------------------------------------------
extern ExportedByHLRDebug const CATHLRDebug::DebugLevel CATHLRCurrentDebugLevel;
extern ExportedByHLRDebug ostream & CATHLRCurrentDebugStream;
enum {CATHLRSizeOfArraySpace = 100 };  
extern ExportedByHLRDebug const char CATHLRArraySpace[]; 

// Function that gives the spaces
inline const char * CATHLRSetSpace(CATLONG32 Size)
{
  return (CATHLRArraySpace + (CATHLRSizeOfArraySpace - Size));
}

//=============================================================================
// INLINE IMPLEMENTATIONS
//=============================================================================

//------------------------------------------------------------
// Getting the debug levels
//------------------------------------------------------------
inline CATLONG32 CATHLRDebug::IsODTMode()
{
  return _IsODTMode;
}

inline ostream & CATHLRDebug::GetErrorStream()
{
  return * _ErrorStream;
}

//------------------------------------------------------------
// Checks if the dialog is active
//------------------------------------------------------------
inline CATLONG32 CATHLRDebug::IsDialogActive()
{
  return _DialogActive;
}

//------------------------------------------------------------
// Space before the sentences
//------------------------------------------------------------
inline const char * CATHLRDebug::GetSpace(CATHLRDebug::DebugLevel Level)
{
  return _Space[Level];
}

//------------------------------------------------------------
// Getting debug levels and streams
//------------------------------------------------------------
inline CATHLRDebug::DebugLevel CATHLRDebug::GetLevelForDomain(CATHLRDebug::Domain WhichDomain)
{
  return (CATHLRDebug::DebugLevel)_Domains[WhichDomain].GetLevel();
}

//-----------------------------------------------------------------------------

inline ostream & CATHLRDebug::GetStreamForDomain(CATHLRDebug::Domain WhichDomain)
{
  return _Domains[WhichDomain].GetStream();
}

//-----------------------------------------------------------------------------

inline ostream & CATHLRDebug::GetDebugStream()
{
  return * _DebugStream;
}

//-----------------------------------------------------------------------------

inline const char * CATHLRDebug::SetSpace(CATLONG32 Size)
{
  return (CATHLRDebug::_BigSpace + (CATHLRDebug::SizeOfArraySpace - Size));
}

//-----------------------------------------------------------------------------

inline CATLONG32 CATHLRDebug::GetLEdgeOK()
{
  return _LEdgeOK;
}

inline void CATHLRDebug::SetLEdgeOK( CATLONG32 LEdgeOK )
{
  _LEdgeOK = LEdgeOK;
  return;
}

inline CATLONG32 CATHLRDebug::GetTagEdge()
{
  return _TagEdge;
}

inline void CATHLRDebug::SetTagEdge( CATLONG32 TagEdge )
{
  _TagEdge = TagEdge;
  return;
}

inline CATLONG32 CATHLRDebug::GetTagFace1()
{
  return _TagFace1;
}

inline void CATHLRDebug::SetTagFace1( CATLONG32 TagFace1 )
{
  _TagFace1 = TagFace1;
  return;
}

inline CATLONG32 CATHLRDebug::GetTagFace2()
{
  return _TagFace2;
}

inline void CATHLRDebug::SetTagFace2( CATLONG32 TagFace2 )
{
  _TagFace2 = TagFace2;
  return;
}

#endif

