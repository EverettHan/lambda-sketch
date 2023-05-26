#ifndef CATSYPParameterDescriptor_H
#define CATSYPParameterDescriptor_H

#include <CATStyleProcessor.h>
#include <CATUnicodeString.h>

/**
 * Data class containing the description of a parameter.
 * <b>Role</b>: Used by introspection mechanisms. 
 * Recovered from a CATISYPIntrospectable.
 */
class ExportedByCATStyleProcessor CATSYPParameterDescriptor
{
public:
  /**
   * Default constructor. Build an invalid descriptor, 
   * that can be filled by a operator=.
   */
  CATSYPParameterDescriptor()
  {
    _requirement=0;
  }
  ~CATSYPParameterDescriptor(){}
  /**
   * Constructor in case of class parameter.
   * @param i_name name of the parameter
   * @param i_type type of the parameter ("int", "CATUnicodeString"...)
   * @param i_requirement requirement of the parameter.
   * <br><b>Legal values</b>: 0 if the parameter is optional,
   * 1 if it is required.
   * @param i_description [optionnal] the description of the parameter
   */
  CATSYPParameterDescriptor(const CATUnicodeString& i_name,const CATUnicodeString& i_type, int i_requirement, const CATUnicodeString& i_description)
  {
    _name = i_name;
    _type = i_type;
    _description = i_description;
    _requirement = i_requirement;
  }
  /**
   * Copy Constructor.
   */
  CATSYPParameterDescriptor(const CATSYPParameterDescriptor & i_toCopy)
  {
    _name = i_toCopy._name;
    _type = i_toCopy._type;
    _description = i_toCopy._description;
    _requirement = i_toCopy._requirement;
  }
  /**
   * Operator=
   */
  CATSYPParameterDescriptor& operator=(const CATSYPParameterDescriptor & i_toCopy)
  {
    _name = i_toCopy._name;
    _type = i_toCopy._type;
    _description = i_toCopy._description;
    _requirement = i_toCopy._requirement;

    return *this;
  }

  /**
   * @return the name of the parameter
   */
  const CATUnicodeString& GetName () const{return _name;}
  /**
   * @return the type of the parameter ("int", "CATUnicodeString"...)
   */
  const CATUnicodeString& GetType () const{return _type;}
  /**
   * @return the description of the parameter
   */
  const CATUnicodeString& GetDecription () const{return _description;}
  /**
   * @return the requirement of the property.
   * <br><b>Legal values</b>: 0 if the parameter is optional,
   * 1 if it is required.
   */
  unsigned int GetRequirement() const{return _requirement;}

private:
  CATUnicodeString _name;
  CATUnicodeString _type;
  CATUnicodeString _description;
  unsigned char    _requirement;
};

#endif
