# ovl2dot
Afg overlaps to dot graph converter

## Requirements
- make
- gcc

## Installation

```
  mkdir bin
  make
```

## Usage

```
  ./bin/ovl2dot < overlaps.afg > graph.dot
```

Or even better, for direct plotting to file

```
  ./bin/ovl2dot < overlaps.afg | dot -T png -o graph.png
```
