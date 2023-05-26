/* -*-C++-*- */
// Copyright Dassault Systemes 1997
//-----------------------------------------------------------------------------
// Abstract: 
//-----------------------------------------------------------------------------
// Usage:    
//           
//-----------------------------------------------------------------------------
// Inheritance: CATFrmCheckHeader
//                CATCheckHeader
//-----------------------------------------------------------------------------
// Main methods:    
//       
//-----------------------------------------------------------------------------
#ifndef CATFrmCheckHeader_H
#define CATFrmCheckHeader_H

#include "CATAfrFoundation.h"
#include "CATCheckHeader.h"

class ExportedByCATAfrFoundation CATFrmCheckHeader : public CATCheckHeader
{ 
   CATDeclareClass;

   public:
      CATFrmCheckHeader ();
      CATFrmCheckHeader (const CATString &);
      virtual ~CATFrmCheckHeader();

      virtual CATCommandHeader * Clone();

      virtual CATCommand * StartCommand();

      void        SetCheckCommand  (const CATString& ChkCmdName);
      void        SetUncheckCommand(const CATString& UchkCmdName);
      CATString & GetCheckCommand  ();
      CATString & GetUncheckCommand();

      void        SetResourceFile(const CATString& fileName);
      CATString GetResourceFile();

      virtual CATString GetIconName(int iIconType = 0);

 //     void RegisterEnveloppe(CATBaseUnknown *);

      virtual void AcceptVisitor(AfrICommandHeaderVisitor* i_pVisitor) override;

   protected:
      CATFrmCheckHeader (CATCommandHeader *);

   private:
      CATString    _chkCmdName, _uchkCmdName;
      CATString    _resourceFileName;
//      CATBaseUnknown *_enveloppe;

  CATDeclareHeaderResources;
};
#endif
