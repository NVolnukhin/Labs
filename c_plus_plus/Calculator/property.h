#ifndef PROPERTY_H
#define PROPERTY_H

template <typename Owner, typename Type>

class Property {
    using Getter = Type(Owner::*)() const;
    using Setter = void (Owner::*)(const Type&);

public:
    Property() = default;
    Property(Owner* const owr, Getter getmethod, Setter setmethod) : owner(owr), methodGet(getmethod), methodSet(setmethod) {}
    void init(Owner* const owr, Getter getmethod, Setter setmethod) {
        owner = owr;
        methodGet = getmethod;
        methodSet = setmethod;
    }

    operator Type() {                       // Getter
        return (owner->*methodGet)();
    }

    void operator=(const Type& data) {      // Setter
        (owner->*methodSet)(data);
    }

private:
    Owner* owner;
    Getter methodGet;
    Setter methodSet;
};

#endif // PROPERTY_H
