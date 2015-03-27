#include <map>
#include <utility>

template <typename K, typename V>
class EdgesSet {
  private:
    std::map<std::pair<K, K>, V> edges;

  public:
    uint32_t count(K n1, K n2);
    V edge_info(K n1, K n2);
    void add(K n1, K n2, V edge_info);
    uint32_t size();
    typename std::map<std::pair<K, K>, V>::iterator begin();
    typename std::map<std::pair<K, K>, V>::iterator end();
};

template <class K, class V>
uint32_t EdgesSet<K, V>::count(K n1, K n2) {
  return edges.count(make_pair(n1, n2));
}

template <class K, class V>
V EdgesSet<K, V>::edge_info(K n1, K n2) {
  return edges[std::make_pair(n1, n2)];
}

template <class K, class V>
void EdgesSet<K, V>::add(K n1, K n2, V edge_info) {
  edges[std::make_pair(n1, n2)] = edge_info;
}

template <class K, class V>
uint32_t EdgesSet<K, V>::size() {
  return edges.size();
}

template <class K, class V>
typename std::map<std::pair<K, K>, V>::iterator EdgesSet<K, V>::begin() {
  return edges.begin();
}

template <class K, class V>
typename std::map<std::pair<K, K>, V>::iterator EdgesSet<K, V>::end() {
  return edges.end();
}
