#ifndef CATPLMECAErrors_H
#define CATPLMECAErrors_H

/**
* @level Protected
* @usage U1  
*/
class CATPLMECAErrors
{
public:
  enum ECAErrorType { Collision, NotSupported, IsOnceInstantiableNotSupported, NotLoaded, Fatal };

  ECAErrorType GetType (){return _type;};

private:

  friend class CATPLMServicesForECAImpl;
  
  CATPLMECAErrors(const ECAErrorType & iType) {_type  = iType;};
  ~CATPLMECAErrors();
  CATPLMECAErrors (CATPLMECAErrors &);
  CATPLMECAErrors & operator=(CATPLMECAErrors &);

  ECAErrorType _type;

};

#endif
