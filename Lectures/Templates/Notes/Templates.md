# Templates
Templates allow us to create *generic* coe, i.e, one code base for many / all data types, instead of code for each particular data type.

A template can be defined for:
- Functions
- Classes

## Template function
Consider the case of squaring a number (a simply function)

    int square(int x)
    {
        return x * x;
    }

    double square(double x)
    {
        return x * x;
    }

    int main()
    {
        cout << square(3) << endl;
        cout << square(3.1) << endl;

        return 0;
    }

Issue(s):
- Repeated code, just for different data types

One solution: Use macros

    #define SQUARE(x) (x*x)
    #define MIN(X, Y) ((X) < (Y) ? (X) : (Y))

    int main()
    {
        cout << SQUARE(3) << endl;
        cout << SQUARE(3.1) << endl;
        cout << SQUARE(3.1e-06) << endl;

        cout << "min: " << MIN(3, MIN(3.1, 3.1e-06)) << endl;

        return 0;
    }

By convention, macro names are defined using ALL CAPITAL LETTERS.

Another solution: Use templates.

    template <Typename T>
    T square(T x)
    {
        return x * x;
    }

    int main()
    {
        cout << square<int>(3) << endl;
        cout << square<double>(3.1) << endl;

        return 0;
    }

Issue(s):
- Code bloat in some cases

## Template Class
String class that handles different languages

    template<class C> class String
    {
        struct Srep;
        Srep *rep;

        public:
            String();
            String(const C*);
            String(const String&);

            C read(int i) const;
            //...
    };

Some details
- **ALL CODE** is in a header file!
- The prefix template<class C> specifies that a template is being declared and that an argument C of data type *type* will be used in the declaration.
- After C is introduced, it is used exactly like any other type name.
- The scope of C extends to the end of the declaration prefixed by template<class C>.
- Note that template<class C> says that C is a *type* namel it need not be the name of a *class*.

The name of a class template followed by a type, bracketed by < >, is the name of a class (As defined by the template) and can be used exactly like other class names.

    String<char> cs;
    String<wchar_t> ws;

    class Jchar
    {
        //Japanese character
    };

    String<Jchar> js;

[Reference Code](../Code/llT.h)

## STL - Brief Overview
The Standard Template Library (STL) is a library of standard class and function templates. The STL contains 6 kinds of components.
- Containers
- container adapters
- iterators
- algorithms
- functors (function objects)
- function adapters

Some references break the STL into only 4 components, the adapters are not considered separate components. Most of the material we have covered (or will cover) is part of the STL (stacks, queues, trees...).