#ifndef PIXEL_H
#define PIXEL_H


class Pixel
{
private:
    int R;
    int G;
    int B;
public:
    Pixel();
    ~Pixel();
    int getR() const;
    void setR(int newR);
    int getG() const;
    void setG(int newG);
    int getB() const;
    void setB(int newB);
};

#endif // PIXEL_H
