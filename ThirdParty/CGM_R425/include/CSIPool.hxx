namespace CSI
{
class Node;
template <class T>
Node* Pool::CreateNode(T& userData)
{
  Node* csiNode = CreateNode(&userData);
  return csiNode;
}

template <class T>
Node* Pool::CreateNode(const EK::NodeSettings& settings, T& userData)
{
  Node* csiNode = CreateNode(settings, &userData);
  return csiNode;
}
}
