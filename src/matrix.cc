#include "matrix.h"

// Constructor from scratch
template <class Element> 
TMatrix<Element> :: TMatrix(const int nrow, const int ncol)
{
  _nrows = nrow;
  _ncols = ncol;
  _length = _nrows*_ncols;
  data = new Element[_length];
  _mypointer = 1;
}

// Constructor from existing C vector - just wraps the pointer
// use with care, user must manage memory
template <class Element> 
TMatrix<Element> :: TMatrix(Element *xref, const int nrow, const int ncol)
{
  _nrows = nrow;
  _ncols = ncol;
  _length = _nrows*_ncols;
  data = xref;
  _mypointer = 0;
}

// destructor
template <class Element> 
TMatrix<Element> :: ~TMatrix()
{
  if (_mypointer) delete [] data;
}

// assign a single value to all entries
template <class Element> 
void TMatrix<Element> :: operator=(const Element &val)
{
  int i;
  for(i=0; i< _length; i++) data[i] = val;
}

// extract reference to an entry (const and non-const versions)
template <class Element> 
Element & TMatrix<Element> ::operator()(const int i, const int j)
{
  return( data[index(i,j)] );
}

template <class Element> 
const Element & TMatrix<Element> ::operator()(const int i, const int j) const
{
  return( data[index(i,j)] );
}

// manually instantiate commonly used variants
template class TMatrix<double>;
template class TMatrix<int>;
template class TVector<double>;
template class TVector<int>;

