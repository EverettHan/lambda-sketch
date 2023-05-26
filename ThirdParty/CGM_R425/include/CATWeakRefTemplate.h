#ifndef CATWeakRefTemplate_H
#define CATWeakRefTemplate_H

#define DeclareWeakRef(Type, Module)                                          \
class Module Type##WeakRef                                                    \
{                                                                             \
  friend class Type;                                                          \
public:                                                                       \
  void AddRef( void );                                                        \
  void Release( void );                                                       \
  virtual Type * GetComponent( void );                                        \
  void SetComponent(Type * i_pComponent);                                     \
protected:                                                                    \
  Type##WeakRef( Type * i_pComponent );                                       \
  ~Type##WeakRef( void );                                                     \
  void KillRef( void );                                                       \
protected:                                                                    \
  Type * m_component;                                                         \
private:                                                                      \
  unsigned int m_cref;                                                        \
};


#define ImplementWeakRef(Type)                                                \
Type##WeakRef::Type##WeakRef( Type * i_pComponent )                           \
: m_cref(1), m_component(i_pComponent)                                        \
{	                                                                            \
}                                                                             \
                                                                              \
Type##WeakRef:: ~Type##WeakRef( void )                                        \
{                                                                             \
  if( m_component )                                                           \
    m_component->_pWeakRef = NULL;                                            \
}                                                                             \
                                                                              \
Type * Type##WeakRef::GetComponent( void )                                   \
{                                                                             \
  return m_component;                                                         \
}                                                                             \
                                                                              \
void Type##WeakRef::AddRef( void )                                            \
{                                                                             \
  m_cref++;                                                                   \
}                                                                             \
                                                                              \
void Type##WeakRef::Release( void )                                           \
{                                                                             \
  if( !--m_cref )                                                             \
    delete this;                                                              \
}                                                                             \
                                                                              \
void Type##WeakRef::KillRef( void )                                           \
{                                                                             \
  m_component = NULL;                                                         \
}                                                                             \
                                                                              \
void Type##WeakRef::SetComponent(Type * i_pComponent)                         \
{                                                                             \
   if (m_component)                                                           \
      m_component->_pWeakRef = NULL;                                          \
                                                                              \
   m_component = i_pComponent;                                                \
                                                                              \
   if(m_component)                                                            \
      m_component->_pWeakRef = this;                                          \
}

#endif
