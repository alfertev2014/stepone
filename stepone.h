#ifndef STEPONE_H
#define STEPONE_H

#include <string>
#include <iostream>

using namespace std;


class Pair;
class Atom;
class Lazy;
class Label;
class Context;

class Symbol;
class Const;

class Macro;
class Function;
class Operation;
class SpecType;


class Ob {
    int refcount;

public: // static
    class Ptr {
        Ob * ob;
    public:
        Ptr() : ob(Ob::anil.ob) {
            if(ob != 0) {
                ob->refcount++;
                //cout << "Ptr(): " << ob->refcount << ob->toString() << __LINE__;
            }
        }
        Ptr(Ob * _ob) : ob(_ob) {
            if(ob != 0) {
                ob->refcount++;
                //cout << "Ptr(Ob*): " << ob->refcount << ob->toString() << __LINE__;
            }
        }
        Ptr(const Ob::Ptr & _ob) : ob(_ob.ob) {
            if(ob != 0) {
                ob->refcount++;
                //cout << "Ptr(Ptr): " << ob->refcount << ob->toString() << __LINE__;
            }
        }

        ~Ptr() {
            if(ob == 0) return;
            ob->refcount--;
            //cout << "~Ptr: " << ob->refcount << ob->toString() << __LINE__;
            if(ob->refcount == 0)  {
                //cout << "~Ptr delete: " << ob->refcount << ob->toString() << __LINE__;
                delete ob;
            }
        }

        bool operator == (const Ptr & p) const {return p.ob == ob;}
        bool operator ==(const Ob * const p) const {return ob == p;}
        friend bool operator ==(const Ob * const ob, const Ptr & p);

        Ptr & operator=(const Ptr & p) {return this->operator=(p.ob);}

        Ptr & operator=(Ob * _ob) {
            if(_ob == ob) return *this;
            if(_ob != 0) {
                //cout << "Ptr=(Ob*): " << ob->refcount << ob->toString() << __LINE__;
                _ob->refcount++;
            }
            if(ob != 0) {
                ob->refcount--;
                //cout << "Ptr= delete (Ob*): " << ob->refcount << ob->toString() << __LINE__;
                if(ob->refcount == 0)
                    delete ob;
            }
            ob = _ob;
            return *this;
        }

        Ob * operator -> () const {return ob;}
    };

    static const Ptr anil;
    static const Ptr at;
    static const Ptr aif;
    static const Ptr aquote;
    static const Ptr alambda;
    static const Ptr alet;
    static const Ptr alazy;
    static const Ptr aunlazy;
    static const Ptr alabel;
    static const Ptr aeval;

public:
    Ob() : refcount(0) {}
    virtual ~Ob() {}

    virtual Ptr car() {cout << "throw car " << __LINE__; throw 0;}
    virtual Ptr cdr() {cout << "throw cdr " << __LINE__; throw 0;}

    virtual Ptr eval(const Ptr & a) {throw 0;}
    virtual Ptr apply(const Ptr & p, const Ptr & a) {
        if(p == Ob::anil) return this;
        throw 0;
    }
    virtual Ptr unlazy() {return this;}
    virtual Ptr assoc(const Ptr & s) const {cout << "throw assoc " << __LINE__; throw 0;}

    //Методы для определения типа

    virtual bool isAtom() const {return false;}
    virtual Atom * asAtom() {return 0;}
    virtual bool isLazy() const {return false;}
    virtual Lazy * asLazy() {return 0;}
    virtual bool isPair() const {return false;}
    virtual Pair * asPair() {return 0;}
    virtual bool isLabel() const {return false;}
    virtual Label * asLabel() {return 0;}

    virtual bool isContext() const {return false;}
    virtual Context * asContext() {return 0;}

    virtual bool isSymbol() const {return false;}
    virtual bool isConst() const {return false;}
    virtual Symbol * asSymbol() {return 0;}
    virtual Const * asConst() {return 0;}

    virtual bool isMacro() const {return false;}
    virtual Macro * asMacro() {return 0;}
    virtual bool isFunction() const {return false;}
    virtual Function * asFunction() {return 0;}
    virtual bool isOperation() const {return false;}
    virtual Operation * asOperation() {return 0;}
    virtual bool isSpecType() const {return false;}
    virtual SpecType * asSpecType() {return 0;}

    // Методы для отладки
    virtual string toString() const = 0;
};

class Pair : public Ob {
    Ptr pcar;
    Ptr pcdr;

public:
    Pair(const Ptr & _pcar, const Ptr & _pcdr)
        : pcar(_pcar), pcdr(_pcdr) {}

    bool isPair() const {return true;}
    Pair * asPair() {return this;}

    Ptr car() {return pcar;}
    Ptr cdr() {return pcdr;}

    Ptr eval(const Ptr & a) {pcar->eval(a)->apply(pcdr);}

    string toString() const {
        if(this == pcar || this == pcdr)
            throw 0;
        string res = "(" + pcar->toString();
        Ptr p = pcdr;
        int k = 4;
        while(p->isPair()) {
            if(k <= 0) {
                res += " ...";
                return res + ")";
            }
            res += " " + p->car()->toString();
            p = p->cdr();
            k--;
        }
        if(!(p == Ob::anil))
            res += " . " + p->toString();
        return res + ")";
    }
};

class Atom : public Ob {
public:
    virtual ~Atom() {}

    bool isAtom() const {return true;}
    Atom * asAtom() {return this;}
};

class Context : public Ob {
    Ptr s;
    Ptr e;
    Ptr next;
public:
    Context(const Ptr & _s, const Ptr & _e, const Ptr & _next) : s(_s), e(_e), next(_next) {}

    Ptr getSymbol() const {return s;}
    Ptr getValue() const {return e;}
    Ptr getNext() const {return next;}

    void setSymbol(const Ptr& _s) {s = _s;}
    void setValue(const Ptr& _e) {e = _e;}

    Ptr assoc(const Ptr & _s) const {
        if(s == _s) return e;
        Context * p = next->asContext();
        while(p) {
            if(p->s == _s) return p->e;
            p = p->next->asContext();
        }
        cout << "Unknown symbol" << __LINE__;
        throw 0;
        //return Ob::abot;
    }

    virtual bool isContext() const {return true;}
    virtual Context * asContext() {return this;}

    string toString() const {
        Context * ctx = next->asContext();
        string res = s->toString() + " = " + e->toString();
        int k = 4;
        while(ctx != 0) {
            if(k <= 0) {
                res += " ...";
                return res;
            }
            res += ", " + ctx->s->toString() + " = " + ctx->e->toString();
            ctx = ctx->next->asContext();
            k--;
        }
        return res;
    }
};

class Lazy : public Ob {
    Ptr e;
    Ptr a;
    bool ready;

    void ev() {
        if(!ready) {
            e = e->eval(a);
            ready = true;
            a = Ob::anil;
        }
    }

    void evw() {
        ev();
        Lazy * l = e->asLazy();
        while(l != 0) {
            l->ev();
            e = l->e;
            l = e->asLazy();
        }
    }

public:
    Lazy(const Ptr & _e, const Ptr & _a) : e(_e), a(_a), ready(false) {}

    Ptr car() {evw(); return e->car();}
    Ptr cdr() {evw(); return e->cdr();}

    bool isLazy() const {return true;}
    Lazy * asLazy() {return this;}

    Ptr eval(const Ptr &a) {evw(); return e->eval(a);}
    Ptr apply(const Ptr &p, const Ptr &a) {
        if(p == Ob::anil) return this;
        evw(); return e->apply(p, a);
    }
    Ptr unlazy() {evw(); return e;}

    string toString() const {return "{# " + e->toString() + " | " + (ready ? "ready" : a->toString()) + "}";}
};

class Label : public Ob {
    Ptr f;
    Ptr e;
    Ptr a;

    Ptr ev() {return e->eval(new Context(f, this, a));}

public:
    Label(const Ptr & _f, const Ptr & _e, const Ptr & _a)
        : f(_f), e(_e), a(_a) {}

    Ptr car() {return ev()->car();}
    Ptr cdr() {return ev()->cdr();}

    Ptr eval(const Ptr &a) {return ev()->eval(a);}

    Ptr apply(const Ptr &p, const Ptr &a) {
        return p == Ob::anil ? this : ev()->apply(p, a);
    }

    Ptr unlazy() {return ev()->unlazy();}

    bool isLabel() const {return true;}
    Label * asLabel() {return this;}

    string toString() const {return "{@ " + f->toString()+ " " + e->toString() + " | " + a->toString() + "}";}
};


class Symbol : public Atom {
public:
    Ptr eval(const Ptr & a) {return a->assoc(this);}

    bool isSymbol() const {return true;}
    Symbol * asSymbol() {return this;}

    string toString() const {
        if(this == Ob::anil) return "()";
        else if(this == Ob::at) return "t";
        else if(this == Ob::alambda) return "\\";
        else if(this == Ob::alet) return ">-";
        else if(this == Ob::aquote) return "\'";
        else if(this == Ob::aeval) return "~";
        else if(this == Ob::alazy) return "#";
        else if(this == Ob::aunlazy) return "$";
        else if(this == Ob::alabel) return "@";
        else if(this == Ob::aif) return "?";
        else if(this == Ob::atry) return "|";
        else if(this == Ob::ado) return ";";
        else if(this == Ob::abot) return "_";
        else {
            int i = ((int)(void *)this);
            i += (i >> 16) & 0xFFFF;
            i += (i >> 16) & 0xFFFF;
            return "s" + string::number(i % (256 * 16), 16);
        }
    }
};

class Const : public Atom {
public:
    virtual ~Const() {}
    bool isConst() const {return true;}
    Const * asConst() {return this;}

    Ob::Ptr eval(const Ptr &a) {return this;}
};


class Macro : public Const
{
public:
    virtual ~Macro() {}
    bool isMacro() const {return true;}
    Macro * asMacro() {return this;}
};


class Function : public Macro {
protected:
    virtual Ob::Ptr applyX(const Ob::Ptr & x) = 0;
public:
    virtual ~Function() {}
    bool isFunction() const {return true;}
    Function * asFunction() {return this;}

    Ptr apply(const Ptr &p, const Ptr &a) {
        if(p == Ob::anil)
            return this;
        Ptr ob = p->car()->eval(a);
        Ptr e = applyX(ob);
        Ob::Ptr p1 = p->cdr();
        while(!(p1 == Ob::anil)) {
            Function * f = e->asFunction(); // Этот код основывается на том, что при применении функции возвращается функция, а не макрос
            if(f == 0) {
                Macro * m = e->asMacro();
                if(m == 0) {
                    cout << "throw can\'t apply " << __LINE__;
                    throw 0;
                } else {
                    e = m->apply(p1, a);
                }
            } else {
                ob = p1->car()->eval(a);
                e = f->applyX(ob);
                p1 = p1->cdr();
            }
        }
        return e;
    }
};


class Operation : public Function {
public:
    virtual ~Operation() {}
    virtual bool isOperation() const {return true;}
    virtual Operation * asOperation() {return this;}
};


class Closure : public Function {
    Ob::Ptr x;
    Ob::Ptr e;
    Ob::Ptr a;
protected:
    Ob::Ptr applyX(const Ptr &x) {return e->eval(new Context(this->x, x, a));}
public:
    Closure(const Ob::Ptr & _x, const Ob::Ptr & _e, const Ob::Ptr & _a)
        : x(_x), e(_e), a(_a) {}

    string toString() const {return "{\\ " + x->toString() + " . " + e->toString() + " | " + a->toString() + "}";}
};


//////////////////////////////////////////////////

class TypeId {
    static int gt;

    int t;
public:
    TypeId():t(gt++){}

    TypeId & operator=(const TypeId & ti) { t = ti.t; return *this;}

    bool operator==(const TypeId & ti) const {return ti.t == t;}
    bool operator!=(const TypeId & ti) const {return ti.t != t;}

    operator int() const {return t;}
};

class SpecType : public Const {
    const TypeId type;
public:
    SpecType(const TypeId _type) : type(_type) {}
    virtual ~SpecType() {}
    bool isSpecType() const {return true;}
    SpecType * asSpecType() {return this;}
    const TypeId getType() const {return type;}
    bool hasType(const TypeId _type) const {return type == _type;}

    template <class T>
    T * cast() {
        if(type != T::type_id) {
            cout << "Invalid cast " << toString() << __LINE__;
            throw 0;
        }
        return dynamic_cast<T*>(this);
    }

    string toString() const {return "{SpecType}";}
};

#endif // STEPONE_H
