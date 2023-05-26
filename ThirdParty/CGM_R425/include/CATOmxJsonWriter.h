#ifndef __CATOmxJsonWriter_H
#define __CATOmxJsonWriter_H

#include "CATOmxKernel.h"
#include "CATOmxTextStream.h"
#include "CATOmxAny.h"
#include "CATOmxKeyString.h"

/**
* CATOmxJsonWriter is an helper for writing json text.
* Each Json primitive is exposed through a dedicated object: Object, List, Attribute (of an object), Atom (basic value: int, double, etc...)
* You can build a tree of these primitives to produce json text
* Check use cases at the end of this file.
*/
namespace CATOmxJsonWriter
{
  class Root;
  class Object;
  class List;
  class Attribute;

  /** internal usage*/
  class _Node
  {
  protected:
    CATOmxTextStream& m_stream;
    int m_nChilds;
    const unsigned int m_flags;
    _Node(CATOmxTextStream& stream, unsigned int flags) :m_stream(stream), m_nChilds(0), m_flags(flags) {}
    _Node(_Node& parent) :m_stream(parent.m_stream), m_nChilds(0), m_flags(parent.m_flags) { ++parent.m_nChilds; }
    int AddChild() { return ++m_nChilds; }
    void Block(bool start, char begin, char end);
    ExportedByCATOmxKernel void Comma();
  private:
    _Node();
    _Node& operator=(const _Node&);
  };

  /** default mode*/
  static const unsigned int OMX_JSW_DEFAULT = 0;
  /** produce indented json*/
  static const unsigned int OMX_JSW_INDENT = 1;

  /** root node */
  class Root : public _Node
  {
  public:
    /**
    * @param flags: see OMX_JSW_* constants
    */
    Root(CATOmxTextStream& stream, unsigned int flags = OMX_JSW_DEFAULT) :_Node(stream, flags) {}
  };

  /**
  * Json atom ("basic value": bool, int, double, string)
  * notice that Atom(TRUE) or Atom(FALSE) do not produce expected value, use Atom(true) or Atom(false)
  */
  class Atom
  {
  public:
    const CATOmxAny m_value;
    Atom(bool b) :m_value(CATOmxAny::CreateBoolean(b == true)) {}
    Atom(int i) :m_value(i) {}
    Atom(CATLONG64 i64) :m_value(i64) {}
    Atom(double d) :m_value(d) {}
    Atom(const CATUnicodeString& s) :m_value(s) {}
    Atom(const char* s) :m_value(s) {}
    static Atom FromAny(const CATOmxAny& any) { return Atom(any); }
    static Atom Null() { return Atom(CATOmxAny()); }
  private:
    Atom(const CATOmxAny& any) :m_value(any) {}
  };

  /**
  * Object node, can be create as root or under an attribute or under a list
  * Beware with brackets in your code, the constructor will add the '{' character and the destructor will add the terminal '}' character.
  */
  class Object : public _Node
  {
  public:
    Object(Root& parent) :_Node(parent) { Write(true); }
    inline Object(Attribute& parent);
    inline Object(List& parent);
    inline Object& AddAttribute(const CATOmxKeyString& key, const Atom& iValue);
    ~Object() { Write(false); }
  private:
    ExportedByCATOmxKernel void Write(bool start);
    friend class Attribute;
  };

  /** Attribute node, can be created under an object only */
  class Attribute : public _Node
  {
  public:
    //create an attribute under an object with a basic value (you can alternatively use parent.Attribute(key,value)
    Attribute(Object& parent, const CATOmxKeyString& key, const Atom& iValue) :_Node(parent) { Start(parent, key, &iValue); }
    //create an attribute under an object without providing its value (use it to create a list or an object under this attribute)
    Attribute(Object& parent, const CATOmxKeyString& key) :_Node(parent) { Start(parent, key, NULL); }
    //provide the value of the attribute
    ExportedByCATOmxKernel void Value(const Atom& iValue);
  private:
    ExportedByCATOmxKernel void Start(Object& parent, const CATOmxKeyString& iKey, const Atom* pValue);
    friend class Object;
  };

  /**
  * List node, can be create as root or under an attribute or under another list
  * Beware with brackets in your code, the constructor will add the '[' character and the destructor will add the terminal ']' character.
  */
  class List : public _Node
  {
  public:
    List(Root& parent) :_Node(parent) { Write(true); }
    List(Attribute& parent) :_Node(parent) { Write(true); }
    List(List& parent) :_Node(parent) { parent.Comma(); Write(true); }
    ~List() { Write(false); }
    ExportedByCATOmxKernel List& Item(const Atom& iItem);
  private:
    ExportedByCATOmxKernel void Write(bool start);
    friend class Object;
  };

  Object::Object(List& parent) : _Node(parent) { parent.Comma(); Write(true); }
  Object::Object(CATOmxJsonWriter::Attribute& parent) : _Node(parent) { parent.AddChild(); Write(true); }
  Object& Object::AddAttribute(const CATOmxKeyString& key, const Atom& iValue) { CATOmxJsonWriter::Attribute(*this, key, iValue); return *this; }
};

#if 0
//Use cases:
//
//Example 1: write a basic object with two attributes: attr1=1, attr2=2
CATOmxTextStream stream;
{ //this brace is necessary
  Root root(stream); //create root node
  //syntax 1:
  { //this brace is necessary
    Object obj(root); //create object node
    Attribute(obj, "attr1", 1); //add an attribute named attr1 with an integer value of 1
    Attribute(obj, "attr2", 2); //add an attribute named attr2 with an integer value of 2
  }
  //syntax 2:
  Object(root).AddAttribute("attr1", 1).AddAttribute("attr2", 2);
}
CATUnicodeString json(stream.ToString()); //json contains {"attr1":1,"attr2":2}

//example 2: create a list containg an integer and an object
CATOmxTextStream stream;
{ //this brace is necessary
  Root root(stream); //create root node
  { //this brace is necessary
    List list(root);       //start a list
    list.Item(1);          //add an integer value to the list
    Object obj(list);            //add an object to the list
    Attribute(obj, "id", 2); //add an attribute to that object
  }
}
CATUnicodeString json(stream.ToString()); //json contains [1,{"id":2}]);

//example 3: supported types
CATOmxTextStream stream;
{
  Root root(stream);
  Object(root)
    .AddAttribute("bool", true)  //add an attribute with bool value (warning TRUE/FALSE do not produce expected result, use true/false)
    .AddAttribute("int", 2)      //add an attribute with int value (int64 is also supported)
    .AddAttribute("double", 3.0) //add an attribute with double value
    .AddAttribute("string", "4"); //add an attribute with string value
}
CATUnicodeString json(stream.ToString()); //json contains {"bool":true,"int":2,"double":3.0,"string":"4"});

//example 4: combine all features
CATOmxTextStream stream;
{//this brace is necessary
  Root root(stream);
  { //this brace is necessary
    Object obj(root);             //start an object
    Attribute(obj, "a", 1);         //add an attribute "a" with an integer value of 1
    Attribute(obj, "b", "2");       //add an attribute "b" with a string value of "2"
    { //this brace is necessary
      Attribute c(obj, "c");         //start an attribute "c" without providing its value
      List(c).Item(3.0).Item(4.0);  //create a list under attribute "c" with two double values [ 3.0, 4.0]
    }
    { //this brace is necessary
      Attribute d(obj, "d");         //start an attribute without providing its value
      Object obj2(d);               //create an empty object under attribute "d"
    }
  }
}
CATUnicodeString json(stream.ToString()); //json contains {"a":1,"b":"2","c":[3.0,4.0],"d":{}}");

//example 5: indentation
CATOmxTextStream stream;
{ //this brace is necessary
  Root root(stream, OMX_JSW_INDENT); //create root node specifying produced json should be indented
  { //this brace is necessary
    Object obj(root); //create object node
    Attribute(obj, "attr1", 1); //add an attribute named attr1 with an integer value of 1
    Attribute(obj, "attr2", 2); //add an attribute named attr2 with an integer value of 2
  }
}
CATUnicodeString json(stream.ToString());
//json contains
//{
//  "attr1": 1,
//  "attr2": 2
//}
#endif

#endif
