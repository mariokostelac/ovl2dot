
#ifndef _AMOS_MSG_TYPES_H
#define _AMOS_MSG_TYPES_H

#include <cstdint>

namespace AMOS {

  struct Read {
    uint32_t iid;
    uint32_t clr_lo;
    uint32_t clr_hi;
    const char *seq;
    const char *qlt;

    Read() : seq(nullptr), qlt(nullptr) {}

    Read(uint32_t iid, uint32_t clr_lo, uint32_t clr_hi, const char *seq, const char *qlt)
      :iid(iid), clr_lo(clr_lo), clr_hi(clr_hi), seq(seq), qlt(qlt)
    {}

    ~Read() {
      if (seq != nullptr) {
        delete[] seq;
      }
      if (qlt != nullptr) {
        delete[] qlt;
      }
    }
  };

  struct Overlap {
    uint32_t read1;
    uint32_t read2;
    char adjacency;
    int32_t a_hang;
    int32_t b_hang;
    uint32_t score;

    Overlap(const uint32_t r1, const uint32_t r2, const char adj, const int32_t ahg, const int32_t bhg, const int32_t scr)
      :read1(r1), read2(r2), adjacency(adj), a_hang(ahg), b_hang(bhg), score(scr)
    {}

    Overlap() {}
  };
}
#endif
