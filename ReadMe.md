# Design Patterns
Design patterns are typical solutions to commonly occurring problems in software design. They are like pre-make blueprints that you can customize to solve a recurring design problem in code

## Why should we learn patterns?

* Design patterns are a toolkit of tried and tested solutions to common problems in software design. Even if you never encounter the problems, knowing the pattern is still useful because it gives you the perspective to solve the problems using the object-oriented design
* Design patterns give us a common language to communicate over the problem, modules, or workflow if we use the word "singleton" then it gives the idea of a single instance object overview

## Criticism of patterns -

Usually, the need for patterns arises when people choose a programming language or a technology that lacks the necessary level of abstraction, in this case, the pattern becomes a kludge that gives the language much-needed super-abilities
Eg- Strategy pattern can be implemented with a simple anonymous(lambda) function in most modern programming languages
* Inefficient solutions
    Pattern tries to systematize approaches that are already widely used. This unification is viewed by many as dogma(a belief or set of beliefs that are accepted by a group without being questioned or doubted) and they implement patterns
* Unjustified use
    > ***"If all you have is a hammer, everything looks like a nail"***

    This is the problem that haunts many novices who have just familiarized themselves with patterns. Having learned about patterns, they try to apply them everywhere, even in situations where simpler code would do just fine
    

## Classification of pattern
'Intent' of the pattern briefly describes both the problems and the solutions.
'Motivation' further explains the problem and the solution the pattern makes possible.
'Structure' of classes shows each part of the pattern and how they are related

### All patterns can be categorized by their intent or purpose
* ***Creational*** patterns provide an object creation mechanism that increases flexibility and reuse of existing code.
    - [x] [Singleton](https://github.com/OmPatil-88/Design-Patterns/tree/master/Singleton)
    - [x] [Factory Method](https://github.com/OmPatil-88/Design-Patterns/tree/master/Factory%20Method)
    - [ ] Abstract Factory
    - [ ] Builder
    - [ ] Prototype
* ***Structural*** patterns explain how to assemble objects and classes into larger structures while keeping these structures flexible and efficient.
    - [ ] Adapter
    - [ ] Bridge
    - [ ] Composite
    - [ ] Decorator
    - [ ] Facade
    - [ ] Flyweight
    - [ ] Proxy
* ***Behavioral*** patterns take care of effective communication and the assignment of responsibilities between objects.
    - [ ] Chain of Responsibility
    - [ ] Command
    - [ ] Iterator
    - [ ] Mediator
    - [ ] Observer
    - [ ] State
    - [ ] Strategy
    - [ ] Template Method
    - Visitor
