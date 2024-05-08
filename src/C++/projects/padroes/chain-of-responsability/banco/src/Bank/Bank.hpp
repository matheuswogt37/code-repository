#ifndef Bank_hpp
#define Bank_hpp

class Bank {
    private:
        float creds;
    public:
        Bank(float c);
        ~Bank();
        float getCreds();
};


#endif