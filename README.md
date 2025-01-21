# Data Treatment Project

This project was made during my first year of university. It includes some functions to help treat data in tables and CSV files. All the data is available in `donnees`. All files are different ways to treat different databases, feel free to explore them, or just use them.

# How to use it ?

Use the commande `make` to create the programs from the files. Here are all the commands:

- `make` or `make all`: compile all the cpp files
- `make clean`: delete all files made by the compilation, including .o and executable
- `make <name_of_file>`: compile only the file given (for example, to compile voitures.cpp, do `make voitures`)

Do `./name_of_file` to start the program (for example, do `./voitures`).

# Warnings

actes-civils.cpp is glitched and will do a core dumped. It was glitched back then and wasn't modified since.

Executing `subventions` isn't a good idea, the file is big and the execution takes a long time.