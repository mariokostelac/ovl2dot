
#ifndef _AMOS_READER_H
#define _AMOS_READER_H

#include "msg_types.h"

#include <cstdio>
#include <vector>

namespace AMOS {
  int get_reads(std::vector<Read*>& container, FILE *fd);
  int get_overlaps(std::vector<Overlap*>& container, FILE *fd);
}

#endif
