#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include "reader.h"
#include "msg_types.h"
#include "edges_set.cpp"
using namespace std;

template <typename K, typename V>
int dot_graph(ostream& output, EdgesSet<K, V>& edges) {
  int lines = 0;

  output << "digraph overlaps {\n";
  lines++;

  for (auto it = edges.begin(); it != edges.end(); ++it) {
    const auto& overlap = it->second;

    // TODO(mk): draw arrow depending on the real direction
    output << overlap->read1 << " -> " << overlap->read2;
    lines++;

    output << ";\n";
    lines++;
  }

  output << "}\n";
  lines++;

  return lines;
}

int main() {
  vector<const AMOS::Overlap*> overlaps;
  int read = get_overlaps(overlaps, stdin);
  fprintf(stderr, "Read %d overlaps\n", read);

  EdgesSet<int, const AMOS::Overlap*> edges;
  for (int i = 0; i < overlaps.size(); ++i) {
    const auto edge = overlaps[i];
    edges.add(edge->read1, edge->read2, edge);
  }

  dot_graph(cout, edges);
}
