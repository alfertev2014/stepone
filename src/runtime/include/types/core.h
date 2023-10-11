#pragma once

/**
 * This file containsse the declarations of possible payloads of objects in managed memory.
 * This declataions are the top of type hierarhy. All declarations are C++ classes.
 * Subtyping implemented via inheritance.
 * If known that there cannot be subtype of some type, the class is final.
 */

#include <ptr.h>

namespace stepone::types {

/**
 * The top of type hierarhy of objects in managed memory.
 */
class Any {};

/**
 * Immutable pair of references to two other objects in manager memory.
 *
 * This struct is used to build acyclic graphs of objects in managed memory.
 * The most frequent data structures in practice that consist of pairs are binary tirees and direct linked lists.
 * But it is possible to construct any kinds of acyclic graphs.
 * Cicles are possible via special type of mutable references.
 * So car and cdr cannot refer to pair itself but can be equal to each other.
 *
 * The names CAR and CDR are borrowed from LISP.
 */
class Pair final : public Any {
public:
    const Ptr car;
    const Ptr cdr;

    Pair(const Ptr & car, const Ptr & cdr)
        : car(car), cdr(cdr) {}

    Ptr eval(const Ptr & context) const;
};

/**
 * The builtin type for any other objects that is not pairs.
 *
 * The therm "atom" is borrowed from LISP.
 */
class Atom : public Any {};

/**
 * Node of evaluation context.
 *
 * Used to store a scope of local definitions a.k.a symbol bindings.
 * Evaluation context is organized in direct linked list of nodes.
 * Every node is a pair of symbol and its bound value and also a reference to next context node.
 * The idea of evaluation contexts is that they are linked lists with possibly common tails.
 * All evaluation contexts are like tree of nodes which grows from empty context node to its leaves.
 * The detail of implementation of evaluation context may differ from this simple model.
 * The goal of evaliation context is to find value by its name presented as a symbol.
 */
class Context final : public Any {
    Context() = delete;
public:
    static Ptr make(const Ptr& symbol, const Ptr& value, const Ptr& next);
    static Ptr assoc(const Ptr & context, const Ptr & symbol);
};

/**
 * Symbol object to name values.
 *
 * Empty object that is used only for its identity.
 * Two references are equal if they reffer to the same object.
 * Symbol objects is used only for this purpose.
 * Evaluation of symbol object usually assumes finding bound value in current evaluation context.
 */
class Symbol final : public Atom {
    // TODO: Should we allocate memory for these empty objects? Think about embedding Symbol semantics into Ptr.
public:
    Ptr eval(const Ptr & context) const;
};

/**
 * Base type of all constant objects.
 *
 * Evaluation of constant always results in the constant object itself.
 * In most cases evaluation of constant has no mean because it is already the result of evaluation.
 * Some types of constants can be created only in runtime and cannot be constructed in source code.
 *
 * It is not recommended to compare these objects by identity. Implementation of runtime will not guarantee to respect identity semantics for Consts.
 */
class Const : public Atom {};

/**
 * Base type of all applyable objects.
 *
 * Applyable objects are those objects which can be applyed to other objects according to its inner logic.
 */
class Macro : public Const {};

/**
 * Base type for all values.
 *
 * Value object contains a payload of some C++ type.
 * Value object is still an object with its identity. Implementation of runtime will not guarantee to respect identity semantics for Consts.
 */
class ValueBase : public Const {};


} // namespaces
