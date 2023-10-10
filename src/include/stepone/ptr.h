#pragma once

#include <utility>

namespace stepone {

class Ptr final {
    struct RefCounter;

    RefCounter * rcob;

    Ptr(RefCounter * const rcob) : rcob(rcob) {
        acquire();
    }
public:
    static const Ptr anil();
    static const Ptr at();

    template <class T, class ...Args>
    static Ptr of(Args&&... args);

    Ptr() : Ptr(Ptr::anil()) {}

    Ptr(const Ptr &p) : Ptr(p.rcob) {}
    Ptr(Ptr &&p) : rcob(p.rcob) {
        p.rcob = nullptr;
    }
    ~Ptr() {
        release();
    }

    Ptr &operator=(const Ptr &p) {
        Ptr copied = p;
        swap(copied);
        return *this;
    }
    Ptr &operator=(Ptr &&p) noexcept {
        Ptr moved = std::move(p);
        swap(moved);
        return *this;
    }

    void swap(Ptr &p) noexcept {
        std::swap(rcob, p.rcob);
    }

    bool operator==(const Ptr &p) const {return rcob == p.rcob;}
    bool operator!=(const Ptr &p) const {return rcob != p.rcob;}

    template <class T>
    T * as() const;
    template <class T>
    bool is() const;
    template <class T>
    T &cast() const;

    Ptr car() const;
    Ptr cdr() const;

    Ptr eval(const Ptr & a) const;
    Ptr apply(const Ptr & p, const Ptr & a) const;
private:
    void acquire() const;
    void release() const;
};

} // namespace
