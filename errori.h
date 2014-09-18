#ifndef ERRORI_H
#define ERRORI_H

#include <string>

using std::string;

class FuoriPosizione{
  private:
    string err;

  public:
	FuoriPosizione(string s) : err(s) {}

    string Mess() { return err; }
};

#endif
