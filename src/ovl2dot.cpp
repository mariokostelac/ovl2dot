#include <cassert>
#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include "reader.h"
#include "msg_types.h"
#include "edges_set.cpp"
using namespace std;

const string get_edge_style(const bool use_start, const bool use_end) {
  if (use_start && use_end) {
    return "box";
  } else if (use_start) {
    return "dot";
  } else if (use_end) {
    return "odot";
  }

  return "none";
}

template <typename K, typename V>
int dot_graph(ostream& output, EdgesSet<K, V>& edges) {
  int lines = 0;

  output << "graph overlaps {\n";
  lines++;

  for (auto it = edges.begin(); it != edges.end(); ++it) {
    const auto& overlap = it->second;

    output << overlap->read1 << " -- " << overlap->read2 << " [";

    string tail_style = get_edge_style(overlap->use_start(overlap->read1), overlap->use_end(overlap->read1));
    string head_style = get_edge_style(overlap->use_start(overlap->read2), overlap->use_end(overlap->read2));

    output << "dir=both arrowtail=" << tail_style << " arrowhead=" << head_style << "];" << endl;
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
