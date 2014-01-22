#include "stepone.h"

bool operator ==(const Ob * const ob, const Ob::Ptr & p) {return ob == p.ob;}

int TypeId::gt = 0;

Ob::Ptr Pair::eval(const Ob::Ptr & a)
{
    if(pcar->isAtom())
    {
        if(pcar == Ob::aquote)
        {
            return pcdr;
        }
        else if(pcar == Ob::alet)
        {
            Ptr val = pcdr->cdr();
            return val->cdr()->eval(new Context(pcdr->car(), val->car()->eval(a), a));
        }
        else if(pcar == Ob::aif)
        {
            Ptr p1 = pcdr;
            if(p1->car()->eval(a) == Ob::anil)
            {
                return p1->cdr()->cdr()->eval(a);
            }
            else
            {
                return p1->cdr()->car()->eval(a);
            }
        }
        else if(pcar == Ob::alambda)
        {
            Ob * ob = new Closure(pcdr->car(), pcdr->cdr(), a);
            return ob;
        }
        else if(pcar == Ob::alazy)
        {
            Ob * ob = new Lazy(pcdr, a);
            return ob;
        }
        else if(pcar == Ob::aeval)
        {
            Ob::Ptr p = pcdr->eval(a)->eval(a);
            return p;
        }
        else if(pcar == Ob::aunlazy)
        {
            return pcdr->eval(a)->unlazy();
        }
        else if(pcar == Ob::alabel)
        {
            Context * c = new Context(pcdr->car(), 0, a);
            Lazy * l = new Lazy(pcdr->cdr(), c);
            c->setValue(l);
            Ob::Ptr ob = l;
            return ob;
        }
        else if(pcar == Ob::atry)
        {
            try
            {
                Ob::Ptr ob = pcdr->car()->eval(a);
                return ob == Ob::abot ? pcdr->cdr()->eval(a) : ob;
            }
            catch(...)
            {
                return pcdr->cdr()->eval(a);
            }
        }
    }
    Ob::Ptr ob = pcar->eval(a)->apply(pcdr, a);
    return ob;
}

const Ob::Ptr Ob::anil(new Symbol);
const Ob::Ptr Ob::at(new Symbol);
const Ob::Ptr Ob::aquote(new Symbol);
const Ob::Ptr Ob::aif(new Symbol);
const Ob::Ptr Ob::alambda(new Symbol);
const Ob::Ptr Ob::alet(new Symbol);
const Ob::Ptr Ob::alazy(new Symbol);
const Ob::Ptr Ob::aunlazy(new Symbol);
const Ob::Ptr Ob::alabel(new Symbol);
const Ob::Ptr Ob::aeval(new Symbol);
const Ob::Ptr Ob::atry(new Symbol);
const Ob::Ptr Ob::ado(new Symbol);
const Ob::Ptr Ob::abot(new Symbol);

