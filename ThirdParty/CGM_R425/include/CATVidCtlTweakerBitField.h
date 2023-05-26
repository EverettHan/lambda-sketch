#ifndef CATVidCtl_CATVidCtlTweakerBitField_h
#define CATVidCtl_CATVidCtlTweakerBitField_h

// COPYRIGHT Dassault Systemes 2012

// Local framework
#include <VisuDialog.h>
#include <CATVidCtlTweaker.h>

// IntrospectionInfrastructure
#include <CATSYPDataBlock.h>

// System framework
#include <CATUnicodeString.h>

// VisuImmersiveDialog framework
#include <CATVidCtlBasicList.h>

class CATISYPIntrospectable_var;
class CATSYPPropertiesChangedEventArgs;

class ExportedByVisuDialog CATVidCtlTweakerBitField : public CATVidCtlTweaker
{
  CATDeclareClass;
public:
  CATVidCtlTweakerBitField();

  void SetBitFieldType( const CATUnicodeString& i_bitfieldType );
  const CATUnicodeString& GetBitFieldType() const;
  
  CATISYPIntrospectable_var GetDataBlock();

  CATUnicodeString GetBitFieldString() const;

protected:
  void SetBitFieldString(CATUnicodeString i_bitfieldString);

protected:
  virtual ~CATVidCtlTweakerBitField();

private:
  CATVidCtlTweakerBitField (CATVidCtlTweakerBitField &);
  CATVidCtlTweakerBitField& operator=(CATVidCtlTweakerBitField& original);

  void TweakerDataChanged(CATBaseUnknown * i_pSender, CATSYPPropertiesChangedEventArgs * i_pArgs);
  void SelectionChanged(CATBaseUnknown *i_pSender, CATSYPEventArgs *i_pArgs);
  void FillList();
  void UpdateDataFromSelection();
  void UpdateSelectionFromData();
  void TemplateDataUpdated();

  const CATSYPDynArray<CATUnicodeString>& GetBitFieldStringsList() ;

private:
  CATUnicodeString _bitfieldType;
  CATSYPDataBlock* _pDataBlock;
  CATVidCtlBasicList* _pList;
  CATSYPDynArray<CATUnicodeString> _stringsList;
};

#endif // CATVidCtl_CATVidCtlTweakerBitField_h
