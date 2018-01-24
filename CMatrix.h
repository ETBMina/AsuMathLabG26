#include <fstream>
#include <string>
#include "CComplex.h"
#ifndef CMatrix_H
#define CMatrix_H

using namespace std;
class CMatrix {
private:
  int nR, nC;
  CComplex **values;

  //static bool fixMatrix(CMatrix &m,int r,int c);
  //static bool checkIfZeroMatrix(CMatrix &m);
  public:

  CMatrix();
  //double getDeterminant2();
  //double getDeterminant3();
  ~CMatrix();
  enum MI { MI_ZEROS, MI_ONES, MI_EYE, MI_RAND, MI_VALUE };
  bool isReal();
  CMatrix(int nR, int nC, int initialization = MI_ZEROS,
          CComplex initializationValue = CComplex(0.0));
  //CMatrix(int nR, int nC, double first, ...);
  CMatrix(const CMatrix &m);
  CMatrix(double d);
  //CMatrix(string s);
  void copy(const CMatrix &m);
  void copy(double d);
  //void copy(string s);
  void reset();

  string getString();

  CMatrix operator=(const CMatrix &m);
  CMatrix operator=(double d);
  //CMatrix operator=(string s);

  void add(const CMatrix &m);
  void operator+=(CMatrix &m);
  void operator+=(double d);
  CMatrix operator+(CMatrix &m);
  CMatrix operator+(double d);

  void sub(const CMatrix &m);
  void operator-=(CMatrix &m);
  void operator-=(double d);
  CMatrix operator-(CMatrix &m);
  CMatrix operator-(double d);

  void mul(const CMatrix &m);
  void operator*=(CMatrix &m);
  void operator*=(double d);
  CMatrix operator*(CMatrix &m);
  CMatrix operator*(double d);

  /*void div(CMatrix &m);
  void operator/=(CMatrix &m);
  void operator/=(double d);
  CMatrix operator/(CMatrix &m);
  CMatrix operator/(double d);
  */
  CMatrix operator++();    // Pre Increment
  CMatrix operator++(int); // Post Increment, int is not used
  CMatrix operator--();    // Pre Increment
  CMatrix operator--(int); // Post Increment, int is not used

  CMatrix operator-();
  CMatrix operator+();
  /*
  friend istream& operator >> (istream &is, CMatrix& C);  //Stream
  friend ostream& operator << (ostream &os, CMatrix& C); //Stream
  friend CMatrix operator /(double d ,CMatrix &m);
  void setSubMatrix(int iR, int iC, CMatrix &m);
  CMatrix getSubMatrix(int r, int c, int nr, int nc);
  CMatrix getCofactor(int r, int c);
  */
  void setSubMatrix(int iR, int iC, CMatrix &m);
  void addColumn(CMatrix &m);
  void addRow(CMatrix& m);

  CComplex &operator[](int i) { return values[i / nC][i % nC]; }
  CComplex &operator()(int i) { return values[i / nC][i % nC]; };
  CComplex &operator()(int r, int c) { return values[r][c]; };
  int getn() { return nR * nC; };
  int getnR() { return nR; };
  int getnC() { return nC; };

  /*double getDeterminant();
  CMatrix getTranspose();
  CMatrix getInverse();
  string getString2();
  void writeMatrixInFile(string file);*/

};

#endif
