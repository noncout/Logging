#ifndef LOGGING_SINGLETION_H
#define LOGGING_SINGLETION_H


template <class T>
class Singletion {
protected:
    Singletion() {}

    ~Singletion() {}

private:
    Singletion(const Singletion & ) {}

    Singletion & operator=(const Singletion & ) {}

public:
   inline static T * Instance() {
        static T instance;
        return &instance;
    }
};


#endif //LOGGING_SINGLETION_H
