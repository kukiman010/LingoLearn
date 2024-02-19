#ifndef FACTORY_H
#define FACTORY_H



class Factory {
public:
    Factory();
    enum class ClassType {
        A,
        B
    };

    // static BaseClass* createClass(ClassType type) {
    //     switch (type) {
    //     case ClassType::A:
    //         return new ClassA();
    //     case ClassType::B:
    //         return new ClassB();
    //     default:
    //         return nullptr;
    //     }
    // }
};

#endif // FACTORY_H
