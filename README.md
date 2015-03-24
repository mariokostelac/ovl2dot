# ovl2dot
Afg overlaps to dot graph converter.

## Requirements
- make
- gcc
- graphviz (for plotting part)

## Installation

```
  make
```

## Usage

```
  ./bin/ovl2dot < overlaps.afg > graph.dot
```

Or even better, for direct plotting to a file

```
  ./bin/ovl2dot < overlaps.afg | dot -T png -o graph.png
```
