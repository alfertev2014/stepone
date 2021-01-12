#pragma once

#include <utility>

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
        acquire();
    }
    Ptr(const Ptr & p) : Ptr(p.ob) {}
    Ptr(Ptr &&p) : WPtr(p.ob) {
        p.ob = Ptr::anil().ob;
	Ptr::anil().acquire();
    }
    Ptr(const WPtr & p) : Ptr(p.ob) {}
    ~Ptr() {
        release();
    }

    Ptr &operator=(const Ptr &p) {
        p.acquire();
        release();
        ob = p.ob;
        return *this;
    }
    Ptr &operator=(Ptr &&p) {
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
