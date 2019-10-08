#pragma once

#include <utility>

#include <stdio.h>

namespace stepone {

namespace core {
class Ob;
}

class Ptr;

class WPtr {
    friend class Ptr;
    core::Ob * ob; // Always not nullptr

    WPtr(core::Ob * _ob) : ob(_ob) {}
public:
    friend bool operator==(const core::Ob * const & ob, const WPtr & p);
    friend bool operator!=(const core::Ob * const & ob, const WPtr & p);

    bool operator==(const WPtr & p) const {return ob == p;}
    bool operator!=(const WPtr & p) const {return ob != p;}

    bool operator==(const core::Ob * const p) const {return ob == p;}
    bool operator!=(const core::Ob * const p) const {return !(ob == p);}

    Ptr car() const;
    Ptr cdr() const;

    Ptr eval(const Ptr & a) const;
    Ptr apply(const Ptr & p, const Ptr & a) const;
    Ptr unlazy() const;
    Ptr assoc(const Ptr & s) const;

    template <class T>
    T * as() const;
    template <class T>
    bool is() const;
    template <class T>
    T &cast() const;
};
inline bool operator==(const core::Ob * const & ob, const WPtr & p) {return ob == p.ob;}
inline bool operator!=(const core::Ob * const & ob, const WPtr & p) {return ob != p.ob;}

class Ptr : public WPtr {
    void acquire() const;
    void release() const;
public:
    static const Ptr anil();
    static const Ptr at();

    Ptr() : Ptr(Ptr::anil()) {}

    // TODO: Ensure _ob is not nullptr
    Ptr(core::Ob * _ob) : WPtr(_ob) {
        // printf("Ptr(), ob=%lx\t", (unsigned long)ob);
        acquire();
    }
    Ptr(const Ptr & p) : Ptr(p.ob) {}
    Ptr(Ptr &&p) : WPtr(p.ob) {
        p.ob = Ptr::anil().ob;
	Ptr::anil().acquire();
    }
    Ptr(const WPtr & p) : Ptr(p.ob) {}
    ~Ptr() {
        // printf("~Ptr(), ob=%lx\t", (unsigned long)ob);
        release();
    }

    Ptr &operator=(const Ptr &p) {
        // printf("Ptr::operator=, ob=%lx\n", (unsigned long) ob);
        p.acquire();
        release();
        ob = p.ob;
        return *this;
    }
    Ptr &operator=(Ptr &&p) {
        // printf("Ptr::operator= &&, ob=%lx\n", (unsigned long) ob);
        if (&p != this) { // TODO: Is it always true?
            release();
            ob = p.ob;
            p.ob = Ptr::anil().ob;
	    Ptr::anil().acquire();
        }
        return *this;
    }

    void swap(Ptr &p) noexcept {
        std::swap(ob, p.ob);
    }
};

} // namespace
