template <class T>
matrix<T>::matrix ( int r, int c ) : num_rows(r), num_columns(c) {

  if ( r <= 0 || c <= 0 ) {
    throw matrix_exception("Attempted to initialize a matrix with non-positive number of rows and/or columns");
  }

  value = new T[r*c];

  for ( int i=0; i<r*c; i++ ) {
    value[i] = (T) 0;
  }

}

template <class T>
matrix<T>::~matrix() {
  delete []value;
}

template <class T>
matrix<T> matrix<T>::add ( const matrix &m ) const {

  if ( rows() != m.rows() || columns() != m.columns() ) {
    throw matrix_exception("Attemped to add matrices with incompatible sizes");
  }

  matrix M(rows(),columns());

  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<columns(); j++ ) {
      M.set(i,j,(T) (get(i,j) + m.get(i,j))); /* NOTE: Casting result back to T */
    }
  }

  return M;

}
template <class T>
matrix<T> matrix<T>::mult ( const matrix &m ) const {

  if ( columns() != m.rows() ) {
    throw matrix_exception("Attemped to multiple matrices with incompatible sizes");
  }

  matrix M(rows(),columns());

  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<m.columns(); j++ ) {
      M.set(i,j,0);
      for ( int k=0; k<columns(); k++ ) {
        M.set(i,j,M.get(i,j) + get(i,k) * m.get(k,j));
      }
    }
  }

  return M;

}

template <class T>
void matrix<T>::scale ( double d ) {
  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<columns(); j++ ) {
      set(i,j,d*get(i,j));
    }
  }
}

template <class T>
matrix<T> matrix<T>::minor ( int r, int c ) {

  if ( !in_range(r,c) ) {
    throw matrix_exception("Attempted to take minor with out of range indices");
  }

  matrix p ( rows() - 1, columns() - 1 );

  int I, J;

  for ( int i=0, I=0; i<rows(); i++ ) {
    for ( int j=0, J=0; j<columns(); j++ ) {
      if ( i != r && j != c ) {
        p.set(I,J,get(i,j));
        J++;
      }
    }
    if ( i != r ) {
      I++;
    }
  }

  return p;

}
template <class T>
T matrix<T>::det(void) {

  if ( rows() == 1 && columns() == 1 ) {

    return get(0,0);

  } else {

    double sign = 1;
    T sum = 0;

    for ( int i=0; i<columns(); i++ ) {
      sum = sign * get(0,i) * minor(0,i).det() + sum;
      sign *= -1;
    }

    return sum;

  }

}

template <class T>
matrix<T> matrix<T>::inverse ( void ) {

  matrix m(rows(),columns());

  if ( rows() != columns() ) {
    throw matrix_exception("Attempted to invert non-square matrix");
  }

  T d = det();

  if ( d == 0.0 ) {
    throw matrix_exception("Attempted to invert non-invertible matrix");
  }

  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<columns(); j++ ) {
      double sign = ( (i+j)%2 == 0 ) ? 1 : -1;
      m.set(i,j,sign * minor(j,i).det()/d);
    }
  }

  return m;

}
template <class T>
bool matrix<T>::less_than ( const matrix & m ) const {
  if ( rows() != m.rows() || columns() != m.columns() ) {
    throw matrix_exception("Attemped to compare matrices with incompatible sizes");
  }
  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<columns(); j++ ) {
      if ( get(i,j) >= m.get(i,j) ) {
        return false;
      }
    }
  }
  return true;
}

template <class T>
bool matrix<T>::equals ( const matrix & m ) const {
  if ( rows() != m.rows() || columns() != m.columns() ) {
    throw matrix_exception("Attemped to compare matrices with incompatible sizes");
  }
  for ( int i=0; i<rows(); i++ ) {
    for ( int j=0; j<columns(); j++ ) {
      if ( get(i,j) != m.get(i,j) ) {
        return false;
      }
    }
  }
  return true;
}

template <class T>
T matrix<T>::get(int r, int c) const {

  if ( !in_range(r,c) ) {
    throw matrix_exception("Indices out of range in matrix::get");
  }

  return value[r * columns() + c];

}

template <class T>
void matrix<T>::set(int r, int c, T x) {
  if ( !in_range(r,c) ) {
    throw matrix_exception("Indices out of range in matrix::set");
  }
  value[r * columns() + c] = x;
}

template <class T>
bool matrix<T>::in_range(int r, int c) const {
  return 0 <= r && r < rows() && 0 <= c && c < columns();
}

template <class T>
std::ostream& operator<<(std::ostream& os, const matrix<T> &m) {

  for ( int i=0; i<m.rows(); i++ ) {
    for ( int j=0; j<m.columns(); j++ ) {
      os << m.get(i,j) << '\t';
    }
    os << std::endl;
  }

  return os;

}
