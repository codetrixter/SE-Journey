/**
 * *This design principle states that whenever there is an interface that methods are not required
 * *to be implemented by most of the classes, then those methos should be separted out and kept in a 
 * *different interface of its own. 
*/
#include <vector>
struct Document;

//struct IMachine
//{
//  virtual void print(Document& doc) = 0;
//  virtual void fax(Document& doc) = 0;
//  virtual void scan(Document& doc) = 0;
//};
//
//struct MFP : IMachine
//{
//  void print(Document& doc) override;
//  void fax(Document& doc) override;
//  void scan(Document& doc) override;
//};

// 1. Recompile
// 2. Client does not need this
// 3. Forcing implementors to implement too much

struct IPrinter
{
  virtual void print(Document& doc) = 0;
};

struct IScanner
{
  virtual void scan(Document& doc) = 0;
};

struct Printer : IPrinter
{
  void print(Document& doc) override;
};

struct Scanner : IScanner
{
  void scan(Document& doc) override;
};

struct IMachine: IPrinter, IScanner
{
};

struct Machine : IMachine
{
  IPrinter& printer;
  IScanner& scanner;

  Machine(IPrinter& printer, IScanner& scanner)
    : printer{printer},
      scanner{scanner}
  {
  }

  void print(Document& doc) override {
    printer.print(doc);
  }
  void scan(Document& doc) override;
};

int main(int argc, char const *argv[])
{
    //TODO: Do the implementation here.
    return 0;
}

// IPrinter --> Printer
// everything --> Machine