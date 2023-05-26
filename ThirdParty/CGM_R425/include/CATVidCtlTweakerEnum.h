#ifndef CATVidCtlTweakerEnum_h
#define CATVidCtlTweakerEnum_h

// COPYRIGHT Dassault Systemes 2005

// VisuImmersiveDialogEx framework
#include <VisuDialog.h>
#include <CATVidCtlTweaker.h>

// System framework
#include <CATUnicodeString.h>
#include <CATListOfCATUnicodeString.h>

/**
 * Tweaker class used to edit enums.
 */
class ExportedByVisuDialog CATVidCtlTweakerEnum : public CATVidCtlTweaker
{
  CATDeclareClass;

public:

  CATVidCtlTweakerEnum();

  virtual CATBaseUnknown_var GetData() const;
  virtual HRESULT SetData(const CATBaseUnknown_var& i_spData);

  void SetEnumType(const CATUnicodeString& i_enumType);
  const CATUnicodeString& GetEnumType() const;

  void SetLines(const CATListOfCATUnicodeString& iLines);

  virtual CATUnicodeString GetType() const;
  virtual int GetValueTypeFlag() const;
  virtual void SetSelectedIndex(int i_index);

  void SetSelectedValue(int i_value);
  int GetSelectedValue() const;

  void SetTweakerData(int i_spData);
  int GetTweakerData() const;

  void SetNlsEnumFlag(int i_nlsEnumFlag);
  int GetNlsEnumFlag() const { return _NlsEnumFlag; }

protected:

  virtual ~CATVidCtlTweakerEnum();

private:
  void UpdateLines();
  
  int _GetComboValue(int i_index) const;

  // Copy constructor and equal operator
  CATVidCtlTweakerEnum (CATVidCtlTweakerEnum &);
  CATVidCtlTweakerEnum& operator=(CATVidCtlTweakerEnum& original);

  CATUnicodeString _enumType;
  unsigned char _NlsEnumFlag;
};

#endif // CATVidCtlTweakerEnum_h
