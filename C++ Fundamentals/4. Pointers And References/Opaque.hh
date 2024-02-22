#include<iostream>
#include<string>
using namespace std;

class Opaque {

    public:
        Opaque(const string name, int id);
        ~Opaque();

        void Introduce() const;

    private:
        struct OpaqueData;
        OpaqueData* data;
};