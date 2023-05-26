#ifndef DSYSysTraceSystemMigration_H
#define DSYSysTraceSystemMigration_H

#ifdef _IOS_SOURCE
//# define DSY_SYS_TRACE_SYSTEM_MIGRATION
# undef DSY_SYS_TRACE_SYSTEM_MIGRATION
#else // _IOS_SOURCE
# undef DSY_SYS_TRACE_SYSTEM_MIGRATION
#endif  // _IOS_SOURCE

#ifdef DSY_SYS_TRACE_SYSTEM_MIGRATION
/************************************************************************/
/* Defines                                                              */
/************************************************************************/

//=======================================================================
//==[ CATFMDebug.h ]=====================================================
//=======================================================================
# define FOCUS_MANAGER_FLAG                                           0x01
# define FOCUS_MANAGER_STRG                                           "Focus_Manager"

# define CMD_SUPER_DEBUG_FLAG                                         0x02
# define CMD_SUPER_DEBUG_STRG                                         "CmdSuperDebug"

# define RECORD_DEBUG_FLAG                                            0x03
# define RECORD_DEBUG_STRG                                            "RecordDebug"

# define RECORD_SPEC_FLAG                                             0x04
# define RECORD_SPEC_STRG                                             "RecordSpec"
//=======================================================================

//=======================================================================
//==[ CATCBAKDebug.h ]===================================================
//=======================================================================
# define CALLBACK_DEBUG_FLAG                                          0x05
# define CALLBACK_DEBUG_STRG                                          "CallbackDebug"
//=======================================================================

//=======================================================================
//==[ CATErrorDebug.h ]==================================================
//=======================================================================
# define ERROR_DEBUG_FLAG                                             0x06
# define ERROR_DEBUG_STRG                                             "CATErrorDebug"

# define ERROR_TRACE_FLAG                                             0x07
# define ERROR_TRACE_STRG                                             "CATErrorTrace"

# define CHKPT_DEBUG_FLAG                                             0x08
# define CHKPT_DEBUG_STRG                                             "CheckPtDebug"

# define SESSI_DEBUG_FLAG                                             0x09
# define SESSI_DEBUG_STRG                                             "SessionStats"
//=======================================================================

//=======================================================================
//==[ CATCOMPDebug.h ]===================================================
//=======================================================================
# define COMP_DEBUG_FLAG                                              0x0A
# define COMP_DEBUG_STRG                                              "STGObj"

# define STGINTERFACE_DEBUG_FLAG                                      0x0B
# define STGINTERFACE_DEBUG_STRG                                      "STGINTERFACE"

# define TOCDUMP_DEBUG_FLAG                                           0x0C
# define TOCDUMP_DEBUG_STRG                                           "TOCDUMP"
//=======================================================================

//=======================================================================
//==[ CATBaseUnknownDebug.h ]============================================
//=======================================================================
# define OLE_DEBUG_FLAG                                               0x0D
# define OLE_DEBUG_STRG                                               "OleDebug"
//=======================================================================

//=======================================================================
//==[ CATBaseUnknownDebug.h ]============================================
//=======================================================================
# define DICOSTRING_DEBUG_FLAG                                        0x0E
# define DICOSTRING_DEBUG_STRG                                        "DicoString"
//=======================================================================

//=======================================================================
//==[ CATBaseUnknownDebug.h ]============================================
//=======================================================================
# define INTERFACE_DEBUG_FLAG                                         0x0F
# define INTERFACE_DEBUG_STRG                                         "InterfaceDebug"
//=======================================================================

//=======================================================================
//==[ CATMrshlDebug.h ]==================================================
//=======================================================================
# define MARSHAL64_DEBUG_FLAG                                         0x10
# define MARSHAL64_DEBUG_STRG                                         "Marshal64Trace"
//=======================================================================

//=======================================================================
//==[ CATStdLibDebug.h ]=================================================
//=======================================================================
# define DLNAME_DEBUG_FLAG                                            0x11
# define DLNAME_DEBUG_STRG                                            "DLName"
//=======================================================================

//=======================================================================
//==[ CATCounterInfraDebug.h ]===========================================
//=======================================================================
# define COUNTERINFRA_DEBUG_FLAG                                      0x12
# define COUNTERINFRA_DEBUG_STRG                                      "CounterInfraTrace"
//=======================================================================

/************************************************************************/
/************************************************************************/

# undef traprint
# define traprint(tracedescriptor, level, message, ...)               \
  do {                                                                \
    TRAOPEN()                                                         \
                                                                      \
    register DSYSysTrace* l_pTrace = __TRAPRINT(tracedescriptor);     \
    if ( l_pTrace != NULL ) l_pTrace->Info(level, message, ##__VA_ARGS__);\
  } while ( 0 )

# undef traput
# define traput(tracedescriptor, level, message)                      \
  traprint(tracedescriptor, level, "%s", message)

# undef TRAOPEN
# define TRAOPEN()                                                    \
  __TRAOPEN();

# undef TRAPRINT
# define TRAPRINT(prefix, level, message, format, ...)                \
  TRAOPEN()                                                           \
  traprint(FOCUS_MANAGER_FLAG, level, prefix#message" : "#format"", ##__VA_ARGS__);

# undef TRAPUT
# define TRAPUT(prefix, level, message)                               \
  TRAOPEN()                                                           \
  traprint(FOCUS_MANAGER_FLAG, level, "%s", prefix#message);

# define CATDevelopmentStage                                          \
  __CATDevelopmentStage

# define CATTrace                                                     DSYSysCATTrace

/************************************************************************/
/* Global includes                                                      */
/************************************************************************/

/************************************************************************/
/* Local includes                                                       */
/************************************************************************/
# include "DSYSysTrace.h"
# include "DSYSysEnviron.h"
# include "CATSysErrorDef.h"

/************************************************************************/
/* Functions declaration                                                */
/************************************************************************/

//=======================================================================
inline int __CATDevelopmentStage(int** oppPtr = NULL)
//=======================================================================
{
  int l_Ret = 0;

  if ( (DSYSysDevelopmentStage(&l_Ret) == 0) & (l_Ret > 0) )
    l_Ret = -1;

  // Done.
  return l_Ret;
}

/************************************************************************/
/* Classes declaration                                                  */
/************************************************************************/

//Initialisations pour le flag Status
#define CATSysStandarsCounter		0x00000001
#define CATSysCounterInitialized	0x00000002

#define CATSysCounterActive		0x10000000
#define CATSysDynamicCounter		0x20000000

/*
 * Definition de la structure CATSysCounter
 */

struct CATSysCounter
{
	unsigned int GetRef();
	int m_ref;
};

inline unsigned int CATSysCounter::GetRef()
{
  return m_ref;
}

class CATSysCounterInfra
{

/*
 * Attributs de la classe
 */
	const char *_iKey;
	unsigned int _Overflow;
	int _Status;
	unsigned int _Value;

/*
 * Methodes de la classe
 */
public:

	~CATSysCounterInfra()
  {}

	static HRESULT GetMoreCounter (char ** MoreCounterName )
  { return E_FAIL; }
	static HRESULT ActivateAll ()
  { return E_FAIL; }

	static HRESULT Activate (const char * iKey)
    { return E_FAIL; }
	
// methode pour creer un compteur
	static HRESULT Get ( const char *iKey ,CATSysCounter *iCounter, const char * iFamily , int iFlags)
    { return E_FAIL; }

// methode pour augmenter la valeur du compteur de iDelta	
	static inline HRESULT Modify(unsigned int iIdx, unsigned int iDelta)
    { return E_FAIL; }

// methode pour positionner la valeur du compteur a iNewVal
	static inline HRESULT Set (unsigned int iIdx, unsigned int iNewVal )
    { return E_FAIL; }

// methode utilisee pour construire le tableau de compteurs
	static HRESULT CreateCounter ( const char * iKey )
    { return E_FAIL; }

//methode pour initialiser les tableaux de compteurs.
	static HRESULT InitializeCounters ()
    { return E_FAIL; }

//methode pour ecrire le fichier de sortie
	static HRESULT Out()
    { return E_FAIL; }

	static int AtExit(int iExit)
    { return 0; }

//methodes pour renvoyer en cours de route les valeurs des compteurs
	static HRESULT GetFirst( char *oName , size_t oNameLen , unsigned int *oValue)
    { return E_FAIL; }
	static HRESULT GetNext (  char *oName , size_t oNameLen , unsigned int *oValue)
    { return E_FAIL; }
	static HRESULT GetCounterByIndex ( unsigned int iIdx , char *oName , size_t oNameLen , unsigned int *oValue)
    { return E_FAIL; }
	static HRESULT GetValue ( unsigned int iIdx , unsigned int *oValue)
    { return E_FAIL; }
	static HRESULT GetIntermediateResult(unsigned int **&ValueTab, int *NbCounter)
    { return E_FAIL; }

//Gestion du OverFlowHandler
	static HRESULT SetOverflowValue( unsigned int iIdx , unsigned int iValue )
    { return E_FAIL; }
	static HRESULT GetOverflowValue( unsigned int iIdx , unsigned int *oValue )
    { return E_FAIL; }
	HRESULT OverflowDetected (const char * iKey, unsigned int iIdx , unsigned int CurrentValue, unsigned int CurrentOverflow)
    { return E_FAIL; }

private :

	CATSysCounterInfra()
  {}

//methode pour lire fichier d'entree
	static HRESULT In()
    { return E_FAIL; }

private :
	static CATSysCounterInfra * S_ActiveCounters;
	static int S_ActiveCountersNumber;
	static int S_OutType; // sauvegarde le type de sortie (0=console/1=fichier)
	static char * S_Output;//sauvegarde le nom du fichier en cas de sortie fichier
	static int S_IncrementCompteur;
	static int DynamicCounters ;
	static int AllActiveCounters ;
	static int EnumMoreCounter ;
};


#define CATSysCounterStandard(iKey,iFamily)                           \
  {}
#define CATSysAdvCounterDelta(lACHandle,iKey, iFamily,iDeltaValue)    \
  {}
#define CATSysAdvCounterModify( lACHandle, iDeltaValue)
#define CATSysAdvCounterAdd1( lACHandle )
#define CATSysAdvCounterSet( lACHandle, lValue)

# endif // DSY_SYS_TRACE_SYSTEM_MIGRATION
#endif  // DSYSysTraceSystemMigration_H
