
//   COPYRIGHT DASSAULT SYSTEMES 2002


/****************************************************************************************
 *					Class CATSysCounterInfra											*
 ****************************************************************************************/



# ifndef CATSYSCOUNTERINFRACLASS_H
# define CATSYSCOUNTERINFRACLASS_H


#include "CATErrorDef.h"	//pour la definition de HRESULT	
#include "JS03TRA.h"


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

class  ExportedByJS03TRA CATSysCounterInfra
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

	~CATSysCounterInfra();		//destructeur

	static HRESULT GetMoreCounter (char ** MoreCounterName );
	static HRESULT ActivateAll () ;
	static HRESULT Activate (const char * iKey);
	
// methode pour creer un compteur
	static HRESULT Get ( const char *iKey ,CATSysCounter *iCounter, const char * iFamily , int iFlags);

// methode pour augmenter la valeur du compteur de iDelta	
	static inline HRESULT Modify(unsigned int iIdx, unsigned int iDelta);

// methode pour positionner la valeur du compteur a iNewVal
	static inline HRESULT Set (unsigned int iIdx, unsigned int iNewVal );

// methode utilisee pour construire le tableau de compteurs
	static HRESULT CreateCounter ( const char * iKey );

//methode pour initialiser les tableaux de compteurs.
	static HRESULT InitializeCounters ();

//methode pour ecrire le fichier de sortie
	static HRESULT Out();
	static int AtExit(int iExit);

//methodes pour renvoyer en cours de route les valeurs des compteurs
	static HRESULT GetFirst( char *oName , size_t oNameLen , unsigned int *oValue);
	static HRESULT GetNext (  char *oName , size_t oNameLen , unsigned int *oValue);
	static HRESULT GetCounterByIndex ( unsigned int iIdx , char *oName , size_t oNameLen , unsigned int *oValue);
	static HRESULT GetValue ( unsigned int iIdx , unsigned int *oValue);
	static HRESULT GetIntermediateResult(unsigned int **&ValueTab, int *NbCounter);

//Gestion du OverFlowHandler
	static HRESULT SetOverflowValue( unsigned int iIdx , unsigned int iValue );
	static HRESULT GetOverflowValue( unsigned int iIdx , unsigned int *oValue );
	HRESULT OverflowDetected (const char * iKey, unsigned int iIdx , unsigned int CurrentValue, unsigned int CurrentOverflow);

private :

	CATSysCounterInfra();		//constructeur
//methode pour lire fichier d'entree
	static HRESULT In();

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

inline HRESULT CATSysCounterInfra::Modify(unsigned int iIdx, unsigned int iDelta)
{
  if ( iIdx!=0 && static_cast<int>(iIdx) <= S_ActiveCountersNumber && S_ActiveCounters)
  {
    if(S_ActiveCounters[iIdx]._Status & CATSysCounterInitialized)	// on verifie que le compteur est actif
    {								//LA VALEUR DE S_ActiveCounters[iIdx]._Status VARIE SUIVANT STANDARD ET ADVANCED
      S_ActiveCounters[iIdx]._Value=S_ActiveCounters[iIdx]._Value + iDelta;
      if ( S_ActiveCounters[iIdx]._Value > S_ActiveCounters[iIdx]._Overflow )
        S_ActiveCounters[iIdx].OverflowDetected(S_ActiveCounters[iIdx]._iKey , iIdx , S_ActiveCounters[iIdx]._Value , S_ActiveCounters[iIdx]._Overflow);
      return S_OK;
    }
  }
  return E_FAIL;
}
	
inline HRESULT CATSysCounterInfra::Set (unsigned int iIdx, unsigned int iNewVal )
{
  if ( iIdx!=0 && static_cast<int>(iIdx) <= S_ActiveCountersNumber && S_ActiveCounters)
  {
    if( S_ActiveCounters[iIdx]._Status & CATSysCounterInitialized )	//on verifie que le compteur est actif 
    {
      if (iNewVal>S_ActiveCounters[iIdx]._Overflow) 
        S_ActiveCounters[iIdx].OverflowDetected(S_ActiveCounters[iIdx]._iKey , iIdx , S_ActiveCounters[iIdx]._Value , S_ActiveCounters[iIdx]._Overflow);
      S_ActiveCounters[iIdx]._Value=iNewVal;
      return S_OK;
    }	
  }
  return E_FAIL;
}

# endif /* CATSYSCOUNTERINFRACLASS_H */
