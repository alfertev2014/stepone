#pragma once

namespace stepone {

namespace core {
class Ob;
}

class Ptr;

class WPtr {
    friend class Ptr;
    core::Ob * ob;

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

    Ptr typeId() const;

    template <class T>
    T * as() const;
    template <class T>
    bool is() const;
    template <class T>
    T * cast() const;
};
inline bool operator==(const core::Ob * const & ob, const WPtr & p) {return ob == p.ob;}
inline bool operator!=(const core::Ob * const & ob, const WPtr & p) {return ob != p.ob;}

class Ptr : public WPtr {
    void acqure();
    void release();
    void assing(core::Ob * _ob);
public:
    static const Ptr anil;
    static const Ptr at;

    Ptr(core::Ob * _ob) : WPtr(_ob) {acqure();}
    Ptr(const Ptr & p) : WPtr(p.ob) {acqure();}
    Ptr(const WPtr & p) : WPtr(p.ob) {acqure();}
    Ptr(bool b) : WPtr(b ? at.ob : anil.ob) {acqure();}
    ~Ptr() {release();}

    Ptr & operator=(const Ptr & p) {return operator=(p.ob);}
    Ptr & operator=(const WPtr & p) {return operator=(p.ob);}
    Ptr & operator=(core::Ob * _ob) {
        assing(_ob);
        return *this;
    }
};

} // namespace
