// COPYRIGHT DASSAULT SYSTEMES 2004
// API d'appel pour la statistique PCS

// include system

# ifndef _CATSYSPCSSTAT_H
# define _CATSYSPCSSTAT_H

// include CATIA
#include "JS03TRA.h"
#include "CATIStatsThematics.h"
#include "CATIStatsManager.h"
#include "CATSysPCSStat.h"

/*
PCS Statistics

  a few remarks :
  - to generate an output, the statistics thematics used in the method CATSysPCSStart, ie iThematicsName parameter
  MUST be activated through the Tools/Options/statistics panel
  - the value of the memory is given at the beginning and at the end of a PCS statistics event
  - the memory field can have 2 names corresponding to 2 different values :
		- start_mem and end_mem correspond to the current value of the memory
	OR	- start_max and end_max correspond to the last memory peak
*/


/*
 start of the PCS statistics
 iActivationLevel : indicates the level of activation ; all statistics with level equal or less than iActivationLevel will be activated
 iCumulationLevel : indicates the cumulation level ; all statistics with level is bigger than iCumulation are cumulated in only one line for each event familly.
					iCumulatedLevel must be less or equal than iActivationLevel
 */

ExportedByJS03TRA HRESULT CATSysPCSStart( int iActivationLevel, int iCumulationLevel=0);

/*
 stops the generation of pcs statistics
*/
ExportedByJS03TRA HRESULT CATSysPCSStop();

/*
 starts a PCS statistics event
 iLevel : activation level of the statistics
 iField : first additionnal field
 iValue : first additionnal value
 oEventId : identifiant of the event ; used in the AddField and EndEvent methods
*/
ExportedByJS03TRA HRESULT CATSysPCSBeginEvent(int iLevel, const char * iField, const char * iValue, CATStatsEventId *oEventId);

/*
 adds field to a PCS statistics event
 iField : additionnal field
 iValue : additionnal value
 iEventId ; identifiant of the event to which the additive field is added
*/
ExportedByJS03TRA HRESULT CATSysPCSAddField(const char * iField, const char * iValue, CATStatsEventId *iEventId);

/*
 ends a PCS statistics event
 iEventId ; identifiant of the event to end
*/
ExportedByJS03TRA HRESULT CATSysPCSEndEvent(CATStatsEventId *iEventId);

/*
 * to check whether a level is active or not
 * returns 1 if is active
 * returns 0 if not or in case of failure
 */
ExportedByJS03TRA int IsCATSysPCSStatActive (int iLevel);



# endif


