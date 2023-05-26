/* -*-c++-*- */
// COPYRIGHT DASSAULT SYSTEMES 2007

#ifndef CATOmbLinkDoctorListener_h
#define CATOmbLinkDoctorListener_h

/**
 * @level Protected
 * @usage U5
 */


#include "CATObjectModelerBase.h"
#include "IUnknown.h"

class CATOmbBeforeSwitchEvent;
class CATOmbLinkDoctorGlobalStatus;


/**
 * LinkDoctor listener
 */
class ExportedByCATObjectModelerBase CATOmbLinkDoctorListener
{
public:
 /**
  * The Tool has 2 phases : Checking and Repairing
  */ 
 enum Phase {Checking, Repairing};
 /**
  * The tool informs the listener of the percentage of completion of each 
  * phase
  */
 virtual void ReportCompleted(int completionStatus,Phase current)=0 ;  

 /**
  * In some cases, the tool needs to switch the selecting loading state.
  * By returning S_FALSE, the listener can interrupt the tool 
  * before any modification of the session.
  */
 virtual HRESULT ReportRequestSwitching ( CATOmbBeforeSwitchEvent& event)=0;
 
 /**
  * At the end of the checking phase, the doctor returns a global proposal.
  * By Returning E_FAIL , the listener can interrupt the tool before 
  * the repairing phase
  */
 virtual HRESULT ReportRepairProposal(CATOmbLinkDoctorGlobalStatus& status)=0 ;

 /**
  * At the end of the repairing phase,the doctor returns  
  * a status of all operations performed
  */
 virtual void ReportFinalResult(CATOmbLinkDoctorGlobalStatus& status)=0;

protected:
 /**
  * Default constructor
  */
 CATOmbLinkDoctorListener() {};
 /**
  * Default destructor
  */
 ~CATOmbLinkDoctorListener() {};

private:
	//Not Implemented
	CATOmbLinkDoctorListener (const CATOmbLinkDoctorListener& );
  CATOmbLinkDoctorListener & operator=(const CATOmbLinkDoctorListener &);
};
#endif
