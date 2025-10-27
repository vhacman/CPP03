![Score](https://img.shields.io/badge/Score-100/100-brightgreen?style=for-the-badge)
[![42 Project](https://img.shields.io/badge/42%20Project-CPP03-blue?style=for-the-badge&logo=42)](https://github.com/vhacman/CPP01)
[![C++ Language](https://img.shields.io/badge/Made%20with-C++-00599C?style=for-the-badge&logo=c++)](https://en.wikipedia.org/wiki/C_(programming_language))
[![Memory Leak Free](https://img.shields.io/badge/Valgrind-Leaks%20Free-success?style=for-the-badge)](https://valgrind.org/)
[![Platform](https://img.shields.io/badge/platform-Linux%20%7C%20Unix-violet?style=for-the-badge)]()
[![License](https://img.shields.io/badge/license-42%20Project-informational?style=for-the-badge)]()
[![Status](https://img.shields.io/badge/42%20status-Completed-brightgreen?style=for-the-badge)]()
[![Created](https://img.shields.io/badge/Created-September_2025-blue?style=for-the-badge)]()

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

**Tested functionality:**
- Basic object creation and destruction
- Copy constructor and assignment operator
- Energy depletion mechanics
- Death state handling (dead robots cannot act)
- Orthodox Canonical Form (OCF) implementation

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

**Comprehensive test suite:**
- Construction/destruction chaining
- Method overriding (ScavTrap's custom attack message)
- ScavTrap-specific methods (guardGate)
- Inherited methods from ClapTrap
- Copy constructor and assignment operator
- Energy depletion testing
- Death scenario handling

### Exercise 02: FragTrap

Another derived class from ClapTrap with different attributes.

**Inherited from ClapTrap with modifications:**
- Hit points: 100
- Energy points: 100
- Attack damage: 30

**Additional features:**
- `highFivesGuys()` - Requests positive high fives

**Key differences from ScavTrap:**
- Does NOT override attack() (uses ClapTrap's version)
- Different stats (100 HP, 100 Energy, 30 Attack)
- Different special ability

**Concepts demonstrated:**
- Parallel inheritance hierarchies
- Polymorphism through base class pointers
- Multiple derived classes from the same base
- Virtual destructors for proper cleanup

**Comprehensive test suite:**
- Base class (ClapTrap) behavior testing
- ScavTrap functionality comparison
- FragTrap specific features
- Construction/destruction chaining
- Copy constructor and assignment operator
- Multiple objects of same type
- **Polymorphism demonstration** - Using base class pointers to derived objects
- Virtual destructor importance

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

**Test suite available:**
The main.cpp includes comprehensive tests (some commented out):
- Basic DiamondTrap creation and whoAmI() functionality
- Default constructor testing
- Copy constructor and assignment operator
- Multiple DiamondTrap objects interaction
- Attribute inheritance verification (HP from FragTrap, Energy from ScavTrap, etc.)
- Destructor call order
- Energy depletion testing (50 energy points from ScavTrap)

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

## 👤 Autore
**vhacman**
- Github: [vhacman](https://github.com/vhacman)
- 42 Intra: [vhacman](https://profile.intra.42.fr/)
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

**Suite di test completa:**
- Concatenamento di costruzione/distruzione
- Override dei metodi (messaggio d'attacco personalizzato di ScavTrap)
- Metodi specifici di ScavTrap (guardGate)
- Metodi ereditati da ClapTrap
- Copy constructor e operatore di assegnazione
- Test di esaurimento dell'energia
- Gestione dello scenario di morte

### Esercizio 02: FragTrap

Un'altra classe derivata da ClapTrap con attributi differenti.

**Ereditato da ClapTrap con modifiche:**
- Punti vita: 100
- Punti energia: 100
- Danno d'attacco: 30

**Funzionalità aggiuntive:**
- `highFivesGuys()` - Richiede high five positivi

**Differenze chiave da ScavTrap:**
- NON effettua l'override di attack() (usa la versione di ClapTrap)
- Statistiche diverse (100 HP, 100 Energia, 30 Attacco)
- Abilità speciale diversa

**Concetti dimostrati:**
- Gerarchie di ereditarietà parallele
- Polimorfismo attraverso puntatori alla classe base
- Classi derivate multiple dalla stessa base
- Distruttori virtuali per una corretta pulizia

**Suite di test completa:**
- Test del comportamento della classe base (ClapTrap)
- Confronto con la funzionalità di ScavTrap
- Funzionalità specifiche di FragTrap
- Concatenamento di costruzione/distruzione
- Copy constructor e operatore di assegnazione
- Oggetti multipli dello stesso tipo
- **Dimostrazione del polimorfismo** - Uso di puntatori alla classe base per oggetti derivati
- Importanza del distruttore virtuale

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

**Suite di test disponibili:**
Il main.cpp include test completi (alcuni commentati):
- Creazione base di DiamondTrap e funzionalità whoAmI()
- Test del costruttore di default
- Copy constructor e operatore di assegnazione
- Interazione tra oggetti DiamondTrap multipli
- Verifica dell'ereditarietà degli attributi (HP da FragTrap, Energia da ScavTrap, ecc.)
- Ordine di chiamata dei distruttori
- Test di esaurimento dell'energia (50 punti energia da ScavTrap)

---

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

## 👤 Autore
**vhacman**
- Github: [vhacman](https://github.com/vhacman)
- 42 Intra: [vhacman](https://profile.intra.42.fr/)

## ⚖️ Licenza
Questo progetto fa parte del curriculum della 42 School. Si prega di fare riferimento alle loro linee guida per l'utilizzo e la distribuzione.
