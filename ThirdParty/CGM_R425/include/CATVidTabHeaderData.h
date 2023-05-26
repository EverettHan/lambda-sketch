#ifndef CATVidTabHeaderData_h
#define CATVidTabHeaderData_h

// COPYRIGHT Dassault Systemes 2012

// Local framework
#include <CATVidImageAndLabelData.h>
#include <VisuDialog.h>

// System framework
#include <CATBoolean.h>


class ExportedByVisuDialog CATVidTabHeaderData : public CATVidImageAndLabelData
{
  CATDeclareClass;

public:

  // Standard constructors and destructors
  CATVidTabHeaderData ();

  void SetAllowCloseButtonFlag(CATBoolean i_allowCloseButtonFlag);
  CATBoolean GetAllowCloseButtonFlag() const;

protected:

  virtual ~CATVidTabHeaderData ();

private:

  // Copy constructor and equal operator
  CATVidTabHeaderData (CATVidTabHeaderData &);
  CATVidTabHeaderData& operator=(CATVidTabHeaderData& original);

  CATBoolean _allowCloseButtonFlag;
};

extern "C" ExportedByVisuDialog 
HRESULT CATSYPCATVidTabHeaderDataSerializer(const CATBaseUnknown_var& i_spCBU, CATUnicodeString& o_string);

inline int operator == (const CATVidTabHeaderData &i_headerData1, const CATVidTabHeaderData &i_headerData2)
{
  return (i_headerData1.GetAllowCloseButtonFlag() == i_headerData2.GetAllowCloseButtonFlag()
    && i_headerData1.GetResourceImage() == i_headerData2.GetResourceImage() && i_headerData1.GetLabel() == i_headerData2.GetLabel()); 
}

#endif // CATVidTabHeaderData_h
