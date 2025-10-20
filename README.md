# CPP Module 03 - Inheritance

A C++ project exploring object-oriented programming concepts, specifically inheritance, polymorphism, and the diamond problem.

## Table of Contents

- [Overview](#overview)
- [Project Structure](#project-structure)
- [Exercises](#exercises)
  - [Exercise 00: ClapTrap](#exercise-00-claptrap)
  - [Exercise 01: ScavTrap](#exercise-01-scavtrap)
  - [Exercise 02: FragTrap](#exercise-02-fragtrap)
  - [Exercise 03: DiamondTrap](#exercise-03-diamondtrap)
- [Compilation](#compilation)
- [Usage](#usage)
- [Key Concepts](#key-concepts)

## Overview

This project implements a series of robot classes demonstrating C++ inheritance concepts. Each exercise builds upon the previous one, introducing new inheritance patterns and exploring the complexity of multiple inheritance, culminating in solving the diamond problem.

## Project Structure

```
CPP03/
├── ex00/           # Base ClapTrap class
│   ├── includes/
│   │   └── ClapTrap.hpp
│   ├── src/
│   │   ├── ClapTrap.cpp
│   │   └── main.cpp
│   └── Makefile
│
├── ex01/           # ScavTrap (inherits from ClapTrap)
│   ├── includes/
│   │   ├── ClapTrap.hpp
│   │   └── ScavTrap.hpp
│   ├── src/
│   │   ├── ClapTrap.cpp
│   │   ├── ScavTrap.cpp
│   │   └── main.cpp
│   └── Makefile
│
├── ex02/           # FragTrap (inherits from ClapTrap)
│   ├── includes/
│   │   ├── ClapTrap.hpp
│   │   ├── ScavTrap.hpp
│   │   └── FragTrap.hpp
│   ├── src/
│   │   ├── ClapTrap.cpp
│   │   ├── ScavTrap.cpp
│   │   ├── FragTrap.cpp
│   │   └── main.cpp
│   └── Makefile
│
└── ex03/           # DiamondTrap (multiple inheritance)
    ├── includes/
    │   ├── ClapTrap.hpp
    │   ├── ScavTrap.hpp
    │   ├── FragTrap.hpp
    │   └── DiamondTrap.hpp
    ├── src/
    │   ├── ClapTrap.cpp
    │   ├── ScavTrap.cpp
    │   ├── FragTrap.cpp
    │   ├── DiamondTrap.cpp
    │   └── main.cpp
    └── Makefile
```

## Exercises

### Exercise 00: ClapTrap

The base robot class with fundamental attributes and behaviors.

**Attributes:**
- Name
- Hit points (10)
- Energy points (10)
- Attack damage (0)

**Methods:**
- `attack(const std::string& target)` - Attacks a target, costing 1 energy point
- `takeDamage(unsigned int amount)` - Reduces hit points
- `beRepaired(unsigned int amount)` - Restores hit points, costing 1 energy point

**Features tested:**
- Basic object creation and destruction
- Copy constructor and assignment operator
- Energy depletion mechanics
- Death state handling

### Exercise 01: ScavTrap

A derived class from ClapTrap with enhanced capabilities.

**Inherited from ClapTrap with modifications:**
- Hit points: 100
- Energy points: 50
- Attack damage: 20

**Additional features:**
- Custom attack message
- `guardGate()` - Special ability to enter gate keeper mode

**Concepts demonstrated:**
- Public inheritance
- Constructor/destructor chaining
- Method overriding
- Virtual destructors

### Exercise 02: FragTrap

Another derived class from ClapTrap with different attributes.

**Inherited from ClapTrap with modifications:**
- Hit points: 100
- Energy points: 100
- Attack damage: 30

**Additional features:**
- `highFivesGuys()` - Requests positive high fives

**Concepts demonstrated:**
- Parallel inheritance hierarchies
- Polymorphism through base class pointers
- Multiple derived classes from the same base

### Exercise 03: DiamondTrap

A class inheriting from both ScavTrap and FragTrap, solving the diamond problem.

**Inheritance structure:**
```
        ClapTrap
       /        \
   ScavTrap  FragTrap
       \        /
      DiamondTrap
```

**Attribute inheritance:**
- Name: Private member (DiamondTrap) + ClapTrap name with "_clap_name" suffix
- Hit points: From FragTrap (100)
- Energy points: From ScavTrap (50)
- Attack damage: From FragTrap (30)

**Methods:**
- `attack()` - Inherited from ScavTrap using `using` declaration
- `whoAmI()` - Displays both DiamondTrap and ClapTrap names

**Concepts demonstrated:**
- Virtual inheritance (solving the diamond problem)
- Multiple inheritance
- Name ambiguity resolution
- Complex constructor/destructor chains
- Method disambiguation with `using` declarations

## Compilation

Each exercise can be compiled independently:

```bash
# Exercise 00
cd ex00
make

# Exercise 01
cd ex01
make

# Exercise 02
cd ex02
make

# Exercise 03
cd ex03
make
```

Compilation flags: `-Wall -Wextra -Werror -std=c++98`

## Usage

Run the compiled binaries to see comprehensive tests:

```bash
# Exercise 00
./ex00/claptrap

# Exercise 01
./ex01/scavtrap

# Exercise 02
./ex02/fragtrap

# Exercise 03
./ex03/diamondtrap
```

Each program demonstrates:
- Object construction and destruction
- Method functionality
- Copy semantics
- Edge cases (energy depletion, death state)
- Inheritance chain behavior

## Key Concepts

### Inheritance
- **Single inheritance**: A class derives from one base class (ex00, ex01, ex02)
- **Multiple inheritance**: A class derives from multiple base classes (ex03)
- **Virtual inheritance**: Prevents duplicate base class instances in diamond inheritance

### Polymorphism
- Method overriding in derived classes
- Virtual destructors for proper cleanup
- Base class pointers to derived objects

### The Diamond Problem
When a class inherits from multiple classes that share a common base class, it creates ambiguity and duplicate base class members. Virtual inheritance solves this by ensuring only one instance of the base class exists.

### Orthodox Canonical Form
All classes implement:
- Default constructor
- Copy constructor
- Assignment operator
- Destructor

### Constructor/Destructor Chaining
- Constructors: Base class → Derived classes (in inheritance order)
- Destructors: Derived classes → Base class (reverse order)

## Author

vhacman (vhacman@student.42.fr)

## License

This project is part of the 42 School curriculum.

# CPP Modulo 03 - Ereditarietà

Un progetto C++ che esplora i concetti della programmazione orientata agli oggetti, in particolare ereditarietà, polimorfismo e il problema del diamante.

## Indice

- [Panoramica](#panoramica)
- [Struttura del Progetto](#struttura-del-progetto)
- [Esercizi](#esercizi)
  - [Esercizio 00: ClapTrap](#esercizio-00-claptrap)
  - [Esercizio 01: ScavTrap](#esercizio-01-scavtrap)
  - [Esercizio 02: FragTrap](#esercizio-02-fragtrap)
  - [Esercizio 03: DiamondTrap](#esercizio-03-diamondtrap)
- [Compilazione](#compilazione)
- [Utilizzo](#utilizzo)
- [Concetti Chiave](#concetti-chiave)

## Panoramica

Questo progetto implementa una serie di classi robot che dimostrano i concetti dell'ereditarietà in C++. Ogni esercizio si costruisce sul precedente, introducendo nuovi pattern di ereditarietà ed esplorando la complessità dell'ereditarietà multipla, culminando nella risoluzione del problema del diamante.

## Struttura del Progetto

```
CPP03/
├── ex00/           # Classe base ClapTrap
│   ├── includes/
│   │   └── ClapTrap.hpp
│   ├── src/
│   │   ├── ClapTrap.cpp
│   │   └── main.cpp
│   └── Makefile
│
├── ex01/           # ScavTrap (eredita da ClapTrap)
│   ├── includes/
│   │   ├── ClapTrap.hpp
│   │   └── ScavTrap.hpp
│   ├── src/
│   │   ├── ClapTrap.cpp
│   │   ├── ScavTrap.cpp
│   │   └── main.cpp
│   └── Makefile
│
├── ex02/           # FragTrap (eredita da ClapTrap)
│   ├── includes/
│   │   ├── ClapTrap.hpp
│   │   ├── ScavTrap.hpp
│   │   └── FragTrap.hpp
│   ├── src/
│   │   ├── ClapTrap.cpp
│   │   ├── ScavTrap.cpp
│   │   ├── FragTrap.cpp
│   │   └── main.cpp
│   └── Makefile
│
└── ex03/           # DiamondTrap (ereditarietà multipla)
    ├── includes/
    │   ├── ClapTrap.hpp
    │   ├── ScavTrap.hpp
    │   ├── FragTrap.hpp
    │   └── DiamondTrap.hpp
    ├── src/
    │   ├── ClapTrap.cpp
    │   ├── ScavTrap.cpp
    │   ├── FragTrap.cpp
    │   ├── DiamondTrap.cpp
    │   └── main.cpp
    └── Makefile
```

## Esercizi

### Esercizio 00: ClapTrap

La classe robot base con attributi e comportamenti fondamentali.

**Attributi:**
- Nome
- Punti vita (10)
- Punti energia (10)
- Danno d'attacco (0)

**Metodi:**
- `attack(const std::string& target)` - Attacca un bersaglio, costando 1 punto energia
- `takeDamage(unsigned int amount)` - Riduce i punti vita
- `beRepaired(unsigned int amount)` - Ripristina i punti vita, costando 1 punto energia

**Funzionalità testate:**
- Creazione e distruzione base degli oggetti
- Copy constructor e operatore di assegnazione
- Meccanica dell'esaurimento dell'energia
- Gestione dello stato di morte

### Esercizio 01: ScavTrap

Una classe derivata da ClapTrap con capacità migliorate.

**Ereditato da ClapTrap con modifiche:**
- Punti vita: 100
- Punti energia: 50
- Danno d'attacco: 20

**Funzionalità aggiuntive:**
- Messaggio d'attacco personalizzato
- `guardGate()` - Abilità speciale per entrare in modalità guardiano del cancello

**Concetti dimostrati:**
- Ereditarietà pubblica
- Concatenamento di costruttori/distruttori
- Override dei metodi
- Distruttori virtuali

### Esercizio 02: FragTrap

Un'altra classe derivata da ClapTrap con attributi differenti.

**Ereditato da ClapTrap con modifiche:**
- Punti vita: 100
- Punti energia: 100
- Danno d'attacco: 30

**Funzionalità aggiuntive:**
- `highFivesGuys()` - Richiede high five positivi

**Concetti dimostrati:**
- Gerarchie di ereditarietà parallele
- Polimorfismo attraverso puntatori alla classe base
- Classi derivate multiple dalla stessa base

### Esercizio 03: DiamondTrap

Una classe che eredita sia da ScavTrap che da FragTrap, risolvendo il problema del diamante.

**Struttura di ereditarietà:**
```
        ClapTrap
       /        \
   ScavTrap  FragTrap
       \        /
      DiamondTrap
```

**Ereditarietà degli attributi:**
- Nome: Membro privato (DiamondTrap) + nome ClapTrap con suffisso "_clap_name"
- Punti vita: Da FragTrap (100)
- Punti energia: Da ScavTrap (50)
- Danno d'attacco: Da FragTrap (30)

**Metodi:**
- `attack()` - Ereditato da ScavTrap usando la dichiarazione `using`
- `whoAmI()` - Mostra sia il nome DiamondTrap che quello ClapTrap

**Concetti dimostrati:**
- Ereditarietà virtuale (risoluzione del problema del diamante)
- Ereditarietà multipla
- Risoluzione dell'ambiguità dei nomi
- Catene complesse di costruttori/distruttori
- Disambiguazione dei metodi con dichiarazioni `using`

## Compilazione

Ogni esercizio può essere compilato indipendentemente:

```bash
# Esercizio 00
cd ex00
make

# Esercizio 01
cd ex01
make

# Esercizio 02
cd ex02
make

# Esercizio 03
cd ex03
make
```

Flag di compilazione: `-Wall -Wextra -Werror -std=c++98`

## Utilizzo

Esegui i binari compilati per vedere test completi:

```bash
# Esercizio 00
./ex00/claptrap

# Esercizio 01
./ex01/scavtrap

# Esercizio 02
./ex02/fragtrap

# Esercizio 03
./ex03/diamondtrap
```

Ogni programma dimostra:
- Costruzione e distruzione degli oggetti
- Funzionalità dei metodi
- Semantica della copia
- Casi limite (esaurimento energia, stato di morte)
- Comportamento della catena di ereditarietà

## Concetti Chiave

### Ereditarietà
- **Ereditarietà singola**: Una classe deriva da una classe base (ex00, ex01, ex02)
- **Ereditarietà multipla**: Una classe deriva da più classi base (ex03)
- **Ereditarietà virtuale**: Previene istanze duplicate della classe base nell'ereditarietà a diamante

### Polimorfismo
- Override dei metodi nelle classi derivate
- Distruttori virtuali per una corretta pulizia
- Puntatori alla classe base per oggetti derivati

### Il Problema del Diamante
Quando una classe eredita da più classi che condividono una classe base comune, si crea ambiguità e membri duplicati della classe base. L'ereditarietà virtuale risolve questo problema garantendo che esista una sola istanza della classe base.

### Forma Canonica Ortodossa
Tutte le classi implementano:
- Costruttore di default
- Copy constructor
- Operatore di assegnazione
- Distruttore

### Concatenamento Costruttori/Distruttori
- Costruttori: Classe base → Classi derivate (nell'ordine di ereditarietà)
- Distruttori: Classi derivate → Classe base (ordine inverso)

## Autore

vhacman (vhacman@student.42.fr)

## Licenza

Questo progetto fa parte del curriculum della Scuola 42.
