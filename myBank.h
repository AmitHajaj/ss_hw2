#ifndef MYBNAK_H_INCLUDED
#define MYBNAK_H_INCLUDED


        void open(float intitDepos);
        void balance(int accoutnNum);
        void deposit(int accountNum, float amount);
        void withdraw(int accountNum, float amount);
        void close(int accountNum);
        void addInt(int interestRate);
        void toString();
        void end();

#endif // MYBNAK_H_INCLUDED
