# Design Patterns

This is my implementation for some of the common Object Oriented Programming design patterns:

* Bridge
* Command
* Observer
* Proxy
* Composite
* Interpreter
* Factory
* Class Adapter
* Object Adapter

Note: The code implements the basic idea of the design pattern and does not aim to create a project in and of itself. 

## Bridge
The Bridge pattern is a design pattern used in software engineering that is meant to “decouple an abstraction from it’s implementation so that the two can vary independently”.

The Bridge uses encapsulation, aggregation, and can use inheritance to separate responsibilities into different classes.

-Wikipedia

UML for my implementation:

![Bridge](https://i.imgur.com/hdh0Itp.png)

## Command

the command pattern is a behavioral design pattern in which an object is used to encapsulate all information needed to perform an action or trigger an event at a later time.

-Wikipedia

UML for my implementation:

![Command](https://i.imgur.com/6MhmUR0.png)

## Observer

The observer pattern is a software design pattern in which an object, named the subject, maintains a list of its dependents, called observers, and notifies them automatically of any state changes, usually by calling one of their methods.

-Wikipedia

![Observer](https://i.imgur.com/V4PPS6u.png)

## Proxy

The proxy pattern is a software design pattern. A proxy, in its most general form, is a class functioning as an interface to something else.

-Wikipedia

![Proxy](https://i.imgur.com/X7sBXEb.png)

## Composite

the composite pattern is a partitioning design pattern. The composite pattern describes a group of objects that are treated the same way as a single instance of the same type of object. The intent of a composite is to "compose" objects into tree structures to represent part-whole hierarchies. Implementing the composite pattern lets clients treat individual objects and compositions uniformly.

-Wikipedia

My implementation also checks and prevents inner loops in the hierarchy.

![Composite](https://i.imgur.com/YhGsP5W.png)

## Interpreter

In computer programming, the interpreter pattern is a design pattern that specifies how to evaluate sentences in a language. The basic idea is to have a class for each symbol, terminal (Num, Var), non-terminal (Plus, Minus), in a specialized computer language. The syntax tree of a sentence in the language is an instance of the composite pattern and is used to evaluate (interpret) the sentence for a client

-Wikipedia

![Interpreter](https://i.imgur.com/ISTkAf0.png)

## Factory

In class-based programming, the factory method pattern is a creational pattern that uses factory methods to deal with the problem of creating objects without having to specify the exact class of the object that will be created. This is done by creating objects by calling a factory method—either specified in an interface and implemented by child classes, or implemented in a base class and optionally overridden by derived classes—rather than by calling a constructor.

-Wikipedia

![Factory](https://i.imgur.com/vlShqav.png)

## Adapter
In software engineering, the adapter pattern is a software design pattern that allows the interface of an existing class to be used as another interface. It is often used to make existing classes work with others without modifying their source code.

-Wikipedia

### Class Adapter
![Class Adapter](https://i.imgur.com/3UBVEvU.png)

### Object Adapter
![Object Adapter](https://i.imgur.com/1YTcdZX.png)

