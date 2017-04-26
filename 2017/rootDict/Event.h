#ifndef MYPROJ_EVENT_H_
#define MYPROJ_EVENT_H_

#include <TNamed.h>

#include <memory> // C++11

class TH1F;

namespace MyProj
{

static const Int_t fVersion = 1;

class Event : public TNamed {

 public:
  Event();
  explicit Event(Int_t iev);
  Event(Int_t iev, Char_t *name, Char_t *title);
  virtual ~Event();
  
 private:
  Int_t     fM1; //
  Float_t   fM2; //
  Int_t     fN;  //
  TH1F     *fH1; //->
  //Double_t *fD;  //![fN]
  std::unique_ptr<Double_t> fD;  //![fN]
  std::vector<Double_t>fDv; //!
  
  ClassDef(Event,1)
    
};

}

#endif
