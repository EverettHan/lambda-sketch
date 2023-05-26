//-----------------------------------------------------------------------------
// COPYRIGHT Dassault Systemes 2015
//-----------------------------------------------------------------------------
#ifndef IVDeviceDefinition_H
#define IVDeviceDefinition_H

#include "IVInterfaces.h"

#include "CATSYPHashMap.h"
#include "CATUnicodeString.h"
#include "CATMathTransformation.h"
#include "IVDeviceDataType.h"
#include "CATBaseUnknown.h"

static int defaultReturnCode = 0;
/**
 * IVDeviceDefinition
 */
class ExportedByIVInterfaces IVDeviceDefinition
{
public:


  IVDeviceDefinition();
  IVDeviceDefinition(IVDeviceDefinition const& iRhs);
  IVDeviceDefinition& operator=(IVDeviceDefinition const& iRhs);
  
  /**
   * Declare a button/analog/tracker component whose state will be updated
   * according to a button event with the given id.
   *
   * @param iEvtId
   * The button/analog/tracker event id. 
   * Note: the IVAtomicID of the component will be the same as the event id.
   *
   * @param iPostprocess (trackers only)
   * The transformation that will be used to modify the pose of the tracker
   * event
   */
  IVDeviceDefinition& AddButton(unsigned int iEvtId, int& oReturnCode=defaultReturnCode);
  IVDeviceDefinition& AddAnalog(unsigned int iEvtId, int& oReturnCode=defaultReturnCode);
  IVDeviceDefinition& AddTracker(unsigned int iEvtId, int& oReturnCode=defaultReturnCode, const CATMathTransformation& iPostProcess = CATMathTransformation());

  /**
   * Declare a button/analog/tracker component whose state will be updated
   * according to a button event with the given id.
   *
   * @param iEvtId
   * The button/analog/tracker event id. 
   * Note: the IVAtomicID of the component will be the same as the event id.
   *
   * @param iID
   * The IVAtomicID of the component.
   *
   * @param iPostprocess (trackers only)
   * The transformation that will be used to modify the pose of the tracker
   * event
   */
  IVDeviceDefinition& AddButton(unsigned int iEvtId, IVAtomicID iID, int& oReturnCode=defaultReturnCode);
  IVDeviceDefinition& AddAnalog(unsigned int iEvtId, IVAtomicID iID, int& oReturnCode=defaultReturnCode);
  IVDeviceDefinition& AddTracker(unsigned int iEvtId, IVAtomicID iID, int& oReturnCode=defaultReturnCode, const CATMathTransformation& iPostprocess = CATMathTransformation());
  
  /**
   * Declare a button/analog/tracker component whose state will be updated
   * according to a button event with the given id.
   *
   * @param iEvtId
   * The button/analog/tracker event id. 
   * Note: the IVAtomicID of the component will be the same as the event id.
   *
   * @param iAlias
   * The user alias of button/analog/tracker component
   * 
   * @param iPostprocess (trackers only)
   * The transformation that will be used to modify the pose of the tracker
   * event
   */
  IVDeviceDefinition& AddNamedButton(unsigned int iEvtId, const CATUnicodeString& iAlias, int& oReturnCode=defaultReturnCode);
  IVDeviceDefinition& AddNamedAnalog(unsigned int iEvtId, const CATUnicodeString& iAlias, int& oReturnCode=defaultReturnCode);
  IVDeviceDefinition& AddNamedTracker(unsigned int iEvtId, const CATUnicodeString& iAlias, int& oReturnCode=defaultReturnCode, const CATMathTransformation& iPostProcess = CATMathTransformation());

  /**
   * Declare a button/analog/tracker component whose state will be updated
   * according to a button event with the given id.
   *
   * @param iEvtId
   * The button/analog/tracker event id. 
   * Note: the IVAtomicID of the component will be the same as the event id.
   *
   * @param iID
   * The IVAtomicID of the component.
   *
   * @param iAlias
   * The user alias of button/analog/tracker component
   *
   * @param iPostprocess (trackers only)
   * The transformation that will be used to modify the pose of the tracker
   * event
   */
  IVDeviceDefinition& AddNamedButton(unsigned int iEvtId, IVAtomicID iID, const CATUnicodeString& iAlias, int& oReturnCode=defaultReturnCode);
  IVDeviceDefinition& AddNamedAnalog(unsigned int iEvtId, IVAtomicID iID, const CATUnicodeString& iAlias, int& oReturnCode=defaultReturnCode);
  IVDeviceDefinition& AddNamedTracker(unsigned int iEvtId, IVAtomicID iID, const CATUnicodeString& iAlias, int& oReturnCode=defaultReturnCode, const CATMathTransformation& iPostprocess = CATMathTransformation());


  /**
   *
   */
  IVDeviceDefinition& SetPostprocessingTransfo(CATMathTransformation const& iTransfo);
  
  /**
   * Check whether this component contains any definition
   */
  bool IsEmpty();


  /**
   * Comparison
   */
  bool operator==(IVDeviceDefinition const& iRhs) const;
  
  struct ExportedByIVInterfaces ButtonProperties {
    unsigned int evtID;
    CATUnicodeString userAlias;
    
    bool operator==(ButtonProperties const& iRhs) const;
  };

  struct ExportedByIVInterfaces AnalogProperties {
    unsigned int evtID;
    CATUnicodeString userAlias;
    
    bool operator==(AnalogProperties const& iRhs) const;
  };

  struct ExportedByIVInterfaces TrackerProperties {
    unsigned int evtID;
    CATUnicodeString userAlias;
    
    bool operator==(TrackerProperties const& iRhs) const;    
  };

  CATMathTransformation PostprocessingTransfo;
  CATSYPHashMap<IVAtomicID, ButtonProperties> AllButtons;
  CATSYPHashMap<IVAtomicID, AnalogProperties> AllAnalogs;
  CATSYPHashMap<IVAtomicID, TrackerProperties> AllTrackers;
};

#endif
