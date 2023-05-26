// COPYRIGHT DASSAULT SYSTEMES 2019, ALL RIGHTS RESERVED.
//===================================================================
//
// CATPolyQMSpecialization.h
//
//===================================================================
// October 2019  Creation JBS2
//===================================================================
#ifndef CATPolyQMSpecialization_H
#define CATPolyQMSpecialization_H


/**
* Enable QM from 3*3 to 5*5 dimension.
*/
const unsigned int minPosDimension = 3;
const unsigned int maxPosDimension = 5;


/**
* Recursive template class with methods to instatiate all QM related templates.
*/
template<template<unsigned int> class Template, unsigned int PosDimension = minPosDimension>
class CATPolyQMTemplateSpecialization {
public:
  template<class ReturnType, class ...Args>
  static ReturnType *New(unsigned int posDimension, Args... args);

  template<class ReturnType, class ...Args>
  static ReturnType Execute(unsigned int posDimension, Args... args);

private:
  static inline void assertDimension();
};

/**
* Specialization for recursive terminal case.
*/
template<template<unsigned int> class Template>
class CATPolyQMTemplateSpecialization<Template, maxPosDimension> {
public:
  template<class ReturnType, class ...Args>
  static ReturnType *New(unsigned int posDimension, Args... args);

  template<class ReturnType, class ...Args>
  static ReturnType Execute(unsigned int posDimension, Args... args);
};


/**
* Implementations for general case.
*/
template<template<unsigned int> class Template, unsigned int PosDimension>
template<class ReturnType, class ...Args>
ReturnType *CATPolyQMTemplateSpecialization<Template, PosDimension>::New(unsigned int posDimension, Args... args)
{
  assertDimension();

  if (posDimension == PosDimension)
    return new Template<PosDimension>(args...);
  else
    return CATPolyQMTemplateSpecialization<Template, PosDimension + 1>::template New<ReturnType, Args...>(posDimension, args...);
}

template<template<unsigned int> class Template, unsigned int PosDimension>
template<class ReturnType, class ...Args>
ReturnType CATPolyQMTemplateSpecialization<Template, PosDimension>::Execute(unsigned int posDimension, Args... args)
{
  assertDimension();

  if (posDimension == PosDimension)
    return Template<PosDimension>::Execute(args...);
  else
    return CATPolyQMTemplateSpecialization<Template, PosDimension + 1>::template Execute<ReturnType, Args...>(posDimension, args...);
}

template<template<unsigned int> class Template, unsigned int PosDimension>
inline void CATPolyQMTemplateSpecialization<Template, PosDimension>::assertDimension()
{
  static_assert(minPosDimension <= PosDimension && PosDimension < maxPosDimension, "CATPolyQMTemplateSpecialization with wrong current dimension !");
}


/**
* Implementation for final case.
*/
template<template<unsigned int> class Template>
template<class ReturnType, class ...Args>
ReturnType *CATPolyQMTemplateSpecialization<Template, maxPosDimension>::New(unsigned int posDimension, Args... args)
{
  if (posDimension == maxPosDimension)
    return new Template<maxPosDimension>(args...);
  else
    return nullptr;
}

template<template<unsigned int> class Template>
template<class ReturnType, class ...Args>
ReturnType CATPolyQMTemplateSpecialization<Template, maxPosDimension>::Execute(unsigned int posDimension, Args... args)
{
  if (posDimension == maxPosDimension)
    return Template<maxPosDimension>::Execute(args...);
  else
    return ReturnType();
}


#endif
