#ifndef YQ_MODEL_H
#define YQ_MODEL_H
int var_a;
int var_b;

float calculate(float, float);

class Sobel{
public: 
    Sobel();
    int m_a;
    int getInfo(const char *);
private:
    void queryInfo(int);
};
#endif