/**
 * @level Private
 * @usage U1
 */
// COPYRIGHT DASSAULT SYSTEMES 2000
//===================================================================
//
// CATOMBAbendInfo.h
// Header definition of CATOMBAbendInfo
//
//===================================================================
//
// Usage notes:
//
//===================================================================
//
//  Mar 2000  Creation: Code generated by the CAA wizard  hhm
//===================================================================
#ifndef CATOMBAbendInfo_H
#define CATOMBAbendInfo_H

#include "AC0XXLNK.h"
#include "CATAbendInfo.h"

//-----------------------------------------------------------------------

class ExportedByAC0XXLNK CATOMBAbendInfo: public CATAbendInfo
{
  public:

  // Standard constructors and destructors
  // -------------------------------------
     CATOMBAbendInfo (/*CAT_ABEND_OMB_INFO*/);
     virtual ~CATOMBAbendInfo ();

  // SymbolicLinkInfo Management
  // -------------------------------------
	 int SetSymbolicLinkRemoveIsA(const char* type);
	 int SetFatherSymbolicLinkRemoveIsA(const char* type);
	 
  /*0004 nll - SpecsModeler data integration
     iType : late type - this is a static class data, so don't worry.
  */
	//int SetSpecData(const char* iType);
	// will be replaced by two methods : for remove and stream/unstream
	int SetSpecRemoveData(const char* iType);
	int SetSpecPhyRemoveData(const char* iType);
	int SetSpecContRmData(const char* iType);
	int SetSpecStreamData(const char* iType);
        int SetSpecTransacData(int infoType, const char* type_mod, const char* type_cont);
	int SetNavigInstData(const char* iType);

	virtual char * Dump();

  private:
  // SymbolicLinkInfo Management
  // -------------------------------------
	char * _SymbolicLinkRemoveIsA;
	char * _SymbolicLinkRemoveFatherIsA;
  // Specs management
    const char*  _spec_rm_type;
    const char*  _spec_phy_rm_type;
    const char*  _spec_rm_cont_type;
    const char*  _spec_str_type;
    const char* _tr_operation;
    const char* _tr_cont_type;
    const char* _tr_mod_type;
	// CATNavigInstance en cours de Remove
	const char* _NavigInst;

};

//-----------------------------------------------------------------------

#endif