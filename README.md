# Data Treatment

C++ programs that load and analyze open data tables from the City of Paris: marriages, first names, remarkable trees, metro traffic, lost objects, grants, Vélib stations and civil registry statistics. A small table library (`tableau-*.hpp` and `tableau-*.cpp`) reads CSV files into tables and queries them.

## Usage

```bash
make              # compile every program
make voitures     # compile a single program
./voitures        # run it
make clean        # remove compiled files
```

The datasets are in `donnees/`. Before running `objets-trouves`, decompress `donnees/objets-trouves-restitution.csv.gz` (101 MB once decompressed). `actes-civils` has a known bug and crashes.

## Credits

The project skeleton, the header files and the datasets were provided by Nicolas M. Thiéry.

## License

MIT, see [LICENSE](LICENSE). The project skeleton, the header files and the datasets provided by Nicolas M. Thiéry are not covered.
