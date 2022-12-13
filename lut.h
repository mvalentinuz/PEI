#ifndef LUT_H
#define LUT_H
#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

class LUT
{
private:
    vector<vector<int>> tabla;
public:
    LUT();
    void cargarLUT(string ruta);
    const vector<vector<int> > &getTabla() const;
    ~LUT();
};

#endif // LUT_H
