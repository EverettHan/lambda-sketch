#ifndef IVisSGOccurrenceNotifier__H
#define IVisSGOccurrenceNotifier__H

#include "VisOccurrencesGraph.h"
#include "CATDataType.h"
#include "VisSGUnionOfBitfields.h"
#include <cstdint>

class VisSGOccurrenceNode;
class VisSGOccurrenceObserver;


/**
* @struct VisSGOccurrenceModifiedFlag is used by the notifier API when there is 
* a modification.
* It allows to distinguish specific modifications. 
* The modifications may be grouped and several flags can be set!
*/
struct ExportedByVisOccurrencesGraph VisSGOccurrenceModifiedFlag
{
  FeaturesMask m_FeaturesMask; // legacy. to remove...
  std::uint32_t m_GeomUpdate : 1; // Update geometry
  std::uint32_t m_GeomTCUpdate : 1; // Update Texture Coordinate
  std::uint32_t m_GeomMaterialUpdate : 1; // Upadate material
  VisSGOccurrenceModifiedFlag();
  ~VisSGOccurrenceModifiedFlag() = default;

  // concatenate all flags (binary or operation)
  VisSGOccurrenceModifiedFlag operator |(const VisSGOccurrenceModifiedFlag& otherModifications);
  VisSGOccurrenceModifiedFlag& operator |=(const VisSGOccurrenceModifiedFlag& otherModifications);
};


/**
* @class IVisSGOccurrenceNotifier is an abstract class to declare the API 
* on how messages are sent by the observer.
*/
class ExportedByVisOccurrencesGraph IVisSGOccurrenceNotifier
{
public:
  IVisSGOccurrenceNotifier();

  virtual void* OnOccurrencesCreated(VisSGOccurrenceObserver* iObs, 
    VisSGOccurrenceNode* iNode, 
    const VisSGOccurrenceModifiedFlag& iModifiedFlags) = 0;

  virtual void OnOccurrencesDeleted(VisSGOccurrenceObserver* iObs, void* iUserData) = 0;
  
  virtual void OnOccurrencesModified(VisSGOccurrenceObserver* iObs, 
    VisSGOccurrenceNode* iNode, 
    const VisSGOccurrenceModifiedFlag& iModifiedFlags,
    void* iClientData) = 0;
   
  virtual void  OnResourcesUpdated(VisSGOccurrenceObserver* iObs, VisSGFeatureType iFeat, CATULONG32 iBegin, CATULONG32 iEnd) = 0;
  virtual void  OnOccurrencesDrawOrderModified(VisSGOccurrenceNode* iNode, void* iUserData);

  virtual void  StartTransaction();
  virtual void  EndTransaction();
  
  VisSGOccurrenceObserver const* GetObserver() const { return m_obs; }
  /**
  * @param iAsynchronous send notification synchronously.it will be soon DEPRECATED!become always async!
  */
  void SetObserver(VisSGOccurrenceObserver* iObs, bool isAsync = false);

protected:
  VisSGOccurrenceObserver* m_obs = nullptr;
};

#endif  // IVisSGOccurrenceNotifier__H
