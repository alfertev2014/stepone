#ifndef TYPESTEMP_H
#define TYPESTEMP_H

//#include "stepone.h"

//template <class T>
//string valueToString(T x)
//{
//    return "fuck!";
//}

//template <class T>
//string typeToString() {return "fuck!";}

////template<>
////string typeToString<int>() {return "i";}

////template<>
////string typeToString<float>() {return "f";}

////template<>
////string typeToString<double>() {return "d";}

////template<>
////string typeToString<char>() {return "c";}


//template <class T>
//class SpecTypeTemp : public SpecType
//{
//    T t;
//public:

//    SpecTypeTemp(const T & _t) : t(_t) {}

//    T getValue() const {return t;}

//    string toString() const
//    {
//        return "{" + typeToString<T>() + ": " + valueToString(t) + "}";
//    }
//};


//template <class T>
//class FSpecTypeP : public Operation
//{
//protected:
//    Ob::Ptr applyX(const Ptr &x)
//    {
//        SpecType * stx = x->asSpecType();
//        return stx == 0 || !stx->hasType(SpecTypeTemp<T>::type_id) ? Ob::anil : Ob::at;
//    }

//public:
//    string toString() const {return "FSpecTypeP{" + typeToString<T>() + "}";}
//};

//template <class T1, class T2>
//class FSpecTypeCast : public Operation
//{
//protected:
//    Ptr applyX(const Ptr &x)
//    {
//        SpecType * stx = x->asSpecType();
//        if(stx == 0) throw 0;
//        return new SpecTypeTemp<T2>(stx->cast<SpecTypeTemp<T1> >()->getValue());
//    }

//public:
//    string toString() const
//    {return "FSpecTypeCast{" + typeToString<T1>() + ", " + typeToString<T2>() + "}";}
//};

//template <class T, class BinOp>
//class FBinaryOp : public Operation
//{
//    class FBinaryOp2 : public Operation
//    {
//        T t1;
//    public:
//        FBinaryOp2(T _t1) : t1(_t1) {}
//    protected:
//        Ptr applyX(const Ptr &x)
//        {
//            SpecType * stx = x->asSpecType();
//            if(stx == 0) throw 0;
//            return new SpecTypeTemp<T>(BinOp::op(t1, stx->cast<SpecTypeTemp<T> >()->getValue()));
//        }
//    public:
//        string toString() const
//        {return "FBinaryOp2{" + typeToString<T>() + ": " + valueToString(t1) + BinOp::toString() + "}";}
//    };
//protected:
//    Ptr applyX(const Ptr &x)
//    {
//        SpecType * stx = x->asSpecType();
//        if(stx == 0) throw 0;
//        return new FBinaryOp2(stx->cast<SpecTypeTemp<T> >()->getValue());
//    }

//public:
//    string toString() const {return "FBinaryOp{" + typeToString<T>() + BinOp::toString() + "}";}
//};

#endif // TYPESTEMP_H
