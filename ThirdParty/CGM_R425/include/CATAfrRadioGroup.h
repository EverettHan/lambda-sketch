/* -*-C++-*- */
// Copyright Dassault Systemes 2014
//-----------------------------------------------------------------------------
// Abstract: 
//-----------------------------------------------------------------------------
// Usage:    
//           
//-----------------------------------------------------------------------------
// Inheritance: CATAfrRadioGroup
//                CATCommandHeader
//-----------------------------------------------------------------------------
// Main methods:    
//       
//-----------------------------------------------------------------------------
#ifndef CATAfrRadioGroup_H
#define CATAfrRadioGroup_H

#include "CATAfrFoundation.h"
#include "CATCommandHeader.h"
#include "CATISYPCollection.h"
#include "CATSYPArray.h"

class CATCommandHeader;

#include "CATListOfCATString.h"

class ExportedByCATAfrFoundation CATAfrRadioGroup : public CATCommandHeader
{ 
  CATDeclareKindOf;
  
public:
  CATDeclareCBEvent(SetSelectedItemEvent);

  CATAfrRadioGroup ();
  CATAfrRadioGroup (const CATString & );
  virtual ~CATAfrRadioGroup();
  
  virtual CATCommandHeader * Clone();
  
  virtual CATCommand * StartCommand();

  virtual void InitSelectedHdr(const CATString &);
  
  CATListOfCATString  GetHdrList();
  
  /////////////////////////////////////////////////////////////////////////////
  // Implementation of the methods that are declared in the CATISYPCollection
  // interface.
  // These methods are used to allow the Style Processor to manipulate this
  // class as a collection.
  ////////////////////////////////////////////////////////////////////////////
  /**
   * @name CATISYPCollection implementation
   */
  /*@{*/ 
    virtual CATISYPCollection_var GetItems();
	/** @copydoc CATISYPCollection#GetAt */
	virtual CATBaseUnknown_var GetAt( int i_index );
	/** @copydoc CATISYPCollection#GetCount */
	virtual int GetCount();
	/** @copydoc CATISYPCollection#Append */
	virtual void Append( const CATBaseUnknown_var &i_spObject );
	/** @copydoc CATISYPCollection#AppendList */
	virtual void AppendList( const CATSYPConstArray<CATBaseUnknown_var> &i_list );
	/** @copydoc CATISYPCollection#Remove */
	virtual void Remove( const CATBaseUnknown_var &i_spObject );
	/** @copydoc CATISYPCollection#RemoveList */
	virtual void RemoveList( const CATSYPConstArray<CATBaseUnknown_var> &i_list );
	/** @copydoc CATISYPCollection#Clear */
	virtual void Clear();
  /** @copydoc CATISYPCollection#Contains */
  virtual int Contains( const CATBaseUnknown_var &i_spObject );
	/** @copydoc CATISYPCollection#Append */
	virtual void Append( const CATLISTV(CATBaseUnknown_var) &i_list );
  /*@}*/
  
  // Get Active command Header
  CATCommandHeader * GetActiveCmdHdr();

  // Set Active command Header 
  virtual void SetActiveCmdHdr( CATCommandHeader * iHeader );

  void InitToFirst();
  CATCommandHeader * Next();

  void        AddItem   (CATCommandHeader * ipHeader);

  void InitFromHdr(CATCommandHeader * iheader );

  int GetNoUncheck();
  void SetNoUncheck(int iNoUncheck);

  //NO DOc Internal use only
  void        UpdateHdrs();

  void CheckedRHCB (CATCommandHeader *iHdr);

void AddItem(const CATString& cmdName);
void BeginItem(const CATString& cmdName);
void EndItem(const CATString& cmdName);
void RemoveItem(const CATString& cmdName);

int GetHLSize();

int  GetCloned();
void SetCloned(int iclonestatus);
 
virtual void AcceptVisitor(AfrICommandHeaderVisitor* i_pVisitor) override;

protected:
  CATAfrRadioGroup (CATCommandHeader *);
  
private:

  void        BeginItem (CATCommandHeader * ipHeader);
  void        EndItem   (CATCommandHeader * ipHeader);
  void        RemoveItem(CATCommandHeader * ipHeader);

  // Headers stored inside this list are not addref.
  CATListOfCATString _commandHeaders;
  int _iterator;
  CATCommandHeader * _pActiveHdr;
  int _CheckCBStatus;
  int _NoUncheck;

  int _Cloned;

  //ID du Header Initialisé
  CATString _InitCmdHdr;

  //CATDeclareHeaderResources;

  void CheckedRHCB (CATCallbackEvent, void *, CATNotification *, CATSubscriberData, CATCallback);


};
#endif
