#ifndef CALCENG_H
#define CALCENG_H


class CalcEng
{
    public:
        CalcEng();
        void operation(char c);
        void operand(double in);
        char opcode() const { return op; }
        double output() const
        { return (argcnt==2?(arg):ans); }

    private:
        void compute();
        void allclear();
        double ans,arg;
        char op;
        int argcnt;
};

#endif // CALCENG_H
